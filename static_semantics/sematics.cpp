//
// Created by 刘宇轩 on 2023/5/21.
//

#include "sematics.h"
#include "../exceptions/parse_exception.h"
#include <utility>
#include <stdexcept>

void assert_valid_typedefs(pAstNode declares) {
    auto cur = declares;
    while (cur) {
        if (cur->type_ == kVarInit)
            goto err;
        if (cur->type_ == kVarDecl || cur->type_ == kFuncDecl) {
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
    throw ParseException{"not a valid typedef"};
}

inline bool is_constant_node(pAstNode node) {
    return node->type_ == kStrLiteral
           || node->type_ == kCharLiteral
           || node->type_ == kFloatNumber
           || node->type_ == kDemNumber
           || node->type_ == kOctNumber
           || node->type_ == kHexNumber;
}

int is_const_expr(pAstNode node) {
    if (!node)
        return false;
    if(node->type_ == kInitList)
        return true;
    if (is_constant_node(node))
        return true;
    if (node->type_ == kExpr)
        return is_const_expr(node->child_);
    if (node->type_ == kBinOp)
        return is_const_expr(node->child_) && is_const_expr(node->child_->next_);
    if (node->type_ == kUop)
        return is_const_expr(node->child_);
    return false;
}


