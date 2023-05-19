
%{
  #include <stdio.h>
  #include "parser.h"
  #include "../exceptions/parser_error.h"
  #define YYDEBUG 1
  #define CDEBUG 1
  extern char *yytext;
  extern int yylex(void);
  extern int yyparse(void);
  int yyerror(char* error);
%}


%union {
    struct AstNode* ast_node;
}

%token <ast_node> NUMBER ID STR
%token <ast_node> TYPE 
%token <ast_node> CONST STATIC SIGNED UNSIGNED RET TYPE_DEF VARGS

%token SEMI
%token STRUCT UNION ENUM DOT ARROW
%token ADD SUB MULT DIV MOD COMMA
%token LB RB
%token LOGIC_AND LOGIC_OR LOGIC_NOT 
%token BIT_OR BIT_AND BIT_XOR BIT_NOT
%token LSHIFT RSHIFT
%token LSBSCRPT RSBSCRPT
%token LSCOPE RSCOPE
%token GT LT GE LE
%token EQ NEQ
%token ASSIGN A_PLUS A_SUB A_MULT A_DIV A_MOD A_LS A_RS A_XOR A_AND A_OR
%token PP SS
%token T1 T2
%token SIZE_OF
%token IF ELSE WHILE DO FOR
%token SWITCH GOTO BREAK CASE DEFAULT CONTINUE RETURN 

%left ADD SUB
%left MULT DIV
%nonassoc "then"
%nonassoc ELSE


%type <ast_node> param_decl
%type <ast_node> init_declarator declarator direct_declarator abstract_declarator direct_abstract_declarator
%type <ast_node> type_qualifier type_qualifier_list storage_class_spec
%type <ast_node> param_type_list param_list
%type <ast_node> decl_list decl_specs init_declarator_list decl type_spec
/* %type <ast_node> stat stat_list labeled_stat exp_stat compound_stat selection_stat iteration_stat jump_stat */
%type <ast_node> initializer initializer_list
%type <ast_node> function_call args_list
%type <ast_node> unaries postfix term factor single line
%type <ast_node> pointer
%type <ast_node> type_name
%type <ast_node> expression expression1 expression2 expression3 expression4 expression5 expression6 expression7 expression8
%type <ast_node> expression9 expression10 expression11
%type <ast_node> uop aop

%start input
%%
/* program:
    | program block
    ;

block: func_delr
    | func_impl
    | glbl_var_def
    | glbl_var_assign
    ; */


input : decl_list;

/* line: var_declare           { TinyParserAppendBlock($1);}
    | func_declare          { TinyParserAppendBlock($1);}
    | typedefs              { TinyParserAppendBlock($1);}
    ; */

line: decl_list { TinyParserAppendBlock($1);};

decl_list					: decl              {printf("parser got declare"); TinyParserAppendBlock($1);}
							| decl_list decl    {addNext($1, $2);}
                            ;

decl						: decl_specs init_declarator_list SEMI { assignType($2, $1); $$ = $2; }				
							/* | decl_specs SEMI                           */
                            ;

decl_specs					: storage_class_spec decl_specs {$$ = maintainTypeSpecs($2, $1); }
							| storage_class_spec            {$$ = maintainTypeSpecs(NULL, $1); }
							| type_spec decl_specs		    {$$ = maintainTypeSpecs($2, $1);}						
							| type_spec 					{$$ = maintainTypeSpecs(NULL, $1);}					
							| type_qualifier decl_specs     {$$ = maintainTypeSpecs($2, $1);}
							| type_qualifier                {$$ = maintainTypeSpecs(NULL, $1);}
							;

storage_class_spec			: STATIC;

type_spec					: type_name ; // TOBE filled

type_qualifier              : CONST;

init_declarator_list		: init_declarator                                { $$ = $1;}
							| init_declarator_list COMMA init_declarator     { addNext($1, $3); }
							;
init_declarator				: declarator                                            {$$ = $1;}
							| declarator ASSIGN initializer                         {$$ = createBinaryTreeNode(kVarInit, $1, $3); }

declarator					: pointer direct_declarator                             {$$ = $2; addLeftMost($$, $1); }
							| direct_declarator                                     {$$ = $1;}
                            ;

direct_declarator			: ID                                                    {$$ = createVarDecl(NULL, $1); }												
							| LB declarator RB									    {$$ = $2; }
							| direct_declarator LSBSCRPT expression10 RSBSCRPT      {$$ = createArrType(NULL, $3); addLeftMost($1, $$); $$ = $1;}    			
							| direct_declarator LSBSCRPT RSBSCRPT                   {$$ = createArrType(NULL, NULL); addLeftMost($1, $$); $$ = $1;}    			                  
							| direct_declarator LB param_type_list RB               {$$ = createFuncType(NULL, $3); addLeftMost($1, $$); $$ = $1;}    			              		
							| direct_declarator LB	RB                              {$$ = createFuncType(NULL, NULL); addLeftMost($1, $$); $$ = $1;} 							    
							;

