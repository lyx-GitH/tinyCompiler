//
// Created by 刘宇轩 on 2023/5/26.
//

#include "code_generator.h"

inline bool IsSigned(llvm::Value *v) {
    return !v->getType()->isIntegerTy(1);
}

llvm::Value *CodeGenerator::CastToBool(llvm::Value *value) {
    if (value->getType()->isIntegerTy() && value->getType()->getIntegerBitWidth() == 1)
        return value;

    if (value->getType()->isIntegerTy()) {
        value = CastToType(IR_builder.getIntNTy(value->getType()->getIntegerBitWidth()), value); // When enabling type factory
        return CodeGenerator::IR_builder.CreateICmpNE(value,
                                                      llvm::ConstantInt::get((llvm::IntegerType *) value->getType(), 0,
                                                                             true));
    }
    if (value->getType()->isFloatingPointTy())
        return CodeGenerator::IR_builder.CreateFCmpONE(value, llvm::ConstantFP::get(value->getType(), 0.0));
    if (value->getType()->isPointerTy())
        return CodeGenerator::IR_builder.CreateICmpNE(CodeGenerator::IR_builder.CreatePtrToInt(value,
                                                                                               CodeGenerator::GetType(
                                                                                                       "long")),
                                                      llvm::ConstantInt::get(CodeGenerator::GetType("long"), 0));

}

llvm::Value *CodeGenerator::CastToType(llvm::Type *type, llvm::Value *value) {
//    auto non_const_type = TypeFactory::GetNonConstOf(type);
//    auto non_const_v_type = TypeFactory::GetNonConstOf(value->getType());

//    if (non_const_type == non_const_v_type) // This would eliminate const issues.
//        return value;
//    if(type == value->getType())
//        return value;
    if (TypeFactory::IsActuallySameType(type, value->getType())) {
        return value;
    } else {
        std::cout << "warning: implicit type conversion is conducted" << std::endl;
    }

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

llvm::Type *CodeGenerator::GetPriorType(llvm::Type *t1, llvm::Type *t2) {
    if (t1->isIntegerTy() && t2->isIntegerTy()) {
        return t1->getIntegerBitWidth() > t2->getIntegerBitWidth() ? t1 : t2;
    }
    if (t1->isFloatingPointTy() && t2->isFloatingPointTy())
        return t1->isFloatTy() ? t2 : t1;
    if (t1->isFloatingPointTy() && t2->isIntegerTy())
        return t1;
    if (t1->isIntegerTy() && t2->isFloatingPointTy())
        return t2;
    return nullptr;
}

void CodeGenerator::AlignType(llvm::Value *&v1, llvm::Value *&v2) {
    auto good_type = GetPriorType(v1->getType(), v2->getType());
    if (!good_type)
        throw std::runtime_error("incompatible types");
    v1 = CastToType(good_type, v1);
    v2 = CastToType(good_type, v2);
}

llvm::Value *CodeGenerator::AlignType(llvm::Value *v, llvm::Type *t) {
    auto good_type = GetPriorType(v->getType(), t);
    if (!good_type)
        throw std::runtime_error("incompatible types");
    return t == good_type ? CastToType(t, v) : v;
}

llvm::Value *CodeGenerator::CastToRightValue(llvm::Value *left_value) {
    assert(left_value);

    auto type = left_value->getType()->getNonOpaquePointerElementType();
    if (type->isArrayTy()) {
        return IR_builder.CreatePointerCast(left_value, type->getArrayElementType()->getPointerTo());
    } else return IR_builder.CreateLoad(type, left_value);
}



