//
// Created by 刘宇轩 on 2023/5/23.
//

#ifndef TINYCOMPILER_TC_PREPROCESSOR_H
#define TINYCOMPILER_TC_PREPROCESSOR_H

#include <list>
#include <string>
#include <cstdio>

extern "C" {
#include "tiny_compiler_prepo.h"
}

class TCPreProcessor {
public:

    static void GenIncludeChain(const std::string &path);

    static const std::list<std::string> &GetIncludeChain();

private:
    static std::list<std::string> include_chain;
    static std::string base_path;

};


#endif //TINYCOMPILER_TC_PREPROCESSOR_H
