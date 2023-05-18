//
// Created by 刘宇轩 on 2023/5/15.
//

#ifndef TINYCOMPILER_PARSER_H
#define TINYCOMPILER_PARSER_H

#include "../ast/ast.h"

void TinyParserMove(int line, char *text);

void TinyParserBegin();

void TinyParserParse(const char *file_name);

void TinyParserEnd();

void TinyParserRaiseError();

const char* TinyParserGetPwd();

pAstNode TinyParserAppendBlock(pAstNode block);

pAstNode TinyParserGetRoot();

pAstNode TinyParserSetRoot(pAstNode node);

int TinyParserGetLine();

int TinyParserGetColumn();

int TinyParserGetCurTokLen();


#endif //TINYCOMPILER_PARSER_H
