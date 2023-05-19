cd ./lexer || exit 1
lex --header-file=./tiny_compiler_lex.h --outfile=./tiny_compiler_lex.c ./lexer.l
cd ../parser || exit 1
bison -d -o   ./tiny_compiler_yacc.c parser.y --verbose --debug
cd ..