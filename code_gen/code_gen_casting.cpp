//
// Created by 刘宇轩 on 2023/5/26.
//

#include "code_generator.h"

inline bool IsSigned(llvm::Value *v) {
    return !v->getType()->isIntegerTy(1);
}

llvm::Value *CodeGenerator::CastToBool(llvm::Value *value) {
    if (value->getType() == CodeGenerator::GetType("_bool"))
        return value;
    if (value->getType()->isIntegerTy())
        return CodeGenerator::IR_builder.CreateICmpNE(value,
                                                      llvm::ConstantInt::get((llvm::IntegerType *) value->getType(), 0,
                                                                             true));
    if (value->getType()->isFloatingPointTy())
        return CodeGenerator::IR_builder.CreateFCmpONE(value, llvm::ConstantFP::get(value->getType(), 0.0));
    if (value->getType()->isPointerTy())
        return CodeGenerator::IR_builder.CreateICmpNE(CodeGenerator::IR_builder.CreatePtrToInt(value,
                                                                                               CodeGenerator::GetType(
                                                                                                       "long")),
                                                      llvm::ConstantInt::get(CodeGenerator::GetType("long"), 0));

}

llvm::Value *CodeGenerator::CastToType(llvm::Type *type, llvm::Value *value) {
    if (value->getType() == type)
        return value;
    if (value->getType() == CodeGenerator::GetType("_bool"))
        return CastToBool(value);

    if (value->getType()->isIntegerTy()) {
        if (type->isIntegerTy())
            return CodeGenerator::IR_builder.CreateIntCast(value, type, IsSigned(value));
        if (type->isFloatingPointTy())
            return IsSigned(value) ? CodeGenerator::IR_builder.CreateSIToFP(value, type) :
                   CodeGenerator::IR_builder.CreateUIToFP(value, type);
        if (type->isPointerTy())
            return CodeGenerator::IR_builder.CreateIntToPtr(value, type);
    }

    if (value->getType()->isFloatingPointTy()) {
        if (type->isFloatingPointTy())
            return CodeGenerator::IR_builder.CreateFPCast(value, type);
        if (type->isIntegerTy())
            return CodeGenerator::IR_builder.CreateFPToSI(value, type);
    }

    if (value->getType()->isPointerTy()) {
        if (type->isIntegerTy())
            return CodeGenerator::IR_builder.CreatePtrToInt(value, type);
        if (type->isPointerTy())
            return CodeGenerator::IR_builder.CreatePointerCast(value, type);
    }
    return nullptr;
}


