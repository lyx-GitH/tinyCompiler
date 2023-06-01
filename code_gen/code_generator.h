//
// Created by 刘宇轩 on 2023/5/15.
//

#ifndef TINYCOMPILER_CODE_GENERATOR_H
#define TINYCOMPILER_CODE_GENERATOR_H

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <exception>
#include <cassert>
#include <functional>
#include <vector>
#include <llvm/IR/Value.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/IR/ValueSymbolTable.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Verifier.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/Interpreter.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/SectionMemoryManager.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/ManagedStatic.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/DynamicLibrary.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Passes/PassBuilder.h>
#include <llvm/Passes/PassPlugin.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Scalar/GVN.h>
#include <llvm/MC/TargetRegistry.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>
#include "llvm/IR/LegacyPassManager.h"

#include "symbol.h"
#include "../types/type_factory.h"
#include "../types/type_checks.h"
#include "../parser/tc_parser.h"
#include "../exceptions/parser_error.h"
#include "../exceptions/parse_exception.h"

extern "C" {
#include "../ast/ast.h"
#include "../parser/parser.h"
}


#define MAX_GEN_NUM 256
#define GEN_NAME(t) gen_##t
#define DECL_GEN(t) static pValue GEN_NAME(t) (const AstNode* node)
#define DEF_GEN(t) CodeGenerator::pValue CodeGenerator:: GEN_NAME(t) (const AstNode* node)
#define LOAD_GEN(t) LOAD_F(t, CodeGenerator:: GEN_NAME(t))
#define LOAD_F(idx, f) CodeGenerator::generators.at(idx) = (f)
#define CALL_GEN(n) CodeGenerator::generators.at((n)->type_)((n))
#define ASSERT_TYPE(n, t) assert((n) && (n)->type_ == (t))
#define TYPE_GETTER(type, name) static inline llvm::Type * Get##type(){return GetType(name);}

#define EXPR_L_NAME(name) LGen##name
#define EXPR_R_NAME(name) RGen##name
#define DECL_EXPR_L(name) static Symbol EXPR_L_NAME(name) (const AstNode* node)
#define DECL_EXPR_R(name) static Symbol EXPR_R_NAME(name) (const AstNode* node)
#define INVALID throw_code_gen_exception(node, "expression must be a right value"); return {}
#define DEFAULT_R(name) CastToRightValue(EXPR_L_NAME(name)(node).GetVariable())
#define PACK_METHOD(m) [](llvm::Value* a, llvm::Value* b) { \
    return (m)(a, b);                                       \
}

#define LOAD_BINARY_OP(op_str, name) do { \
    printf("generating at %d %s\n", GetOpHash(op_str), #name);                                      \
    CodeGenerator::binary_gen_left.at(GetOpHash(op_str)) = CodeGenerator:: EXPR_L_NAME(name);                                          \
    CodeGenerator::binary_gen_right.at(GetOpHash(op_str)) = CodeGenerator:: EXPR_R_NAME(name);                                         \
 } while(0)

#define LOAD_UNARY_OP(op_str, name) do { \
    CodeGenerator::unary_gen_left.at(GetOpHash(op_str)) = CodeGenerator:: EXPR_L_NAME(name);                                        \
    CodeGenerator::unary_gen_right.at(GetOpHash(op_str)) = CodeGenerator:: EXPR_R_NAME(name);                                       \
 }while(0)

#define LOAD_ASSIGN_OP(op_str, name) do { \
    CodeGenerator::assign_gen_left.at(GetOpHash(op_str)) = CodeGenerator:: EXPR_L_NAME(name);                                        \
    CodeGenerator::assign_gen_right.at(GetOpHash(op_str)) = CodeGenerator:: EXPR_R_NAME(name);                                       \
 }while(0)


class CodeGenerator : public TCParser {
public:
    using pValue = Symbol;
    using GenFunc = std::function<pValue(const AstNode *)>;
    using LoopScope = std::pair<llvm::BasicBlock *, llvm::BasicBlock *>;
    using SymbolTable = std::map<std::string, pValue>;
    using TypeTable = std::map<std::string, const AstNode *>;
    using StructMemberType = std::pair<std::size_t, llvm::Type *>;
    using StructMemberMap = std::map<std::string, StructMemberType>;
    using StructTypeTable = std::map<std::string, StructMemberMap>;
    using UnionTypeTable = std::map<std::string, StructMemberMap>;


    static void InitGenerators();

    static void InitBasicTypes();

    static void InitBinaryOperators();

