//
// Created by 刘宇轩 on 2023/5/15.
//

#include "code_generator.h"

std::array<CodeGenerator::GenFunc, MAX_GEN_NUM> CodeGenerator::generators{};
llvm::LLVMContext CodeGenerator::context{};
llvm::IRBuilder<> CodeGenerator::IR_builder{CodeGenerator::context};
llvm::Module CodeGenerator::module{"main", context};
llvm::DataLayout CodeGenerator::data_layout{&module};
llvm::Function *CodeGenerator::cur_func_{nullptr};
std::vector<CodeGenerator::SymbolTable> CodeGenerator::symbol_table_stack_{};
std::set<std::string> CodeGenerator::defined_functions{};
bool CodeGenerator::cur_init_{false};

void CodeGenerator::InitGenerators() {
    LOAD_GEN(kRoot);

    LOAD_GEN(kType);
    LOAD_GEN(kTypeDef);
    LOAD_GEN(kTypeFeature);
    LOAD_GEN(kFuncDef);
    LOAD_GEN(kScope);
    LOAD_GEN(kFuncType);
    LOAD_GEN(kPtrType);
    LOAD_GEN(kArrType);

    LOAD_GEN(kVarInit);
    LOAD_GEN(kVarDecl);

    LOAD_GEN(kHexNumber);
    LOAD_GEN(kDemNumber);
    LOAD_GEN(kOctNumber);
    LOAD_GEN(kCharLiteral);
    LOAD_GEN(kStrLiteral);

    LOAD_GEN(kExpr);
}

void CodeGenerator::InitBasicTypes() {
    SetType("void", TypeFactory::Get(IR_builder.getVoidTy()));
    SetType("_bool", TypeFactory::Get(IR_builder.getInt16Ty()));
    SetType("char", TypeFactory::Get(IR_builder.getInt8Ty()));
    SetType("short", TypeFactory::Get(IR_builder.getInt16Ty()));
    SetType("int", TypeFactory::Get(IR_builder.getInt32Ty()));
    SetType("float", TypeFactory::Get(IR_builder.getFloatTy()));
    SetType("double", TypeFactory::Get(IR_builder.getDoubleTy()));
    SetType("long", TypeFactory::Get(IR_builder.getInt64Ty()));
}

CodeGenerator::pValue CallGenerator(const AstNode *node) {
    if (!node)
        return {};
    else return CALL_GEN(node);
}

void CodeGenerator::Optimize(const std::string &opt_level) {
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
    MPM.run(module, MAM);
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

    module.setDataLayout(TargetMachine->createDataLayout());
    module.setTargetTriple(TargetTriple);

    std::error_code ec;
    llvm::raw_fd_ostream Dest(file_name, ec, llvm::sys::fs::OF_None);

    if (ec)
        throw std::runtime_error("Could not open file: " + ec.message());

    auto FileType = llvm::CGFT_ObjectFile;
    llvm::legacy::PassManager PM;

    if (TargetMachine->addPassesToEmitFile(PM, Dest, nullptr, FileType))
        throw std::runtime_error("type unsupported");


    PM.run(module);
    Dest.flush();
}

void CodeGenerator::DumpIR(std::string &&file_name) {
    if (file_name.empty()) {
        file_name.assign("IR");
    }
    std::error_code ec;
    llvm::raw_fd_ostream Out(file_name, ec);

    module.print(Out, nullptr);

    if (!llvm::verifyModule(module, &Out))
        Out << "No errors.\n";
}


Symbol const *CodeGenerator::GetSymbol(const std::string &name) {
    for (auto rit = symbol_table_stack_.rbegin(); rit != symbol_table_stack_.rend(); ++rit) {
        if (rit->contains(name))
            return &rit->at(name);
    }
    return nullptr;
}

Symbol const *CodeGenerator::GetLocalSymbol(const std::string &name) {
    if (symbol_table_stack_.empty())
        return nullptr;
    auto &top = symbol_table_stack_.back();
    return top.contains(name) ? &top.at(name) : nullptr;
}

void CodeGenerator::Generate() {
    if (!ast_root_)
        return;
    assert(ast_root_->type_ == kRoot);
    try{
        CallGenerator(ast_root_);
    } catch (ParseException& e) {
        e.show();
    }

}



