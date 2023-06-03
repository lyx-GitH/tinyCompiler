//
// Created by 刘宇轩 on 2023/5/15.
//
#include "../types/type_checks.h"
#include "ast.h"
#include <stdio.h>


static int parser_node_cnt = 0;
extern int parser_line_no;
extern int parser_col_no;


pAstNode check_types(pAstNode type) {
    type = maintainTypeSpecs(type);
    if (IS_TYPE(type->type_)) return type;
    assert(type->child_ != NULL);
    if (!IS_TYPE(type->child_->type_)) {
        printf("add default\n");
        pAstNode node = createAstNode(kType, "int", 3);
        addChildHead(type, node);
    }
    if (type->child_->next_ == NULL) {
        pAstNode junk = type;
        type = type->child_;
        junk->child_ = NULL;
        freeAstNode(junk);
    }
    return type;
}

void assignType(pAstNode dec_list, pAstNode type) {
    type = check_types(type);
    pAstNode cur = dec_list;
    while (cur) {
        addLeftMost(cur, copyNode(type));
        cur = cur->next_;
    }
    freeAstNode(type);
}

size_t safe_strlen(char *s) { return s == NULL ? 0 : strlen(s); }

pAstNode copyNode(const struct AstNode *target) {
    if (target == NULL) return NULL;
    pAstNode new_node =
            createAstNode(target->type_, target->val_, safe_strlen(target->val_));
    new_node->col_no_ = target->col_no_;
    new_node->line_no_ = target->line_no_;
    new_node->next_ = copyNode(target->next_);
    new_node->child_ = copyNode(target->child_);
    return new_node;
}

void addChild(pAstNode target, pAstNode child) {
    if (!target || !child) return;
    if (!target->child_) {
        target->child_ = child;
        return;
    }

    pAstNode c = target->child_;
    while (c->next_) c = c->next_;
    c->next_ = child;
}

void addNullableChild(pAstNode target, pAstNode child) {
    if (!child) child = createEmptyTreeNode();
    addChild(target, child);
}

void addNext(pAstNode target, pAstNode next) {
    if (!target && !next) return;
    if (!target->next_) {
        target->next_ = next;
        return;
    }
    pAstNode n = target->next_;
    while (n->next_) n = n->next_;
    n->next_ = next;
}

void merge(pAstNode prev, pAstNode next) {
    addChild(prev, next->child_);
    next->child_ = NULL;
    freeAstNode(next);
}

void addChildHead(pAstNode target, pAstNode child) {
    if (!target || !child) return;
    if (!target->child_) {
        target->child_ = child;
        return;
    }

    addChild(child, target->child_);
    target->child_ = child;
}

pAstNode initAstNode() {
    pAstNode node = (pAstNode) malloc(sizeof(struct AstNode));
    node->id_ = parser_node_cnt++;
    node->child_ = NULL;
    node->next_ = NULL;
    node->type_ = kNULL;
    node->col_no_ = -1;
    node->line_no_ = -1;
    return node;
}

pAstNode createAstNode(enum AstNodeType type, char *value, int len) {
    pAstNode node = initAstNode();
    node->type_ = type;
    node->line_no_ = parser_line_no;
    node->col_no_ = parser_col_no;
    if (value && len != 0) {
        node->val_ = malloc(len + 1);
        memset(node->val_, 0, len + 1);
        strncpy(node->val_, value, len);
    } else {
        node->val_ = NULL;
    }
    return node;
}

void freeAstNode(pAstNode node) {
    if (!node) return;
    if (node->val_ && strlen(node->val_) != 0) free(node->val_);
    freeAstNode(node->next_);
    freeAstNode(node->child_);
    free(node);
}

pAstNode createEmptyTreeNode() { return createAstNode(kNULL, NULL, 0); }

pAstNode createBinaryOpTree(const char *op, pAstNode lhs, pAstNode rhs) {
    if (lhs == NULL) lhs = createEmptyTreeNode();
    if (rhs == NULL) lhs = createEmptyTreeNode();

    pAstNode node = createAstNode(kBinOp, op, strlen(op));
    addChild(node, lhs);
    addChild(node, rhs);
    return node;
}

pAstNode createUnaryOpTree(const char *op, pAstNode hs) {
    pAstNode node = createAstNode(kUop, op, strlen(op));
    addChild(node, hs);
    return node;
}

pAstNode createTrinaryOpTree(pAstNode condition, pAstNode true_exp,
                             pAstNode false_exp) {
    pAstNode node = createAstNode(kTriOp, "?:", 2);
    addChild(node, condition);
    addChild(node, true_exp);
    addChild(node, false_exp);
    return node;
}

