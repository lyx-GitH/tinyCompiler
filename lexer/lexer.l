%{
    #define MOVE TinyParserMove(yylineno, yytext)
    #include <stdio.h>
    #include "../ast/ast.h"
    #include "../parser/parser.h"
    #include "../parser/tiny_compiler_yacc.h"
    extern YYSTYPE yylval;
%}

%option yylineno
%option noyywrap


NUM 0|[1-9]+[0-9]*|[1-9]+[0-9]*"."[0-9]*|"."[0-9]+

%%
{NUM} {
    MOVE;
    yylval.ast_node = createAstNode(kNumber, yytext, yyleng);
    return NUMBER;}
"+" {MOVE; return ADD;};
"-" {MOVE; return SUB;};
"*" {MOVE; return MULT;};
"/" {MOVE; return DIV;};
"(" {MOVE; return LB;};
")" {MOVE; return RB;};
"_" {MOVE; return US;};
"\n" {MOVE; return CR;};
"!" {MOVE; return LOGIC_NOT;};
"||" {MOVE; return LOGIC_OR;};
"&&" {MOVE; return LOGIC_AND;};

"~" {MOVE; return BIT_NOT;};
"|" {MOVE; return BIT_OR;};
"&" {MOVE; return BIT_AND;};
"^" {MOVE; return BIT_XOR;};

"\t" {MOVE;};
.

%%

