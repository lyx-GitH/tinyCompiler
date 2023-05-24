//
// Created by 刘宇轩 on 2023/5/15.
//

#ifndef TINYCOMPILER_TC_PARSER_H
#define TINYCOMPILER_TC_PARSER_H

#include <utility>

extern "C" {
#include "parser.h"
#include "../ast/ast.h"
};

#include "../visualizer/syntax_tree_printer.h"


class TCParser {
public:
    explicit TCParser(std::string file_path) : file_path_(std::move(file_path)), ast_root_{nullptr}, is_ok_{false} {}
    ~TCParser() { freeAstNode(ast_root_); }

    void Parse();

    void Visualize(bool to_file = false, const std::string &out_file_path = "");

    [[nodiscard]] pAstNode getSyntaxTree() const;

    pAstNode releaseSyntaxTree();



    [[nodiscard]] bool isParseOK() const{
        return is_ok_;
    }

protected:
    bool is_ok_;
    std::string file_path_;
    pAstNode ast_root_;

};


#endif //TINYCOMPILER_TC_PARSER_H
