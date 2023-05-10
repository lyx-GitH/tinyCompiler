%option c++

%{

#include <string>
#include <iostream>
#include "tokens.h"

%}

WhiteSpace          [ \t]

%%


[A-Za-z]+           {return Token::WORD;}
[0-9]+              {return Token::NUMBER;}

{WhiteSpace}+       {/*IgnoreSpace*/}

.                   {return Token::UNKNOWN;}


%%

int yyFlexLexer::yywrap()
{
    return true;
}