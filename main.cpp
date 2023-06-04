#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/raw_ostream.h"

#include "lexer/tcLexer.h"
#include "parser/tc_parser.h"
#include "code_gen/code_generator.h"
#include "compiler/tiny_compiler.h"


extern "C" {
#include "parser/tiny_compiler_yacc.h"
#include "lexer/tiny_compiler_lex.h"
extern int yyparse(void);
extern int yydebug;
}



int main(int argc, char **argv) {
    TinyCompiler tinyCompiler(argc, argv);
    tinyCompiler.Config();
    tinyCompiler.Run();

    return 0;
}