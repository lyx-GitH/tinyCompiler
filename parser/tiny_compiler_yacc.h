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
     HEADER = 271,
     STRUCT = 272,
     UNION = 273,
     ENUM = 274,
     DOT = 275,
     ARROW = 276,
     ADD = 277,
     SUB = 278,
     MULT = 279,
     DIV = 280,
     MOD = 281,
     COMMA = 282,
     LB = 283,
     RB = 284,
     LOGIC_AND = 285,
     LOGIC_OR = 286,
     LOGIC_NOT = 287,
     BIT_OR = 288,
     BIT_AND = 289,
     BIT_XOR = 290,
     BIT_NOT = 291,
     LSHIFT = 292,
     RSHIFT = 293,
     LSBSCRPT = 294,
     RSBSCRPT = 295,
     LSCOPE = 296,
     RSCOPE = 297,
     GT = 298,
     LT = 299,
     GE = 300,
     LE = 301,
     EQ = 302,
     NEQ = 303,
     ASSIGN = 304,
     A_PLUS = 305,
     A_SUB = 306,
     A_MULT = 307,
     A_DIV = 308,
     A_MOD = 309,
     A_LS = 310,
     A_RS = 311,
     A_XOR = 312,
     A_AND = 313,
     A_OR = 314,
     PP = 315,
     SS = 316,
     T1 = 317,
     T2 = 318,
     SIZE_OF = 319,
     IF = 320,
     ELSE = 321,
     WHILE = 322,
     DO = 323,
     FOR = 324,
     SWITCH = 325,
     CASE = 326,
     DEFAULT = 327
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
#define HEADER 271
#define STRUCT 272
#define UNION 273
#define ENUM 274
#define DOT 275
#define ARROW 276
#define ADD 277
#define SUB 278
#define MULT 279
#define DIV 280
#define MOD 281
#define COMMA 282
#define LB 283
#define RB 284
#define LOGIC_AND 285
#define LOGIC_OR 286
#define LOGIC_NOT 287
#define BIT_OR 288
#define BIT_AND 289
#define BIT_XOR 290
#define BIT_NOT 291
#define LSHIFT 292
#define RSHIFT 293
#define LSBSCRPT 294
#define RSBSCRPT 295
#define LSCOPE 296
#define RSCOPE 297
#define GT 298
#define LT 299
#define GE 300
#define LE 301
#define EQ 302
#define NEQ 303
#define ASSIGN 304
#define A_PLUS 305
#define A_SUB 306
#define A_MULT 307
#define A_DIV 308
#define A_MOD 309
#define A_LS 310
#define A_RS 311
#define A_XOR 312
#define A_AND 313
#define A_OR 314
#define PP 315
#define SS 316
#define T1 317
#define T2 318
#define SIZE_OF 319
#define IF 320
#define ELSE 321
#define WHILE 322
#define DO 323
#define FOR 324
#define SWITCH 325
#define CASE 326
#define DEFAULT 327




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "parser.y"
{
    struct AstNode* ast_node;
}
/* Line 1529 of yacc.c.  */
#line 197 "./tiny_compiler_yacc.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

