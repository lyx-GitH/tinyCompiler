//
// Created by 刘宇轩 on 2023/5/10.
//

#ifndef TINYCOMPILER_TCLEXER_H
#define TINYCOMPILER_TCLEXER_H

#include "base_lexer.h"
#include "tokens.h"
#include <string>
#include <fstream>
#include <vector>
#include <tuple>
#include <filesystem>


class TCLexer {
public:
    using ParsedTokenStream = std::vector<std::tuple<Token, std::string>>;

    TCLexer(std::string file_path) : file_path_{std::move(file_path)} {}

    void parse();

    [[nodiscard]] const std::string &getFilePath() const;

    [[nodiscard]] const ParsedTokenStream &getParsedTokenStream() const;


private:
    std::string file_path_;
    ParsedTokenStream parsedTokenStream;
};


#endif //TINYCOMPILER_TCLEXER_H