    static void InitUnaryOperators();

    static void InitAssignOperators();

    static std::array<GenFunc, MAX_GEN_NUM> generators;

    static std::array<GenFunc, MAX_GEN_NUM> binary_gen_left;

    static std::array<GenFunc, MAX_GEN_NUM> binary_gen_right;

    static std::array<GenFunc, MAX_GEN_NUM> unary_gen_left;

    static std::array<GenFunc, MAX_GEN_NUM> unary_gen_right;

    static std::array<GenFunc, MAX_GEN_NUM> assign_gen_left;

    static std::array<GenFunc, MAX_GEN_NUM> assign_gen_right;

//    CodeGenerator() = default;

    explicit CodeGenerator(std::string file_path) : TCParser(std::move(file_path)) {
        InScope();
        InitGenerators();
        InitBasicTypes();
        InitUnaryOperators();
        InitAssignOperators();
        InitBinaryOperators();
    };


    ~CodeGenerator() {
        OffScope();
    }

    void SetAstRoot(pAstNode root) {
        ast_root_ = root;
    }

    void Generate();

    void Optimize(const std::string &opt_level);

    void GenObjectCode(const std::string &file_name);

    inline void CallClangGenExe(const std::string &object_file_path, const std::string &exe_path) {
        auto cmd = "clang " + object_file_path + " -o " + exe_path;
        system(cmd.c_str());
    }

    void DumpIR(std::string &&file_name);

    class ScopeGuard {
    public:
        ~ScopeGuard() { OffScope(); }

        ScopeGuard() { InScope(); }
    };

    class FuncGuard {
    public:
        ~FuncGuard() {
            OffFunc();
        }

        explicit FuncGuard(llvm::Function *f) {
            InFunc(f);
        }
    };

    class VarInitGuard {
    public:
        ~VarInitGuard() {
            cur_init_ = false;
        }

        VarInitGuard() {
            cur_init_ = true;
        }
    };

    class LoopGuard {
    public:
        ~LoopGuard() {
            OffLoop();
        }

        LoopGuard(llvm::BasicBlock *loop_begin, llvm::BasicBlock *loop_end) {
            InLoop(loop_begin, loop_end);
        }
    };

    inline void PrintIR() {
        module.print(llvm::outs(), nullptr);
        if (llvm::verifyModule(module, &llvm::outs()) == 0)
            llvm::outs() << "No errors.\n";
    }


private:
    static llvm::Module module;
    static llvm::DataLayout data_layout;
    static llvm::LLVMContext context;
    static llvm::IRBuilder<> IR_builder;
    static llvm::BasicBlock *global_entry;
    static llvm::Function *global;
    static llvm::Function *cur_func_;
    static bool cur_init_;
    static bool en_warn;
    static std::vector<SymbolTable> symbol_table_stack_;
    static std::vector<TypeTable> symbol_type_stack_;
    static std::vector<LoopScope> loop_stack;
    static std::map<std::string, const AstNode *> type_aliases_map;
    static std::set<std::string> defined_functions;
    static StructTypeTable struct_type_table;
    static UnionTypeTable union_type_table;

    static void InScope() {
        symbol_table_stack_.emplace_back();
        symbol_type_stack_.emplace_back();
    }

    static void OffScope() {
        assert(!symbol_table_stack_.empty());
        symbol_table_stack_.pop_back();
        symbol_type_stack_.pop_back();
    }

    static void InFunc(llvm::Function *f) {
        assert(!cur_func_);
        cur_func_ = f;
    }

    static void OffFunc() {
        cur_func_ = nullptr;
    }

    static void InLoop(llvm::BasicBlock *loop_begin, llvm::BasicBlock *loop_end) {
        loop_stack.emplace_back(loop_begin, loop_end);
    }

    static void OffLoop() {
        assert(!loop_stack.empty());
        loop_stack.pop_back();
    }


    static void SetType(const std::string &name, llvm::Type *type);

    static void AddTypeAlias(const std::string &name, llvm::Type *type);

    static llvm::Type *GetType(const std::string &name);

    TYPE_GETTER(Bool, "_bool");

    TYPE_GETTER(Char, "char");

    TYPE_GETTER(Short, "short");

    TYPE_GETTER(Int, "int");

    TYPE_GETTER(Float, "float");

    TYPE_GETTER(Double, "double");

    TYPE_GETTER(Long, "long");

    TYPE_GETTER(Void, "void");


    static void SetSymbol(const std::string &name, Symbol symbol);

