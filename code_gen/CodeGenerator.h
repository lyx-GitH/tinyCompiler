//
// Created by 刘宇轩 on 2023/5/15.
//

#ifndef TINYCOMPILER_CODEGENERATOR_H
#define TINYCOMPILER_CODEGENERATOR_H

#include <functional>
#include <cassert>
#include "../ast/ast.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"

typedef std::function<llvm::Value *()> genFunc;

static std::array<genFunc, 1024> generators{};

class CodeGenerator {
public:
    CodeGenerator(pAstNode root) : root_{root} {};
    void generate();
private:
    const pAstNode root_;

};


#endif //TINYCOMPILER_CODEGENERATOR_H
