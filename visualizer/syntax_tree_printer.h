//
// Created by 刘宇轩 on 2023/5/15.
//

#ifndef TINYCOMPILER_SYNTAX_TREE_PRINTER_H
#define TINYCOMPILER_SYNTAX_TREE_PRINTER_H


#include <iostream>
#include <string>

extern "C" {
#include "../ast/ast.h"
};

class SyntaxTreePrinter {
public:
    explicit SyntaxTreePrinter(pAstNode root) : root_(root) {};

    void PrintTree(std::ostream &out);

private:
    void PrintTreeLow(pAstNode node, std::ostream &out);

private:
    pAstNode root_;
};


void visualize();

#endif //TINYCOMPILER_SYNTAX_TREE_PRINTER_H
