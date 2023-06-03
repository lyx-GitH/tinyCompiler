//
// Created by 刘宇轩 on 2023/6/3.
//

#include "code_generator.h"
#include "../static_semantics/sematics.h"


llvm::Constant *
CodeGenerator::InitVariableUsingInitList(llvm::Type *type, const AstNode *init_list, const AstNode *where) {
    if (type->isStructTy())
        return InitStructUsingInitList((llvm::StructType *) (type), init_list, where);
    else if (type->isArrayTy())
        return InitArrayUsingInitList((llvm::ArrayType *) (type), init_list, where);
    else {
        if (init_list && init_list->type_ == kInitList)
            return InitVariableUsingInitList(type, init_list->child_, where);
        else {
            if (init_list) {
                if (!is_const_expr((AstNode *) init_list))
                    throw_code_gen_exception(where, "cannot init static value with non-static value");
                auto value = GenExpression(init_list).GetVariable();
                value = CastToType(type, value);
                return (llvm::Constant *) value;
            } else {
                auto zero = llvm::ConstantInt::get(type, 0);
                return zero;
            }
        }
    }
}


llvm::Constant *
CodeGenerator::InitStructUsingInitList(llvm::StructType *struct_type, const AstNode *init_list, const AstNode *where) {
    assert(struct_type->isStructTy());
    std::vector<llvm::Constant *> init_values;

    auto list_head = init_list ? init_list->child_ : nullptr;
    uint32_t mem_idx = 0;
    uint32_t mem_size = struct_type->getNumElements();

    while (list_head && mem_idx < mem_size) {
        auto mem_type = struct_type->elements()[mem_idx];
//        InitVariableUsingInitList(mem_inst, list_head, where);
        llvm::Constant *mem_value = InitVariableUsingInitList(mem_type, list_head, where);
        mem_idx++;
        list_head = list_head->next_;
        init_values.push_back(mem_value);
    }

    for (; mem_idx < mem_size; ++mem_idx) {
        auto mem_type = struct_type->elements()[mem_idx];
        llvm::Constant *mem_value = InitVariableUsingInitList(mem_type, nullptr, where);
        init_values.push_back(mem_value);
    }

    llvm::Constant *const_struct = llvm::ConstantStruct::get(struct_type, init_values);
    return const_struct;
}


llvm::Constant *
CodeGenerator::InitArrayUsingInitList(llvm::ArrayType *arr_type, const AstNode *init_list, const AstNode *where) {
    assert(arr_type->isArrayTy());
    auto list_head = init_list ? init_list->child_ : nullptr;
    std::vector<llvm::Constant *> init_values;

    uint32_t mem_idx = 0;
    uint32_t mem_size = arr_type->getNumElements();
    auto mem_type = arr_type->getElementType();
    while (list_head && mem_idx < mem_size) {
//        auto mem_inst = GetArrayMemAt(IR_builder, CastToRightValue(array_inst), mem_idx);
        auto init_value = InitVariableUsingInitList(mem_type, list_head, where);
        mem_idx++;
        list_head = list_head->next_;
        init_values.push_back(init_value);
    }

    for (; mem_idx < mem_size; ++mem_idx) {
        auto init_value = InitVariableUsingInitList(mem_type, nullptr, where);
        init_values.push_back(init_value);
    }

    auto const_arr = llvm::ConstantArray::get(arr_type, init_values);
    return const_arr;

}