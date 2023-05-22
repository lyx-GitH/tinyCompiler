//
// Created by 刘宇轩 on 2023/5/22.
//

#include "parse_exception.h"



void ThrowParseException(const char *e) {
    throw ParseException(e);
}