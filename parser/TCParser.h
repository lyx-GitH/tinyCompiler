//
// Created by 刘宇轩 on 2023/5/15.
//

#ifndef TINYCOMPILER_TCPARSER_H
#define TINYCOMPILER_TCPARSER_H

#include <utility>

extern "C" {
#include "parser.h"
#include "../ast/ast.h"
};

#include "../visualizer/syntax_tree_printer.h"


class TCParser {
public:
    TCParser(std::string file_path) : file_path_(std::move(file_path)), ast_root_{nullptr} {}

    void parse();

    void visualize(bool to_file = false, const std::string &out_file_path = "");

    ~TCParser() { freeAstNode(ast_root_); }

private:
    std::string file_path_;
    pAstNode ast_root_;

};



#endif //TINYCOMPILER_TCPARSER_H
