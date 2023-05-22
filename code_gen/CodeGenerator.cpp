//
// Created by 刘宇轩 on 2023/5/15.
//

#include "CodeGenerator.h"
llvm::LLVMContext CodeGenerator::Context;
llvm::IRBuilder<> CodeGenerator::IRBuilder{CodeGenerator::Context};

void CodeGenerator::optimize(const std::string &opt_level) {
    assert(Module);

    static std::map<std::string, llvm::OptimizationLevel> optimizer = {
            {"O0", llvm::OptimizationLevel::O0},
            {"O1", llvm::OptimizationLevel::O1},
            {"O2", llvm::OptimizationLevel::O2},
            {"O3", llvm::OptimizationLevel::O3},
            {"Oz", llvm::OptimizationLevel::Oz},
            {"Os", llvm::OptimizationLevel::Os}
    };

    llvm::LoopAnalysisManager LAM;
    llvm::FunctionAnalysisManager FAM;
    llvm::CGSCCAnalysisManager CGAM;
    llvm::ModuleAnalysisManager MAM;
    //Create the new pass manager builder.
    llvm::PassBuilder PB;
    //Register all the basic analyses with the managers.
    PB.registerModuleAnalyses(MAM);
    PB.registerCGSCCAnalyses(CGAM);
    PB.registerFunctionAnalyses(FAM);
    PB.registerLoopAnalyses(LAM);
    PB.crossRegisterProxies(LAM, FAM, CGAM, MAM);
    auto opt_level_llvm = optimizer.contains(opt_level) ? optimizer.at(opt_level) : llvm::OptimizationLevel::O0;
    auto MPM = PB.buildPerModuleDefaultPipeline(opt_level_llvm);
    MPM.run(*Module, MAM);
}

void CodeGenerator::GenObjectCode(std::string file_name) {
    auto TargetTriple = llvm::sys::getDefaultTargetTriple();

    llvm::InitializeAllTargetInfos();
    llvm::InitializeAllTargets();
    llvm::InitializeAllTargetMCs();
    llvm::InitializeAllAsmParsers();
    llvm::InitializeAllAsmPrinters();

    std::string error;
    auto Target = llvm::TargetRegistry::lookupTarget(TargetTriple, error);

    if (!Target)
        throw std::runtime_error(error);

    auto CPU = "generic";

    llvm::TargetOptions opt;
    auto RM = llvm::Optional<llvm::Reloc::Model>();
    auto TargetMachine = Target->createTargetMachine(TargetTriple, CPU, "", opt, RM);

    Module->setDataLayout(TargetMachine->createDataLayout());
    Module->setTargetTriple(TargetTriple);

    std::error_code ec;
    llvm::raw_fd_ostream Dest(file_name, ec, llvm::sys::fs::OF_None);

    if (ec)
        throw std::runtime_error("Could not open file: " + ec.message());

    auto FileType = llvm::CGFT_ObjectFile;
    llvm::legacy::PassManager PM;

    if (TargetMachine->addPassesToEmitFile(PM, Dest, nullptr, FileType))
        throw std::runtime_error("type unsupported");


    PM.run(*Module);
    Dest.flush();
}

void CodeGenerator::generate() {
    assert(root_ != nullptr && root_->type_ == kRoot);
    auto start = root_->child_;
    while (start) {
        generators[start->type_]();
        start = start->next_;
    }
}