    static void SetSymbolTypeTree(const std::string &name, const AstNode *node);

    static void SetFunction(const std::string &name, llvm::Function *f);

    static void AddTypeDefTreeInfo(const char *name, const AstNode *pNode);

    static const AstNode *GetExactTypeTree(const AstNode *type);

    static Symbol const *GetSymbol(const std::string &name);

    static const AstNode *GetSymbolTypeTree(const std::string &name);

    static Symbol const *GetLocalSymbol(const std::string &name);

    static void CollectArgTypes(pAstNode node, std::vector<llvm::Type *> &collector);

    static void CollectArgs(pAstNode node, std::vector<llvm::Value *> &collector);

    static void SwapBtwGlobal();

    static llvm::Value *AllocFunctionArg(llvm::Function *f, llvm::Type *t, const std::string &name);

    static llvm::Value *CastToType(llvm::Type *type, llvm::Value *value);

    static llvm::Value *CastToBool(llvm::Value *value);

    static llvm::Type *GetPriorType(llvm::Type *t1, llvm::Type *t2);

    static void AlignType(llvm::Value *&v1, llvm::Value *&v2);

    static llvm::Value *AlignType(llvm::Value *v, llvm::Type *t);

    static llvm::Value *CastToRightValue(llvm::Value *left_value);

    static Symbol GenExpression(const AstNode *node, bool r_value = true);

    static Symbol AssignValue(llvm::Value *lhs, llvm::Value *rhs, const AstNode *node);

    // <var>++, <var>--, ++<var>, --<var>
    static Symbol SelfPSValue(const AstNode *v, bool is_prefix, bool is_add);

    // x <op>= x eq. to  x = x <op> y
    static Symbol DefaultAssignGen(const AstNode *node, const GenFunc &bin_op);

    static void SetCurBlockTo(llvm::BasicBlock *block);

    static const AstNode *cur_node;

    static inline void CurNodeStepDown() {
        assert(cur_node && cur_node->child_);

        if (cur_node->type_ == kTypeFeature) {
            cur_node = cur_node->child_->child_;
        } else cur_node = cur_node->child_;
    }


    template<typename F>
    static llvm::Value *GenBinaryOpIntInt(const AstNode *node, F &&f, bool logical = false) {
        auto lhs = GenExpression(getNChildSafe(node, 0)).GetVariable();
        auto rhs = GenExpression(getNChildSafe(node, 1)).GetVariable();
        if (logical) {
            lhs = CastToBool(lhs);
            rhs = CastToBool(rhs);
        }
        if (!lhs || !rhs)
            throw_code_gen_exception(node, "operator between given types are not supported");
        if (!lhs->getType()->isIntegerTy() || !rhs->getType()->isIntegerTy())
            return nullptr;
        AlignType(lhs, rhs);
        return f(lhs, rhs);
    }

    template<typename FInt, typename FFloat>
    static llvm::Value *RunOpNumNum(FInt &&i_f, FFloat &&f_f, llvm::Value *lhs, llvm::Value *rhs) {
        AlignType(lhs, rhs);
        if (lhs->getType()->isFloatingPointTy()) {
            return f_f(lhs, rhs);
        } else {
            assert(lhs->getType()->isIntegerTy());
            return i_f(lhs, rhs);
        }
    }

    template<typename FInt, typename FFloat, typename FPtr>
    static llvm::Value *GenBinaryOpAnyAny(const AstNode *node, FInt &&i_f, FFloat &&f_f, FPtr &&p_f) {
        auto lhs = GenExpression(node->child_).GetVariable();
        auto rhs = GenExpression(node->child_->next_).GetVariable();
        if (TypeFactory::IsSameTypePtr(lhs, rhs)) {
            return p_f(
                    IR_builder.CreatePtrToInt(lhs, IR_builder.getInt64Ty()),
                    IR_builder.CreatePtrToInt(rhs, IR_builder.getInt64Ty())
            );
        }

        if (TypeFactory::IsPtrOperation(lhs, rhs)) {
            return p_f(
                    IR_builder.CreatePtrToInt(lhs, IR_builder.getInt64Ty()),
                    AlignType(rhs, IR_builder.getInt64Ty())
            );
        }

        try {
            return RunOpNumNum(std::forward<FInt &&>(i_f), std::forward<FFloat &&>(f_f), lhs, rhs);
        } catch (std::exception &e) {
            throw_code_gen_exception(node, e.what());
        }

        return nullptr;
    }

