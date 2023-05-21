cmake_minimum_required(VERSION 3.4.3)
project(tinyCompiler)

find_package(LLVM REQUIRED CONFIG)

# Set your project compile flags.
# E.g. if using the C++ header files
# you will need to enable C++11 support
# for your compiler.

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Now build our tools
add_executable(tinyCompiler main.cpp ast/ast.h lexer/tokens.h lexer/base_lexer.h lexer/base_lexer.cpp lexer/tcLexer.cpp lexer/tcLexer.h code_gen/CodeGenerator.cpp code_gen/CodeGenerator.h ast/ast_node_type.h ast/ast.c parser/parser.h parser/parser.c visualizer/syntax_tree_printer.cpp visualizer/syntax_tree_printer.h parser/TCParser.cpp parser/TCParser.h
        parser/tiny_compiler_yacc.c parser/tiny_compiler_yacc.h lexer/tiny_compiler_lex.c lexer/tiny_compiler_lex.h exceptions/parser_error.h exceptions/parser_error.cpp types/type.cpp types/type.h types/type_checks.h types/type_checks.cpp)

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)

# Link against LLVM libraries
target_link_libraries(tinyCompiler ${llvm_libs})

add_custom_command(
        TARGET tinyCompiler
        POST_BUILD
        COMMAND pwd
)