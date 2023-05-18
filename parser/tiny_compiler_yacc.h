/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     ID = 259,
     VOID = 260,
     TYPE = 261,
     CONST = 262,
     STATIC = 263,
     SIGNED = 264,
     SEMI = 265,
     ADD = 266,
     SUB = 267,
     MULT = 268,
     DIV = 269,
     MOD = 270,
     COMMA = 271,
     LB = 272,
     RB = 273,
     LOGIC_AND = 274,
     LOGIC_OR = 275,
     LOGIC_NOT = 276,
     BIT_OR = 277,
     BIT_AND = 278,
     BIT_XOR = 279,
     LSHIFT = 280,
     RSHIFT = 281,
     LSBSCRPT = 282,
     RSBSCRPT = 283,
     LSCOPE = 284,
     RSCOPE = 285,
     GT = 286,
     LT = 287,
     GE = 288,
     LE = 289,
     EQ = 290,
     NEQ = 291,
     ASSIGN = 292,
     T1 = 293,
     T2 = 294,
     BIT_NOT = 295,
     UPOSITIVE = 296,
     UMINUS = 297
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define ID 259
#define VOID 260
#define TYPE 261
#define CONST 262
#define STATIC 263
#define SIGNED 264
#define SEMI 265
#define ADD 266
#define SUB 267
#define MULT 268
#define DIV 269
#define MOD 270
#define COMMA 271
#define LB 272
#define RB 273
#define LOGIC_AND 274
#define LOGIC_OR 275
#define LOGIC_NOT 276
#define BIT_OR 277
#define BIT_AND 278
#define BIT_XOR 279
#define LSHIFT 280
#define RSHIFT 281
#define LSBSCRPT 282
#define RSBSCRPT 283
#define LSCOPE 284
#define RSCOPE 285
#define GT 286
#define LT 287
#define GE 288
#define LE 289
#define EQ 290
#define NEQ 291
#define ASSIGN 292
#define T1 293
#define T2 294
#define BIT_NOT 295
#define UPOSITIVE 296
#define UMINUS 297




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 13 "parser.y"
{
    struct AstNode* ast_node;
}
/* Line 1529 of yacc.c.  */
#line 137 "./tiny_compiler_yacc.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

