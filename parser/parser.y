
%{
  #include <stdio.h>
  #include "parser.h"
  #include "../exceptions/parser_error.h"
  #include "../sematics/sematics.h"
  #include "../types/type_checks.h"
  #define YYDEBUG 1
  #define CDEBUG 1
  #define INT_TYPE createAstNode(kType, "int", 3)
  #define EMPTY_NODE createEmptyTreeNode()
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
%token <ast_node> CONST STATIC TYPE_DEF VARGS
%token <ast_node> GOTO BREAK CONTINUE RETURN;

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
%token SWITCH  CASE DEFAULT

%left ADD SUB
%left MULT DIV
%nonassoc "then"
%nonassoc ELSE


%type <ast_node> param_decl function_definition external_decl 
%type <ast_node> init_declarator declarator direct_declarator abstract_declarator direct_abstract_declarator
%type <ast_node> type_qualifier type_qualifier_list storage_class_spec
%type <ast_node> enum_const enumerator_list enumerator enum_spec
%type <ast_node> struct_or_union_spec struct_or_union struct_decl_list struct_declarator_list struct_decl spec_qualifier_list
%type <ast_node> struct_declarator
%type <ast_node> param_type_list param_list
%type <ast_node> decl_list decl_specs init_declarator_list decl type_spec
%type <ast_node> stat stat_list labeled_stat exp_stat compound_stat selection_stat iteration_stat jump_stat
%type <ast_node> initializer initializer_list
%type <ast_node> function_call args_list
%type <ast_node> unaries postfix term factor single program_unit translation_unit
%type <ast_node> pointer
%type <ast_node> type_name
%type <ast_node> expression expression1 expression2 expression3 expression4 expression5 expression6 expression7 expression8
%type <ast_node> expression9 expression10 expression11
%type <ast_node> uop aop

%start program_unit
%%
/* program:
    | program block
    ;

block: func_delr
    | func_impl
    | glbl_var_def
    | glbl_var_assign
    ; */


/* input : decl_list; */

/* line: var_declare           { TinyParserAppendBlock($1);}
    | func_declare          { TinyParserAppendBlock($1);}
    | typedefs              { TinyParserAppendBlock($1);}
    ; */

/* program_unit				: HEADER program_unit                               
							| DEFINE primary_exp program_unit                 	
							| translation_unit									
							; */

program_unit                : translation_unit;

translation_unit			: external_decl                     {TinyParserAppendBlock($1); } 									
							| translation_unit external_decl    {TinyParserAppendBlock($2); }					
							;
external_decl				: function_definition               {$$ = $1;}
							| decl                              {$$ = $1;}
							| TYPE_DEF decl                     {assert_valid_typedefs($2); $$ = $2;}
							;

function_definition			: decl_specs declarator	compound_stat 	            {assignType($2, $1); $$ = createBinaryTreeNode(kFuncDef, $2, $3); }			
							| declarator compound_stat                          {assignType($1, INT_TYPE); $$ = createBinaryTreeNode(kFuncDef, $1, $2); }
							;

decl_list					: decl              {$$ = $1; }
							| decl_list decl    {addNext($1, $2);}
                            ;

decl						: decl_specs init_declarator_list SEMI { assignType($2, $1); $$ = $2; }				
							| decl_specs SEMI                      {$$ = $1;}                          
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

stat						: labeled_stat 									      	
							| exp_stat 											  	
							| compound_stat 									  	
							| selection_stat  									  
							| iteration_stat
							| jump_stat
							;

labeled_stat				: ID T2 stat                    {$$ = createLabledStmt($1, $3);}                    
							| CASE expression10 T2 stat     {$$ = createBinaryTreeNode(kCase, $2, $4); }
							| DEFAULT T2 stat
							;

exp_stat					: expression SEMI               {$$ = createExprTree($1);}
							| SEMI                          
							;

compound_stat				: LSCOPE decl_list stat_list RSCOPE     {$$ = createBinaryTreeNode(kScope, $2, $3); }  						
							| LSCOPE stat_list RSCOPE               {$$ = createUnaryTreeNode(kScope, $2); }										
							| LSCOPE decl_list	RSCOPE	            {$$ = createUnaryTreeNode(kScope, $2); }									
							| LSCOPE RSCOPE                         {$$ = createUnaryTreeNode(kScope, NULL); }												
							;

stat_list					: stat              {$$ = $1;} 												
							| stat_list stat    {addNext($1, $2); }  										
							;

selection_stat				: IF LB expression RB stat 									%prec "then"    {$$ = createTrinaryTreeNode(kIfStmt, $3, $5, NULL); }
							| IF LB expression RB stat ELSE stat                                        {$$ = createTrinaryTreeNode(kIfStmt, $3, $5, $7); }
							| SWITCH LB expression RB stat                                              {$$ = createBinaryTreeNode(kSwitchStmt, $3, $5); }
							;

iteration_stat				: WHILE LB expression RB stat                                   {$$ = createBinaryTreeNode(kWhileStmt, createExprTree($3), $5); }
							| DO stat WHILE LB expression RB SEMI                           {$$ = createBinaryTreeNode(kDoWhileStmt, $2, createExprTree($5)); }                          
							| FOR LB expression SEMI expression SEMI expression RB stat     {$$ = createForStmt($3, $5, $7, $9); }
							| FOR LB expression SEMI expression SEMI	        RB stat     {$$ = createForStmt($3, $5, NULL, $8); }
							| FOR LB expression SEMI            SEMI expression RB stat     {$$ = createForStmt($3, NULL, $6, $8); }
							| FOR LB expression SEMI            SEMI            RB stat     {$$ = createForStmt($3, NULL, NULL, $7); }
							| FOR LB            SEMI expression SEMI expression RB stat     {$$ = createForStmt(NULL, $4, $6, $8); }
							| FOR LB            SEMI expression SEMI            RB stat     {$$ = createForStmt(NULL, $4, NULL, $7); }
							| FOR LB            SEMI            SEMI expression RB stat     {$$ = createForStmt(NULL, NULL, $5, $7); }
							| FOR LB            SEMI            SEMI            RB stat     {$$ = createForStmt(NULL, NULL, NULL, $6); }
							;

jump_stat					: GOTO ID SEMI                  {addChild($1, $2); $$ = $1; }
							| CONTINUE SEMI                 {$$ = $1;}
							| BREAK SEMI                    {$$ = $1;}
							| RETURN expression SEMI        {$2 = createExprTree($2); addChild($1, $2); $$ = $1; }
							| RETURN SEMI                   {$$ = $1;}
							;


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


type_name : TYPE
    /* | ID            {$$ = $1; $$->type_ = kType; } */
    | struct_or_union_spec
    | enum_spec
    ;

struct_or_union_spec		: struct_or_union ID LSCOPE struct_decl_list RSCOPE {add_hidden_type($2->val_); addChild($1, $2); addChild($1, $4); $$ = $1;}
							| struct_or_union LSCOPE struct_decl_list RSCOPE    {addChild($1, EMPTY_NODE); addChild($1, $3); $$ = $1;}    
							| struct_or_union ID                                {addChild($1, $2); addChild($1, EMPTY_NODE); $$ = $1;}                            
							;

struct_or_union				: STRUCT    {$$ = createAstNode(kStructType, NULL, 0); }
                            | UNION     {$$ = createAstNode(kUnionType, NULL, 0); }    
							;

struct_decl_list			: struct_decl                   {$$ = $1;}
							| struct_decl_list struct_decl  {addNext($1, $2); }
                            ;

struct_decl					: spec_qualifier_list struct_declarator_list SEMI   {assignType($2, $1); $$ = $2;}

spec_qualifier_list			: type_spec spec_qualifier_list                     {$$ = maintainTypeSpecs($2, $1);}
							| type_spec                                         {$$ = maintainTypeSpecs(NULL, $1); }
							| type_qualifier spec_qualifier_list                {$$ = maintainTypeSpecs($2, $1); }
							| type_qualifier                                    {$$ = maintainTypeSpecs(NULL, $1); }
							;

struct_declarator_list		: struct_declarator                                 {$$ = $1;}
							| struct_declarator_list COMMA struct_declarator    {addNext($1, $3); }  
							;

struct_declarator			: declarator
							/* | declarator ':' const_exp
							| ':' const_exp */
							;

enum_spec					: enum_const ID LSCOPE enumerator_list RSCOPE   {add_hidden_type($2->val_); $$ = createBinaryTreeNode(kEnumType, $2, $4); }
							| enum_const LSCOPE enumerator_list RSCOPE      {$$ = createBinaryTreeNode(kEnumType, NULL, $3);}
							| enum_const ID                                 {$$ = createBinaryTreeNode(kEnumType, $2, NULL); }
							;

enumerator_list				: enumerator                            {$$ = $1;}
							| enumerator_list COMMA enumerator      {addNext($1, $3); }
							;

enumerator					: ID                                    {$$ = createEnumerator($1, NULL); }
							| ID ASSIGN expression10                {$$ = createEnumerator($1, $3);}
							;

enum_const                  : ENUM { $$ = createAstNode(kEnumType, NULL, 0); }



%%
int yyerror(char* s) {
    printf("tinyParser: \033[31merror:\033[0m %s at %s:%d:%d\n", s, TinyParserGetPwd(), TinyParserGetLine(), TinyParserGetColumn() - TinyParserGetCurTokLen());
    show_lexer_error(TinyParserGetPwd(), TinyParserGetColumn() - TinyParserGetCurTokLen(), TinyParserGetLine());
    return 1;
}

