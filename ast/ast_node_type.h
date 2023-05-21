//
// Created by 刘宇轩 on 2023/5/15.
//

#ifndef TINYCOMPILER_AST_NODE_TYPE_H
#define TINYCOMPILER_AST_NODE_TYPE_H

enum AstNodeType {
    kNULL = 0,
    kRoot,
    kNumber,
    kDemNumber = 4,
    kHexNumber = 5,
    kOctNumber = 6,
    kFloatNumber = 7,
    kType = 16,
    kPtrType,
    kArrType,
    kFuncType,
    kEnumType,
    kUnionType,
    kStructType,
    kBinOp = 24,
    kTriOp,
    kUop,
    kExpr,
    kInitList,
    kId,
    kArgList,
    kFuncCall,
    kSubScript,
    kTypeQualifier,
    kTypeFeature,
    kTypeFeatureEmpty,
    kArgPlaceholders,
    kAssign,
    KUAsign,
    kCast,
    kAssignOp,
    kVarDecl,
    kVarInit,
    kTypeDef,
    kFuncDelc,
    kFuncParams,
    kStructMember,
    kScope,
    kIfStmt,
    kForStmt,
    kWhileStmt,
    kDoWhileStmt,
    kLabeledStmt,
    kSwitchStmt,
    kCase,
    kJump,
    kFuncDef,
    kCharLiteral,
    kStrLiteral,
    kTypeDecl,
};

#define IS_NUMBER(TYPE) ((TYPE) >> 2 == 1)
#define IS_TYPE(t) ((t) >> 2 == 4 || (t) >> 2 == 5)




#endif //TINYCOMPILER_AST_NODE_TYPE_H
