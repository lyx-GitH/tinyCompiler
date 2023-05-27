//
// Created by 刘宇轩 on 2023/5/15.
//

#ifndef TINYCOMPILER_PARSER_H
#define TINYCOMPILER_PARSER_H


#include <unistd.h>
#include <libgen.h>
#include <stdio.h>
#include <string.h>

#include "../ast/ast.h"

void TinyParserMove(int line, char *text);

void TinyParserBegin();

void TinyParserParse(const char *file_name);

void TinyParserEnd();

void TinyParserRaiseError(const char*);

void TinyParserInclude(const char*, char, int);

const char* TinyParserGetPwd();

void TinyParserSetPwd(const char* );

pAstNode TinyParserAppendBlock(pAstNode block);

pAstNode TinyParserGetRoot();

pAstNode TinyParserMoveRoot();

pAstNode TinyParserSetRoot(pAstNode node);

int TinyParserGetLine();

int TinyParserGetColumn();

int TinyParserGetCurTokLen();


#endif //TINYCOMPILER_PARSER_H
