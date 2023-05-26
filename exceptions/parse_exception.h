//
// Created by 刘宇轩 on 2023/5/22.
//

#ifndef TINYCOMPILER_PARSE_EXCEPTION_H
#define TINYCOMPILER_PARSE_EXCEPTION_H

#include <stdexcept>
#include <iostream>

extern "C" {
#include "../parser/parser.h"
#include "parser_error.h"

}


class ParseException : public std::runtime_error {
public:
    explicit ParseException(const char *e) : std::runtime_error{e},
                                             err_col_(TinyParserGetColumn() - TinyParserGetCurTokLen()),
                                             err_line_(TinyParserGetLine()), file_path_(TinyParserGetPwd()) {}

    ParseException(const char *e, const AstNode *node) : std::runtime_error{e}, err_col_(node->col_no_),
                                                         err_line_(node->line_no_), file_path_{TinyParserGetPwd()} {}

    void show() {
        std::cout << what();
        show_lexer_error(file_path_, err_col_, err_line_, false);
    }


private:
    const char *file_path_;
    int err_col_;
    int err_line_;
};

void ThrowParseException(const char *e);

void ThrowParseException(const char *e, const struct AstNode *node);

#endif //TINYCOMPILER_PARSE_EXCEPTION_H
