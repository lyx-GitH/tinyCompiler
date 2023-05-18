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
    kBinOp,
    kTriOp,
    kUop,
    kExpr,
    kId,
    kArgList,
    kFuncCall,
    kSubScript,
    kType,
    kTypeQualifier,
    kTypeFeature,
    kArgPlaceholders,
    kAssign,
    kVarDecl,
    kFuncDelc,
    kFuncPlaceHolds
};

#define IS_NUMBER(TYPE) ((TYPE) >> 2 == 1)




#endif //TINYCOMPILER_AST_NODE_TYPE_H
