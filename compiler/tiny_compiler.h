//
// Created by 刘宇轩 on 2023/5/22.
//

#ifndef TINYCOMPILER_TINY_COMPILER_H
#define TINYCOMPILER_TINY_COMPILER_H

#include <string>
#include "../parser/tc_parser.h"
#include "../code_gen/code_generator.h"

class TinyCompiler {
public:
    TinyCompiler(std::string file_name) : file_name_(std::move(file_name)), parser_(file_name_){};

    void Compile();

    [[nodiscard]] auto &GetConfig() {
        return config;
    }

private:
    struct {
        bool dump_ir = true;

    } config;
    std::string file_name_;
    TCParser parser_;
//    CodeGenerator code_generator_;

};


#endif //TINYCOMPILER_TINY_COMPILER_H
