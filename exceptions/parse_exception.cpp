//
// Created by 刘宇轩 on 2023/5/22.
//

#include "parse_exception.h"



void ThrowParseException(const char *e) {
    throw ParseException(e);
}

void ThrowParseException(const char* e, const struct AstNode* node){
    throw ParseException(e, node);
}