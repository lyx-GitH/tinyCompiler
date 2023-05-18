//
// Created by 刘宇轩 on 2023/5/18.
//

#include "parser_error.h"
#include <string>


void show_lexer_error(const char *file_name, int column, int line){
    //sed "${line_number}q;d" $filename
    std::string command = std::string{"sed "} + "\"" + std::to_string(line+1) + "q;d" + "\" " + std::string{file_name};
    system(command.c_str());
    for(int _=0; _<column ; ++_) {
        putchar(' ');
    }
    printf("\033[32m^\033[0m\n");
    throw std::runtime_error("");
}
