//
// Created by 刘宇轩 on 2023/5/18.
//

#include "parser_error.h"
#include <string>


void show_lexer_error(const char *file_name, int column, int line, int throw_err) {
    printf(" in %s:%d:%d\n", file_name, line + 1, column + 1);
    //```sed "${line_number}q;d" $filename```
    // use this to extract that line of error
    std::string command =
            std::string{"sed "} + "\"" + std::to_string(line + 1) + "q;d" + "\" " + std::string{file_name};
    system(command.c_str());
    for (int _ = 0; _ < column; ++_) {
        putchar(' ');
    }
    printf("\033[32m^\033[0m\n");
    if (throw_err)
        throw std::runtime_error("");
}

extern void ThrowParseException(const char *e);

void throw_parse_exception(const char *e){
    ThrowParseException(e);
}
