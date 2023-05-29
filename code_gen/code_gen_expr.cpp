//
// Created by 刘宇轩 on 2023/5/28.
//

#include "code_generator.h"

extern CodeGenerator::pValue CallGenerator(const AstNode *node);

Symbol CodeGenerator::GenExpression(const AstNode *node) {
    if (!node)
        return {};

    switch (node->type_) {
        case kExpr:
            return GenExpression(node->child_);
        case kId:
            return CastToRightValue(CallGenerator(node).GetVariable());
        case kDemNumber:
        case kHexNumber:
        case kOctNumber:
        case kCharLiteral:
        case kStrLiteral:
        case kFuncCall:
            return CallGenerator(node);
        default:
            assert(false && "Not Implemented yet");

    }
}





/*Binary Operators*/

