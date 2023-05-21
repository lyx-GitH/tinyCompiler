//
// Created by 刘宇轩 on 2023/5/20.
//

#include "type.h"

const std::string &Type::getName() const {
    return name_;
}

void Type::setName(const std::string &name) {
    name_ = name;
}

size_t Type::getSize() const {
    return size_;
}