    // add and sub involves pointers and constant checks, so it needs to be considered.
    static llvm::Value *RunAdd(llvm::Value *lhs, llvm::Value *rhs);

    static llvm::Value *RunSub(llvm::Value *lhs, llvm::Value *rhs);

    DECL_GEN(kRoot);

    DECL_GEN(kId); // left value

    DECL_GEN(kFuncDef);

    DECL_GEN(kVarDecl);

    DECL_GEN(kVarInit);

    DECL_GEN(kFuncType);

    DECL_GEN(kPtrType);

    DECL_GEN(kArrType);

    DECL_GEN(kType);

    DECL_GEN(kTypeAlias);

    DECL_GEN(kTypeFeature);

    DECL_GEN(kTypeDef);

    DECL_GEN(kCharLiteral);

    DECL_GEN(kStrLiteral);

    DECL_GEN(kDemNumber);

    DECL_GEN(kHexNumber);

    DECL_GEN(kOctNumber);

    DECL_GEN(kFloatNumber);

    DECL_GEN(kExpr); // right value

    DECL_GEN(kScope);

    DECL_GEN(kFuncCall);

    DECL_GEN(kFuncDecl);

    DECL_GEN(kEnumType);

    DECL_GEN(kStructType);

    DECL_GEN(kUnionType);

    DECL_GEN(kCast); // right value

    DECL_GEN(kSubScript);// left value

    DECL_GEN(kAssign);

    DECL_GEN(KUAsign);

    DECL_GEN(kGoto);

    DECL_GEN(kRet);

    DECL_GEN(kCont);

    DECL_GEN(kBreak);

    DECL_GEN(kIfStmt);

    DECL_GEN(kWhileStmt);

    DECL_GEN(kDoWhileStmt);

    DECL_GEN(kForStmt);



    // Operators and Expression Generators

    DECL_EXPR_R(Comma) {
        GenExpression(node->child_);
        return GenExpression(node->child_->next_);
    }

    DECL_EXPR_L(Comma) {
        GenExpression(node->child_);
        return GenExpression(node->child_->next_, false);
    }

    DECL_EXPR_R(Plus) {
        auto lhs = GenExpression(node->child_);
        auto lhs_node = cur_node;
        auto rhs = GenExpression(node->child_->next_);
        if (lhs.GetVariable()->getType()->isPointerTy() || lhs.GetVariable()->getType()->isArrayTy())
            cur_node = lhs_node;
        try {
            return RunAdd(lhs.GetVariable(), rhs.GetVariable());
        } catch (std::exception &e) {
            throw_code_gen_exception(node, e.what());
        }
    }

    DECL_EXPR_L(Plus) {
        INVALID;
    }

    DECL_EXPR_R(Sub) {
        auto lhs = GenExpression(node->child_);
        auto lhs_node = cur_node;
        auto rhs = GenExpression(node->child_->next_);
        if (lhs.GetVariable()->getType()->isPointerTy() || lhs.GetVariable()->getType()->isArrayTy())
            cur_node = lhs_node;
        try {
            return RunSub(lhs.GetVariable(), rhs.GetVariable());
        } catch (std::exception &e) {
            throw_code_gen_exception(node, e.what());
        }
    }

    DECL_EXPR_L(Sub) {
        INVALID;
    }

    DECL_EXPR_R(Mult) {
        auto mul_int_f = PACK_METHOD(IR_builder.CreateMul);
        auto mul_float_f = PACK_METHOD(IR_builder.CreateFMul);
        auto lhs = GenExpression(node->child_);
        auto rhs = GenExpression(node->child_->next_);
        try {
            return RunOpNumNum(mul_int_f, mul_float_f, lhs.GetVariable(), rhs.GetVariable());
        } catch (std::exception &e) {
            throw_code_gen_exception(node, e.what());
            return {};
        }
    }

    DECL_EXPR_L(Mult) {
        INVALID;
    }

    DECL_EXPR_R(Div) {
        auto mul_int_f = PACK_METHOD(IR_builder.CreateSDiv);
        auto mul_float_f = PACK_METHOD(IR_builder.CreateFDiv);
        auto lhs = GenExpression(node->child_);
        auto rhs = GenExpression(node->child_->next_);
        try {
            return RunOpNumNum(mul_int_f, mul_float_f, lhs.GetVariable(), rhs.GetVariable());
        } catch (std::exception &e) {
            throw_code_gen_exception(node, e.what());
            return {};
        }
    }

    DECL_EXPR_L(Div) {
        INVALID;
    }

