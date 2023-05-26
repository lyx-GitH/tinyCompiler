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


class CodeGenerator : public TCParser {
public:
    using pValue = Symbol;
    using GenFunc = std::function<pValue(const AstNode *)>;
    using SymbolTable = std::map<std::string, pValue>;

    static void InitGenerators();

    static void InitBasicTypes();

    static std::array<GenFunc, MAX_GEN_NUM> generators;

//    CodeGenerator() = default;

    explicit CodeGenerator(std::string file_path) : TCParser(std::move(file_path)) {
        InScope();
        InitGenerators();
        InitBasicTypes();
//       module
//        test();
//        test2();
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

    void test() {
        auto int_type = GetType("int");
        assert(int_type->isIntOrIntVectorTy());

        auto const_int_type = TypeFactory::GetConstTypeOf(int_type);
        auto const_int_ptr_type = TypeFactory::Get<llvm::PointerType>(const_int_type, 0U);
        std::cout << "const int:" << const_int_type << " " << "const int*: " << const_int_ptr_type << std::endl;
        auto int_ptr_type = TypeFactory::Get<llvm::PointerType>(int_type, 0U);
        std::cout << "int* : " << int_ptr_type << std::endl;

    }

    void test2() {
        auto int_type = GetType("int");
        assert(!TypeFactory::IsConst(int_type));
        assert(int_type != IR_builder.getInt32Ty());
        assert(int_type->isIntOrIntVectorTy());
        auto const_int_type = TypeFactory::GetConstTypeOf(int_type);
        auto c_const_int_ty = TypeFactory::GetConstTypeOf(const_int_type);
        assert(const_int_type == c_const_int_ty);
        assert(TypeFactory::IsConst(const_int_type));
        auto const_int_ptr_type = TypeFactory::Get<llvm::PointerType>(const_int_type, 0U);
        std::cout << "const int:" << const_int_type << " " << "const int*: " << const_int_ptr_type << std::endl;
        auto int_ptr_type = TypeFactory::Get<llvm::PointerType>(int_type, 0U);
        std::cout << "int* : " << int_ptr_type << std::endl;
        auto f_cst_type = TypeFactory::Get<llvm::FunctionType>(int_type, std::vector<llvm::Type *>{}, false);
        auto f_int_type = TypeFactory::Get<llvm::FunctionType>(const_int_type, std::vector<llvm::Type *>{}, false);
        assert(f_cst_type != f_int_type);

    }

    static inline void PrintIR() {
        module.print(llvm::outs(), nullptr);
    }


private:
    llvm::DataLayout *data_layout_ = nullptr;


    std::vector<llvm::BasicBlock *> ContinueBlockStack;    //Store blocks for "continue" statement
    std::vector<llvm::BasicBlock *> BreakBlockStack;        //Store blocks for "break" statement
    llvm::BasicBlock *TmpBB = nullptr;                            //Temp block for global instruction code generation
    llvm::Function *TmpFunc = nullptr;                            //Temp function for global instruction code generation

    static llvm::Module module;
    static llvm::DataLayout data_layout;
    static llvm::LLVMContext context;
    static llvm::IRBuilder<> IR_builder;
    static llvm::Function *cur_func_;
    static bool cur_init_;
    static std::vector<SymbolTable> symbol_table_stack_;
    static std::set<std::string> defined_functions;

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

    static void SetSymbol(const std::string &name, Symbol symbol);

    static Symbol const *GetSymbol(const std::string &name);

    static Symbol const *GetLocalSymbol(const std::string &name);

    static void CollectArgTypes(pAstNode node, std::vector<llvm::Type *> &collector);


    DECL_GEN(kRoot);

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


};


#endif //TINYCOMPILER_CODE_GENERATOR_H
