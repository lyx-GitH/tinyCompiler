//
// Created by 刘宇轩 on 2023/5/10.
//

#include "tcLexer.h"

void TCLexer::parse() {
//    if (!std::filesystem::exists(file_path_)) {
//        throw std::runtime_error("tcLexer: file " + file_path_ + " does not exist");
//    }
//    std::ifstream ifstream{file_path_};
//    auto lexer = yyFlexLexer{&ifstream};
//    while (int res = lexer.yylex()) {
//        parsedTokenStream.emplace_back(static_cast<Token>(res), std::string{lexer.YYText(), lexer.YYLeng()});
//    }
}

const std::string &TCLexer::getFilePath() const {
    return file_path_;
}

const TCLexer::ParsedTokenStream &TCLexer::getParsedTokenStream() const {
    return parsedTokenStream;
}
