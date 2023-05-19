//
// Created by 刘宇轩 on 2023/5/15.
//

#include "CodeGenerator.h"

void CodeGenerator::generate() {
    assert(root_ != nullptr && root_->type_ == kRoot);
    auto start = root_->child_;
    while(start) {
        generators[start->type_]();
        start = start->next_;
    }

}
