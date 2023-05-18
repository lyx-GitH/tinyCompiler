//
// Created by 刘宇轩 on 2023/5/15.
//

#include "ast.h"

#include "stdio.h"

static int parser_node_cnt = 0;
extern int parser_line_no;
extern int parser_col_no;

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
    if (value) {
        node->val_ = malloc(len + 1);
        memset(node->val_, 0, len + 1);
        strncpy(node->val_, value, len);
    }
    return node;
}

void freeAstNode(pAstNode node) {
    if (!node) return;
    if (node->val_) free(node->val_);
    freeAstNode(node->next_);
    freeAstNode(node->child_);
    free(node);
}

pAstNode createBinaryOpTree(const char *op, pAstNode lhs, pAstNode rhs) {
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
    if (IS_NUMBER(expr_top->type_))
        return expr_top;
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
    assert(function_name->type_ == kId);
    assert(arg_list == NULL || arg_list->type_ == kArgList);
    addChild(node, function_name);
    addChild(node, arg_list);
    return node;
}

pAstNode createBinaryTreeNode(enum AstNodeType type, pAstNode left, pAstNode right) {
    pAstNode node = createAstNode(type, NULL, 0);
    addChild(node, left);
    addChild(node, right);
    return node;
}

pAstNode createQualifiedVar(pAstNode qualifiers, pAstNode type, pAstNode Id) {
    assert(qualifiers->type_ == kTypeQualifier);
    assert(type->type_ == kType);
    assert(Id->type_ == kId);

    // pAstNode type_node = createBinaryTreeNode(kTypeFeature, type, qualifiers);
    pAstNode type_node = createFeaturedType(qualifiers, type);
    pAstNode node = createBinaryTreeNode(kVarDecl, type_node, Id);
    return node;
}

pAstNode createFeaturedType(pAstNode features, pAstNode type){
    assert(features->type_ == kTypeQualifier);
    assert(type->type_ == kType);
    return createBinaryTreeNode(kTypeFeature, type, features);
}

pAstNode createFunctionDelcTree(pAstNode var_delc, pAstNode placeholders){
    var_delc->type_ = kFuncDelc;
    pAstNode node = createAstNode(kFuncPlaceHolds, NULL, 0);
    addChild(node, placeholders);
    addChild(var_delc,node);
    return var_delc;
}