    DECL_EXPR_R(Mod) {
        auto f = PACK_METHOD(CodeGenerator::IR_builder.CreateSRem);
        return GenBinaryOpIntInt(node, f);
    }

    DECL_EXPR_L(Mod) {
        INVALID;
    }

    DECL_EXPR_R(Shl) {
        auto f = PACK_METHOD(CodeGenerator::IR_builder.CreateShl);
        return GenBinaryOpIntInt(node, f);
    }

    DECL_EXPR_L(Shl) {
        INVALID;
    }

    DECL_EXPR_R(Shr) {
        return GenBinaryOpIntInt(node, PACK_METHOD(CodeGenerator::IR_builder.CreateAShr));
    }

    DECL_EXPR_L(Shr) {
        INVALID;
    }

    DECL_EXPR_R(BitAnd) {
        return GenBinaryOpIntInt(node, PACK_METHOD(CodeGenerator::IR_builder.CreateAnd));
    }

    DECL_EXPR_L(BitAnd) {
        INVALID;
    }

    DECL_EXPR_R(LogAnd) {
        return GenBinaryOpIntInt(node, PACK_METHOD(CodeGenerator::IR_builder.CreateLogicalAnd), true);
    }

    DECL_EXPR_L(LogAnd) {
        INVALID;
    }


    DECL_EXPR_R(BitOr) {
        return GenBinaryOpIntInt(node, PACK_METHOD(CodeGenerator::IR_builder.CreateOr));
    }

    DECL_EXPR_L(BitOr) {
        INVALID;
    }

    DECL_EXPR_R(LogOr) {
        return GenBinaryOpIntInt(node, PACK_METHOD(CodeGenerator::IR_builder.CreateLogicalOr), true);
    }

    DECL_EXPR_L(LogOr) {
        INVALID;
    }

    DECL_EXPR_R(BitXor) {
        return GenBinaryOpIntInt(node, PACK_METHOD(CodeGenerator::IR_builder.CreateXor));
    }

    DECL_EXPR_L(BitXor) {
        INVALID;
    }

    DECL_EXPR_R(GreaterThan) {
        auto i_f = PACK_METHOD(IR_builder.CreateICmpSGT);
        auto f_f = PACK_METHOD(IR_builder.CreateFCmpOGT);
        auto p_f = PACK_METHOD(IR_builder.CreateICmpUGT);
        return GenBinaryOpAnyAny(node, i_f, f_f, p_f);
    }

    DECL_EXPR_L(GreaterThan) {
        INVALID;
    }

    DECL_EXPR_R(LessThan) {
        auto i_f = PACK_METHOD(IR_builder.CreateICmpSLT);
        auto f_f = PACK_METHOD(IR_builder.CreateFCmpOLT);
        auto p_f = PACK_METHOD(IR_builder.CreateICmpULT);
        return GenBinaryOpAnyAny(node, i_f, f_f, p_f);
    }

    DECL_EXPR_L(LessThan) {
        INVALID;
    }

    DECL_EXPR_R(GreaterEq) {
        auto i_f = PACK_METHOD(IR_builder.CreateICmpSGE);
        auto f_f = PACK_METHOD(IR_builder.CreateFCmpOGE);
        auto p_f = PACK_METHOD(IR_builder.CreateICmpUGE);
        return GenBinaryOpAnyAny(node, i_f, f_f, p_f);
    }

    DECL_EXPR_L(GreaterEq) {
        INVALID;
    }

    DECL_EXPR_R(LessEq) {
        auto i_f = PACK_METHOD(IR_builder.CreateICmpSLE);
        auto f_f = PACK_METHOD(IR_builder.CreateFCmpOLE);
        auto p_f = PACK_METHOD(IR_builder.CreateICmpULE);
        return GenBinaryOpAnyAny(node, i_f, f_f, p_f);
    }

    DECL_EXPR_L(LessEq) {
        INVALID;
    }

    DECL_EXPR_R(Eq) {
        auto i_f = PACK_METHOD(IR_builder.CreateICmpEQ);
        auto f_f = PACK_METHOD(IR_builder.CreateFCmpOEQ);
        auto p_f = PACK_METHOD(IR_builder.CreateICmpEQ);
        return GenBinaryOpAnyAny(node, i_f, f_f, p_f);
    }

    DECL_EXPR_L(Eq) {
        INVALID;
    }

