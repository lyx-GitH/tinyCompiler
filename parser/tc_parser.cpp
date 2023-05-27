//
// Created by 刘宇轩 on 2023/5/15.
//

#include "tc_parser.h"
#include <fstream>
#include <iostream>

#include "../exceptions/parse_exception.h"
#include "../preprocessor/tc_preprocessor.h"

void TCParser::Parse() {
    TinyParserSetRoot(createAstNode(kRoot, nullptr, 0));
    TCPreProcessor::GenIncludeChain(file_path_);
    for(const auto& file : TCPreProcessor::GetIncludeChain()){
        TinyParserBegin();
        try {
            TinyParserParse(file.c_str());
        } catch (ParseException &e) {
            std::printf("\033[31mfailed \033[0m");
            e.show();
            TinyParserEnd();
            is_ok_ = false;
            return;
        } catch (std::runtime_error &e) {
            // do nothing
        }
        is_ok_ = true;
//        ast_root_ = TinyParserGetRoot();
        auto root = TinyParserMoveRoot();
        if(!ast_root_) {
            ast_root_ = root;
        } else {
            merge(ast_root_, root);
        }
    }
    std::printf("\033[32m done \033[0m\n");
    assert(ast_root_ != nullptr);
}

void TCParser::Visualize(bool to_file, const std::string &out_file_path) {
    if (!ast_root_)
        return;
    auto printer = SyntaxTreePrinter(ast_root_);
    if (!to_file)
        printer.PrintTree(std::cout);
    else {
        auto fs = std::ofstream{file_path_};
        printer.PrintTree(static_cast<std::ostream &>(fs));
    }
}

pAstNode TCParser::getSyntaxTree() const {
    return ast_root_;
}

pAstNode TCParser::releaseSyntaxTree() {
    auto ptr = ast_root_;
    ast_root_ = nullptr;
    return ptr;
}
