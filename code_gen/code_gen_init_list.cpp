//
// Created by 刘宇轩 on 2023/6/3.
//

#include "code_generator.h"


void CodeGenerator::InitVariableUsingInitList(llvm::Value *left_value, const AstNode *init_list, const AstNode *where) {
    if (left_value->getType()->getPointerElementType()->isStructTy()) {
        InitStructUsingInitList(left_value, init_list, where);
    } else if (left_value->getType()->getPointerElementType()->isArrayTy()) {
        InitArrayUsingInitList(left_value, init_list, where);
    } else {
        if (init_list && init_list->type_ == kInitList)
            InitVariableUsingInitList(left_value, init_list->child_, where);
        else {
            // now, the init_list is a trivial type(like string or int), and the left value is also a trivial type(like int)
            // we can assign to this value directly.
            llvm::Value *initializer = IR_builder.getInt64(0);
            if (init_list) {
                initializer = GenExpression(init_list).GetVariable();
            }
            AssignValue(left_value, initializer, where);
        }
    }
}

llvm::Value *GetStructMemberAt(llvm::IRBuilder<> &IR_builder, llvm::Value *struct_id, uint32_t mem_idx) {
    std::vector<llvm::Value *> index_list;
    index_list.push_back(IR_builder.getInt32(0));
    index_list.push_back(IR_builder.getInt32(mem_idx));
    return IR_builder.CreateGEP(struct_id->getType()->getNonOpaquePointerElementType(),
                                struct_id, index_list);
}

llvm::Value *GetArrayMemAt(llvm::IRBuilder<> &IR_builder, llvm::Value *array, uint32_t idx) {
    auto idx_value = IR_builder.getInt64(idx);
    return IR_builder.CreateGEP(array->getType()->getNonOpaquePointerElementType(), array, idx_value);
}

void CodeGenerator::InitStructUsingInitList(llvm::Value *struct_inst, const AstNode *init_list, const AstNode *where) {
    assert(struct_inst->getType()->getPointerElementType()->isStructTy());
    auto struct_type = (llvm::StructType *) (struct_inst->getType()->getPointerElementType());
    // eq.to a.p = x
    auto list_head = init_list->child_;
    uint32_t mem_idx = 0;
    uint32_t mem_size = struct_type->getNumElements();
    while (list_head) {
        auto mem_inst = GetStructMemberAt(IR_builder, struct_inst, mem_idx);
        InitVariableUsingInitList(mem_inst, list_head, where);
        mem_idx++;
        list_head = list_head->next_;
    }

    for (; mem_idx < mem_size; ++mem_idx) {
        auto mem_inst = GetStructMemberAt(IR_builder, struct_inst, mem_idx);
        InitVariableUsingInitList(mem_inst, nullptr, where);
    }
}

void CodeGenerator::InitArrayUsingInitList(llvm::Value *array_inst, const AstNode *init_list, const AstNode *where) {
    assert(array_inst->getType()->getPointerElementType()->isArrayTy());
    auto list_head = init_list ? init_list->child_ : nullptr;
    auto array_type = (llvm::ArrayType *) (array_inst->getType()->getPointerElementType());

    uint32_t mem_idx = 0;
    uint32_t mem_size = array_type->getNumElements();
    while (list_head) {
        auto mem_inst = GetArrayMemAt(IR_builder, CastToRightValue(array_inst), mem_idx);
        InitVariableUsingInitList(mem_inst, list_head, where);
        mem_idx++;
        list_head = list_head->next_;
    }

    for (; mem_idx < mem_size; ++mem_idx) {
        auto mem_inst = GetArrayMemAt(IR_builder, CastToRightValue(array_inst), mem_idx);
        InitVariableUsingInitList(mem_inst, nullptr, where);
    }

}
