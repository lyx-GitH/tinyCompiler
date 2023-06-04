//
// Created by 刘宇轩 on 2023/5/22.
//

#include "tiny_compiler.h"

inline std::string SafeToString(char *s) {
    return s == nullptr ? "" : std::string{s};
}

inline std::string GetNextArg(int argc, char **argv, int idx) {
    if (idx >= argc)
        return {};
    else {
        auto next_arg = SafeToString(argv[idx + 1]);
        return next_arg.starts_with('-') ? "" : next_arg;
    }
}

std::pair<bool, std::string>
TinyCompiler::TryGetArg(std::map<std::string, int> &args_info, const char *arg_name, const char *default_value) {
    auto arg_idx = args_info.find(arg_name);
    bool found = false;
    std::string arg_path{};
    if (arg_idx != args_info.end()) {
        found = true;
        arg_path = GetNextArg(argc_, argv_, arg_idx->second);
        if (arg_path.empty())
            arg_path = default_value;

        args_info.erase(arg_path);
        args_info.erase(arg_name);
        arg_path = std::filesystem::absolute(arg_path);
    }
    return {found, arg_path};

}

void TinyCompiler::Config() {
    if (argc_ <= 1)
        PrintArgInfo();
    std::map<std::string, int> args_info;
    for (int i = 1; i < argc_; i++)
        args_info[argv_[i]] = i;

    auto vis_info = TryGetArg(args_info, "-v", "ast.dot");
    config.visualize_ast = vis_info.first;
    config.ast_path = vis_info.second;

    auto ir_info = TryGetArg(args_info, "-l", "a.ll");
    config.dump_ir = ir_info.first;
    config.ir_path = ir_info.second;

    auto obj_info = TryGetArg(args_info, "-o", "a.o");
    config.obj_path = obj_info.first ? obj_info.second : "a.o";

    config.opt_level = FindOptLevel(args_info);
    config.opt = !config.opt_level.empty();
    if (args_info.size() > 1) {
        std::cout << "unrecognized argument pattern!" << std::endl;
        for (const auto &arg: args_info) {
            std::cout << arg.first << std::endl;
        }
        exit(0);
    } else if (args_info.empty()) {
        std::cout << "requires a source file path!" << std::endl;
        exit(0);
    } else {
        for (const auto &arg: args_info)
            config.src_path = arg.first;
    }
}

void TinyCompiler::Run() {
    auto parser = CodeGenerator(config.src_path);
    parser.Parse();

    if (config.visualize_ast)
        parser.Visualize(true, config.ast_path);


    parser.Generate();
    if (config.opt)
        parser.Optimize(config.opt_level);

    if (config.dump_ir)
        parser.DumpIR(config.ir_path);

    std::cout << "end gen" << std::endl;

    parser.GenObjectCode(config.obj_path);
}

void TinyCompiler::PrintArgInfo() {
    const static char *info =
            "TinyCompiler:\n"
            "usage: TinyCompiler <src_file_name> [-l <?IR_file_name>] [-v <?ast_vis_file_name>] [-o <?obj_file_name>] -[OptLevel]";
    std::cout << info << std::endl;
    exit(0);
}

std::string TinyCompiler::FindOptLevel(std::map<std::string, int> &args_info) {
    std::string opt_level{};
    for (const auto &it: args_info) {
        if (it.first.starts_with("-O")) {
            opt_level = it.first;
        }
    }
    args_info.erase(opt_level);
    return opt_level;
}

