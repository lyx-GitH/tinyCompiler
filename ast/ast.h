//
// Created by 刘宇轩 on 2023/5/10.
//

#ifndef TINYCOMPILER_AST_H
#define TINYCOMPILER_AST_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
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

inline const char* GetSyntaxNodeTypeStr(enum AstNodeType type) {
    //TODO: change this to return real names
    switch (type) {

        case kNULL:
            return "kNull";
        case kRoot:
            return "kRoot";
        case kNumber:
            return "kNumber";
        case kBinOp:
            return "kBiOp";
        case kUop:
            return "KUop";
        case kExpr:
            return "kExpr";
        default:
            return "Unsupported";
    }
}

/*=========== Specialized functions for binary ops ======== */
pAstNode createBinaryOpTree(const char * op, pAstNode lhs, pAstNode rhs);

pAstNode createUnaryOpTree(const char* op, pAstNode hs);

pAstNode createExprTree(pAstNode expr_top);

#endif //TINYCOMPILER_AST_H
