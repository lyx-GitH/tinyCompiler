//
// Created by 刘宇轩 on 2023/5/15.
//

#include "code_generator.h"

std::array<CodeGenerator::GenFunc, MAX_GEN_NUM> CodeGenerator::generators{};
llvm::LLVMContext CodeGenerator::context{};
llvm::IRBuilder<> CodeGenerator::IR_builder{CodeGenerator::context};
llvm::Function *CodeGenerator::cur_func_{nullptr};
std::vector<CodeGenerator::SymbolTable> CodeGenerator::symbol_table_stack_{};

void CodeGenerator::InitGenerators() {
    LOAD_GEN(kRoot);
    LOAD_GEN(kFuncDef);
    LOAD_GEN(kVarDecl);
    LOAD_GEN(kType);
    LOAD_GEN(kTypeFeature);
    LOAD_GEN(kFuncDef);
    LOAD_GEN(kFuncType);
    LOAD_GEN(kPtrType);
    LOAD_GEN(kArrType);
}

void CodeGenerator::InitBasicTypes() {
    SetType("char", TypeFactory::Get(IR_builder.getInt8Ty()));
    SetType("short", TypeFactory::Get(IR_builder.getInt16Ty()));
    SetType("int", TypeFactory::Get(IR_builder.getInt32Ty()));
    SetType("float", TypeFactory::Get(IR_builder.getFloatTy()));
    SetType("double", TypeFactory::Get(IR_builder.getDoubleTy()));
}

CodeGenerator::pValue CallGenerator(const AstNode *node) {
    if (!node)
        return {};
    else return CALL_GEN(node);
}

void CodeGenerator::Optimize(const std::string &opt_level) {
    assert(module_);

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
    MPM.run(*module_, MAM);
}

void CodeGenerator::GenObjectCode(const std::string &file_name) {
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

    module_->setDataLayout(TargetMachine->createDataLayout());
    module_->setTargetTriple(TargetTriple);

    std::error_code ec;
    llvm::raw_fd_ostream Dest(file_name, ec, llvm::sys::fs::OF_None);

    if (ec)
        throw std::runtime_error("Could not open file: " + ec.message());

    auto FileType = llvm::CGFT_ObjectFile;
    llvm::legacy::PassManager PM;

    if (TargetMachine->addPassesToEmitFile(PM, Dest, nullptr, FileType))
        throw std::runtime_error("type unsupported");


    PM.run(*module_);
    Dest.flush();
}

void CodeGenerator::DumpIR(std::string &&file_name) {
    if (file_name.empty()) {
        file_name.assign("IR");
    }
    std::error_code ec;
    llvm::raw_fd_ostream Out(file_name, ec);

    module_->print(Out, nullptr);

    if (!llvm::verifyModule(*module_, &Out))
        Out << "No errors.\n";
}


Symbol const *CodeGenerator::GetSymbol(const std::string &name) {
    for (auto rit = symbol_table_stack_.rbegin(); rit != symbol_table_stack_.rend(); ++rit) {
        if (rit->contains(name))
            return &rit->at(name);
    }
    return nullptr;
}

void CodeGenerator::Generate() {
    if (!ast_root_)
        return;
    assert(ast_root_->type_ == kRoot);
    CALL_GEN(ast_root_);
}


GEN_DEF(kRoot) {
    {
        ScopeGuard guard;
        auto sub_blocks = node->child_;
        while (sub_blocks) {
            CallGenerator(sub_blocks);
            sub_blocks = sub_blocks->next_;
        }
    }
    return {};
}

GEN_DEF(kFuncDef) {
    ASSERT_TYPE(node, kFuncDef);
    {
        ScopeGuard guard;
        auto func_decl_node = getNChildSafe(node, 0);
        auto func_body_node = getNChildSafe(node, 1);
        ASSERT_TYPE(func_decl_node, kVarDecl);
        ASSERT_TYPE(func_body_node, kScope);
        auto func_var = CallGenerator(func_decl_node).GetFunction();
        FuncGuard func_guard(func_var);
        {
            CallGenerator(func_body_node);
        }
        return {};
    }
}

GEN_DEF(kVarDecl) {
    auto var_type_node = getNChildSafe(node, 0);
    auto var_id_node = getNChildSafe(node, 1);
    assert(var_type_node);
    assert(var_id_node);
    auto symbol = CallGenerator(var_type_node);
    return {};
}

GEN_DEF(kFuncType) {
    ASSERT_TYPE(node, kFuncType);
    auto ret_node = getNChildSafe(node, 0);
    auto ret_type = CallGenerator(ret_node).GetType();
    std::vector<llvm::Type *> param_types;
    //TODO: add methods to create params_types

    auto type = TypeFactory::Get<llvm::FunctionType>(ret_type, param_types, false);
    return pValue{type};
}

GEN_DEF(kType) {
    ASSERT_TYPE(node, kType);
    return Symbol{GetType(node->val_)};
}

GEN_DEF(kPtrType) {
    auto ptr_to_type = getNChildSafe(node, 0);
    assert(ptr_to_type);
    auto ptr_to_symbol = CallGenerator(ptr_to_type);
    return pValue{TypeFactory::Get<llvm::PointerType>(ptr_to_symbol.GetType(), 0U)};
}

GEN_DEF(kArrType) {
    auto ele_type = getNChildSafe(node, 0);
    auto len = getNChildSafe(node, 1);
    assert(ele_type);
    assert(len);
    auto type_symbol = CallGenerator(ele_type);
    if (len->type_ == kDemNumber && strcmp(len->val_, "*") == 0) {
        return pValue{TypeFactory::Get<llvm::PointerType>(type_symbol.GetType(), 0U)};
    } else {
        uint64_t len_i = solveConstantExpr(len);
        return pValue{TypeFactory::Get<llvm::ArrayType>(type_symbol.GetType(), len_i)};
    }
}

GEN_DEF(kTypeFeature) {
    auto type_node = getNChildSafe(node, 0);
    ASSERT_TYPE(type_node, kType);
    auto type = CallGenerator(type_node);
    auto qualifiers = type_node->next_;
    while (qualifiers && strcmp(qualifiers->val_, "const")) {
        qualifiers = qualifiers->next_;
    }
    if (qualifiers) {
        return pValue{TypeFactory::GetConstTypeOf(type.GetType())};
    } else return type;
}

GEN_DEF(kTypeDef) {
    ASSERT_TYPE(node, kTypeDef);
    auto real_type_node = getNChildSafe(node, 0);
    auto real_type = CallGenerator(real_type_node).GetType();
    auto alias_name = getNChildSafe(node, 1)->val_;
    AddTypeAlias(alias_name, real_type);
}

void CodeGenerator::SetSymbol(const std::string &name, Symbol symbol) {
    assert(!symbol_table_stack_.empty() && !symbol_table_stack_.back().contains(name));
    symbol_table_stack_.back().insert({name, symbol});
}

void CodeGenerator::SetType(const std::string &name, llvm::Type *type) {
    SetSymbol(name, Symbol{type});
}

void CodeGenerator::AddTypeAlias(const std::string &name, llvm::Type *type) {
    assert(GetSymbol(name));
    SetType(name, type);
}

llvm::Type *CodeGenerator::GetType(const std::string &name) {
    auto symbol = GetSymbol(name);
    assert(symbol && symbol->IsType());
    return symbol->GetType();
}