    DECL_EXPR_R(NEq) {
        auto i_f = PACK_METHOD(IR_builder.CreateICmpNE);
        auto f_f = PACK_METHOD(IR_builder.CreateFCmpONE);
        auto p_f = PACK_METHOD(IR_builder.CreateICmpNE);
        return GenBinaryOpAnyAny(node, i_f, f_f, p_f);
    }

    DECL_EXPR_L(NEq) {
        INVALID;
    }

    DECL_EXPR_R(Assign) {
        return DEFAULT_R(Assign);
    }

    DECL_EXPR_L(Assign) {
        auto left = GenExpression(getNChildSafe(node, 0), false);
        if (cur_node && cur_node->type_ == kTypeFeature)
            throw_code_gen_exception(node, "cannot assign value to const variables");
        auto right = GenExpression(getNChildSafe(node, 1), true);
        return AssignValue(left.GetVariable(), right.GetVariable(), node);
    }


    DECL_EXPR_R(DeRef) {
        return DEFAULT_R(DeRef);
    }

    DECL_EXPR_L(DeRef) {
        Symbol ptr = GenExpression(node->child_);
        if (!ptr.GetVariable()->getType()->isPointerTy()) {
            throw_code_gen_exception(node, "deref operator must be assigned to a pointer");
        }
        CurNodeStepDown();
        return ptr;
    }

    DECL_EXPR_R(AddrOf) {
        return GenExpression(node->child_, false).GetVariable();
    }

    DECL_EXPR_L(AddrOf) {
        INVALID;
    }

    DECL_EXPR_R(UPlus) {
        auto val = GenExpression(node->child_);
        if (!val.GetVariable()->getType()->isIntegerTy() || !val.GetVariable()->getType()->isFloatingPointTy()) {
            throw_code_gen_exception(node, "must be applied to a number");
        }
        return val;
    }

    DECL_EXPR_L(UPlus) {
        INVALID;
    }

    DECL_EXPR_R(UMinus) {
        auto val = GenExpression(node->child_).GetVariable();
        if (val->getType()->isIntegerTy())
            return IR_builder.CreateNeg(val);
        if (val->getType()->isFloatingPointTy())
            return IR_builder.CreateFNeg(val);
        throw_code_gen_exception(node, "must be applied to a number");
        return {};
    }

    DECL_EXPR_L(UMinus) {
        INVALID;
    }

    DECL_EXPR_R(ULogNot) {
        auto boolean_val = CastToBool(GenExpression(node->child_).GetVariable());
        auto boolean_0 = llvm::ConstantInt::get(boolean_val->getType(), 0);
        return IR_builder.CreateICmpEQ(boolean_val, boolean_0);
    }

    DECL_EXPR_L(ULogNot) {
        INVALID;
    }

    DECL_EXPR_R(UBitNot) {
        auto val = GenExpression(node->child_).GetVariable();
        val->print(llvm::outs(), true);
        if (!val->getType()->isIntegerTy())
            throw_code_gen_exception(node, "\'~\' must be applied to a integer");
        auto rev_val = IR_builder.CreateNot(val);
        val->print(llvm::outs(), true);
        return rev_val;
    }

    DECL_EXPR_L(UBitNot) {
        INVALID;
    }

    DECL_EXPR_R(FuncCall) {
        return gen_kFuncCall(node).GetVariable();
    }

    DECL_EXPR_L(FuncCall) {
        INVALID;
    }

    DECL_EXPR_R(SubScript) {
        return DEFAULT_R(SubScript);
    }

    DECL_EXPR_L(SubScript) {
        return gen_kSubScript(node);
    }

    DECL_EXPR_R(SizeOf) {
        llvm::Type *type = nullptr;
        if (IS_TYPE(node->child_->type_)) {
            type = CALL_GEN(node->child_).GetType();
        } else if (node->child_->type_ == kId) {
            type = GenExpression(node->child_).GetVariable()->getType();
        } else {
            type = GenExpression(node->child_).GetVariable()->getType();
        }
        auto size = data_layout.getTypeAllocSize(type);
        return llvm::ConstantInt::get(CodeGenerator::GetLong(), size);
    }

    DECL_EXPR_L(SizeOf) {
        INVALID;
    }

    DECL_EXPR_R(MemOf) {
        return DEFAULT_R(MemOf);
    }

    DECL_EXPR_L(MemOf);

    DECL_EXPR_R(TrinaryExpr);

    DECL_EXPR_L(TrinaryExpr);


    static std::string cur_struct_name;


};


#endif //TINYCOMPILER_CODE_GENERATOR_H
