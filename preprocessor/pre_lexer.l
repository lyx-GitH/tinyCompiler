%{
    #include <stdio.h>
    #include "preprocessor.h"
    extern char *yytext;
    extern int yylex(void);
    extern void preprocess_run();

%}
%option yylineno
%option noyywrap
%%
"//"(\\.|[^\n])*[\n]																						{;}
[/][*]([^*]|[*]*[^*/])*[*]+[/]                                                                              {;}

"#include"[ \t]*<[^>]*>     { add_include_path(yytext, '<', yyleng); }
"#include"[ \t]*\"[^\"]*\"  { add_include_path(yytext, '\"', yyleng); }

. {;}
%%

void preprocess_run() {
    yylex();
}
