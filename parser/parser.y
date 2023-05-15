
%{
  #include <stdio.h>
  #include "parser.h"

  extern char *yytext;
  extern int yylex(void);
  extern int yyparse(void);
  int yyerror(char* error);
%}

%union {
    struct AstNode* ast_node;
}

%token <ast_node> NUMBER
%token  ADD SUB MULT DIV EXPO LB RB US CR

%left ADD SUB
%left MULT DIV
%right EXPO
%nonassoc UMINUS

%type <ast_node> expression term factor single line

%%
input:
    | input line
    ;

line: CR
    | expression CR {$$ = createExprTree($1); TinyParserAppendBlock($$); }
    ;

expression: term
    | expression ADD term { $$ = createBinaryOpTree("+", $1, $3);}
    | expression SUB term { $$ = createBinaryOpTree("-", $1, $3);}
    ;

term: factor
    | term MULT factor { $$ = createBinaryOpTree("*", $1, $3); }
    | term DIV factor { $$ = createBinaryOpTree("/", $1, $3);}
    ;

factor: single
    | factor EXPO factor { $$ = createBinaryOpTree("exp", $1, $3);}
    ;

single: NUMBER
    | LB expression RB { $$ = $2; }
    | SUB single %prec UMINUS { $$ = createUnaryOpTree("-", $2);}
    | US { $$ = initAstNode(); }
    ;


%%
int yyerror(char* s) {
    fprintf(stderr, "Error: %s at %d, %d\n", s, yytext);
    return 1;
}

