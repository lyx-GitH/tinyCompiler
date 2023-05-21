//
// Created by 刘宇轩 on 2023/5/21.
//

#include "sematics.h"
#include <utility>
#include <stdexcept>

void assert_valid_typedefs(pAstNode declares){
    auto cur = declares;
    while (cur) {
        if (cur->type_ == kVarInit)
            goto err;
        if (cur->type_ == kVarDecl){
            cur->type_ = kTypeDef;
            assert(cur->child_->next_);
            add_type(cur->child_->next_->val_);
            cur->child_->next_->type_ = kType;
        }

        cur = cur->next_;
    }
    return;

    err:
    freeAstNode(declares);
    throw std::runtime_error{"not a valid typedef"};
}