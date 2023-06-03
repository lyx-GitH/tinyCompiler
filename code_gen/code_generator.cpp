//
// Created by 刘宇轩 on 2023/5/15.
//

#include "code_generator.h"
#include "../static_semantics/sematics.h"

std::string CodeGenerator::cur_struct_name{};

std::array<CodeGenerator::GenFunc, MAX_GEN_NUM> CodeGenerator::generators{};

llvm::LLVMContext CodeGenerator::context{};

llvm::IRBuilder<> CodeGenerator::IR_builder{CodeGenerator::context};

llvm::Module CodeGenerator::module{"main", context};

llvm::DataLayout CodeGenerator::data_layout{&module};

llvm::Function *CodeGenerator::cur_func_{nullptr};

llvm::BasicBlock *CodeGenerator::global_entry{nullptr};

llvm::Function *CodeGenerator::global{nullptr};

const AstNode *CodeGenerator::cur_node{nullptr};

std::vector<CodeGenerator::SymbolTable> CodeGenerator::symbol_table_stack_{};

std::vector<CodeGenerator::TypeTable> CodeGenerator::symbol_type_stack_{};

std::vector<CodeGenerator::LoopScope> CodeGenerator::loop_stack{};

std::map<std::string, const AstNode *> CodeGenerator::type_aliases_map{};

CodeGenerator::StructTypeTable CodeGenerator::struct_type_table{};

CodeGenerator::UnionTypeTable CodeGenerator::union_type_table{};

CodeGenerator::BlockTable CodeGenerator::block_table{};

std::set<std::string> CodeGenerator::defined_functions{};

bool CodeGenerator::cur_init_{false};

int CodeGenerator::cur_init_list_size{-1};

bool CodeGenerator::en_warn{true};

std::array<CodeGenerator::GenFunc, MAX_GEN_NUM> CodeGenerator::binary_gen_left{};

std::array<CodeGenerator::GenFunc, MAX_GEN_NUM> CodeGenerator::binary_gen_right{};

std::array<CodeGenerator::GenFunc, MAX_GEN_NUM> CodeGenerator::unary_gen_left{};

std::array<CodeGenerator::GenFunc, MAX_GEN_NUM> CodeGenerator::unary_gen_right{};

std::array<CodeGenerator::GenFunc, MAX_GEN_NUM> CodeGenerator::assign_gen_left{};

std::array<CodeGenerator::GenFunc, MAX_GEN_NUM> CodeGenerator::assign_gen_right{};

std::string convert_to_raw(const char *s, std::size_t len);


