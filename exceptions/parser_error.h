//
// Created by 刘宇轩 on 2023/5/18.
//

#ifndef TINYCOMPILER_PARSER_ERROR_H
#define TINYCOMPILER_PARSER_ERROR_H


#ifdef __cplusplus
extern "C" {
#endif

void show_lexer_error(const char *file_name, int column, int line, int throw_exp);

void throw_parse_exception(const char *e);

#ifdef __cplusplus
}
#endif


#endif //TINYCOMPILER_PARSER_ERROR_H
