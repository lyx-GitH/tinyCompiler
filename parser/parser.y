
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

%token <ast_node> NUMBER ID
%token <ast_node> TYPE TYPE_QUALI CONST
%token SEMI
%token ADD SUB MULT DIV MOD COMMA
%token LB RB
%token LOGIC_AND LOGIC_OR LOGIC_NOT 
%token BIT_OR BIT_AND BIT_XOR
%token LSHIFT RSHIFT
%token LSBSCRPT RSBSCRPT
%token LSCOPE RSCOPE
%token GT LT GE LE
%token EQ NEQ
%token ASSIGN
%token T1 T2


%left ADD SUB
%left MULT DIV
%nonassoc UMINUS UPOSITIVE BIT_NOT LOGIC_NOT

%type <ast_node> var_declare var_impl
%type <ast_node> func_declare func_delr_list func_impl
%type <ast_node> type_qualifier
%type <ast_node> left_value
%type <ast_node> init_list
%type <ast_node> function_call args_list
%type <ast_node> subscripts subscript
%type <ast_node> term factor single line
%type <ast_node> expression expression1 expression2 expression3 expression4 expression5 expression6 expression7 expression8
%type <ast_node> expression9


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
    | line
    | input line
    ;

line: var_declare SEMI  { TinyParserAppendBlock($1);}
    | var_impl SEMI     { TinyParserAppendBlock($1);}
    | func_declare      { TinyParserAppendBlock($1);}
    | func_impl         { TinyParserAppendBlock($1);}
    ;

var_declare : TYPE ID           { $$ = createBinaryTreeNode(kVarDecl, $1, $2);}
    | type_qualifier TYPE ID    { $$ = createBinaryTreeNode(kTypeQualifier, $1, $2); $$ = createBinaryTreeNode(kVarDecl, $3, $$);}
    ;

// TODO : implement this
func_declare: var_declare LB RB SEMI
    | var_declare LB func_delr_list RB SEMI
    ;

var_impl : var_declare ASSIGN expression {$$ = createBinaryTreeNode(kAssign, $1, $3); }

type_qualifier: TYPE_QUALI {$$ = $1; }
    | CONST {$$ = $1; }
    | type_qualifier TYPE_QUALI {addNext($1, $2);}
    | type_qualifier CONST {addNext($1, $2); }
    ;

expression : expression9
    | expression9 T1 expression9 T2 expression9 {$$ = createTrinaryOpTree($1, $3, $5);}
    ;

expression9 : expression8
    | expression9 LOGIC_OR expression8 { $$ = createBinaryOpTree("||", $1, $3);}
    ;

expression8 : expression7
    | expression8 LOGIC_AND expression7 { $$ = createBinaryOpTree("&&", $1, $3);}
    ;

expression7 : expression6
    | expression7 BIT_OR expression6 { $$ = createBinaryOpTree("|", $1, $3);}
    ;

expression6 : expression5
    | expression6 BIT_XOR expression5 { $$ = createBinaryOpTree("^", $1, $3);}
    ;

expression5 : expression4
    | expression5 BIT_AND expression4 { $$ = createBinaryOpTree("&", $1, $3);}
    ;

expression4 : expression3
    | expression4 EQ expression3 { $$ = createBinaryOpTree("==", $1, $3);}
    | expression4 NEQ expression3 { $$ = createBinaryOpTree("!=", $1, $3);}
    ;

expression3 : expression2
    | expression3 GT expression2 { $$ = createBinaryOpTree(">", $1, $3);}
    | expression3 LT expression2 { $$ = createBinaryOpTree("<", $1, $3);}
    | expression3 GE expression2 { $$ = createBinaryOpTree(">=", $1, $3);}
    | expression3 LE expression2 { $$ = createBinaryOpTree("<=", $1, $3);}
    ;

expression2 : expression1
    | expression2 LSHIFT expression1 { $$ = createBinaryOpTree("<<", $1, $3);}
    | expression2 RSHIFT expression1 { $$ = createBinaryOpTree(">>", $1, $3);}
    ;

expression1: term
    | expression1 ADD term { $$ = createBinaryOpTree("+", $1, $3);}
    | expression1 SUB term { $$ = createBinaryOpTree("-", $1, $3);}
    ;

term: factor
    | term MULT factor  { $$ = createBinaryOpTree("*", $1, $3);}
    | term DIV factor   { $$ = createBinaryOpTree("/", $1, $3);}
    | term MOD factor   { $$ = createBinaryOpTree("%", $1, $3);}
    ;

factor: single          { $$ = $1; }
    | single subscripts {$$ = createBinaryTreeNode(kSubScript, $1, $2);}
    ;

single: NUMBER
    | function_call                     { $$ = $1;}
    | left_value                        { $$ = $1;}
    | LB expression RB                  { $$ = $2;}
    | SUB single %prec UMINUS           { $$ = createUnaryOpTree("-", $2);}
    | ADD single %prec UPOSITIVE        { $$ = createUnaryOpTree("+", $2);}
    | LOGIC_NOT single %prec LOGIC_NOT  { $$ = createUnaryOpTree("!", $2);}
    | BIT_NOT single %prec BIT_NOT      { $$ = createUnaryOpTree("~", $2);}
    ;

subscripts: subscript {$$ = $1; }
    | subscripts subscript {addNext($1, $2);}
    ;

subscript : LSBSCRPT expression RSBSCRPT {$$ = createExprTree($2);};

function_call: ID LB RB { $$ = createFunctionCallTree($1, NULL);}
    | ID LB args_list RB {$$ = createFunctionCallTree($1, $3);}
    ;

args_list : expression {$$ = createArgList($1); }
    | args_list COMMA expression {addChild($$, $3); }
    ;

// TODO: implement this
func_delr_list : TYPE ID
    | CONST TYPE ID
    | func_delr_list COMMA TYPE ID
    | func_delr_list COMMA CONST TYPE ID
    ;

left_value: ID { $$ = $1;}
    ;

init_list: LSCOPE RSCOPE
    | LSCOPE args_list RSCOPE
    ;

%%
int yyerror(char* s) {
    fprintf(stderr, "Error: %s at %s\n", s, yytext);
    return 1;
}