void CodeGenerator::InitGenerators() {
    LOAD_GEN(kRoot);

    LOAD_GEN(kId);

    LOAD_GEN(kType);
    LOAD_GEN(kTypeDef);
    LOAD_GEN(kTypeAlias);
    LOAD_GEN(kTypeFeature);
    LOAD_GEN(kFuncDef);
    LOAD_GEN(kScope);

    LOAD_GEN(kFuncType);
    LOAD_GEN(kPtrType);
    LOAD_GEN(kArrType);
    LOAD_GEN(kStructType);
    LOAD_GEN(kUnionType);
    LOAD_GEN(kEnumType);

    LOAD_GEN(kVarInit);
    LOAD_GEN(kVarDecl);
    LOAD_GEN(kFuncDecl);

    LOAD_GEN(kHexNumber);
    LOAD_GEN(kDemNumber);
    LOAD_GEN(kOctNumber);
    LOAD_GEN(kFloatNumber);
    LOAD_GEN(kCharLiteral);
    LOAD_GEN(kStrLiteral);

    LOAD_GEN(kExpr);
    LOAD_GEN(kFuncCall);
    LOAD_GEN(kSubScript);
    LOAD_GEN(kAssign);
    LOAD_GEN(kCast);
    LOAD_GEN(KUAsign);

    LOAD_GEN(kRet);
    LOAD_GEN(kBreak);
    LOAD_GEN(kCont);
    LOAD_GEN(kIfStmt);
    LOAD_GEN(kWhileStmt);
    LOAD_GEN(kDoWhileStmt);
    LOAD_GEN(kForStmt);

    LOAD_GEN(kGoto);
    LOAD_GEN(kLabeledStmt);
    LOAD_GEN(kSwitchStmt);


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
    if (!node || node->type_ == kNULL)
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
    printf("Dump object to %s\n", file_name.c_str());
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

const AstNode *CodeGenerator::GetSymbolTypeTree(const std::string &name) {
    for (auto rit = symbol_type_stack_.rbegin(); rit != symbol_type_stack_.rend(); ++rit) {
        if (rit->contains(name))
            return rit->at(name);
    }
    return nullptr;
}

Symbol const *CodeGenerator::GetLocalSymbol(const std::string &name) {
    if (symbol_table_stack_.empty())
        return nullptr;
    auto &top = symbol_table_stack_.back();
    return top.contains(name) ? &top.at(name) : nullptr;
}

llvm::BasicBlock *CodeGenerator::GetBlock(const std::string &name) {
    return block_table.contains(name) ? block_table.at(name) : nullptr;
}

void CodeGenerator::Generate() {
    std::printf("\033[32m[codegen begins] \033[0m\n");
    global = llvm::Function::Create(llvm::FunctionType::get(IR_builder.getVoidTy(), false),
                                    llvm::GlobalValue::InternalLinkage, "global", module);
    global_entry = llvm::BasicBlock::Create(context, "global_entry", global);
    if (!ast_root_)
        return;
    assert(ast_root_->type_ == kRoot);
    try {
        CallGenerator(ast_root_);
    } catch (ParseException &e) {
        std::printf("\033[31merror\033[0m ");
        e.show();
        exit(1);
    }

    global_entry->eraseFromParent();
    global->eraseFromParent();
    std::printf("\033[32m[codegen succeed] \033[0m\n");

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

DEF_GEN(kId) {
    auto p_symbol = GetSymbol(node->val_);
    if (!p_symbol)
        throw_code_gen_exception(node, "unidentified id");
    cur_node = GetSymbolTypeTree(node->val_);
    return *p_symbol;
}

DEF_GEN(kFuncDef) {
    ASSERT_TYPE(node, kFuncDef);

    auto func_decl_node = getNChildSafe(node, 0);
    auto func_body_node = getNChildSafe(node, 1);
    ASSERT_TYPE(func_decl_node, kFuncDecl);
    ASSERT_TYPE(func_body_node, kScope);

    auto f = CallGenerator(func_decl_node).GetFunction();
    printf("fn:\n");
    f->print(llvm::outs());

    defined_functions.insert(f->getName().str());
    {
        ScopeGuard scope_guard;
        auto func_block = llvm::BasicBlock::Create(context, f->getName() + "_entry", f);
        IR_builder.SetInsertPoint(func_block);
        FuncGuard func_guard(f);
        {
            auto params = func_decl_node->child_->child_->next_;
            ASSERT_TYPE(params, kFuncParams);
            auto cur = params->child_;

            int arg_idx = 0;
            en_warn = false;
            for (auto arg_it = f->arg_begin(); arg_it < f->arg_end(); arg_it++, arg_idx++, cur = cur->next_) {
                if (!cur)
                    throw_code_gen_exception(cur, "too few arguments");
                assert(cur->type_ == kVarDecl || cur->type_ == kFuncDecl);
                std::string var_name{cur->child_->next_->val_};
                const AstNode *var_type_tree = cur->child_;
                auto alloc_inst = AllocFunctionArg(f, arg_it->getType(), cur->child_->next_->val_);
                IR_builder.CreateStore(arg_it, alloc_inst);
                SetSymbol(var_name, alloc_inst);
                SetSymbolTypeTree(var_name, var_type_tree);
            }
            if (cur) {
                throw_code_gen_exception(cur, "too many arguments");
            }
            en_warn = true;

            CallGenerator(func_body_node);

            if (!IR_builder.GetInsertBlock()->getTerminator()) {
                // No returns yet!
                auto ret_type = f->getReturnType();
                if (ret_type->isVoidTy()) {
                    IR_builder.CreateRetVoid();
                } else {
                    IR_builder.CreateRet(llvm::UndefValue::get(ret_type));
                }
            }

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

    if (type->isFunctionTy() && cur_init_) {
        throw_code_gen_exception(var_type_node, "cannot initialize a function");
    }

    if (GetLocalSymbol(name))
        throw_code_gen_exception(var_id_node, "duplicate symbol");

    if (en_warn && !cur_init_ && TypeFactory::IsConst(type))
        show_code_gen_warning(node, "uninitialized const variable");
//        throw_code_gen_exception(var_id_node, "uninitialized const variable");

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
        Symbol s{glob_var};
        SetSymbol(name, s);
        SetSymbolTypeTree(cur_struct_name + name, var_type_node);
        return glob_var;
    } else {
        // this var is a local var
        auto block_builder = llvm::IRBuilder<>(&cur_func_->getEntryBlock(), cur_func_->getEntryBlock().begin());
        auto alloc = block_builder.CreateAlloca(type, nullptr, name);
        SetSymbol(name, alloc);
        SetSymbolTypeTree(name, var_type_node);
        return {alloc};
    }
//    return type;
}

DEF_GEN(kFuncDecl) {
    auto func_node = getNChildSafe(node, 0);
    auto name_node = getNChildSafe(node, 1);
    if (func_node->type_ != kFuncType) {
        return gen_kVarDecl(node);
    }
    ASSERT_TYPE(func_node, kFuncType);
    ASSERT_TYPE(name_node, kId);
    auto func_type = (llvm::FunctionType *) (CallGenerator(func_node).GetType());
    auto prev_symbol = GetSymbol(name_node->val_);
    if (!prev_symbol) {
        auto f = llvm::Function::Create(func_type, llvm::GlobalValue::ExternalLinkage, std::string{name_node->val_},
                                        module);
        SetFunction(name_node->val_, f);
        return f;
    } else if (prev_symbol->IsFunction()) {
        return *prev_symbol;
    } else throw_code_gen_exception(name_node, "duplicated symbol");

}

int GetListLen(const AstNode* node) {
    int l = 0;
    while(node) {
        ++l;
        node=node->next_;
    }
    return l;
}

DEF_GEN(kVarInit) {
    {
        VarInitGuard g;
        auto var_decl_node = getNChildSafe(node, 0);
        auto expr_node = getNChildSafe(node, 1);
        auto is_init_list = expr_node->type_ == kInitList;

        if(is_init_list){
            cur_init_ = false;
            cur_init_list_size = GetListLen(expr_node->child_);
            auto alloc_inst = CallGenerator(var_decl_node).GetVariable();
            InitVariableUsingInitList(alloc_inst, expr_node, node);
            cur_init_list_size = -1;
            cur_init_ = true;
            return {};
        }

        auto init_value_sym = is_init_list ? Symbol{} : GenExpression(expr_node);

        assert(expr_node);
        ASSERT_TYPE(var_decl_node, kVarDecl);
        CallGenerator(var_decl_node);// this would do semantic checks.

        if (!cur_func_)
            SwapBtwGlobal();

        auto is_const_init_val = is_const_expr(expr_node);
        if (!cur_func_)
            SwapBtwGlobal();

        auto type = CallGenerator(getNChildSafe(var_decl_node, 0)).GetType();
        auto name = std::string{getNChildSafe(var_decl_node, 1)->val_};
        auto type_tree = GetExactTypeTree(var_decl_node->child_);
        auto initializer = CastToType(type, init_value_sym.GetVariable());

        if (!initializer)
            throw_code_gen_exception(expr_node, "cannot convert expression to target type");

        if (cur_func_) {
            auto alloca = AllocFunctionArg(cur_func_, type, name);
            IR_builder.CreateStore(initializer, alloca);
            SetSymbol(name, alloca);
            SetSymbolTypeTree(name, type_tree);
        } else {
            auto is_const_type = type_tree->type_ == kTypeFeature;
            if (is_const_type && !is_const_init_val)
                throw_code_gen_exception(node, "cannot assign non-compile-time constant value to global constant");
            auto global_var = new llvm::GlobalVariable(
                    module,
                    type,
                    is_const_type,
                    llvm::Function::ExternalLinkage,
                    (llvm::Constant *) initializer,
                    name
            );
            Symbol s{global_var};
            SetSymbol(name, s);
            SetSymbolTypeTree(name, type_tree);
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
        if (param_start->type_ == kVarInit || param_start->type_ == kVarDecl || param_start->type_ == kFuncDecl) {
            collector.push_back(CallGenerator(param_start->child_).GetType());
        } else {
            collector.push_back(CallGenerator(param_start).GetType());
        }
        if (collector.back()->isVoidTy())
            void_idx = param_idx;
        if (collector.back()->isArrayTy() || collector.back()->isPointerTy()) {
            auto arr_type = collector.back();
            collector.back() = TypeFactory::GetNonArrayType(arr_type);
        }
        if (collector.back()->isFunctionTy()) {
            auto f_type = collector.back();
            collector.back() = f_type->getPointerTo();
        }
        ++param_idx;
        param_start = param_start->next_;
    }
    if (void_idx >= 0) {
        if (collector.size() > 1)
            throw_code_gen_exception(getNChildSafe(node, void_idx),
                                     "no void type allowed in function declaration/definition");
        else collector.clear();
    }
}

void CodeGenerator::CollectArgs(pAstNode node, std::vector<llvm::Value *> &collector) {
    if (!node)
        return;
    //TODO: add type checks and argument checks
    ASSERT_TYPE(node, kArgList);
    auto arg_list = node->child_;
    while (arg_list) {
        auto symbol = GenExpression(arg_list); // TODO: here has been fix
        collector.push_back(symbol.GetVariable());
        arg_list = arg_list->next_;
    }
}

void CodeGenerator::CollecCases(pAstNode node, std::vector<pAstNode> &collector, AstNode *&default_node) {
    if (!node)
        return;

    if (node->type_ == kScope) {
        CollecCases(node->child_, collector, default_node);
        return;
    }
    if (node->type_ == kCase) {
        collector.push_back(node->child_);
        CollecCases(node->child_->next_, collector, default_node);
        CollecCases(node->next_, collector, default_node);
    } else if (node->type_ == kLabeledStmt && strcmp("default", node->val_) == 0) {
        if (default_node)
            throw_code_gen_exception(node, "multiple default statements not allowed");
        default_node = node;
        collector.push_back(nullptr);
        CollecCases(node->child_->next_, collector, default_node);
        CollecCases(node->next_, collector, default_node);
    } else {
        CollecCases(node->child_, collector, default_node);
        CollecCases(node->next_, collector, default_node);
    }

}


void CodeGenerator::SwapBtwGlobal() {
    auto cur_block = IR_builder.GetInsertBlock();
    IR_builder.SetInsertPoint(global_entry);
    global_entry = cur_block;
}

llvm::Value *CodeGenerator::AllocFunctionArg(llvm::Function *f, llvm::Type *t, const std::string &name) {
    llvm::IRBuilder<> func_builder{&f->getEntryBlock(), f->getEntryBlock().begin()};
    return func_builder.CreateAlloca(t, nullptr, name);
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

DEF_GEN(kTypeAlias) {
    ASSERT_TYPE(node, kTypeAlias);
    assert(type_aliases_map.contains(node->val_));
    return Symbol{GetType(node->val_)};
}

DEF_GEN(kPtrType) {
    auto ptr_to_type = getNChildSafe(node, 0);
    assert(ptr_to_type);
    auto ptr_to_symbol = CallGenerator(ptr_to_type);
    return pValue{TypeFactory::Get<llvm::PointerType>(ptr_to_symbol.GetType(), 0U)};
}

DEF_GEN(kArrType) {
    static int rec_level = 0;
    ++ rec_level;
    auto ele_type = getNChildSafe(node, 0);
    auto len = getNChildSafe(node, 1);
    assert(ele_type);
    assert(len);
    auto type_symbol = CallGenerator(ele_type);
    if (len->type_ == kDemNumber && strcmp(len->val_, "*") == 0) {
        if(cur_init_list_size < 0)
            throw_code_gen_exception(node, "needs an initializer list");
        if(rec_level != 1)
            throw_code_gen_exception(node, "does not allow empty subscript here");
        --rec_level;
        return TypeFactory::Get<llvm::ArrayType>(type_symbol.GetType(), cur_init_list_size);
    } else {
        if(!is_const_expr(len))
            throw_code_gen_exception(len, "cannot dynamically alloc a array currently");
        auto len_constant = (llvm::ConstantInt*) GenExpression(len).GetVariable();
        uint64_t len_i = len_constant->getValue().getLimitedValue();
        --rec_level;
        return pValue{TypeFactory::Get<llvm::ArrayType>(type_symbol.GetType(), len_i)};
    }
}

DEF_GEN(kTypeFeature) {
    auto type_node = getNChildSafe(node, 0);
    assert(type_node && IS_TYPE(type_node->type_));
    auto type = CallGenerator(type_node);
    auto qualifiers = type_node->next_;
    while (qualifiers && strcmp(qualifiers->val_, "const") != 0) {
        qualifiers = qualifiers->next_;
    }
    if (qualifiers) {
        auto t = TypeFactory::GetConstTypeOf(type.GetType());
        return t;
    } else return type;
}

DEF_GEN(kTypeDef) {
    ASSERT_TYPE(node, kTypeDef);
    auto real_type_node = getNChildSafe(node, 0);
    cur_node = GetExactTypeTree(real_type_node);
    auto real_type = CallGenerator(real_type_node).GetType();
    auto alias_name = getNChildSafe(node, 1)->val_;
    AddTypeAlias(alias_name, real_type);
    AddTypeDefTreeInfo(alias_name, cur_node);
    return {};
}

// Const Literals
DEF_GEN(kDemNumber) {
    assert(node && IS_NUMBER(node->type_));
    auto i = strtoll(node->val_, nullptr, 0);
    auto s = Symbol{llvm::ConstantInt::get(GetType("int"), i), true};
//    assert(s.GetVariable()->getType() == GetType("int") );
    return s;

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
//    std::string content{node->val_ + 1, strlen(node->val_) - 2};
    std::string content{convert_to_raw(node->val_ + 1, strlen(node->val_) - 2)};
    return {IR_builder.CreateGlobalStringPtr(content), true};
}

DEF_GEN(kFloatNumber) {
    auto f = atof(node->val_);
    return {llvm::ConstantFP::get(GetType("double"), f), true};
}

DEF_GEN(kCharLiteral) {
    std::string content{convert_to_raw(node->val_ + 1, strlen(node->val_) - 2)};
    return {llvm::ConstantInt::get(GetType("char"), content[0]), true};
}

DEF_GEN(kExpr) {
    // TODO: modify this
    return CallGenerator(node->child_);
}

// Const end

void CodeGenerator::SetSymbol(const std::string &name, Symbol symbol) {
    assert(!symbol_table_stack_.empty() && !symbol_table_stack_.back().contains(name));
    symbol_table_stack_.back().insert({name, symbol});
}

void CodeGenerator::SetSymbolTypeTree(const std::string &name, const AstNode *node) {
    assert(!symbol_type_stack_.empty() && !symbol_type_stack_.back().contains(name));
    symbol_type_stack_.back().insert({name, GetExactTypeTree(node)});
}

void CodeGenerator::SetFunction(const std::string &name, llvm::Function *f) {
    assert(!symbol_table_stack_.empty() && !symbol_table_stack_.back().contains(name));
    Symbol s{f};
    assert(s.IsFunction());
    symbol_table_stack_.back().insert({name, s});
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

DEF_GEN(kFuncCall) {
    llvm::Function *f = nullptr;
    auto func_name_node = getNChildSafe(node, 0)->child_;
    auto args_node = getNChildSafe(node, 1);
    std::vector<llvm::Value *> args;
    CollectArgs(args_node, args);


    auto f_v = GenExpression(func_name_node, false);
    if (f_v.IsFunction()) {
        f = f_v.GetFunction();
    } else {
        //TODO: finish IR gen for variable function call
        auto func_var = f_v.GetVariable();
        printf("func-var's type is : ");
        func_var->getType()->print(llvm::outs(), true);
        printf("\n");
        if (!func_var->getType()->isPointerTy() || !func_var->getType()->getPointerElementType()->isFunctionTy())
            throw_code_gen_exception(node, "invalid callee type");

        return IR_builder.CreateCall((llvm::FunctionType *) (func_var->getType()->getPointerElementType()),
                                     func_var,
                                     args);

    }


    if (!f->isVarArg()) {
        std::size_t i = 0;
        for (auto arg_it = f->arg_begin(); arg_it != f->arg_end(); ++arg_it, ++i) {
            if (i >= args.size())
                throw_code_gen_exception(node, "too few arguments in function call");

            auto casted = CastToType(arg_it->getType(), args[i]);
            if (!casted)
                throw_code_gen_exception(node, "unqualified type");

            args[i] = casted;
        }
        if (i != args.size())
            throw_code_gen_exception(node, "too many arguments in function call");
    }
    return IR_builder.CreateCall(f, args);
}

DEF_GEN(kStructType) {
    std::vector<llvm::Type *> member_types;
    std::vector<std::string> member_names;
    auto id_node = getNChildSafe(node, 0);
    assert(id_node);

    std::string struct_name;

    if (id_node->type_ == kNULL) {
        struct_name.assign("struct-" + std::to_string(struct_type_table.size()));
    } else if (id_node->type_ == kId) {
        struct_name.assign("struct-" + std::string{id_node->val_});
    } else
        assert(false);

    auto supposed_type = GetSymbol(struct_name);
    if (supposed_type) {
        assert(supposed_type->IsType() && supposed_type->GetType()->isStructTy());
        return supposed_type->GetType();
    }

    auto decl_list_node = id_node->next_;
    if (!decl_list_node || decl_list_node->type_ == kNULL) {
        auto it = GetSymbol(id_node->val_);
        if (!it || !it->GetType()->isStructTy())
            throw_code_gen_exception(id_node, "invalid struct type id");
        else return *it;
    }

    auto struct_type = TypeFactory::Get(llvm::StructType::create(context, struct_name));
    SetType(struct_name, struct_type);

    for (auto cur = decl_list_node; cur; cur = cur->next_) {
        ASSERT_TYPE(cur, kVarDecl);
        auto type = CallGenerator(cur->child_).GetType();
        if (type->isVoidTy())
            throw_code_gen_exception(cur, "cannot declare a void type variable");
        member_types.push_back(type);
        member_names.emplace_back(cur->child_->next_->val_);
        auto mem_id_name = struct_name + std::string{cur->child_->next_->val_};
        SetSymbolTypeTree(mem_id_name, cur->child_);
    }


    struct_type->setBody(member_types);


    StructMemberMap member_map;
    for (std::size_t i = 0; i < member_names.size(); i++) {
        StructMemberType mem{i, member_types[i]};
        member_map.emplace(member_names[i], mem);
    }
    struct_type_table.insert(std::make_pair(struct_name, std::move(member_map)));

    return struct_type;
}

DEF_GEN(kCast) {
    auto type_node = getNChildSafe(node, 0);
    assert(IS_TYPE(type_node->type_));
    auto type = CallGenerator(type_node).GetType();
    auto expr_node = getNChildSafe(node, 1);
    assert(expr_node);
    auto expr_value = GenExpression(expr_node).GetVariable();
    return CastToType(type, expr_value);
}

DEF_GEN(kSubScript) {
    auto arr_node = getNChildSafe(node, 0);
    auto idx_node = getNChildSafe(node, 1);
    assert(arr_node);
    assert(idx_node);
    auto array = GenExpression(arr_node).GetVariable();
    auto left_cur_node = cur_node;
    auto idx = GenExpression(idx_node).GetVariable();
    if (!array->getType()->isPointerTy() || !idx->getType()->isIntegerTy()) {
        throw_code_gen_exception(node, "incompatible type for subscript");
    }
    cur_node = left_cur_node;
    CurNodeStepDown();

    return IR_builder.CreateGEP(array->getType()->getNonOpaquePointerElementType(), array, idx);
}

DEF_GEN(kAssign) {
    return GenExpression(node);
}

DEF_GEN(KUAsign) {
    return GenExpression(node);
}

DEF_GEN(kUnionType) {
    std::vector<llvm::Type *> member_types;
    std::vector<std::string> member_names;
    auto id_node = getNChildSafe(node, 0);
    assert(id_node);

    std::string union_name;

    if (id_node->type_ == kNULL) {
        union_name.assign("union-" + std::to_string(struct_type_table.size()));
    } else if (id_node->type_ == kId) {
        union_name.assign("union-" + std::string{id_node->val_});
    } else
        assert(false);

    auto supposed_type = GetSymbol(union_name);
    if (supposed_type) {
        assert(supposed_type->IsType() && supposed_type->GetType()->isStructTy());
        return supposed_type->GetType();
    }

    auto decl_list_node = id_node->next_;
    if (!decl_list_node || decl_list_node->type_ == kNULL) {
        auto it = GetSymbol(id_node->val_);
        if (!it || !it->GetType()->isStructTy())
            throw_code_gen_exception(id_node, "invalid struct type id");
        else return *it;
    }

    auto union_type = TypeFactory::Get(llvm::StructType::create(context, union_name));
    SetType(union_name, union_type);

    uint64_t max_type_size = 0;
    llvm::Type *max_type = nullptr;

    for (auto cur = decl_list_node; cur; cur = cur->next_) {
        ASSERT_TYPE(cur, kVarDecl);
        auto type = CallGenerator(cur->child_).GetType();
        if (type->isVoidTy())
            throw_code_gen_exception(cur, "cannot declare a void type variable");
        member_types.push_back(type);
        member_names.emplace_back(cur->child_->next_->val_);
        auto mem_id_name = union_name + std::string{cur->child_->next_->val_};
        SetSymbolTypeTree(mem_id_name, cur->child_);
        auto size = data_layout.getTypeAllocSize(type);
        if (size > max_type_size) {
            max_type_size = size;
            max_type = type;
        }
    }


    union_type->setBody(std::vector<llvm::Type*>{max_type});

    StructMemberMap member_map;
    for (std::size_t i = 0; i < member_names.size(); i++) {
        StructMemberType mem{i, member_types[i]};
        member_map.emplace(member_names[i], mem);
    }
    union_type_table.insert(std::make_pair(union_name, std::move(member_map)));

    return union_type;
}

DEF_GEN(kEnumType) {
    auto enum_list = node->child_->next_;
    uint32_t enum_value = 0;
    if (enum_list && enum_list->type_ != kNULL) {
        while (enum_list) {
            CallGenerator(enum_list);
            enum_list = enum_list->next_;
        }
    }
    return IR_builder.getInt32Ty();
}

DEF_GEN(kRet) {
    if (!cur_func_)
        throw_code_gen_exception(node, "return statement out of function");
    if (!node->child_) {
        if (!cur_func_->getReturnType()->isVoidTy())
            throw_code_gen_exception(node, "return type unmatched");
        else {
            IR_builder.CreateRetVoid();
            return {};
        }
    }

    auto ret_value = GenExpression(node->child_).GetVariable();
    ret_value = CastToType(cur_func_->getReturnType(), ret_value);
    if (!ret_value)
        throw_code_gen_exception(node, "return type unmatched");
    return IR_builder.CreateRet(ret_value);
}

DEF_GEN(kBreak) {
    if (!cur_func_ || CodeGenerator::loop_stack.empty())
        throw_code_gen_exception(node, "break statement out of function");
    auto loop_end = loop_stack.back().second;
    return IR_builder.CreateBr(loop_end);
}

DEF_GEN(kCont) {
    if (!cur_func_ || CodeGenerator::loop_stack.empty())
        throw_code_gen_exception(node, "break statement out of function");
    auto loop_begin = loop_stack.back().first;
    return IR_builder.CreateBr(loop_begin);
}

void CodeGenerator::GotoBlock(llvm::BasicBlock *block) {
    if (!IR_builder.GetInsertBlock()->getTerminator())
        IR_builder.CreateBr(block);
}

inline void CodeGenerator::SetCurBlockTo(llvm::BasicBlock *block) {
    cur_func_->getBasicBlockList().push_back(block);
    IR_builder.SetInsertPoint(block);
}

pAstNode GetCaseStmtByCase(AstNode *node) {
    if (node->type_ == kCase)
        return nullptr;
    else return node;
}

inline pAstNode GetCaseStmt(const AstNode *case_value_node) {

    if (auto stmt_node = case_value_node->next_) {
        if (stmt_node->type_ == kCase)
            return nullptr;
        else if (stmt_node->type_ == kLabeledStmt && strcmp(stmt_node->val_, "default") == 0)
            return GetCaseStmtByCase(stmt_node->child_);
        else return stmt_node;
    } else return nullptr;
}


DEF_GEN(kIfStmt) {
    if (!cur_func_)
        throw_code_gen_exception(node, "cannot declare if statement outside a function");
    auto cond_node = getNChildSafe(node, 0);
    auto true_node = getNChildSafe(node, 1);
    auto false_node = getNChildSafe(node, 2);
    llvm::Value *cond = CastToBool(GenExpression(cond_node).GetVariable());
    if (!cond)
        throw_code_gen_exception(cond_node, "expression cannot become a if-condition");

    auto t_block = llvm::BasicBlock::Create(context, "if-true:");
    auto f_block = llvm::BasicBlock::Create(context, "if-false");
    auto q_block = llvm::BasicBlock::Create(context, "if-quit");

    IR_builder.CreateCondBr(cond, t_block, f_block);


    SetCurBlockTo(t_block);
    CallGenerator(true_node);
    GotoBlock(q_block);


    SetCurBlockTo(f_block);
    CallGenerator(false_node);
    GotoBlock(q_block);

    if (q_block->hasNPredecessorsOrMore(1)) {
        SetCurBlockTo(q_block);
    }

    return {};
}

inline bool IsDefault(pAstNode node) {
    return node->type_ == kLabeledStmt && strcmp(node->val_, "default") == 0;
}

DEF_GEN(kSwitchStmt) {
    auto match_node = getNChildSafe(node, 0);
    auto cases_node = getNChildSafe(node, 1);

    auto matcher = GenExpression(match_node).GetVariable();
    if (!matcher->getType()->isIntegerTy())
        throw_code_gen_exception(match_node, "switch statement only accepts integer types");

    std::vector<AstNode *> case_values;
    std::vector<AstNode *> case_stmts;
    AstNode *default_node = nullptr;
    AstNode *default_stmt = nullptr;
    llvm::BasicBlock *default_block = nullptr;
    CollecCases(cases_node, case_values, default_node);
    int default_idx = -1;
    for (int i = 0; i < case_values.size(); i++) {
        if (case_values[i])
            case_stmts.push_back(GetCaseStmt(case_values[i]));
        else {
            default_idx = i;
            default_stmt = GetCaseStmtByCase(default_node);
            case_stmts.push_back(default_stmt);
        }
    }

    if (default_idx >= 0) {
        assert(default_stmt && default_node);
        case_values.erase(case_values.begin() + default_idx);
        case_stmts.erase(case_stmts.begin() + default_idx);
    }


    // block vectors for 1) case IR gen, and 2) cmp IR gen
    std::vector<llvm::BasicBlock *> case_blocks;
    std::vector<llvm::BasicBlock *> cmp_blocks;

    for (int i = 0; i < case_values.size(); i++)
        case_blocks.push_back(llvm::BasicBlock::Create(context, "case-" + std::to_string(i)));
    case_blocks.push_back(llvm::BasicBlock::Create(context, "switch-end"));

    cmp_blocks.push_back(IR_builder.GetInsertBlock());
    for (int i = 1; i < case_values.size(); i++)
        cmp_blocks.push_back(llvm::BasicBlock::Create(context, "cmp-" + std::to_string(i)));
    if (default_node) {
        default_block = llvm::BasicBlock::Create(context, "default");
        cmp_blocks.push_back(default_block);
    }
    cmp_blocks.push_back(case_blocks.back());

    for (int i = 0; i < case_values.size(); i++) {
        if (i > 0) {
            SetCurBlockTo(cmp_blocks[i]);
        }
        if (case_values[i]) {
            auto to_match = GenExpression(case_values[i]).GetVariable();
            to_match = CastToType(matcher->getType(), to_match);
            if (!to_match->getType()->isIntegerTy())
                throw_code_gen_exception(case_values[i], "switch statement only accepts integer types");
            auto cond = IR_builder.CreateICmpEQ(matcher, to_match);
            IR_builder.CreateCondBr(cond, case_blocks[i], cmp_blocks[i + 1]);
        } else                                    //Default
            IR_builder.CreateBr(case_blocks[i]);
    }

    {
        ScopeGuard g;
        for (int i = 0; i < case_values.size(); i++) {
            SetCurBlockTo(case_blocks[i]);
            LoopGuard lg{case_blocks[i + 1], case_blocks.back()};
            {
//                CallGenerator(case_stmts[i]);
                auto head = case_stmts[i];
                while (head && head->type_ != kCase && !IsDefault(head)) {
                    CallGenerator(head);
                    head = head->next_;
                }
                GotoBlock(case_blocks[i + 1]);
            }
        }
        if (default_node) {
            SetCurBlockTo(default_block);
            LoopGuard lg{case_blocks.back(), case_blocks.back()};
            {
                auto head = default_stmt;
                while (head && head->type_ != kCase) {
                    CallGenerator(head);
                    head = head->next_;
                }

                GotoBlock(case_blocks[default_idx]); // in case the default sentence is in the middle
            }
        }
    }
    //Finish "SwitchEnd" block
    if (case_blocks.back()->hasNPredecessorsOrMore(1)) {
        SetCurBlockTo(case_blocks.back());
    }


    return {};
}

DEF_GEN(kWhileStmt) {
    if (!cur_func_)
        throw_code_gen_exception(node, "cannot declare while statement outside a function");
    auto cond_node = getNChildSafe(node, 0);
    auto body_node = getNChildSafe(node, 1);

    auto loop_begin = llvm::BasicBlock::Create(context, "whl_begin");
    auto loop_body = llvm::BasicBlock::Create(context, "whl_body");
    auto loop_end = llvm::BasicBlock::Create(context, "whl_end");

    IR_builder.CreateBr(loop_begin);
//    cur_func_->getBasicBlockList().push_back(c_block);
//    IR_builder.SetInsertPoint(c_block);
    SetCurBlockTo(loop_begin);
    auto cond = CastToBool(GenExpression(cond_node).GetVariable());
    if (!cond)
        throw_code_gen_exception(node, "expression cannot become a while-condition");

    IR_builder.CreateCondBr(cond, loop_body, loop_end);

    SetCurBlockTo(loop_body);
    {
        LoopGuard g(loop_begin, loop_end);
        CallGenerator(body_node);
    }

    GotoBlock(loop_begin);
    SetCurBlockTo(loop_end);
    return {};
}

DEF_GEN(kDoWhileStmt) {
    if (!cur_func_)
        throw_code_gen_exception(node, "cannot declare for statement outside a function");
    auto loop_body_node = getNChildSafe(node, 0);
    auto loop_cond_node = getNChildSafe(node, 1);

    llvm::BasicBlock *loop_body = llvm::BasicBlock::Create(context, "dw_body");
    llvm::BasicBlock *loop_cond = llvm::BasicBlock::Create(context, "dw_cond");
    llvm::BasicBlock *loop_end = llvm::BasicBlock::Create(context, "dw_end");

    IR_builder.CreateBr(loop_body);
    SetCurBlockTo(loop_body);
    {
        LoopGuard f(loop_cond, loop_end);
        CallGenerator(loop_body_node);
    }
    GotoBlock(loop_cond);

    SetCurBlockTo(loop_cond);
    auto cond = CastToBool(GenExpression(loop_cond_node).GetVariable());

    if (!cond) {
        throw_code_gen_exception(node, "expression cannot become a do-while-condition");
    }

    IR_builder.CreateCondBr(cond, loop_body, loop_end);
    SetCurBlockTo(loop_end);
    return {};
}

DEF_GEN(kForStmt) {
    auto for_init_node = getNChildSafe(node, 0);
    auto for_cond_node = getNChildSafe(node, 1);
    auto for_update_node = getNChildSafe(node, 2);
    auto for_body_node = getNChildSafe(node, 3);

    if (for_init_node->type_ != kNULL)
        GenExpression(for_init_node);

    auto loop_begin = llvm::BasicBlock::Create(context, "for_begin");
    auto loop_body = llvm::BasicBlock::Create(context, "for_body");
    auto loop_update = llvm::BasicBlock::Create(context, "for_update");
    auto loop_end = llvm::BasicBlock::Create(context, "for_end");

    GotoBlock(loop_begin);
    SetCurBlockTo(loop_begin);

    llvm::Value *cond = IR_builder.getInt1(true);
    if (for_cond_node->type_ != kNULL)
        cond = CastToBool(GenExpression(for_cond_node).GetVariable());
    if (!cond)
        throw_code_gen_exception(node, "expression cannot become a for-condition");

    IR_builder.CreateCondBr(cond, loop_body, loop_end);

    SetCurBlockTo(loop_body);
    {
        LoopGuard g{loop_update, loop_end};
        CallGenerator(for_body_node);
    }

    GotoBlock(loop_update);
    SetCurBlockTo(loop_update);
    if (for_update_node->type_ != kNULL)
        GenExpression(for_update_node);
    IR_builder.CreateBr(loop_begin);

    SetCurBlockTo(loop_end);
    return {};
}

DEF_GEN(kGoto) {
    if (!cur_func_)
        throw_code_gen_exception(node, "cannot declare for statement outside a function");
    auto label_name = std::string{node->child_->val_};
    auto label_block = GetBlock(label_name);
    if (!label_block) {
        label_block = llvm::BasicBlock::Create(context, label_name);
        block_table[label_name] = label_block;
    }

    GotoBlock(label_block);
    return {};
}

DEF_GEN(kLabeledStmt) {
    auto label_name = std::string{node->val_};
    auto label_block = GetBlock(label_name);
    if (!label_block) {
        label_block = llvm::BasicBlock::Create(context, label_name);
        block_table[label_name] = label_block;
    }
    GotoBlock(label_block);
    SetCurBlockTo(label_block);
    CallGenerator(node->child_);
    return {};
}

void CodeGenerator::AddTypeDefTreeInfo(const char *name, const AstNode *pNode) {
    assert(!type_aliases_map.contains(name));
    type_aliases_map[name] = pNode;
}

const AstNode *CodeGenerator::GetExactTypeTree(const AstNode *type_node) {
    if (type_node->type_ == kTypeAlias) {
        assert(type_aliases_map.contains(type_node->val_));
        return type_aliases_map[type_node->val_];
    } else return type_node;

}


std::string convert_to_raw(const char *s, std::size_t len) {
    std::string result{};
    for (int i = 0; i < len; i++) {
        if (s[i] == '\\' && i + 1 < len) {
            switch (s[i + 1]) {
                case 'n':
                    result += '\n';
                    break;
                case 't':
                    result += '\t';
                    break;
                case '\\':
                    result += '\\';
                    break;
                case 'r':
                    result += '\r';
                    break;
                case 'v':
                    result += '\v';
                    break;
                case 'f':
                    result += '\f';
                    break;
                case 'a':
                    result += '\a';
                    break;
                case 'b':
                    result += '\b';
                    break;
                case '?':
                    result += '\?';
                    break;
                case '\'':
                    result += '\'';
                    break;
                case '\"':
                    result += '\"';
                    break;
                default:
                    result += s[i];
                    result += s[i + 1];
            }
            i++;
        } else {
            result += s[i];
        }
    }
    return result;
}




