//
// Created by 刘宇轩 on 2023/5/10.
//

#ifndef TINYCOMPILER_AST_H
#define TINYCOMPILER_AST_H

#include "stddef.h"
#include "stdlib.h"
#include "string.h"
#include "ast_node_type.h"


struct AstNode {
    int id_;
    enum AstNodeType type_;
    int line_no_;
    int col_no_;
    char *val_;
    struct AstNode *child_;
    struct AstNode *next_;
};



typedef struct AstNode *pAstNode;

void addChild(pAstNode target, pAstNode child);

void addNext(pAstNode target, pAstNode next);


pAstNode initAstNode();

pAstNode createAstNode(enum AstNodeType type, char* value, int len);

void freeAstNode(pAstNode node);

#endif //TINYCOMPILER_AST_H
