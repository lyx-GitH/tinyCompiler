//
// Created by 刘宇轩 on 2023/5/15.
//

#include "TCParser.h"
#include <fstream>
#include <iostream>


void TCParser::parse() {
    TinyParserSetRoot(createAstNode(kRoot, nullptr, 0));
    TinyParserBegin();
    try{
        TinyParserParse(file_path_.c_str());
    } catch(std::runtime_error& e) {
        std::printf("\033[31m failed \033[0m\n");
        TinyParserEnd();
        is_ok_ = false;
        return;
    }
    is_ok_ = true;
    ast_root_ = TinyParserGetRoot();
    std::printf("\033[32m done \033[0m\n");
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

pAstNode TCParser::getSyntaxTree() {
    return ast_root_;
}

pAstNode TCParser::releaseSyntaxTree() {
    auto ptr = ast_root_;
    ast_root_ = nullptr;
    return ptr;
}
