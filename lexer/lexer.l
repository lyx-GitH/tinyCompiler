%{
    #define MOVE TinyParserMove(yylineno, yytext)
    #define NODE(t)  yylval.ast_node = createAstNode(t, yytext, yyleng)
    #include <stdio.h>
    #include "../ast/ast.h"
    #include "../types/type_checks.h"
    #include "../parser/parser.h"
    #include "../parser/tiny_compiler_yacc.h"

    extern YYSTYPE yylval;
    extern int yychar;

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

"#include"([ ]+)?((<(\\.|[^>])+>)|(\"(\\.|[^"])+\"))	{
    /*This part has been pre-processed by TCPreProcessor*/
    MOVE;
}

";" {MOVE; return SEMI;}

"char"|"short"|"int"|"long"|"float"|"double"|"void"|"signed"|"unsigned" {
    printf("get type: %s\n", yytext);
    MOVE;
    NODE(kType);
    return TYPE;
}

"const" {
    printf("get const\n");
    MOVE;
    NODE(kTypeQualifier);
    return CONST;
}

"static" {
    MOVE;
    NODE(kTypeQualifier);
    return STATIC;
}

"struct" {
    MOVE;
    return STRUCT;
}

"enum" {
    MOVE;
    return ENUM;
}

"union" {
    MOVE;
    return UNION;
}

"sizeof" {
    MOVE;
    return SIZE_OF;
}

"typedef" {
    MOVE; 
    return TYPE_DEF;
}

"if"    {MOVE; return IF;}
"else"  {MOVE; return ELSE;}

"for"   {MOVE; return FOR;}
"while" {MOVE; return WHILE;}
"do"    {MOVE; return DO; }

"switch"    {MOVE; return SWITCH; }
"case"      {MOVE; return CASE;}
"defualt"   {MOVE; return DEFAULT; }

"goto"      {MOVE; NODE(kJump); return GOTO;}
"break"     {MOVE; NODE(kJump); return BREAK;}
"continue"  {MOVE; NODE(kJump); return CONTINUE;}

"..." {MOVE; NODE(kVargs); return VARGS; }
"return" {MOVE; NODE(kJump); return RETURN;}



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
    NODE(kFloatNumber);
    return NUMBER;
}

{ID} {
    
    MOVE;
    // ID can be a type-alias
    if(has_type(yytext)){
        NODE(kType);
        return TYPE;
    } else {
        NODE(kId);
        return ID;
    }
        
}





"\." {MOVE; return DOT;}
"->" {MOVE; return ARROW;}




"=" { MOVE; return ASSIGN;};
"+=" {MOVE; return A_PLUS;};
"-=" {MOVE; return A_SUB;};
"*=" {MOVE; return A_MULT;};
"/=" {MOVE; return A_DIV;};
"%=" {MOVE; return A_MOD;};
"<<=" {MOVE; return A_LS;};
">>=" {MOVE; return A_RS;};
"|=" {MOVE; return A_OR;};
"&=" {MOVE; return A_AND;};
"^=" {MOVE; return A_XOR;};

"(" {MOVE; return LB;};
")" {MOVE; return RB;};

"++" {MOVE; return PP;};
"--" {MOVE; return SS; }

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

"//"(\\.|[^\n])*[\n]																						{MOVE;};
[/][*]([^*]|[*]*[^*/])*[*]+[/]                                                                              {MOVE;};
"\""(\\.|[^"\\])*"\""																						{MOVE; NODE(kStrLiteral); return STR; }
"'"."'"                                                                                                     {MOVE; NODE(kCharLiteral); return NUMBER;}
. {MOVE;};

%%

