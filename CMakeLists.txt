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
add_executable(tinyCompiler main.cpp ast/ast.h lexer/tokens.h lexer/base_lexer.h lexer/base_lexer.cpp lexer/tcLexer.cpp lexer/tcLexer.h code_gen/CodeGenerator.cpp code_gen/CodeGenerator.h ast/ast_node_type.h ast/ast.c parser/parser.h parser/parser.c visualizer/syntax_tree_printer.cpp visualizer/syntax_tree_printer.h parser/TCParser.cpp parser/TCParser.h
        parser/tiny_compiler_yacc.c parser/tiny_compiler_yacc.h lexer/tiny_compiler_lex.c lexer/tiny_compiler_lex.h exceptions/parser_error.h exceptions/parser_error.cpp exceptions/parse_exception.h exceptions/parse_exception.cpp types/type.cpp types/type.h types/type_checks.h types/type_checks.cpp sematics/sematics.h sematics/sematics.cpp code_gen/Symbol.h)

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

