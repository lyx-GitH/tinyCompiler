//
// Created by 刘宇轩 on 2023/5/22.
//

#ifndef TINYCOMPILER_TINY_COMPILER_H
#define TINYCOMPILER_TINY_COMPILER_H

#include <string>
#include "../parser/tc_parser.h"
#include "../code_gen/code_generator.h"

class TinyCompiler {
public:
    TinyCompiler(int argc, char** argv) : argc_(argc), argv_(argv) {}

    void Run();

    void Config();


    [[nodiscard]] auto &GetConfig() {
        return config;
    }

private:
    struct {
        bool dump_ir{};
        std::string ir_path{};
        bool visualize_ast{};
        std::string ast_path{};

        std::string src_path{};
        std::string obj_path{};

        bool opt{};
        std::string opt_level{};

    } config;
    void PrintArgInfo();
    std::pair<bool, std::string> TryGetArg(std::map<std::string, int>& args_info, const char* arg_name, const char* default_value);
    std::string FindOptLevel(std::map<std::string, int>& args_info);
    int argc_;
    char** argv_;


};


#endif //TINYCOMPILER_TINY_COMPILER_H
