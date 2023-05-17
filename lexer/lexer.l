%{
    #define MOVE TinyParserMove(yylineno, yytext)
    #define NODE(t)  yylval.ast_node = createAstNode(t, yytext, yyleng)
    #include <stdio.h>
    #include "../ast/ast.h"
    #include "../parser/parser.h"
    #include "../parser/tiny_compiler_yacc.h"

    extern YYSTYPE yylval;
%}

%option yylineno
%option noyywrap


DEM_NUM 0|[1-9]+[0-9]*
OCT_NUM 0[0-7]+
HEX_NUM 0[xX][0-9a-fA-F]+
FLT_NUM [0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?

LITERAL [a-zA-Z_]
DIGIT [0-9]
ID_C {LITERAL}|{DIGIT}
ID {LITERAL}+{ID_C}*



%%
"char"|"short"|"int"|"long"|"float"|"double" {
    MOVE;
    NODE(kType);
    return TYPE;
}

"static"|"signed" {
    MOVE;
    NODE(kTypeQualifier);
    return TYPE_QUALI;
}

"const" {
    MOVE;
    NODE(kTypeQualifier);
    return CONST;
}


{DEM_NUM} {
    MOVE;
    NODE(kDemNumber);
    return NUMBER;
}

{OCT_NUM} {
    MOVE;
    NODE(kOctNumber);
    return NUMBER;
}

{HEX_NUM} {
    MOVE;
    NODE(kHexNumber);
    return NUMBER;
}

{FLT_NUM} {
    MOVE;
    yylval.ast_node = createAstNode(kFloatNumber, yytext, yyleng);
    return NUMBER;
}

{ID} {
    MOVE;
    yylval.ast_node = createAstNode(kId, yytext, yyleng);
    return ID;
}

";" {MOVE; return SEMI;}

"=" {MOVE; return ASSIGN;};

"(" {MOVE; return LB;};
")" {MOVE; return RB;};

"[" {MOVE; return LSBSCRPT;};
"]" {MOVE; return RSBSCRPT;};

"{" {MOVE; return LSCOPE;};
"}" {MOVE; return RSCOPE;};

"+" {MOVE; return ADD;};
"-" {MOVE; return SUB;};
"*" {MOVE; return MULT;};
"/" {MOVE; return DIV;};
"%" {MOVE; return MOD;};

"<<" {MOVE; return LSHIFT;};
">>" {MOVE; return RSHIFT;};

">" {MOVE; return GT;};
"<" {MOVE; return LT;};
">=" {MOVE; return GE;};
"<=" {MOVE; return LE;};

"==" {MOVE; return EQ;};
"!=" {MOVE; return NEQ;};

"," {MOVE; return COMMA;};


"!" {MOVE; return LOGIC_NOT;};
"||" {MOVE; return LOGIC_OR;};
"&&" {MOVE; return LOGIC_AND;};

"~" {MOVE; return BIT_NOT;};
"|" {MOVE; return BIT_OR;};
"&" {MOVE; return BIT_AND;};
"^" {MOVE; return BIT_XOR;};

"?" {MOVE; return T1;};
":" {MOVE; return T2;};

"\n" {MOVE;};
"\t" {MOVE;};
.

%%

