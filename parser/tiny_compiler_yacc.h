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
     STR = 260,
     TYPE = 261,
     CONST = 262,
     STATIC = 263,
     TYPE_DEF = 264,
     VARGS = 265,
     GOTO = 266,
     BREAK = 267,
     CONTINUE = 268,
     RETURN = 269,
     SEMI = 270,
     STRUCT = 271,
     UNION = 272,
     ENUM = 273,
     DOT = 274,
     ARROW = 275,
     ADD = 276,
     SUB = 277,
     MULT = 278,
     DIV = 279,
     MOD = 280,
     COMMA = 281,
     LB = 282,
     RB = 283,
     LOGIC_AND = 284,
     LOGIC_OR = 285,
     LOGIC_NOT = 286,
     BIT_OR = 287,
     BIT_AND = 288,
     BIT_XOR = 289,
     BIT_NOT = 290,
     LSHIFT = 291,
     RSHIFT = 292,
     LSBSCRPT = 293,
     RSBSCRPT = 294,
     LSCOPE = 295,
     RSCOPE = 296,
     GT = 297,
     LT = 298,
     GE = 299,
     LE = 300,
     EQ = 301,
     NEQ = 302,
     ASSIGN = 303,
     A_PLUS = 304,
     A_SUB = 305,
     A_MULT = 306,
     A_DIV = 307,
     A_MOD = 308,
     A_LS = 309,
     A_RS = 310,
     A_XOR = 311,
     A_AND = 312,
     A_OR = 313,
     PP = 314,
     SS = 315,
     T1 = 316,
     T2 = 317,
     SIZE_OF = 318,
     IF = 319,
     ELSE = 320,
     WHILE = 321,
     DO = 322,
     FOR = 323,
     SWITCH = 324,
     CASE = 325,
     DEFAULT = 326
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define ID 259
#define STR 260
#define TYPE 261
#define CONST 262
#define STATIC 263
#define TYPE_DEF 264
#define VARGS 265
#define GOTO 266
#define BREAK 267
#define CONTINUE 268
#define RETURN 269
#define SEMI 270
#define STRUCT 271
#define UNION 272
#define ENUM 273
#define DOT 274
#define ARROW 275
#define ADD 276
#define SUB 277
#define MULT 278
#define DIV 279
#define MOD 280
#define COMMA 281
#define LB 282
#define RB 283
#define LOGIC_AND 284
#define LOGIC_OR 285
#define LOGIC_NOT 286
#define BIT_OR 287
#define BIT_AND 288
#define BIT_XOR 289
#define BIT_NOT 290
#define LSHIFT 291
#define RSHIFT 292
#define LSBSCRPT 293
#define RSBSCRPT 294
#define LSCOPE 295
#define RSCOPE 296
#define GT 297
#define LT 298
#define GE 299
#define LE 300
#define EQ 301
#define NEQ 302
#define ASSIGN 303
#define A_PLUS 304
#define A_SUB 305
#define A_MULT 306
#define A_DIV 307
#define A_MOD 308
#define A_LS 309
#define A_RS 310
#define A_XOR 311
#define A_AND 312
#define A_OR 313
#define PP 314
#define SS 315
#define T1 316
#define T2 317
#define SIZE_OF 318
#define IF 319
#define ELSE 320
#define WHILE 321
#define DO 322
#define FOR 323
#define SWITCH 324
#define CASE 325
#define DEFAULT 326




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "parser.y"
{
    struct AstNode* ast_node;
}
/* Line 1529 of yacc.c.  */
#line 195 "./tiny_compiler_yacc.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

