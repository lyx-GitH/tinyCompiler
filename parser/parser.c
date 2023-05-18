//
// Created by 刘宇轩 on 2023/5/15.
//
#include "parser.h"

#include <assert.h>
#include <stdio.h>

static pAstNode parser_root_node = NULL;
static const char *pwd = NULL;
int parser_line_no = 0;
int parser_col_no = 0;
int cur_token_len = 0;
int parse_error = 0;
extern FILE *yyin;

extern int yyparse(void);

void TinyParserMove(int line, char *text) {
    size_t i = 0;
    int len = strlen(text);
    while (i < len) {
        char ch = text[i];
        switch (ch) {
            case '\n':
                parser_col_no = 0;
                parser_line_no++;
                break;
            case '\t':
                parser_col_no += 4 - (parser_col_no % 4);
                break;
            default:
                parser_col_no++;
        }
        i++;
    }
    cur_token_len = len;
}

void TinyParserBegin() {
    parser_col_no = 0;
    parser_line_no = 0;
    parser_root_node = createAstNode(kRoot, NULL, 0);
    assert(parser_root_node != NULL);
}

void TinyParserRaiseError() { parse_error |= 1; }

void TinyParserParse(const char *file_name) {
    FILE *input_file = fopen(file_name, "r");
    if (!input_file) {
        exit(1);
    }
    pwd = file_name;
    yyin = input_file;
    yyparse();
    fclose(input_file);
}

const char *TinyParserGetPwd() { return pwd; }

void TinyParserEnd() { freeAstNode(parser_root_node); }

pAstNode TinyParserAppendBlock(pAstNode node) {
    assert(parser_root_node != NULL);
    addChild(parser_root_node, node);
    return parser_root_node;
}

pAstNode TinyParserGetRoot() { return parser_root_node; }

pAstNode TinyParserSetRoot(pAstNode node) {
    parser_root_node = node;
    return node;
}

int TinyParserGetLine() { return parser_line_no; }

int TinyParserGetColumn() { return parser_col_no; }

int TinyParserGetCurTokLen() { return cur_token_len; }
