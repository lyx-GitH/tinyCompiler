//
// Created by 刘宇轩 on 2023/5/26.
//

#ifndef TINYCOMPILER_TYPE_CASTING_H
#define TINYCOMPILER_TYPE_CASTING_H

#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/IRBuilder.h>
#include "../ast/ast.h"
#include "../exceptions/parser_error.h"

class CodeGenerator;

class CastUtils {
public:
    static llvm::Value *CastToBool(llvm::IRBuilder<> &IR_builder, llvm::Value *v, const AstNode *node);


    static llvm::Value *CastToTargetInt(llvm::IRBuilder<> &IR_builder, llvm::Value *v, const AstNode *node);
};

#endif //TINYCOMPILER_TYPE_CASTING_H
