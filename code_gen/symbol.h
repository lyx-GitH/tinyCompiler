//
// Created by 刘宇轩 on 2023/5/22.
//

#ifndef TINYCOMPILER_SYMBOL_H
#define TINYCOMPILER_SYMBOL_H

#include <llvm/IR/Value.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include "../types/type_factory.h"
extern "C" {
#include "../ast/ast.h"
};


class Symbol {
public:
    union SymbolContent {
        llvm::Type *t = nullptr;
        llvm::Function *f;
        llvm::Value *v;
    };

    Symbol() : type_(UNDEFINED) {}

    Symbol(llvm::Function *Func) : type_(FUNCTION) { content_.f = Func; }

    Symbol(llvm::Type *Ty) : type_(TYPE) { content_.t = Ty; }


    Symbol(llvm::Value *Value, bool isConst = false, bool release = false) : type_(isConst ? CONSTANT : VARIABLE),
                                                                             relase_mem_(
                                                                                     true) { content_.v = Value; }

    [[nodiscard]] llvm::Function *GetFunction() const { return this->type_ == FUNCTION ? content_.f : nullptr; }

    [[nodiscard]] llvm::Type *GetType() const { return this->type_ == TYPE ? content_.t : nullptr; }

    [[nodiscard]] llvm::Value *GetVariable() const { return content_.v; }

    [[nodiscard]] llvm::Value *GetConstant() const { return this->type_ == CONSTANT ? content_.v : nullptr; }

    bool IsConst() const {
        return type_ == CONSTANT;
    }

    bool IsFunction() const {
        return type_ == FUNCTION;
    }

    bool IsType() const {
        return type_ == TYPE;
    }

//    bool IsConstType() const {
//        return type_ == TYPE && content_.t.IsConst();
//    }

    bool IsVariable() const {
        return type_ == VARIABLE;
    }

    bool IsUndefined() const {
        return type_ == UNDEFINED;
    }


private:
    SymbolContent content_;
    bool relase_mem_ = false;
    enum {
        FUNCTION,
        TYPE,
        VARIABLE,
        CONSTANT,
        UNDEFINED
    } type_;
};

#endif //TINYCOMPILER_SYMBOL_H
