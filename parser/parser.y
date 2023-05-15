
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
%token  ADD SUB MULT DIV LB RB US CR
%token LOGIC_AND LOGIC_OR LOGIC_NOT BIT_OR BIT_AND BIT_XOR

%left ADD SUB
%left MULT DIV
%nonassoc UMINUS BIT_NOT LOGIC_NOT

%type <ast_node> expression term factor line program block
%type <asi_node> func_delr func_impl glbl_var_def glbl_var_assign scope


%%
/* program:
    | program block
    ;

block: func_delr
    | func_impl
    | glbl_var_def
    | glbl_var_assign
    ; */


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


factor: NUMBER
    | LB expression RB { $$ = $2; }
    | SUB factor %prec UMINUS { $$ = createUnaryOpTree("-", $2);}
    | LOGIC_NOT factor %prec LOGIC_NOT {printf("LOGIC NOT\n");$$ = createUnaryOpTree("!", $2);}
    | BIT_NOT factor %prec BIT_NOT {printf("BIT NOT\n"); $$ = createUnaryOpTree("~", $2);}
    | US { $$ = initAstNode(); }
    ;


%%
int yyerror(char* s) {
    fprintf(stderr, "Error: %s at %d, %d\n", s, yytext);
    return 1;
}

