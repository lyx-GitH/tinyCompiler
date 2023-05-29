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


#define MAX_GEN_NUM 1024
#define GEN_NAME(t) gen_##t
#define DECL_GEN(t) static pValue GEN_NAME(t) (const AstNode* node)
#define DEF_GEN(t) CodeGenerator::pValue CodeGenerator:: GEN_NAME(t) (const AstNode* node)
#define LOAD_GEN(t) LOAD_F(t, CodeGenerator:: GEN_NAME(t))
#define LOAD_F(idx, f) CodeGenerator::generators.at(idx) = (f)
#define CALL_GEN(n) CodeGenerator::generators.at((n)->type_)((n))
#define ASSERT_TYPE(n, t) assert((n) && (n)->type_ == (t))
#define TYPE_GETTER(type, name) static inline llvm::Type * Get##type(){return GetType(name);}


class CodeGenerator : public TCParser {
public:
    using pValue = Symbol;
    using GenFunc = std::function<pValue(const AstNode *)>;
    using SymbolTable = std::map<std::string, pValue>;
    using StructMemberType = std::pair<std::size_t, llvm::Type *>;
    using StructMemberMap = std::map<std::string, StructMemberType>;
    using StructTypeTable = std::map<std::string, StructMemberMap>;
    using UnionTypeTable = std::map<std::string, StructMemberMap>;


    static void InitGenerators();

    static void InitBasicTypes();

    static std::array<GenFunc, MAX_GEN_NUM> generators;

//    CodeGenerator() = default;

    explicit CodeGenerator(std::string file_path) : TCParser(std::move(file_path)) {
        InScope();
        InitGenerators();
        InitBasicTypes();
//        global_func = llvm::Function::Create(llvm::FunctionType::get(GetVoid(), false),
//                                             llvm::GlobalValue::InternalLinkage, "_", &module);
//        global_block = llvm::BasicBlock::Create(context, "__", global_func);
    };

    ~CodeGenerator() {
        OffScope();
//        delete data_layout_;
//        delete module_;
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

    inline void PrintIR() {
        module.print(llvm::outs(), nullptr);
        if (llvm::verifyModule(module, &llvm::outs()) == 0)
            llvm::outs() << "No errors.\n";
        else
            llvm::outs() << "error!\n"
                         << "NOTE: when enabling type factory, mismatched signatures are totally normal\n";
//        llvm::StructType* c_int = llvm::StructType::get(IR_builder.getInt32Ty());
//        c_int->elements()[0]
    }

    static llvm::Value* CreateLoad(llvm::Value* pLHS) {
        //For array types, return the pointer to its first element
        if (pLHS->getType()->getNonOpaquePointerElementType()->isArrayTy())
            return IR_builder.CreatePointerCast(pLHS, pLHS->getType()->getNonOpaquePointerElementType()->getArrayElementType()->getPointerTo());
        else
            return IR_builder.CreateLoad(pLHS->getType()->getNonOpaquePointerElementType(), pLHS);
    }

private:
    llvm::DataLayout *data_layout_ = nullptr;


    std::vector<llvm::BasicBlock *> ContinueBlockStack;    //Store blocks for "continue" statement
    std::vector<llvm::BasicBlock *> BreakBlockStack;        //Store blocks for "break" statement
//    static llvm::BasicBlock *global_block;                            //Temp block for global instruction code generation
//    static llvm::Function *global_func;                            //Temp function for global instruction code generation

    static llvm::Module module;
    static llvm::DataLayout data_layout;
    static llvm::LLVMContext context;
    static llvm::IRBuilder<> IR_builder;
    static llvm::Function *cur_func_;
    static bool cur_init_;
    static bool en_warn;
    static std::vector<SymbolTable> symbol_table_stack_;
    static std::set<std::string> defined_functions;
    static StructTypeTable struct_type_table;
    static UnionTypeTable union_type_table;

    static void InScope() {
        symbol_table_stack_.emplace_back();
    }

    static void OffScope() {
        assert(!symbol_table_stack_.empty());
        symbol_table_stack_.pop_back();
    }

    static void InFunc(llvm::Function *f) {
        assert(!cur_func_);
        cur_func_ = f;
    }

    static void OffFunc() {
        cur_func_ = nullptr;
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

    TYPE_GETTER(Void, "void");


    static void SetSymbol(const std::string &name, Symbol symbol);

    static Symbol const *GetSymbol(const std::string &name);

    static Symbol const *GetLocalSymbol(const std::string &name);

    static void CollectArgTypes(pAstNode node, std::vector<llvm::Type *> &collector);

    static void CollectArgs(pAstNode node, std::vector<llvm::Value *> &collector);

    static llvm::Value *CastToType(llvm::Type *type, llvm::Value *value);

    static llvm::Value *CastToBool(llvm::Value *value);

    static llvm::Type *GetPriorType(llvm::Type *t1, llvm::Type *t2);

    static void AlignType(llvm::Value *&v1, llvm::Value *&v2);

    static llvm::Value *AlignType(llvm::Value *v, llvm::Type *t);

    static llvm::Value *CastToRightValue(llvm::Value *left_value);

    static Symbol GenExpression(const AstNode *node);


    DECL_GEN(kRoot);

    DECL_GEN(kId);

    DECL_GEN(kFuncDef);

    DECL_GEN(kVarDecl);

    DECL_GEN(kVarInit);

    DECL_GEN(kFuncType);

    DECL_GEN(kPtrType);

    DECL_GEN(kArrType);

    DECL_GEN(kType);

    DECL_GEN(kTypeFeature);

    DECL_GEN(kTypeDef);

    DECL_GEN(kCharLiteral);

    DECL_GEN(kStrLiteral);

    DECL_GEN(kDemNumber);

    DECL_GEN(kHexNumber);

    DECL_GEN(kOctNumber);

    DECL_GEN(kFloatNumber);

    DECL_GEN(kExpr);

    DECL_GEN(kScope);

    DECL_GEN(kFuncCall);

    DECL_GEN(kFuncDecl);

    DECL_GEN(kEnumType);

    DECL_GEN(kStructType);

    DECL_GEN(kUnionType);
};


#endif //TINYCOMPILER_CODE_GENERATOR_H
