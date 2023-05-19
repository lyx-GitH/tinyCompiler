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

void addChildHead(pAstNode target, pAstNode child);

void assignType(pAstNode root, pAstNode type);

void addNext(pAstNode target, pAstNode next);

pAstNode copyNode(pAstNode target);

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
        case kFuncParams:
            return "kFuncParams";
        case kTypeFeature:
            return "kTypeFeature";
        case kStructMember:
            return "kStructMember";
        case kArrType:
            return "kArrType";
        case kPtrType:
            return "kPtrType";
        case kFuncType:
            return "kFuncType";
        case kInitList:
            return "kInitList";
        case kVarInit:
            return "kVarInit";
        default:
            return "Unsupported";
    }
}

/*=========== Specialized functions for binary ops ======== */

void addNewTypeHint(pAstNode root, pAstNode type_hint);

void addLeftMost(pAstNode root, pAstNode node);

pAstNode createEmptyTreeNode(); 

pAstNode createBinaryTreeNode(enum AstNodeType type, pAstNode left, pAstNode right);

pAstNode createUnaryTreeNode(enum AstNodeType type, pAstNode child);

pAstNode createBinaryOpTree(const char * op, pAstNode lhs, pAstNode rhs);

pAstNode createUnaryOpTree(const char* op, pAstNode hs);

pAstNode createTrinaryOpTree(pAstNode condition, pAstNode true_exp, pAstNode false_exp);

pAstNode createExprTree(pAstNode expr_top);

pAstNode createArgList(pAstNode args);

pAstNode createFunctionCallTree(pAstNode function_name, pAstNode arg_list);

pAstNode createFeaturedType(pAstNode features, pAstNode type);

pAstNode createQualifiedVar(pAstNode qualifiers, pAstNode type, pAstNode Id);

pAstNode createFunctionDelcTree(pAstNode var_decl, pAstNode placeholders);

pAstNode createStructMember(pAstNode node,pAstNode member,  char* val);

pAstNode createTypeDefTree(pAstNode old_type, pAstNode new_type);

pAstNode createFuncType(pAstNode ret_type, pAstNode args_types);

pAstNode createPtrType(pAstNode ptr_to_type);

pAstNode createArrType(pAstNode ele_type, pAstNode size);

pAstNode createScope(pAstNode stats);

pAstNode createVarDecl(pAstNode type, pAstNode var);

pAstNode extractType(pAstNode keywords_list);

pAstNode maintainTypeSpecs(pAstNode root, pAstNode node);





#endif //TINYCOMPILER_AST_H