pAstNode createExprTree(pAstNode expr_top) {
    assert(expr_top != NULL);
    if (IS_NUMBER(expr_top->type_)) return expr_top;
    pAstNode node = createAstNode(kExpr, NULL, 0);
    addChild(node, expr_top);
    return node;
}

pAstNode createArgList(pAstNode args) {
    pAstNode node = createAstNode(kArgList, NULL, 0);
    addChild(node, args);
    return node;
}

pAstNode createFunctionCallTree(pAstNode function_name, pAstNode arg_list) {
    pAstNode node = createAstNode(kFuncCall, NULL, 0);
    pAstNode expr_node = createAstNode(kExpr, NULL, 0);
    expr_node->child_ = function_name;
    assert(arg_list == NULL || arg_list->type_ == kArgList);
    addChild(node, expr_node);
    addChild(node, arg_list);
    return node;
}

pAstNode createBinaryTreeNode(enum AstNodeType type, pAstNode left,
                              pAstNode right) {
    pAstNode node = createAstNode(type, NULL, 0);
    addChild(node, left);
    addChild(node, right);
    return node;
}

pAstNode createUnaryTreeNode(enum AstNodeType type, pAstNode child) {
    pAstNode node = createAstNode(type, NULL, 0);
    addChild(node, child);
    return node;
}

pAstNode createQualifiedVar(pAstNode qualifiers, pAstNode type, pAstNode Id) {
    assert(qualifiers->type_ == kTypeQualifier);
    assert(type->type_ == kType);
    assert(Id->type_ == kId);

    // pAstNode type_node = createBinaryTreeNode(kTypeFeature, Type,
    // qualifiers);
    pAstNode type_node = createFeaturedType(qualifiers, type);
    pAstNode node = createBinaryTreeNode(kVarDecl, type_node, Id);
    return node;
}

pAstNode createFeaturedType(pAstNode features, pAstNode type) {
    assert(features->type_ == kTypeQualifier);
    pAstNode node = createBinaryTreeNode(kTypeFeature, type, features);
    if (type == NULL) {
        node->type_ = kTypeFeatureEmpty;
    }
    return node;
}

// pAstNode createFunctionDelcTree(pAstNode var_delc, pAstNode placeholders) {
//     var_delc->type_ = kFuncDelc;
//     pAstNode node = createAstNode(kFuncPlaceHolds, NULL, 0);
//     addChild(node, placeholders);
//     addChild(var_delc, node);
//     return var_delc;
// }

pAstNode createStructMember(pAstNode s, pAstNode member, char *val) {
    pAstNode node = createAstNode(kStructMember, val, strlen(val));
    addChild(node, s);
    addChild(node, member);
    return node;
}

//pAstNode createTypeDefTree(pAstNode old_type, pAstNode new_type) {
//    assert(old_type != NULL && new_type != NULL);
//    return createBinaryTreeNode(kTypeDef, old_type, new_type);
//}

pAstNode createFuncType(pAstNode ret_type, pAstNode args_types) {
    pAstNode params = createUnaryTreeNode(kFuncParams, args_types);
    if (ret_type == NULL) ret_type = createEmptyTreeNode();
    pAstNode node = createBinaryTreeNode(kFuncType, ret_type, params);
    return node;
}

pAstNode createPtrType(pAstNode ptr_to_type) {
    if (ptr_to_type == NULL) ptr_to_type = createEmptyTreeNode();
    pAstNode node = createUnaryTreeNode(kPtrType, ptr_to_type);
    return node;
}

pAstNode createArrType(pAstNode ele_type, pAstNode size) {
    pAstNode node = NULL;
    if (ele_type == NULL) ele_type = createEmptyTreeNode();
    if (size != NULL)
        node = createBinaryTreeNode(kArrType, ele_type, size);
    else {
        pAstNode sz_node = createAstNode(kDemNumber, "*", 1);
        node = createBinaryTreeNode(kArrType, ele_type, sz_node);
    }
    return node;
}

// pAstNode extractType(pAstNode keywords_list) {
//     assert(keywords_list != NULL);
//     int i = 0;
//     pAstNode cur = keywords_list;
//     while (cur && cur->type_ != kType) {
//         cur = cur->next_;
//         i++;
//     }
//     if (!cur) {
//         pAstNode node = createAstNode(kType, "int", 3);
//         node->next_ = keywords_list;
//         return node;
//     }
// }

pAstNode createScope(pAstNode stats) {
    pAstNode node = createAstNode(kScope, NULL, 0);
    addChild(node, stats);
    return node;
}

