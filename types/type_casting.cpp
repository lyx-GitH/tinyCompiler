//
// Created by 刘宇轩 on 2023/5/26.
//

#include "type_casting.h"


//llvm::Value *CastUtils::CastToBool(llvm::IRBuilder<> &IR_builder, llvm::Value *v, const AstNode *node) {
//    if (v->getType() == IR_builder.getInt1Ty())
//        return v;
//    else if (v->getType()->isIntegerTy())
//        return IR_builder.CreateICmpNE(v, llvm::ConstantInt::get((llvm::IntegerType *) v->getType(), 0, true));
//    else if (v->getType()->isFloatingPointTy())
//        return IR_builder.CreateFCmpONE(v, llvm::ConstantFP::get(v->getType(), 0.0));
//    else if (v->getType()->isPointerTy())
//        return IR_builder.CreateICmpNE(IR_builder.CreatePtrToInt(v), IR_builder.getInt64(0));
//    else throw_code_gen_exception(node, "cannot cast to bool");
//}
//
//llvm::Value *CastToTargetInt(llvm::IRBuilder<> &IR_builder, llvm::Value *v, const AstNode *node){
//    return nullptr;
//}