DEF_GEN(kRoot) {
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

DEF_GEN(kFuncDef) {
    ASSERT_TYPE(node, kFuncDef);

    auto func_decl_node = getNChildSafe(node, 0);
    auto func_body_node = getNChildSafe(node, 1);
    ASSERT_TYPE(func_decl_node, kVarDecl);
    ASSERT_TYPE(func_body_node, kScope);

    auto func_var = CallGenerator(func_decl_node).GetFunction();
    defined_functions.insert(func_var->getName().str());
    {
        ScopeGuard scope_guard;
        auto func_block = llvm::BasicBlock::Create(context, func_var->getName() + "_entry", func_var);
        IR_builder.SetInsertPoint(func_block);
        FuncGuard func_guard(func_var);
        {
            auto params = func_decl_node->child_->child_->next_;
            ASSERT_TYPE(params, kFuncParams);
            auto cur = params->child_;
            while (cur && cur->type_ == kVarDecl) {
                if (cur->type_ != kVarDecl)
                    throw_code_gen_exception(cur, "no anonymous declaration allowed");
                CallGenerator(cur);
                cur = cur->next_;
            }

            CallGenerator(func_body_node);

        }
    }
    return {};


}

DEF_GEN(kVarDecl) {
    auto var_type_node = getNChildSafe(node, 0);
    auto var_id_node = getNChildSafe(node, 1);
    assert(var_type_node);
    assert(var_id_node);
    auto type = CallGenerator(var_type_node).GetType();
    auto name = var_id_node->val_;

    if (type->isVoidTy())
        throw_code_gen_exception(var_type_node, "cannot declare a void variable");

    if (type->isFunctionTy()) {
        if (cur_init_)
            throw_code_gen_exception(var_type_node, "cannot initialize a function");
        if (cur_func_)
            throw_code_gen_exception(var_type_node, "cannot declare a function inside a function");
        if (defined_functions.contains(name))
            throw_code_gen_exception(var_type_node, "function redefined");
        else if (GetLocalSymbol(name) && GetLocalSymbol(name)->GetFunction()->getFunctionType() == type) {
            return GetLocalSymbol(name)->GetFunction();
        }
    }

    if (GetLocalSymbol(name))
        throw_code_gen_exception(var_id_node, "duplicate symbol");

    if (var_type_node->type_ == kFuncType && type->isFunctionTy()) {
        auto f = llvm::Function::Create((llvm::FunctionType *) (type), llvm::GlobalValue::ExternalLinkage,
                                        std::string{name}, module);
        SetSymbol(name, f);
        return {f};
    }


    if (!cur_init_ && TypeFactory::IsConst(type))
        throw_code_gen_exception(var_id_node, "uninitialized const variable");

    if (cur_init_)
        return {type}; // semantics checks are done, if this is a child node, the parent will do the rest.

    if (!cur_func_) {
        // this var is a global var.
        // this is a global with an undefined value
        auto value = llvm::UndefValue::get(type);
        auto glob_var = new llvm::GlobalVariable(
                module,
                type,
                false,
                llvm::Function::ExternalLinkage,
                value,
                std::string{name}
        );
//                Symbol s(glob_var);
        Symbol s{glob_var};
        SetSymbol(name, s);
    } else {
        auto block_builder = llvm::IRBuilder<>(&cur_func_->getEntryBlock(), cur_func_->getEntryBlock().begin());
        auto alloc = block_builder.CreateAlloca(type, nullptr, name);
        SetSymbol(name, alloc);
        return {alloc};
    }
//    return type;
}

DEF_GEN(kVarInit) {
    {
        VarInitGuard g;
        auto var_decl_node = getNChildSafe(node, 0);
        auto expr_node = getNChildSafe(node, 1);
        assert(expr_node);
        ASSERT_TYPE(var_decl_node, kVarDecl);
        CallGenerator(var_decl_node);   // this would do semantic checks.
        auto init_value_sym = CallGenerator(expr_node);
        if (!cur_func_ && !init_value_sym.IsConst())
            throw_code_gen_exception(expr_node, "cannot use non-const value to initialize global variables");
        auto type = CallGenerator(getNChildSafe(var_decl_node, 0)).GetType();
        auto name = std::string{getNChildSafe(var_decl_node, 1)->val_};
        if (cur_func_) {
            auto block_builder = llvm::IRBuilder<>(&cur_func_->getEntryBlock(), cur_func_->getEntryBlock().begin());
            auto alloca = block_builder.CreateAlloca(type, nullptr, name);
            IR_builder.CreateStore(init_value_sym.GetVariable(), alloca);
            SetSymbol(name, alloca);
        } else {
            assert(init_value_sym.IsConst());
            auto global_var = new llvm::GlobalVariable(
                    module,
                    type,
                    TypeFactory::IsConst(type),
                    llvm::Function::ExternalLinkage,
                    (llvm::Constant *) init_value_sym.GetConstant(),
                    name
            );
            Symbol s{global_var};
            SetSymbol(name, s);
        }


        return {};
    }

}

void CodeGenerator::CollectArgTypes(pAstNode node, std::vector<llvm::Type *> &collector) {
    ASSERT_TYPE(node, kFuncParams);
    auto param_start = node->child_;
    int param_idx = 0;
    int void_idx = -1;
    while (param_start) {
        if (param_start->type_ == kVargs) {
            if (param_start->next_)
                throw_code_gen_exception(param_start, "va-args must be at the end of function");
            else collector.push_back(nullptr);
            break;
        }
        if (param_start->type_ == kVarInit || param_start->type_ == kVarDecl) {
            collector.push_back(CallGenerator(param_start->child_).GetType());
        } else {
            collector.push_back(CallGenerator(param_start).GetType());
        }
        if (collector.back()->isVoidTy())
            void_idx = param_idx;
        ++param_idx;
        param_start = param_start->next_;
    }
    if (void_idx >= 0 && collector.size() != 1)
        throw_code_gen_exception(getNChildSafe(node, void_idx),
                                 "no void type allowed in function declaration/definition");
}


DEF_GEN(kFuncType) {
    ASSERT_TYPE(node, kFuncType);
    auto ret_node = getNChildSafe(node, 0);
    auto ret_type = CallGenerator(ret_node).GetType();
    std::vector<llvm::Type *> param_types;
    bool is_vargs = false;
    CollectArgTypes(ret_node->next_, param_types);
    // a nullptr is a placeholder for va_args
    if (!param_types.empty() && param_types.back() == nullptr) {
        is_vargs = true;
        param_types.pop_back();
    }


    auto type = TypeFactory::Get<llvm::FunctionType>(ret_type, param_types, is_vargs);
    return pValue{type};
}

DEF_GEN(kType) {
    ASSERT_TYPE(node, kType);

    return Symbol{GetType(node->val_)};
}

DEF_GEN(kPtrType) {
    auto ptr_to_type = getNChildSafe(node, 0);
    assert(ptr_to_type);
    auto ptr_to_symbol = CallGenerator(ptr_to_type);
    return pValue{TypeFactory::Get<llvm::PointerType>(ptr_to_symbol.GetType(), 0U)};
}

DEF_GEN(kArrType) {
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

DEF_GEN(kTypeFeature) {
    auto type_node = getNChildSafe(node, 0);
    ASSERT_TYPE(type_node, kType);
    auto type = CallGenerator(type_node);
    auto qualifiers = type_node->next_;
    while (qualifiers && strcmp(qualifiers->val_, "const") != 0) {
        qualifiers = qualifiers->next_;
    }
    if (qualifiers) {
        return pValue{TypeFactory::GetConstTypeOf(type.GetType())};
    } else return type;
}

DEF_GEN(kTypeDef) {
    ASSERT_TYPE(node, kTypeDef);
    auto real_type_node = getNChildSafe(node, 0);
    auto real_type = CallGenerator(real_type_node).GetType();
    auto alias_name = getNChildSafe(node, 1)->val_;
    AddTypeAlias(alias_name, real_type);
    return {};
}

// Const Literals
DEF_GEN(kDemNumber) {
    assert(node && IS_NUMBER(node->type_));
    auto i = strtoll(node->val_, nullptr, 0);
    return {llvm::ConstantInt::get(GetType("long"), i), true};
}

DEF_GEN(kHexNumber) {
    ASSERT_TYPE(node, kOctNumber);
    return GEN_NAME(kDemNumber)(node);
}

DEF_GEN(kOctNumber) {
    ASSERT_TYPE(node, kOctNumber);
    return GEN_NAME(kDemNumber)(node);
}

DEF_GEN(kStrLiteral) {
    ASSERT_TYPE(node, kStrLiteral);
    return {IR_builder.CreateGlobalStringPtr(node->val_), true};
}

DEF_GEN(kFloatNumber) {
    auto f = atof(node->val_);
    return {llvm::ConstantFP::get(GetType("double"), f), true};
}

DEF_GEN(kCharLiteral) {
    auto c = static_cast<uint8_t>(node->val_[0]);
    return {llvm::ConstantInt::get(GetType("char"), c), true};
}

DEF_GEN(kExpr) {
    return CallGenerator(node->child_);
}

// Const end

void CodeGenerator::SetSymbol(const std::string &name, Symbol symbol) {
    assert(!symbol_table_stack_.empty() && !symbol_table_stack_.back().contains(name));
    symbol_table_stack_.back().insert({name, symbol});
}

void CodeGenerator::SetType(const std::string &name, llvm::Type *type) {
    SetSymbol(name, Symbol{type});
}

void CodeGenerator::AddTypeAlias(const std::string &name, llvm::Type *type) {
    assert(has_type(name.c_str()));
    SetType(name, type);
}

llvm::Type *CodeGenerator::GetType(const std::string &name) {
    auto symbol = GetSymbol(name);
    assert(symbol && symbol->IsType());
    return symbol->GetType();
}

DEF_GEN(kScope) {
    ASSERT_TYPE(node, kScope);
    {
        ScopeGuard guard;
        auto stats = node->child_;
        while (stats) {
            CallGenerator(stats);
            stats = stats->next_;
        }
    }
}



//void CodeGenerator::HandleFunctionDecl(const AstNode *func_node, bool is_def) {
//
//}



