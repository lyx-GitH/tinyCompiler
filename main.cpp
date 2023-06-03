#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/raw_ostream.h"

#include "lexer/tcLexer.h"
#include "parser/tc_parser.h"
#include "code_gen/code_generator.h"


extern "C" {
#include "parser/tiny_compiler_yacc.h"
#include "lexer/tiny_compiler_lex.h"
extern int yyparse(void);
extern int yydebug;
}



int main(int argc, char **argv) {
    auto src_path = "/Users/liuyuxuan/CLionProjects/tinyCompiler/test/src.c";
    auto vis_path = "/Users/liuyuxuan/CLionProjects/tinyCompiler/test/ast.dot";
    auto obj_path = "/Users/liuyuxuan/CLionProjects/tinyCompiler/test/src.o";
    auto exe_path = "/Users/liuyuxuan/CLionProjects/tinyCompiler/test/src.out";

    yydebug = 0; // set this to 1 to enable debugging
    auto parser = CodeGenerator(src_path);
    parser.Parse();
    parser.Visualize(true, vis_path);
    parser.Generate();
    parser.PrintIR();
    std::cout << "end gen" << std::endl;
    parser.GenObjectCode(obj_path);
    return 0;
}