abstract_declarator			: pointer                                               {$$ = $1;}
							| pointer direct_abstract_declarator                    {$$ = $2; addLeftMost($$, $1);}
							| direct_abstract_declarator                            {$$ = $1;}
							;

direct_abstract_declarator	: LB abstract_declarator RB                                         {$$ = $2;}
							| direct_abstract_declarator LSBSCRPT expression10 RSBSCRPT         {$$ = createArrType(NULL, $3); addLeftMost($1, $$); $$ = $1; }
							| LSBSCRPT expression10 RSBSCRPT                                    {$$ = createArrType(NULL, $2); }
							| direct_abstract_declarator LSBSCRPT RSBSCRPT                      {$$ = createArrType(NULL, NULL); addLeftMost($1, $$); $$ = $1;}
							| LSBSCRPT RSBSCRPT                                                 {$$ = createArrType(NULL, NULL); }
							| direct_abstract_declarator LB param_type_list RB                  {$$ = createFuncType(NULL, $3); addLeftMost($1, $$); $$ = $1;}
							| LB param_type_list RB                                             {$$ = createFuncType(NULL, $2); }
							| direct_abstract_declarator LB RB                                  {$$ = createFuncType(NULL, NULL); addLeftMost($1, $$); $$ = $1;}
							| LB  RB                                                            {$$ = createFuncType(NULL, NULL); }
							;

param_type_list				: param_list                        {$$ = $1; }
							| param_list COMMA VARGS            {addNext($1, $3);}        
                            ;

param_list					: param_decl                        {$$ = $1;}
							| param_list COMMA param_decl       {addNext($1, $3);}
							;

param_decl					: decl_specs declarator             {assignType($2, $1); $$ = $2;}
							| decl_specs abstract_declarator    {assignType($2, $1); $$ = $2;}
							| decl_specs                        
							;

pointer						: MULT type_qualifier_list              {$$ = createPtrType($2); $$ = createFeaturedType($2, NULL);}
							| MULT                                  {$$ = createPtrType(NULL); }
							| MULT type_qualifier_list pointer      {$$ = createFeaturedType($2, $3); $$ = createPtrType($$); }
							| MULT pointer                          {$$ = createPtrType($2); }
                            ; 

type_qualifier_list			: type_qualifier
							| type_qualifier_list type_qualifier
							;


initializer					: expression11                                  {$$ = createExprTree($1); }
							| LSCOPE initializer_list RSCOPE                {$$ = createUnaryTreeNode(kInitList, $2); }
							| LSCOPE initializer_list COMMA RSCOPE          {$$ = createUnaryTreeNode(kInitList, $2); }
							;
initializer_list			: initializer                               { $$ = $1;}
							| initializer_list COMMA initializer        { addNext($1, $3); }
							;

/* stat						: labeled_stat 									      	
							| exp_stat 											  	
							| compound_stat 									  	
							| selection_stat  									  
							| iteration_stat
							| jump_stat
							;

labeled_stat				: ID T2 stat
							| CASE expression10 T2 stat
							| DEFAULT T2 stat
							;

exp_stat					: expression SEMI
							| SEMI
							;

compound_stat				: LSCOPE decl_list stat_list RSCOPE   						
							| LSCOPE stat_list RSCOPE										
							| LSCOPE decl_list	RSCOPE										
							| LSCOPE RSCOPE												
							;

stat_list					: stat              {$$ = $1;} 												
							| stat_list stat    {addNext($1, $2); }  										
							;

selection_stat				: IF LB expression RB stat 									%prec "then"
							| IF LB expression RB stat ELSE stat
							| SWITCH LB expression RB stat
							;

iteration_stat				: WHILE LB expression RB stat
							| DO stat WHILE LB expression RB SEMI
							| FOR LB expression SEMI expression SEMI expression RB stat
							| FOR LB expression SEMI expression SEMI	RB stat
							| FOR LB expression SEMI SEMI expression RB stat
							| FOR LB expression SEMI SEMI RB stat
							| FOR LB SEMI expression SEMI expression RB stat
							| FOR LB SEMI expression SEMI RB stat
							| FOR LB SEMI SEMI expression RB stat
							| FOR LB SEMI SEMI RB stat
							;

jump_stat					: GOTO ID SEMI
							| CONTINUE SEMI
							| BREAK SEMI
							| RETURN expression SEMI
							| RETURN SEMI
							; */


