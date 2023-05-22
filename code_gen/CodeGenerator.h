//
// Created by 刘宇轩 on 2023/5/15.
//

#ifndef TINYCOMPILER_CODEGENERATOR_H
#define TINYCOMPILER_CODEGENERATOR_H

#include <iostream>
#include <fstream>
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
#include "../ast/ast.h"
#include "Symbol.h"

typedef std::function<llvm::Value *()> genFunc;

static std::array<genFunc, 1024> generators{};

#define LOAD_F(idx, f) generators.at(idx) = (f)

static void initGenerators() {

}


class CodeGenerator {
public:
    using pValue = llvm::Value *;
    using SymbolTable = std::map<std::string, Symbol>;

    CodeGenerator(pAstNode root) : root_{root} {
        Module = new llvm::Module("main", Context);
        DataLayout = new llvm::DataLayout(Module);
    };

    void generate();

    void optimize(const std::string &opt_level);

    void GenObjectCode(std::string file_name);

private:
    llvm::DataLayout *DataLayout;                                //Data layout
    llvm::Function *CurrFunction;                        //Current function
//    StructTypeTable* StructTyTable;						//Struct type table
//    UnionTypeTable* UnionTyTable;						//Union type table
//    std::vector<SymbolTable*> SymbolTableStack;			//Symbol table
    std::vector<llvm::BasicBlock *> ContinueBlockStack;    //Store blocks for "continue" statement
    std::vector<llvm::BasicBlock *> BreakBlockStack;        //Store blocks for "break" statement
    llvm::BasicBlock *TmpBB = nullptr;                            //Temp block for global instruction code generation
    llvm::Function *TmpFunc = nullptr;                            //Temp function for global instruction code generation
    const AstNode *root_;

    llvm::Module *Module;
    static llvm::LLVMContext Context;
    static llvm::IRBuilder<> IRBuilder;

    std::vector<SymbolTable> SymbolTableStack;


};




#endif //TINYCOMPILER_CODEGENERATOR_H
