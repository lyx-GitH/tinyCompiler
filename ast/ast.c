//
// Created by 刘宇轩 on 2023/5/15.
//

#include "ast.h"


static int parser_node_cnt = 0;
extern int parser_line_no;
extern int parser_col_no;


void addChild(pAstNode target, pAstNode child) {
    if (!target || !child)
        return;
    if (!target->child_) {
        target->child_ = child;
        return;
    }

    pAstNode c = target->child_;
    while (c->next_)
        c = c->next_;
    c->next_ = child;
}

void addNext(pAstNode target, pAstNode next) {
    if (!target && !next)
        return;
    if (!target->next_) {
        target->next_ = next;
        return;
    }
    pAstNode n = target->next_;
    while (n->next_)
        n = n->next_;
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
    if (!node)
        return;
    if (node->val_)
        free(node->val_);
    freeAstNode(node->next_);
    freeAstNode(node->child_);
    free(node);
}

pAstNode createBinaryOpTree(const char *op, pAstNode lhs, pAstNode rhs) {
    pAstNode node = createAstNode(kBINOP, op, strlen(op));
    addChild(node, lhs);
    addChild(node, rhs);
    return node;
}

pAstNode createUnaryOpTree(const char* op, pAstNode hs) {
    pAstNode node = createAstNode(kUOP, op, strlen(op));
    addChild(node, hs);
    return node;
}
