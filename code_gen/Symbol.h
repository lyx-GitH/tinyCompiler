//
// Created by 刘宇轩 on 2023/5/22.
//

#ifndef TINYCOMPILER_SYMBOL_H
#define TINYCOMPILER_SYMBOL_H

#include <llvm/IR/Value.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>

class Symbol {
public:
    Symbol() : Type(UNDEFINED) {}

    Symbol(llvm::Function *Func) : Type(FUNCTION) { Content.f = Func; }

    Symbol(llvm::Type *Ty) : Type(TYPE) { Content.t = Ty; }

    Symbol(llvm::Value *Value, bool isConst) : Type(isConst ? CONSTANT : VARIABLE) { Content.v = Value; }

    llvm::Function *GetFunction() { return this->Type == FUNCTION ? Content.f : nullptr; }

    llvm::Type *GetType() { return this->Type == TYPE ? Content.t : nullptr; }

    llvm::Value *GetVariable() { return this->Type == VARIABLE ? Content.v : nullptr; }

    llvm::Value *GetConstant() { return this->Type == CONSTANT ? Content.v : nullptr; }

private:
    union {
        llvm::Function *f = nullptr;
        llvm::Value *v;
        llvm::Type *t;
    } Content;
    enum {
        FUNCTION,
        TYPE,
        VARIABLE,
        CONSTANT,
        UNDEFINED
    } Type;
};

#endif //TINYCOMPILER_SYMBOL_H
