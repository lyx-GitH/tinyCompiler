//
// Created by 刘宇轩 on 2023/5/20.
//
#include "type_checks.h"
#include <map>
#include <string>
#include "type.h"

static std::map<std::string, std::shared_ptr<Type>> declared_types;

void add_hidden_type(const char *type_name){
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