expression : expression11
    | expression COMMA expression11             {$$ = createBinaryOpTree(",", $1, $3); }

expression11 : expression10
    | unaries aop expression11                  {$$ = $2; addChild($$, $1); addChild($$, $3);}
    ;

expression10 : expression9
    | expression9 T1 expression T2 expression10 {$$ = createTrinaryOpTree($1, $3, $5);}
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

factor: unaries                     
    | LB type_name RB factor {$$ = createBinaryTreeNode(kCast, $2, $4); }
    ;

unaries : postfix                           
    | PP unaries                               {$$ = createUnaryOpTree("++_", $2); $$->type_ = KUAsign; }
    | SS unaries                               {$$ = createUnaryOpTree("--_", $2); $$->type_ = KUAsign; }
    | uop factor                               {$$ = $1; addChild($$, $2); }
    | SIZE_OF unaries                          {$$ = createUnaryOpTree("sizeof", $2);}
    | SIZE_OF LB type_name RB                   {$$ = createUnaryOpTree("sizeof", $3);}
    ;

postfix : single                                {$$ = $1;}
    | postfix LSBSCRPT expression RSBSCRPT      {$$ = createBinaryTreeNode(kSubScript, $1, $3); }
    | postfix DOT ID                            {$$ = createStructMember($1, $3, "."); }
    | postfix ARROW ID                          {$$ = createStructMember($1, $3, "->"); }
    | postfix PP                                {$$ = createUnaryOpTree("_++", $1); $$->type_ = KUAsign; }
    | postfix SS                                {$$ = createUnaryOpTree("_--", $1); $$->type_ = KUAsign; }
    | function_call                             {$$ = $1;}
    ;

    
single: NUMBER          {$$ = $1;}
    | STR               {$$ = $1;}
    | ID                {$$ = $1;}
    | LB expression RB  {$$ = $2;}
    ;

aop : ASSIGN {$$ = createAstNode(kAssign, "=", 1); }
    | A_AND {$$ = createAstNode(kAssign, "&", 1);}
    | A_DIV {$$ = createAstNode(kAssign, "/", 1);}
    | A_PLUS {$$ = createAstNode(kAssign, "+", 1);}
    | A_SUB {$$ = createAstNode(kAssign, "-", 1);}
    | A_MULT {$$ = createAstNode(kAssign, "*", 1);}
    | A_LS {$$ = createAstNode(kAssign, "<", 1);}
    | A_RS {$$ = createAstNode(kAssign, ">", 1);}
    | A_OR {$$ = createAstNode(kAssign, "|", 1);}
    | A_XOR {$$ = createAstNode(kAssign, "^", 1);}
    | A_MOD {$$ = createAstNode(kAssign, "%", 1);}
    ;

uop : ADD {$$ = createAstNode(kUop, "+", 1);}
    | SUB  {$$ = createAstNode(kUop, "-", 1);}
    | BIT_AND {$$ = createAstNode(kUop, "&", 1);}
    | LOGIC_NOT {$$ = createAstNode(kUop, "!", 1);}
    | BIT_NOT {$$ = createAstNode(kUop, "~", 1);}
    | MULT {$$ = createAstNode(kUop, "*", 1);}
    ;


function_call: postfix LB RB { $$ = createFunctionCallTree($1, NULL);}
    | postfix LB args_list RB {$$ = createFunctionCallTree($1, $3);}
    ;

args_list : expression {$$ = createArgList($1); }
    | args_list COMMA expression {addChild($$, $3); }
    ;

/* // TODO: implement this
f_args_plchld : arg_placeholder
    | f_args_plchld COMMA arg_placeholder {addNext($1, $3); }
    ;

arg_placeholder: CONST TYPE {$$ = createFeaturedType($1, $2); }
    | TYPE ID               {$$ = $1;}
    ; */

type_name : TYPE
    /* | ID            {$$ = $1; $$->type_ = kType; } */
    | STRUCT ID     {$$ = $2; $$->type_ = kType; }
    | ENUM ID       {$$ = $2; $$->type_ = kType; }
    | UNION ID      {$$ = $2; $$->type_ = kType;}
    ;




%%
int yyerror(char* s) {
    printf("tinyParser: \033[31merror:\033[0m %s at %s:%d:%d\n", s, TinyParserGetPwd(), TinyParserGetLine(), TinyParserGetColumn() - TinyParserGetCurTokLen());
    show_lexer_error(TinyParserGetPwd(), TinyParserGetColumn() - TinyParserGetCurTokLen(), TinyParserGetLine());
    return 1;
}

