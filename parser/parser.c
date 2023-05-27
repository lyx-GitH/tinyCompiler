//
// Created by 刘宇轩 on 2023/5/15.
//
#include "parser.h"

#include <assert.h>
#include <stdio.h>

#include "../exceptions/parser_error.h"


static pAstNode parser_root_node = NULL;
static const char *pwd;

#define MAX_INCLUDE 1024
static char included_files[MAX_INCLUDE][MAX_INCLUDE] = {0};
static int include_file_cnt = 0;

FILE *parser_file = NULL;
int parser_line_no = 0;
int parser_col_no = 0;
int cur_token_len = 0;
int parse_error = 0;

extern int yychar;

extern FILE *yyin;

extern int yyparse(void);

extern int yylex(void);

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
    pwd = getcwd(NULL, 0);
    assert(parser_root_node != NULL);
}

void TinyParserRaiseError(const char *e) {
    parse_error |= 1;
    throw_parse_exception(e);
}

void TinyParserParse(const char *file_name) {
    FILE *input_file = fopen(file_name, "r");
    if (!input_file) {
        fprintf(stderr, "no such file or directory: %s", file_name);
        exit(1);
    }
    yyin = input_file;

    printf("parsing begins : %s\n", pwd);
    yyparse();
    printf("parsing ends : %s\n", pwd);

    fclose(input_file);
}

void TinyParserInclude(const char *include_file, char mode, int len) {
//    char *pos = strchr(include_file, mode);
//    assert(pos != NULL);
//    int file_len = len - (pos - include_file) - 2;
//
//    if (file_len >= MAX_INCLUDE) {
//        fprintf(stderr, "%s\n include file length over flow", include_file);
//        exit(1);
//    }
//    if (include_file_cnt >= MAX_INCLUDE) {
//        fprintf(stderr, "include depth overflow\n");
//        exit(1);
//    }
//    strncpy(included_files[include_file_cnt], pos + 1, file_len);
//    TinyParserParse(included_files[include_file_cnt++]);
}

const char *TinyParserGetPwd() { return pwd; }

// void TinyParserSetPwd(const char *path) { const char *dir = chdir(path); }

void TinyParserEnd() {
    freeAstNode(parser_root_node);
    free((void *) pwd);
}

pAstNode TinyParserAppendBlock(pAstNode node) {
    assert(parser_root_node != NULL);
    addChild(parser_root_node, node);
    return parser_root_node;
}

pAstNode TinyParserGetRoot() { return parser_root_node; }

pAstNode TinyParserMoveRoot() {
    pAstNode old_root = TinyParserGetRoot();
    TinyParserSetRoot(NULL);
    return old_root;
}

pAstNode TinyParserSetRoot(pAstNode node) {
    parser_root_node = node;
    return node;
}

int TinyParserGetLine() { return parser_line_no; }

int TinyParserGetColumn() { return parser_col_no; }

int TinyParserGetCurTokLen() { return cur_token_len; }
