//
// Created by 刘宇轩 on 2023/5/15.
//

#include "TCParser.h"
#include <fstream>
#include <iostream>

void TCParser::parse() {
    TinyParserBegin();
    TinyParserParse(file_path_.c_str());
    ast_root_ = TinyParserGetRoot();
    assert(ast_root_ != nullptr);
}

void TCParser::visualize(bool to_file, const std::string &out_file_path) {
    if(!ast_root_)
        return;
    auto printer = SyntaxTreePrinter(ast_root_);
    if(!to_file)
        printer.PrintTree(std::cout);
    else{
        auto fs = std::ofstream{file_path_};
        printer.PrintTree(static_cast<std::ostream&>(fs));
    }
}
