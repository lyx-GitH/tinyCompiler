//
// Created by 刘宇轩 on 2023/5/28.
//

#include "code_generator.h"

static inline uint32_t GetOpHash(const std::string &str) {
    if (str.length() == 1)
        return static_cast<uint32_t>(str[0]);
    else return static_cast<uint32_t>(str[0]) + static_cast<uint32_t>(str[1]);
}

//static const char *binary_ops[] = {
//        "+", "-", "*", "/", "%", "<<", ">>", "&&", "||", "&", "|", "^",
//        ">", "<", ">=", "<=", "==", "!="
//};
//
//static const char *unary_ops[] = {
//        "+", "-", "!", "~", "*", "&", "sizeof"
//};
//
//static const char *assign_ops[] = {
//        "=", "+=", "-=", "*=", "/=", "%=", "<<=", ">>=", "&=", "|=", "^="
//};


extern CodeGenerator::pValue CallGenerator(const AstNode *node);

void CodeGenerator::InitBinaryOperators() {
//    LOAD_BINARY_OP("+", Plus);
//    LOAD_BINARY_OP("-", Sub);
//    LOAD_BINARY_OP("*", Mult);
//    LOAD_BINARY_OP("/", Div);
//    LOAD_BINARY_OP("%", Mod);
//    LOAD_BINARY_OP("<<", Shl);
//    LOAD_BINARY_OP(">>", Shr);
//    LOAD_BINARY_OP("|", BitOr);
//    LOAD_BINARY_OP("&", BitAnd);
//    LOAD_BINARY_OP("^", BitXor);
}

void CodeGenerator::InitUnaryOperators() {
    LOAD_UNARY_OP("+", UPlus);
    LOAD_UNARY_OP("-", UMinus);
    LOAD_UNARY_OP("&", AddrOf);
    LOAD_UNARY_OP("*", DeRef);
    LOAD_UNARY_OP("~", UBitNot);
    LOAD_UNARY_OP("!", ULogNot);
    LOAD_UNARY_OP("sizeof", SizeOf);
}

void CodeGenerator::InitAssignOperators() {
    LOAD_ASSIGN_OP("=", Assign);
    LOAD_ASSIGN_OP("+=", AssignPlus);
    LOAD_ASSIGN_OP("-=", AssignSub);
    LOAD_ASSIGN_OP("*=", AssignMult);
    LOAD_ASSIGN_OP("/=", AssignDiv);
}


Symbol CodeGenerator::GenExpression(const AstNode *node, bool r_value) {
    if (!node)
        return {};

    switch (node->type_) {
        case kExpr:
            return GenExpression(node->child_);
        case kId:
        case kSubScript: {
            auto value = CallGenerator(node);
            return r_value ? CastToRightValue(value.GetVariable()) : value;
        }
        case kDemNumber:
        case kHexNumber:
        case kOctNumber:
        case kCharLiteral:
        case kStrLiteral:
        case kFuncCall:
        case kFloatNumber:
        case kCast: {
            if (!r_value)
                throw_code_gen_exception(node, "term must be a right value");
            return CallGenerator(node).GetVariable();
        }
        case kUop: {
            if (r_value)
                return CodeGenerator::unary_gen_right.at(GetOpHash(node->val_))(node);
            else return CodeGenerator::unary_gen_left.at(GetOpHash(node->val_))(node);
        }
        case kBinOp: {
            if (r_value)
                return CodeGenerator::binary_gen_right.at(GetOpHash(node->val_))(node);
            else return CodeGenerator::binary_gen_left.at(GetOpHash(node->val_))(node);
        }
        case kAssign: {
            if (r_value)
                return CodeGenerator::assign_gen_right.at(GetOpHash(node->val_))(node);
            else return CodeGenerator::assign_gen_left.at(GetOpHash(node->val_))(node);
        }
        default:
            assert(false && "Not Implemented yet");

    }
}

Symbol CodeGenerator::AssignValue(llvm::Value *lhs, llvm::Value *rhs, const AstNode* node) {
    rhs = CastToType(lhs->getType()->getNonOpaquePointerElementType(), rhs);
    if (!rhs) {
        throw_code_gen_exception(node, "incompatible assignment");
    }
    IR_builder.CreateStore(rhs, lhs);
    return lhs;
}

void CodeGenerator::CheckValidAssign(llvm::Value* lhs, llvm::Value* rhs, const AstNode* node){
    if(!lhs || ! rhs)
        throw_code_gen_exception(node, "invalid Assignment");
    if(TypeFactory::IsConst(lhs->getType())){
        throw_code_gen_exception(node, "cannot assign value to a const value");
    }
}





/*Binary Operators*/

