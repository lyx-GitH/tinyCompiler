//
// Created by 刘宇轩 on 2023/5/15.
//
#include <stdio.h>
#include <assert.h>
#include "parser.h"

static pAstNode parser_root_node = NULL;
int parser_line_no = 0;
int parser_col_no = 0;
extern FILE *yyin;

extern int yyparse(void);


void TinyParserMove(int line, char *text) {
    size_t i = 0;
    while (i < strlen(text)) {
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
}

void TinyParserBegin() {
    parser_col_no = 0;
    parser_line_no = 0;
    parser_root_node = createAstNode(kROOT, NULL, 0);
    assert(parser_root_node != NULL);
}

void TinyParserParse(const char *file_name) {
    FILE *input_file = fopen(file_name, "r");
    if (!input_file) {
        exit(1);
    }
    yyin = input_file;
    yyparse();
    fclose(input_file);
}


void TinyParserEnd() {
    freeAstNode(parser_root_node);
}

void TinyParserAppendBlock(pAstNode node) {
    assert(parser_root_node != NULL);
    addChild(parser_root_node, node);
}

pAstNode TinyParserGetRoot() {
    return parser_root_node;
}

pAstNode TinyParserSetRoot(pAstNode node) {
    parser_root_node = node;
}

int TinyParserGetLine() {
    return parser_line_no;
}

int TinyParserGetColumn() {
    return parser_col_no;
}





