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
using namespace llvm;

//template<typename T, typename... Args> requires std::is_base_of_v<llvm::Type, T>
//class MyClass : public T {
//private:
//    bool is_const_;
//public:
//    void MarkConst() {
//        is_const_ = true;
//        return *this;
//    }
//
//    MyClass(Args &&...args) : T(std::forward<Args>(args)...), is_const_(false) {
//
//    }
//
//
//};

//template<typename T>
//requires
//std::is_base_of_v<llvm::Type, T>
//auto make_my_class(T *x)
//
//-> std::shared_ptr<MyClass<T>> {
//    return std::make_shared<MyClass<T>>(new MyClass<T>(*x));
//}

// This function tests that if your llvm is correctly configured
void llvm_test() {
    LLVMContext context;
    auto *module = new Module("my_compiler", context);
    IRBuilder<> builder(context);

    // Create a function named `add` that takes two `i32` arguments and returns an `i32` value
    FunctionType *funcType = FunctionType::get(builder.getInt32Ty(), {builder.getInt32Ty(), builder.getInt32Ty()},
                                               false);
//    auto p = make_my_class(funcType);
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

//int llvm_test2() {
//    LLVMContext Context;
//    // Create some module_ to put our function into it.
//    std::unique_ptr<Module> Owner = std::make_unique<Module>("test", Context);
//    Module *M = Owner.get();
//
//    // Create the add1 function entry and insert this entry into module_ M.  The
//    // function will have a return type of "int" and take an argument of "int".
//    Function *Add1F =
//            Function::Create(FunctionType::get(Type::getInt32Ty(Context),
//                                               {Type::getInt32Ty(Context)}, false),
//                             Function::ExternalLinkage, "add1", M);
//
//
//    // Add a basic block to the function. As before, it automatically inserts
//    // because of the last argument.
//    BasicBlock *BB = BasicBlock::Create(Context, "EntryBlock", Add1F);
//
//
//    // Create a basic block builder with default parameters.  The builder will
//    // automatically append instructions to the basic block `BB'.
//    IRBuilder<> builder(BB);
//    // Get pointers to the constant `1'.
//    Value *One = builder.getInt32(1);
//    // Get pointers to the integer argument of the add1 function...
//    assert(Add1F->arg_begin() != Add1F->arg_end()); // Make sure there's an arg
//    Argument *ArgX = &*Add1F->arg_begin();          // Get the arg
//    ArgX->setName("AnArg");            // Give it a nice symbolic name for fun.
//
//
//    // Create the add instruction, inserting it into the end of BB.
//    Value *Add = builder.CreateAdd(One, ArgX);
//    // Create the return instruction and add it to the basic block
//    builder.CreateRet(Add);
//    // Now, function add1 is ready.
//    // Now we're going to create function `foo', which returns an int and takes no
//    // arguments.
//    Function *FooF =
//            Function::Create(FunctionType::get(Type::getInt32Ty(Context), {}, false),
//                             Function::ExternalLinkage, "foo", M);
//    // Add a basic block to the FooF function.
//    BB = BasicBlock::Create(Context, "EntryBlock", FooF);
//    // Tell the basic block builder to attach itself to the new basic block
//    builder.SetInsertPoint(BB);
//    // Get pointer to the constant `10'.
//    Value *Ten = builder.getInt32(10);
//    // Pass Ten to the call to Add1F
//    CallInst *Add1CallRes = builder.CreateCall(Add1F, Ten);
//    Add1CallRes->setTailCall(true);
//    // Create the return instruction and add it to the basic block.
//    builder.CreateRet(Add1CallRes);
//
//
//    outs() << "We just constructed this LLVM module_:\n\n" << *M;
//    outs().flush();
//    std::error_code error_code;
//    std::unique_ptr<ToolOutputFile> Out(new ToolOutputFile(
//            "./test.bc", error_code, sys::fs::F_None));
//
//    if (errorCodeToError(error_code)) {
//        errs() << errorCodeToError(error_code) << '\n';
//        return -1;
//    }
//    //write bitcode
//    WriteBitcodeToFile(*M, Out->os());
//    Out->keep(); // Declare success
//    return 0;
//}





int main() {
    yydebug = 1; // set this to 1 to enable debugging
    auto parser = CodeGenerator("/Users/liuyuxuan/CLionProjects/tinyCompiler/test/expression.txt");
    parser.Parse();
    parser.Visualize(false);

    return 0;
}