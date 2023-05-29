//
// Created by 刘宇轩 on 2023/5/23.
//

#include "tc_preprocessor.h"
#include "tiny_compiler_prepo.h"
#include <libgen.h>
#include <filesystem>
#include <iostream>

extern "C" {
#include "preprocessor.h"
}

std::list<std::string> TCPreProcessor::include_chain{};
std::string TCPreProcessor::base_path{};

void add_include_path(const char *path, char mode, int len) {
    auto pos = strchr(path, mode);
    assert(pos != nullptr);
    int file_len = len - (pos - path) - 2;
    auto file_path = std::string(pos + 1, file_len);
    TCPreProcessor::GenIncludeChain(file_path);
}

const std::list<std::string> &TCPreProcessor::GetIncludeChain() {
    return TCPreProcessor::include_chain;
}

extern FILE *p_yyin;
extern FILE *p_yyout;

extern int p_yylex(void);

static int level = 0;

inline void add_level() {
    ++level;
    if (level == 1) {
        p_yyout = fopen("/dev/null", "w");
    }

}

inline void sub_level() {
    --level;
    if (level == 0) {
        fclose(p_yyout);
    }
}


void TCPreProcessor::GenIncludeChain(const std::string &path) {
//
    auto abs_path = absolute(std::filesystem::path(path));
    if (!std::filesystem::exists(abs_path) || std::filesystem::is_directory(abs_path))
        throw std::runtime_error("invalid path: " + path);

    include_chain.push_front(abs_path.string());
    std::printf("\033[32m[include file] %s \033[0m\n", abs_path.c_str());

    auto dir = abs_path.parent_path();
    chdir(dir.c_str());

    FILE *old_yyin = p_yyin;
    FILE *f = fopen(path.c_str(), "r");
    if (!f) {
        fprintf(stderr, "cannot open file:  %s\n", path.c_str());
    }
    p_yyin = f;

    add_level();
    p_yylex();
    sub_level();

    fclose(p_yyin);
    p_yyin = old_yyin;
    chdir(dir.c_str());

}