pAstNode createVarDecl(pAstNode type, pAstNode var) {
    if (type == NULL) {
        type = createEmptyTreeNode();
    }

    pAstNode node = createBinaryTreeNode(kVarDecl, type, var);
    return node;
}

/**
 * @brief
 *                  R
 *                  |
 *                  A - B
 * @param root
 * @param type_hint
 */

void addNewTypeHint(pAstNode root, pAstNode type_hint) {
    pAstNode a = root, b = root->child_, c = root->child_->next_, d = type_hint,
            e = type_hint->child_->next_, x = type_hint->child_;

    assert(x->type_ == kNULL);
    assert(x->child_ == NULL);
    d->next_ = c;
    d->child_ = b;
    b->next_ = e;
    a->child_ = d;
    x->next_ = NULL;
    freeAstNode(x);
}

void addLeftMost(pAstNode root, pAstNode node) {
    while (root->child_ && root->child_->type_ != kNULL) root = root->child_;
    pAstNode junk = root->child_;
    pAstNode right_node = root->child_->next_;
    root->child_ = node;
    root->child_->next_ = right_node;
    junk->next_ = NULL;
    freeAstNode(junk);
}

pAstNode maintainTypeSpecs(pAstNode root) {
    // pAstNode top = NULL;
    // if (!root || root->type_ != kTypeFeature)
    //     top = createAstNode(kTypeFeature, NULL, 0);
    // else
    //     top = root;

    // if (node && IS_TYPE(node->type_)) {
    //     if (!top->child_) {
    //         addChild(top, node);
    //     } else {
    //         addChildHead(top, node);
    //     }
    // } else if (node && node->type_ == kTypeQualifier) {
    //     addChild(top, node);
    // }

    // return top;
    if (root && IS_TYPE(root->type_)) {
        if (root->next_) {
            pAstNode node = createAstNode(kTypeFeature, NULL, 0);
            addChild(node, root);
            return node;
        } else {
            return root;
        }
    } else {
        pAstNode node = createAstNode(kType, "int", 3);
        addChild(node, root);
        return node;
    }
}

pAstNode createLabledStmt(pAstNode lableId, pAstNode stat) {
    lableId->type_ = kLabeledStmt;
    addChild(lableId, stat);
    return lableId;
}

pAstNode createLableThroughName(const char *name, pAstNode stat) {
    pAstNode node = createAstNode(kLabeledStmt, name, strlen(name));
    addChild(node, stat);
    return node;
}

pAstNode createTrinaryTreeNode(enum AstNodeType type, pAstNode left, pAstNode mid,
                               pAstNode right) {
    pAstNode node = createAstNode(type, NULL, 0);
    left = left == NULL ? createEmptyTreeNode() : left;
    mid = mid == NULL ? createEmptyTreeNode() : mid;
    right = right == NULL ? createEmptyTreeNode() : right;
    addChild(node, left);
    addChild(node, mid);
    addChild(node, right);
    return node;
}

pAstNode initVar(pAstNode var, pAstNode value) {
    pAstNode node = createBinaryTreeNode(kVarInit, var, value);
    return node;
}


pAstNode createEnumerator(pAstNode id, pAstNode value) {
    pAstNode const_int_type = createBinaryTreeNode(kTypeFeature, createAstNode(kType, "int", 3),
                                                   createAstNode(kTypeQualifier, "const", 5));
    pAstNode var_dec = createBinaryTreeNode(kVarDecl, const_int_type, id);
    if (value)
        return createBinaryTreeNode(kVarInit, var_dec, value);
    else return var_dec;
}

pAstNode createForStmt(pAstNode exp1, pAstNode exp2, pAstNode exp3, pAstNode stmt) {
    pAstNode node = createAstNode(kForStmt, NULL, 0);
    addNullableChild(node, exp1);
    addNullableChild(node, exp2);
    addNullableChild(node, exp3);
    addNullableChild(node, stmt);
    return node;
}

pAstNode createTypeDefTree(pAstNode decl_tree) {

}

pAstNode getNChildSafe(struct AstNode const *node, int n) {
    if (!node)
        return NULL;
    assert(n >= 0);
    pAstNode cur = node->child_;
    for (int i = 0; cur && i < n; i++) {
        cur = cur->next_;
    }
    return cur;
}

uint64_t solveConstantExpr(const struct AstNode *node) {
    assert(node);
    if (node->type_ == kExpr) {
        return solveConstantExpr(node->child_);
    } else if (IS_NUMBER(node->type_)) {
        return strtoll(node->val_, NULL, 0);
    } else {

    }

    assert(0);
}
