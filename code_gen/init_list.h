//
// Created by 刘宇轩 on 2023/6/2.
//

#ifndef TINYCOMPILER_INIT_LIST_H
#define TINYCOMPILER_INIT_LIST_H

#include "llvm/IR/Value.h"

struct InitListNode{
    llvm::Value* value;
    const AstNode* sub_list;

    bool isSubList() {
        return value == nullptr;
    }
};

#endif //TINYCOMPILER_INIT_LIST_H
