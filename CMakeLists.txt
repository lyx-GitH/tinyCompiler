cmake_minimum_required(VERSION 3.4.3)

file(RELATIVE_PATH project_name ${CMAKE_CURRENT_LIST_DIR}/.. ${CMAKE_CURRENT_LIST_DIR})

project(${project_name})

find_package(LLVM REQUIRED CONFIG)

set(CMAKE_CXX_STANDARD 20)

find_package(LLVM REQUIRED CONFIG)
llvm_map_components_to_libnames(LLVM_LIBS core executionengine interpreter mc support nativecodegen)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Now build our tools

# Now build our tools
add_executable(tinyCompiler main.cpp ast/ast.h lexer/tokens.h  lexer/tcLexer.cpp lexer/tcLexer.h code_gen/code_generator.cpp code_gen/code_generator.h ast/ast_node_type.h ast/ast.c parser/parser.h parser/parser.c visualizer/syntax_tree_printer.cpp visualizer/syntax_tree_printer.h parser/tc_parser.cpp parser/tc_parser.h
        parser/tiny_compiler_yacc.c parser/tiny_compiler_yacc.h lexer/tiny_compiler_lex.c lexer/tiny_compiler_lex.h exceptions/parser_error.h exceptions/parser_error.cpp exceptions/parse_exception.h exceptions/parse_exception.cpp types/type_factory.cpp types/type_factory.h types/type_checks.h types/type_checks.cpp static_semantics/sematics.h static_semantics/sematics.cpp code_gen/symbol.h compiler/tiny_compiler.cpp compiler/tiny_compiler.h preprocessor/tc_preprocessor.cpp preprocessor/tc_preprocessor.h types/type_casting.h types/type_casting.cpp code_gen/code_gen_casting.cpp preprocessor/tiny_compiler_prepo.c preprocessor/tiny_compiler_prepo.h preprocessor/preprocessor.h  code_gen/code_gen_expr.cpp code_gen/init_list.h code_gen/code_gen_init_list.cpp)

# God, this part is so ridiculous
foreach (target ${LLVM_TARGETS_TO_BUILD})
    list(APPEND targets "LLVM${target}CodeGen")
endforeach ()

set(ARCH_POSTFIXES AArch64 AMDGPU ARM AVR BPF MSP430 Mips PowerPC RISCV Sparc SystemZ VE WebAssembly X86)
foreach (POSTFIX IN LISTS ARCH_POSTFIXES)
    list(APPEND targets "LLVM${POSTFIX}AsmParser")
endforeach ()


# This part cause trouble, throw it away!
#foreach(target ${LLVM_TARGETS_TO_BUILD})
#    list(APPEND targets "LLVM${target}AsmParser")
#endforeach()


target_link_libraries(tinyCompiler LLVMInterpreter LLVMMCJIT)

target_link_libraries(tinyCompiler ${llvm_libraries} ${targets})

