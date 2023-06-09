//
// Created by 刘宇轩 on 2023/5/18.
//

#ifndef TINYCOMPILER_PARSER_ERROR_H
#define TINYCOMPILER_PARSER_ERROR_H


#ifdef __cplusplus
extern "C" {
#endif
#include "../ast/ast.h"
extern const char *TinyParserGetPwd();

void show_lexer_error(const char *file_name, int column, int line, int throw_exp);

void show_code_gen_warning(const struct AstNode *node, const char *e) ;

void throw_parse_exception(const char *e);

//extern struct AstNode;

void throw_code_gen_exception(const struct AstNode *node, const char *e);

#ifdef __cplusplus
}
#endif


#endif //TINYCOMPILER_PARSER_ERROR_H
