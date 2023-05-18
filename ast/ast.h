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
        case kDemNumber:
            return "kDemNumber";
        case kHexNumber:
            return "kHexNumber";
        case kOctNumber:
            return "kOctNumber";
        case kFloatNumber:
            return "kFloatNumber";
        case kBinOp:
            return "kBinOp";
        case kUop:
            return "KUop";
        case kExpr:
            return "kExpr";
        case kTriOp:
            return "kTriOp";
        case kId:
            return "kId";
        case kFuncCall:
            return "kFuncCall";
        case kArgList:
            return "kArgList";
        case kSubScript:
            return "kSubScript";
        case kType:
            return "kType";
        case kAssign:
            return "kAssign";
        case kVarDecl:
            return "kVarDecl";
        case kTypeQualifier:
            return "kTypeQualifier";
        case kFuncDelc:
            return "kFuncDelc";
        case kFuncPlaceHolds:
            return "kFuncPlaceHolds";
        case kTypeFeature:
            return "kTypeFeature";
        default:
            return "Unsupported";
    }
}

/*=========== Specialized functions for binary ops ======== */

pAstNode createBinaryTreeNode(enum AstNodeType type, pAstNode left, pAstNode right);

pAstNode createBinaryOpTree(const char * op, pAstNode lhs, pAstNode rhs);

pAstNode createUnaryOpTree(const char* op, pAstNode hs);

pAstNode createTrinaryOpTree(pAstNode condition, pAstNode true_exp, pAstNode false_exp);

pAstNode createExprTree(pAstNode expr_top);

pAstNode createArgList(pAstNode args);

pAstNode createFunctionCallTree(pAstNode function_name, pAstNode arg_list);

pAstNode createFeaturedType(pAstNode features, pAstNode type);

pAstNode createQualifiedVar(pAstNode qualifiers, pAstNode type, pAstNode Id);

pAstNode createFunctionDelcTree(pAstNode var_decl, pAstNode placeholders);

#endif //TINYCOMPILER_AST_H
