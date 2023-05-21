#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/raw_ostream.h"

#include "lexer/tcLexer.h"
#include "parser/TCParser.h"


extern "C" {
#include "parser/tiny_compiler_yacc.h"
#include "lexer/tiny_compiler_lex.h"
int yyparse(void);
extern int yydebug;
}
using namespace llvm;

// This function tests that if your llvm is correctly configured
void llvm_test() {
    LLVMContext context;
    Module *module = new Module("my_compiler", context);
    IRBuilder<> builder(context);

    // Create a function named `add` that takes two `i32` arguments and returns an `i32` value
    FunctionType *funcType = FunctionType::get(builder.getInt32Ty(), {builder.getInt32Ty(), builder.getInt32Ty()},
                                               false);
    Function *addFunc = Function::Create(funcType, Function::ExternalLinkage, "add", module);

    // Set names for the function arguments
    Function::arg_iterator args = addFunc->arg_begin();
    Value *x = args++;
    x->setName("x");
    Value *y = args++;
    y->setName("y");

    // Create a basic block and set the insertion point to the end of the block
    BasicBlock *block = BasicBlock::Create(context, "entry", addFunc);
    builder.SetInsertPoint(block);

    // Generate IR code for the function body
    Value *sum = builder.CreateAdd(x, y, "sum");
    builder.CreateRet(sum);

    // Print the generated IR code
    module->print(outs(), nullptr);
    delete module;
}


int main() {
    yydebug = 0;
    auto parser = TCParser("/Users/liuyuxuan/CLionProjects/tinyCompiler/test/expression.txt");
    parser.parse();
    parser.visualize(false);
    return 0;
}