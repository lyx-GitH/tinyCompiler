//
// Created by 刘宇轩 on 2023/5/20.
//
#include "type_checks.h"
#include <map>
#include <string>
#include <llvm/IR/Type.h>

#include "type.h"

static std::map<std::string, llvm::Type *> declared_types;

//void SetType(const char* name, void *llvm_type){
//    declared_types[name] = static_cast<llvm::Type*>(llvm_type);
//}
//
//void* GetType(const char *name){
//    return declared_types[name];
//}

void add_hidden_type(const char *type_name) {
    const std::string hidden_type_name = "!" + std::string{type_name};
    declared_types.insert(std::make_pair(hidden_type_name, nullptr));
}

void add_type(const char *type_name) {
    if (declared_types.contains(type_name)) {
        throw std::runtime_error("type " + std::string{type_name} + " already declared");
    } else {
        declared_types.insert(std::make_pair(std::string{type_name}, nullptr));
    }
}

int has_type(const char *type_name) {
    auto b = declared_types.contains(type_name);
    return b;
}

int has_hidden_type(const char *type_name) {
    return declared_types.contains(std::string{"!"} + type_name);
}

void AddTypeAlias(const char *name, void *llvm_type) {
    assert(has_type(name));
    declared_types[name] = static_cast<llvm::Type*>(llvm_type);
}

void AddHiddenTypeAlias(const char *name, void *llvm_type) {
    std::string hidden_type_name = std::string{"!"} + name;
    assert(has_type(hidden_type_name.c_str()));
    declared_types[hidden_type_name] =static_cast<llvm::Type*>(llvm_type);
}
