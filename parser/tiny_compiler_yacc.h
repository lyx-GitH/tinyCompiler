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
     SIGNED = 264,
     UNSIGNED = 265,
     RET = 266,
     TYPE_DEF = 267,
     VARGS = 268,
     SEMI = 269,
     STRUCT = 270,
     UNION = 271,
     ENUM = 272,
     DOT = 273,
     ARROW = 274,
     ADD = 275,
     SUB = 276,
     MULT = 277,
     DIV = 278,
     MOD = 279,
     COMMA = 280,
     LB = 281,
     RB = 282,
     LOGIC_AND = 283,
     LOGIC_OR = 284,
     LOGIC_NOT = 285,
     BIT_OR = 286,
     BIT_AND = 287,
     BIT_XOR = 288,
     BIT_NOT = 289,
     LSHIFT = 290,
     RSHIFT = 291,
     LSBSCRPT = 292,
     RSBSCRPT = 293,
     LSCOPE = 294,
     RSCOPE = 295,
     GT = 296,
     LT = 297,
     GE = 298,
     LE = 299,
     EQ = 300,
     NEQ = 301,
     ASSIGN = 302,
     A_PLUS = 303,
     A_SUB = 304,
     A_MULT = 305,
     A_DIV = 306,
     A_MOD = 307,
     A_LS = 308,
     A_RS = 309,
     A_XOR = 310,
     A_AND = 311,
     A_OR = 312,
     PP = 313,
     SS = 314,
     T1 = 315,
     T2 = 316,
     SIZE_OF = 317,
     IF = 318,
     ELSE = 319,
     WHILE = 320,
     DO = 321,
     FOR = 322,
     SWITCH = 323,
     GOTO = 324,
     BREAK = 325,
     CASE = 326,
     DEFAULT = 327,
     CONTINUE = 328,
     RETURN = 329
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define ID 259
#define STR 260
#define TYPE 261
#define CONST 262
#define STATIC 263
#define SIGNED 264
#define UNSIGNED 265
#define RET 266
#define TYPE_DEF 267
#define VARGS 268
#define SEMI 269
#define STRUCT 270
#define UNION 271
#define ENUM 272
#define DOT 273
#define ARROW 274
#define ADD 275
#define SUB 276
#define MULT 277
#define DIV 278
#define MOD 279
#define COMMA 280
#define LB 281
#define RB 282
#define LOGIC_AND 283
#define LOGIC_OR 284
#define LOGIC_NOT 285
#define BIT_OR 286
#define BIT_AND 287
#define BIT_XOR 288
#define BIT_NOT 289
#define LSHIFT 290
#define RSHIFT 291
#define LSBSCRPT 292
#define RSBSCRPT 293
#define LSCOPE 294
#define RSCOPE 295
#define GT 296
#define LT 297
#define GE 298
#define LE 299
#define EQ 300
#define NEQ 301
#define ASSIGN 302
#define A_PLUS 303
#define A_SUB 304
#define A_MULT 305
#define A_DIV 306
#define A_MOD 307
#define A_LS 308
#define A_RS 309
#define A_XOR 310
#define A_AND 311
#define A_OR 312
#define PP 313
#define SS 314
#define T1 315
#define T2 316
#define SIZE_OF 317
#define IF 318
#define ELSE 319
#define WHILE 320
#define DO 321
#define FOR 322
#define SWITCH 323
#define GOTO 324
#define BREAK 325
#define CASE 326
#define DEFAULT 327
#define CONTINUE 328
#define RETURN 329




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "parser.y"
{
    struct AstNode* ast_node;
}
/* Line 1529 of yacc.c.  */
#line 201 "./tiny_compiler_yacc.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

