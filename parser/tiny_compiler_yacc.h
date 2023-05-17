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
     TYPE = 260,
     TYPE_QUALI = 261,
     SEMI = 262,
     ADD = 263,
     SUB = 264,
     MULT = 265,
     DIV = 266,
     MOD = 267,
     COMMA = 268,
     LB = 269,
     RB = 270,
     LOGIC_AND = 271,
     LOGIC_OR = 272,
     LOGIC_NOT = 273,
     BIT_OR = 274,
     BIT_AND = 275,
     BIT_XOR = 276,
     LSHIFT = 277,
     RSHIFT = 278,
     LSBSCRPT = 279,
     RSBSCRPT = 280,
     LSCOPE = 281,
     RSCOPE = 282,
     GT = 283,
     LT = 284,
     GE = 285,
     LE = 286,
     EQ = 287,
     NEQ = 288,
     ASSIGN = 289,
     T1 = 290,
     T2 = 291,
     BIT_NOT = 292,
     UPOSITIVE = 293,
     UMINUS = 294
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define ID 259
#define TYPE 260
#define TYPE_QUALI 261
#define SEMI 262
#define ADD 263
#define SUB 264
#define MULT 265
#define DIV 266
#define MOD 267
#define COMMA 268
#define LB 269
#define RB 270
#define LOGIC_AND 271
#define LOGIC_OR 272
#define LOGIC_NOT 273
#define BIT_OR 274
#define BIT_AND 275
#define BIT_XOR 276
#define LSHIFT 277
#define RSHIFT 278
#define LSBSCRPT 279
#define RSBSCRPT 280
#define LSCOPE 281
#define RSCOPE 282
#define GT 283
#define LT 284
#define GE 285
#define LE 286
#define EQ 287
#define NEQ 288
#define ASSIGN 289
#define T1 290
#define T2 291
#define BIT_NOT 292
#define UPOSITIVE 293
#define UMINUS 294




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 12 "parser.y"
{
    struct AstNode* ast_node;
}
/* Line 1529 of yacc.c.  */
#line 131 "./tiny_compiler_yacc.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

