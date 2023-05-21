/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 2 "parser.y"

  #include <stdio.h>
  #include "parser.h"
  #include "../exceptions/parser_error.h"
  #include "../types/type_checks.h"
  #define YYDEBUG 1
  #define CDEBUG 1
  #define INT_TYPE createAstNode(kType, "int", 3)
  #define EMPTY_NODE createEmptyTreeNode()
  extern char *yytext;
  extern int yylex(void);
  extern int yyparse(void);
  int yyerror(char* error);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 18 "parser.y"
{
    struct AstNode* ast_node;
}
/* Line 193 of yacc.c.  */
#line 257 "./tiny_compiler_yacc.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 270 "./tiny_compiler_yacc.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1081

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  198
/* YYNRULES -- Number of states.  */
#define YYNSTATES  344

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   327

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    18,    21,
      23,    26,    30,    33,    36,    38,    41,    43,    46,    48,
      50,    52,    54,    56,    60,    62,    66,    69,    71,    73,
      77,    82,    86,    91,    95,    97,   100,   102,   106,   111,
     115,   119,   122,   127,   131,   135,   138,   140,   144,   146,
     150,   153,   156,   158,   161,   163,   167,   170,   172,   175,
     177,   181,   186,   188,   192,   194,   196,   198,   200,   202,
     204,   208,   213,   217,   220,   222,   227,   231,   235,   238,
     240,   243,   249,   257,   263,   269,   277,   287,   296,   305,
     313,   322,   330,   338,   345,   349,   352,   355,   359,   362,
     364,   368,   370,   374,   376,   382,   384,   388,   390,   394,
     396,   400,   402,   406,   408,   412,   414,   418,   422,   424,
     428,   432,   436,   440,   442,   446,   450,   452,   456,   460,
     462,   466,   470,   474,   476,   481,   483,   486,   489,   492,
     495,   500,   502,   507,   511,   515,   518,   521,   523,   525,
     527,   529,   533,   535,   537,   539,   541,   543,   545,   547,
     549,   551,   553,   555,   557,   559,   561,   563,   565,   567,
     571,   576,   578,   582,   584,   586,   588,   594,   599,   602,
     604,   606,   608,   611,   615,   618,   620,   623,   625,   627,
     631,   633,   639,   644,   647,   649,   653,   655,   659
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      74,     0,    -1,    75,    -1,    76,    -1,    75,    76,    -1,
      77,    -1,    79,    -1,    80,    86,   100,    -1,    86,   100,
      -1,    79,    -1,    78,    79,    -1,    80,    84,    15,    -1,
      80,    15,    -1,    81,    80,    -1,    81,    -1,    82,    80,
      -1,    82,    -1,    83,    80,    -1,    83,    -1,     8,    -1,
     126,    -1,     7,    -1,    85,    -1,    84,    26,    85,    -1,
      86,    -1,    86,    48,    95,    -1,    93,    87,    -1,    87,
      -1,     4,    -1,    27,    86,    28,    -1,    87,    38,   107,
      39,    -1,    87,    38,    39,    -1,    87,    27,    90,    28,
      -1,    87,    27,    28,    -1,    93,    -1,    93,    89,    -1,
      89,    -1,    27,    88,    28,    -1,    89,    38,   107,    39,
      -1,    38,   107,    39,    -1,    89,    38,    39,    -1,    38,
      39,    -1,    89,    27,    90,    28,    -1,    27,    90,    28,
      -1,    89,    27,    28,    -1,    27,    28,    -1,    91,    -1,
      91,    26,    10,    -1,    92,    -1,    91,    26,    92,    -1,
      80,    86,    -1,    80,    88,    -1,    80,    -1,    23,    94,
      -1,    23,    -1,    23,    94,    93,    -1,    23,    93,    -1,
      83,    -1,    94,    83,    -1,   106,    -1,    40,    96,    41,
      -1,    40,    96,    26,    41,    -1,    95,    -1,    96,    26,
      95,    -1,    98,    -1,    99,    -1,   100,    -1,   102,    -1,
     103,    -1,   104,    -1,     4,    62,    97,    -1,    70,   107,
      62,    97,    -1,    71,    62,    97,    -1,   105,    15,    -1,
      15,    -1,    40,    78,   101,    41,    -1,    40,   101,    41,
      -1,    40,    78,    41,    -1,    40,    41,    -1,    97,    -1,
     101,    97,    -1,    64,    27,   105,    28,    97,    -1,    64,
      27,   105,    28,    97,    65,    97,    -1,    69,    27,   105,
      28,    97,    -1,    66,    27,   105,    28,    97,    -1,    67,
      97,    66,    27,   105,    28,    15,    -1,    68,    27,   105,
      15,   105,    15,   105,    28,    97,    -1,    68,    27,   105,
      15,   105,    15,    28,    97,    -1,    68,    27,   105,    15,
      15,   105,    28,    97,    -1,    68,    27,   105,    15,    15,
      28,    97,    -1,    68,    27,    15,   105,    15,   105,    28,
      97,    -1,    68,    27,    15,   105,    15,    28,    97,    -1,
      68,    27,    15,    15,   105,    28,    97,    -1,    68,    27,
      15,    15,    28,    97,    -1,    11,     4,    15,    -1,    13,
      15,    -1,    12,    15,    -1,    14,   105,    15,    -1,    14,
      15,    -1,   106,    -1,   105,    26,   106,    -1,   107,    -1,
     119,   122,   106,    -1,   108,    -1,   108,    61,   105,    62,
     107,    -1,   109,    -1,   108,    30,   109,    -1,   110,    -1,
     109,    29,   110,    -1,   111,    -1,   110,    32,   111,    -1,
     112,    -1,   111,    34,   112,    -1,   113,    -1,   112,    33,
     113,    -1,   114,    -1,   113,    46,   114,    -1,   113,    47,
     114,    -1,   115,    -1,   114,    42,   115,    -1,   114,    43,
     115,    -1,   114,    44,   115,    -1,   114,    45,   115,    -1,
     116,    -1,   115,    36,   116,    -1,   115,    37,   116,    -1,
     117,    -1,   116,    21,   117,    -1,   116,    22,   117,    -1,
     118,    -1,   117,    23,   118,    -1,   117,    24,   118,    -1,
     117,    25,   118,    -1,   119,    -1,    27,   126,    28,   118,
      -1,   120,    -1,    59,   119,    -1,    60,   119,    -1,   123,
     118,    -1,    63,   119,    -1,    63,    27,   126,    28,    -1,
     121,    -1,   120,    38,   105,    39,    -1,   120,    19,     4,
      -1,   120,    20,     4,    -1,   120,    59,    -1,   120,    60,
      -1,   124,    -1,     3,    -1,     5,    -1,     4,    -1,    27,
     105,    28,    -1,    48,    -1,    57,    -1,    52,    -1,    49,
      -1,    50,    -1,    51,    -1,    54,    -1,    55,    -1,    58,
      -1,    56,    -1,    53,    -1,    21,    -1,    22,    -1,    33,
      -1,    31,    -1,    35,    -1,    23,    -1,   120,    27,    28,
      -1,   120,    27,   125,    28,    -1,   105,    -1,   125,    26,
     105,    -1,     6,    -1,   127,    -1,   134,    -1,   128,     4,
      40,   129,    41,    -1,   128,    40,   129,    41,    -1,   128,
       4,    -1,    16,    -1,    17,    -1,   130,    -1,   129,   130,
      -1,   131,   132,    15,    -1,    82,   131,    -1,    82,    -1,
      83,   131,    -1,    83,    -1,   133,    -1,   132,    26,   133,
      -1,    86,    -1,   137,     4,    40,   135,    41,    -1,   137,
      40,   135,    41,    -1,   137,     4,    -1,   136,    -1,   135,
      26,   136,    -1,     4,    -1,     4,    48,   107,    -1,    18,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    96,    97,    99,   100,   103,   104,   107,
     108,   111,   112,   115,   116,   117,   118,   119,   120,   123,
     125,   127,   129,   130,   132,   133,   135,   136,   139,   140,
     141,   142,   143,   144,   147,   148,   149,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   163,   164,   167,   168,
     171,   172,   173,   176,   177,   178,   179,   182,   183,   187,
     188,   189,   191,   192,   195,   196,   197,   198,   199,   200,
     203,   204,   205,   208,   209,   212,   213,   214,   215,   218,
     219,   222,   223,   224,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   239,   240,   241,   242,   243,   247,
     248,   250,   251,   254,   255,   258,   259,   262,   263,   266,
     267,   270,   271,   274,   275,   278,   279,   280,   283,   284,
     285,   286,   287,   290,   291,   292,   295,   296,   297,   300,
     301,   302,   303,   306,   307,   310,   311,   312,   313,   314,
     315,   318,   319,   320,   321,   322,   323,   324,   328,   329,
     330,   331,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   347,   348,   349,   350,   351,   352,   356,
     357,   360,   361,   365,   367,   368,   371,   372,   373,   376,
     377,   380,   381,   384,   386,   387,   388,   389,   392,   393,
     396,   401,   402,   403,   406,   407,   410,   411,   414
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ID", "STR", "TYPE", "CONST",
  "STATIC", "TYPE_DEF", "VARGS", "GOTO", "BREAK", "CONTINUE", "RETURN",
  "SEMI", "STRUCT", "UNION", "ENUM", "DOT", "ARROW", "ADD", "SUB", "MULT",
  "DIV", "MOD", "COMMA", "LB", "RB", "LOGIC_AND", "LOGIC_OR", "LOGIC_NOT",
  "BIT_OR", "BIT_AND", "BIT_XOR", "BIT_NOT", "LSHIFT", "RSHIFT",
  "LSBSCRPT", "RSBSCRPT", "LSCOPE", "RSCOPE", "GT", "LT", "GE", "LE", "EQ",
  "NEQ", "ASSIGN", "A_PLUS", "A_SUB", "A_MULT", "A_DIV", "A_MOD", "A_LS",
  "A_RS", "A_XOR", "A_AND", "A_OR", "PP", "SS", "T1", "T2", "SIZE_OF",
  "IF", "ELSE", "WHILE", "DO", "FOR", "SWITCH", "CASE", "DEFAULT",
  "\"then\"", "$accept", "program_unit", "translation_unit",
  "external_decl", "function_definition", "decl_list", "decl",
  "decl_specs", "storage_class_spec", "type_spec", "type_qualifier",
  "init_declarator_list", "init_declarator", "declarator",
  "direct_declarator", "abstract_declarator", "direct_abstract_declarator",
  "param_type_list", "param_list", "param_decl", "pointer",
  "type_qualifier_list", "initializer", "initializer_list", "stat",
  "labeled_stat", "exp_stat", "compound_stat", "stat_list",
  "selection_stat", "iteration_stat", "jump_stat", "expression",
  "expression11", "expression10", "expression9", "expression8",
  "expression7", "expression6", "expression5", "expression4",
  "expression3", "expression2", "expression1", "term", "factor", "unaries",
  "postfix", "single", "aop", "uop", "function_call", "args_list",
  "type_name", "struct_or_union_spec", "struct_or_union",
  "struct_decl_list", "struct_decl", "spec_qualifier_list",
  "struct_declarator_list", "struct_declarator", "enum_spec",
  "enumerator_list", "enumerator", "enum_const", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    73,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    79,    79,    80,    80,    80,    80,    80,    80,    81,
      82,    83,    84,    84,    85,    85,    86,    86,    87,    87,
      87,    87,    87,    87,    88,    88,    88,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    90,    90,    91,    91,
      92,    92,    92,    93,    93,    93,    93,    94,    94,    95,
      95,    95,    96,    96,    97,    97,    97,    97,    97,    97,
      98,    98,    98,    99,    99,   100,   100,   100,   100,   101,
     101,   102,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   104,   104,   104,   104,   104,   105,
     105,   106,   106,   107,   107,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   113,   113,   114,   114,
     114,   114,   114,   115,   115,   115,   116,   116,   116,   117,
     117,   117,   117,   118,   118,   119,   119,   119,   119,   119,
     119,   120,   120,   120,   120,   120,   120,   120,   121,   121,
     121,   121,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   123,   123,   123,   123,   123,   123,   124,
     124,   125,   125,   126,   126,   126,   127,   127,   127,   128,
     128,   129,   129,   130,   131,   131,   131,   131,   132,   132,
     133,   134,   134,   134,   135,   135,   136,   136,   137
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     2,     1,
       2,     3,     2,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     3,     1,     3,     2,     1,     1,     3,
       4,     3,     4,     3,     1,     2,     1,     3,     4,     3,
       3,     2,     4,     3,     3,     2,     1,     3,     1,     3,
       2,     2,     1,     2,     1,     3,     2,     1,     2,     1,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     1,     4,     3,     3,     2,     1,
       2,     5,     7,     5,     5,     7,     9,     8,     8,     7,
       8,     7,     7,     6,     3,     2,     2,     3,     2,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     4,     1,     2,     2,     2,     2,
       4,     1,     4,     3,     3,     2,     2,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     1,     3,     1,     1,     1,     5,     4,     2,     1,
       1,     1,     2,     3,     2,     1,     2,     1,     1,     3,
       1,     5,     4,     2,     1,     3,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    28,   173,    21,    19,   179,   180,   198,    54,     0,
       0,     2,     3,     5,     6,     0,    14,    16,    18,     0,
      27,     0,    20,   174,     0,   175,     0,    57,    56,    53,
       0,     1,     4,    12,     0,    22,    24,    13,    15,    17,
       0,     8,     0,     0,    26,   178,     0,   193,     0,    58,
      55,    29,    11,     0,     0,     7,   148,   150,   149,     0,
       0,     0,     0,    74,   163,   164,   168,     0,   166,   165,
     167,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     0,    79,    64,    65,    66,     0,
      67,    68,    69,     0,    99,   101,   103,   105,   107,   109,
     111,   113,   115,   118,   123,   126,   129,   133,   135,   141,
       0,   147,    33,    52,     0,    46,    48,   150,    31,     0,
     133,     0,   185,   187,     0,   181,     0,     0,   196,     0,
     194,    23,    24,     0,    25,    59,     0,     0,    96,    95,
      98,     0,     0,     0,     0,   136,   137,     0,   139,     0,
       0,     0,     0,     0,     0,     0,    77,    10,     0,    76,
      80,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   152,   155,   156,   157,   154,   162,   158,   159,
     161,   153,   160,     0,     0,     0,     0,     0,   145,   146,
     138,     0,     0,    50,    51,    36,    34,    32,     0,    30,
       0,   184,   186,   177,   182,   190,     0,   188,     0,     0,
       0,   192,    62,     0,    70,    94,    97,   151,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,    75,   100,
     106,     0,   108,   110,   112,   114,   116,   117,   119,   120,
     121,   122,   124,   125,   127,   128,   130,   131,   132,   102,
     143,   144,   169,   171,     0,     0,    45,     0,     0,    41,
       0,     0,     0,    35,    47,    49,   176,   183,     0,   191,
     197,   195,     0,    60,   134,   140,     0,     0,     0,     0,
       0,     0,     0,    71,     0,     0,   170,   142,    37,    43,
      39,    44,     0,    40,     0,   189,    61,    63,    81,    84,
       0,     0,     0,     0,     0,     0,    83,   104,   172,    42,
      38,     0,     0,    93,     0,     0,     0,     0,     0,     0,
      82,    85,    92,    91,     0,    89,     0,     0,     0,    90,
      88,    87,     0,    86
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    82,    14,   113,    16,    17,
      18,    34,    35,    19,    20,   204,   205,   114,   115,   116,
      21,    29,   134,   223,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   193,
     110,   111,   264,    22,    23,    24,   124,   125,   126,   216,
     217,    25,   129,   130,    26
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -191
static const yytype_int16 yypact[] =
{
     390,  -191,  -191,  -191,  -191,  -191,  -191,  -191,    11,    85,
      23,   390,  -191,  -191,  -191,    47,   430,   430,   430,    89,
      80,    99,  -191,  -191,    10,  -191,    13,  -191,  -191,    11,
      44,  -191,  -191,  -191,    52,  -191,    71,  -191,  -191,  -191,
     290,  -191,   124,   670,    80,    96,   221,   118,   149,  -191,
    -191,  -191,  -191,    85,   685,  -191,  -191,   100,  -191,   172,
     175,   188,   142,  -191,  -191,  -191,  -191,   636,  -191,  -191,
    -191,  -191,   964,   964,   979,   180,   181,   567,   220,   229,
    1013,   158,   360,  -191,    47,  -191,  -191,  -191,  -191,   429,
    -191,  -191,  -191,   109,  -191,  -191,    19,   243,   258,   257,
     259,    69,   198,    97,   128,   162,  -191,   423,    27,  -191,
    1013,  -191,  -191,    25,   271,   274,  -191,  -191,  -191,   270,
    -191,   221,   221,   221,    15,  -191,    85,   149,   266,    32,
    -191,  -191,   267,   685,  -191,  -191,   567,   301,  -191,  -191,
    -191,   113,    43,   291,  1013,  -191,  -191,   636,  -191,  1013,
    1013,   252,   719,  1013,   260,   567,  -191,  -191,   498,  -191,
    -191,  -191,  1013,  1013,  1013,  1013,  1013,  1013,  1013,  1013,
    1013,  1013,  1013,  1013,  1013,  1013,  1013,  1013,  1013,  1013,
    1013,  1013,  -191,  -191,  -191,  -191,  -191,  -191,  -191,  -191,
    -191,  -191,  -191,  1013,   316,   320,   734,  1013,  -191,  -191,
    -191,  1043,   768,  -191,  -191,   116,    39,  -191,   327,  -191,
      20,  -191,  -191,  -191,  -191,  -191,   140,  -191,    42,  1013,
     149,  -191,  -191,    84,  -191,  -191,  -191,  -191,  1013,   298,
     163,   167,   302,   783,   141,   170,   567,  -191,  -191,  -191,
     243,    -7,   258,   257,   259,    69,   198,   198,    97,    97,
      97,    97,   128,   128,   162,   162,  -191,  -191,  -191,  -191,
    -191,  -191,  -191,   306,   178,    88,  -191,   300,   310,  -191,
     303,   206,   817,   116,  -191,  -191,  -191,  -191,    85,  -191,
    -191,  -191,   588,  -191,  -191,  -191,   567,   567,  1013,   832,
     153,   866,   567,  -191,  1013,  1013,  -191,  -191,  -191,  -191,
    -191,  -191,   311,  -191,   307,  -191,  -191,  -191,   275,  -191,
     189,   567,   193,   881,   915,   157,  -191,  -191,   306,  -191,
    -191,   567,   326,  -191,   567,   567,   218,   567,   224,   930,
    -191,  -191,  -191,  -191,   567,  -191,   567,   567,   231,  -191,
    -191,  -191,   567,  -191
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -191,  -191,  -191,   336,  -191,  -191,   -25,    24,  -191,   -26,
      -1,  -191,   295,    -9,   -12,   150,   146,  -190,  -191,   147,
      -4,  -191,  -123,  -191,   -76,  -191,  -191,    40,   280,  -191,
    -191,  -191,   -59,   -49,   -41,  -191,   207,   204,   213,   217,
     222,     1,    91,    50,    22,   -80,   108,  -191,  -191,  -191,
    -191,  -191,  -191,   -55,  -191,  -191,   264,  -108,   145,  -191,
     110,  -191,   262,   166,  -191
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      30,   151,   119,   141,    28,   135,    36,    27,   142,    44,
     222,   268,   143,   160,    45,    83,   214,    47,     3,   162,
     122,     2,     3,    31,    15,    50,     2,     3,    49,     1,
     200,     5,     6,     7,     8,    15,     5,     6,     7,   154,
      37,    38,    39,     1,   132,   123,   194,   195,     8,   163,
      46,     1,   201,    48,   196,   294,   213,   157,   220,    41,
     224,   276,    33,   202,    84,   197,   201,    52,   220,   162,
       8,   227,    51,   221,     9,   132,    55,   202,    53,   237,
     164,   302,   160,   279,   135,   142,   198,   199,   142,     1,
     230,   231,   229,   234,   235,   122,   122,   122,   122,   256,
     257,   258,   214,     1,   203,   241,    84,    42,     8,   206,
     282,    40,     9,   239,   162,   169,   170,   215,    43,    54,
     123,   123,   123,   123,   161,   283,     9,   297,   226,    40,
       2,     3,     4,   175,   176,   162,   121,   263,   265,   162,
       5,     6,     7,   271,   259,    56,   117,    58,   284,   177,
     178,   120,   112,   128,   272,   277,   291,   140,   127,   307,
     293,   270,   136,    64,    65,    66,   278,   162,   313,    67,
     246,   247,   329,    68,   290,    69,   137,    70,   280,   162,
     145,   146,   148,   162,   122,   179,   180,   181,   120,   162,
     138,   286,    30,   162,    44,   287,   162,   206,   292,   254,
     255,    72,    73,   139,   295,    74,   296,   149,   150,   123,
     308,   309,     2,     3,     4,   162,   316,   322,   120,   162,
     155,   324,     5,     6,     7,   252,   253,     2,     3,   310,
     312,   304,   315,   135,   301,   323,   318,     5,     6,     7,
     171,   172,   173,   174,   162,   330,   334,   152,   332,   333,
     162,   335,   336,   317,   326,   328,   153,   162,   339,   342,
     340,   341,   248,   249,   250,   251,   343,   211,   212,   215,
     338,   120,   165,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     166,   167,   168,    56,    57,    58,     2,     3,     4,   207,
     208,    59,    60,    61,    62,    63,     5,     6,     7,   209,
     120,    64,    65,    66,   219,    54,   225,    67,   232,   228,
     260,    68,   236,    69,   261,    70,   285,   120,   298,   288,
      40,    71,   162,     2,     3,     4,   120,   274,   299,   319,
     321,   331,   300,     5,     6,     7,   320,    32,   131,    72,
      73,   267,   273,    74,    75,   275,    76,    77,    78,    79,
      80,    81,   158,    56,    57,    58,     2,     3,     4,   242,
     240,    59,    60,    61,    62,    63,     5,     6,     7,   243,
     120,    64,    65,    66,   244,   210,   281,    67,   305,   218,
     245,    68,     0,    69,     1,    70,     2,     3,     4,     0,
      40,   156,   120,     0,     0,     0,     5,     6,     7,     0,
       0,     0,     0,     8,     0,     0,     0,     9,     0,    72,
      73,     0,     0,    74,    75,     0,    76,    77,    78,    79,
      80,    81,    56,    57,    58,     0,     2,     3,     4,     0,
      59,    60,    61,    62,    63,     0,     5,     6,     7,     0,
      64,    65,    66,     0,     0,     0,    67,     0,     0,     0,
      68,     0,    69,     0,    70,     0,     0,     0,     0,    40,
     159,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,     0,     0,     0,     0,     0,    72,    73,
       0,     0,    74,    75,     0,    76,    77,    78,    79,    80,
      81,    56,    57,    58,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,     0,     0,     0,    64,
      65,    66,     0,     0,     0,    67,     0,     0,     0,    68,
       0,    69,     0,    70,     0,     0,     0,     0,    40,   238,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,    73,     0,
       0,    74,    75,     0,    76,    77,    78,    79,    80,    81,
      56,    57,    58,     0,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,     0,     0,     0,    64,    65,
      66,    56,   117,    58,    67,     0,     0,     0,    68,     0,
      69,     0,    70,     0,     0,     0,     0,    40,     0,    64,
      65,    66,     0,     0,     0,    67,     0,     0,     0,    68,
       0,    69,     0,    70,     0,     0,    72,    73,   133,   306,
      74,    75,     0,    76,    77,    78,    79,    80,    81,    56,
     117,    58,     2,     0,     0,     0,     0,    72,    73,     0,
       0,    74,     5,     6,     7,     0,     0,    64,    65,    66,
       0,     0,     0,    67,     0,     0,     0,    68,     0,    69,
       0,    70,     0,    56,   117,    58,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56,   117,
      58,    64,    65,    66,     0,    72,    73,    67,     0,    74,
       0,    68,     0,    69,     0,    70,    64,    65,    66,   118,
       0,     0,    67,     0,     0,     0,    68,     0,    69,     0,
      70,     0,    56,   117,    58,   133,     0,     0,     0,    72,
      73,     0,     0,    74,   233,     0,     0,    56,   117,    58,
      64,    65,    66,     0,    72,    73,    67,     0,    74,     0,
      68,     0,    69,     0,    70,    64,    65,    66,     0,     0,
       0,    67,   262,     0,     0,    68,     0,    69,     0,    70,
       0,    56,   117,    58,     0,     0,     0,     0,    72,    73,
       0,     0,    74,     0,     0,     0,    56,   117,    58,    64,
      65,    66,     0,    72,    73,    67,     0,    74,   289,    68,
       0,    69,     0,    70,    64,    65,    66,   269,     0,     0,
      67,     0,     0,     0,    68,     0,    69,     0,    70,     0,
      56,   117,    58,     0,     0,     0,     0,    72,    73,     0,
       0,    74,     0,     0,     0,    56,   117,    58,    64,    65,
      66,     0,    72,    73,    67,     0,    74,     0,    68,     0,
      69,     0,    70,    64,    65,    66,   303,     0,     0,    67,
     311,     0,     0,    68,     0,    69,     0,    70,     0,    56,
     117,    58,     0,     0,     0,     0,    72,    73,     0,     0,
      74,   314,     0,     0,    56,   117,    58,    64,    65,    66,
       0,    72,    73,    67,     0,    74,     0,    68,     0,    69,
       0,    70,    64,    65,    66,     0,     0,     0,    67,   325,
       0,     0,    68,     0,    69,     0,    70,     0,    56,   117,
      58,     0,     0,     0,     0,    72,    73,     0,     0,    74,
       0,     0,     0,    56,   117,    58,    64,    65,    66,     0,
      72,    73,    67,   327,    74,     0,    68,     0,    69,     0,
      70,    64,    65,    66,     0,     0,     0,    67,   337,     0,
       0,    68,     0,    69,     0,    70,     0,    56,   117,    58,
       0,     0,     0,     0,    72,    73,     0,     0,    74,     0,
       0,     0,    56,   117,    58,    64,    65,    66,     0,    72,
      73,   144,     0,    74,     0,    68,     0,    69,     0,    70,
      64,    65,    66,     0,     0,     0,   147,     0,     0,     0,
      68,     0,    69,     0,    70,     0,    56,   117,    58,     0,
       0,     0,     0,    72,    73,     0,     0,    74,     0,     0,
       0,     0,     0,     0,    64,    65,    66,     0,    72,    73,
      67,     0,    74,     0,    68,     0,    69,     1,    70,     2,
       3,     4,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     0,     0,     0,     0,     8,     0,     0,     0,
     201,   266,    72,    73,     0,     0,    74,     0,     0,     0,
       0,   202
};

static const yytype_int16 yycheck[] =
{
       9,    77,    43,    62,     8,    54,    15,     8,    67,    21,
     133,   201,    67,    89,     4,    40,   124,     4,     7,    26,
      46,     6,     7,     0,     0,    29,     6,     7,    29,     4,
     110,    16,    17,    18,    23,    11,    16,    17,    18,    80,
      16,    17,    18,     4,    53,    46,    19,    20,    23,    30,
      40,     4,    27,    40,    27,    62,    41,    82,    26,    19,
     136,    41,    15,    38,    40,    38,    27,    15,    26,    26,
      23,    28,    28,    41,    27,    84,    36,    38,    26,   155,
      61,   271,   158,    41,   133,   144,    59,    60,   147,     4,
     149,   150,   147,   152,   153,   121,   122,   123,   124,   179,
     180,   181,   210,     4,   113,   164,    82,    27,    23,   113,
      26,    40,    27,   162,    26,    46,    47,   126,    38,    48,
     121,   122,   123,   124,    15,    41,    27,    39,    15,    40,
       6,     7,     8,    36,    37,    26,    40,   196,   197,    26,
      16,    17,    18,    27,   193,     3,     4,     5,   228,    21,
      22,    43,    28,     4,    38,    15,    15,    15,    40,   282,
     236,   202,    62,    21,    22,    23,    26,    26,    15,    27,
     169,   170,    15,    31,   233,    33,     4,    35,   219,    26,
      72,    73,    74,    26,   210,    23,    24,    25,    80,    26,
      15,    28,   201,    26,   206,    28,    26,   201,    28,   177,
     178,    59,    60,    15,    26,    63,    28,    27,    27,   210,
     286,   287,     6,     7,     8,    26,   292,    28,   110,    26,
      62,    28,    16,    17,    18,   175,   176,     6,     7,   288,
     289,   272,   291,   282,    28,   311,   295,    16,    17,    18,
      42,    43,    44,    45,    26,   321,    28,    27,   324,   325,
      26,   327,    28,   294,   313,   314,    27,    26,   334,    28,
     336,   337,   171,   172,   173,   174,   342,   122,   123,   278,
     329,   163,    29,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
      32,    34,    33,     3,     4,     5,     6,     7,     8,    28,
      26,    11,    12,    13,    14,    15,    16,    17,    18,    39,
     202,    21,    22,    23,    48,    48,    15,    27,    66,    28,
       4,    31,    62,    33,     4,    35,    28,   219,    28,    27,
      40,    41,    26,     6,     7,     8,   228,    10,    28,    28,
      65,    15,    39,    16,    17,    18,    39,    11,    53,    59,
      60,   201,   206,    63,    64,   208,    66,    67,    68,    69,
      70,    71,    82,     3,     4,     5,     6,     7,     8,   165,
     163,    11,    12,    13,    14,    15,    16,    17,    18,   166,
     272,    21,    22,    23,   167,   121,   220,    27,   278,   127,
     168,    31,    -1,    33,     4,    35,     6,     7,     8,    -1,
      40,    41,   294,    -1,    -1,    -1,    16,    17,    18,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    27,    -1,    59,
      60,    -1,    -1,    63,    64,    -1,    66,    67,    68,    69,
      70,    71,     3,     4,     5,    -1,     6,     7,     8,    -1,
      11,    12,    13,    14,    15,    -1,    16,    17,    18,    -1,
      21,    22,    23,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      31,    -1,    33,    -1,    35,    -1,    -1,    -1,    -1,    40,
      41,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    21,
      22,    23,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      -1,    33,    -1,    35,    -1,    -1,    -1,    -1,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,     3,     4,     5,    27,    -1,    -1,    -1,    31,    -1,
      33,    -1,    35,    -1,    -1,    -1,    -1,    40,    -1,    21,
      22,    23,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      -1,    33,    -1,    35,    -1,    -1,    59,    60,    40,    41,
      63,    64,    -1,    66,    67,    68,    69,    70,    71,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    63,    16,    17,    18,    -1,    -1,    21,    22,    23,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    -1,    33,
      -1,    35,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    21,    22,    23,    -1,    59,    60,    27,    -1,    63,
      -1,    31,    -1,    33,    -1,    35,    21,    22,    23,    39,
      -1,    -1,    27,    -1,    -1,    -1,    31,    -1,    33,    -1,
      35,    -1,     3,     4,     5,    40,    -1,    -1,    -1,    59,
      60,    -1,    -1,    63,    15,    -1,    -1,     3,     4,     5,
      21,    22,    23,    -1,    59,    60,    27,    -1,    63,    -1,
      31,    -1,    33,    -1,    35,    21,    22,    23,    -1,    -1,
      -1,    27,    28,    -1,    -1,    31,    -1,    33,    -1,    35,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    63,    -1,    -1,    -1,     3,     4,     5,    21,
      22,    23,    -1,    59,    60,    27,    -1,    63,    15,    31,
      -1,    33,    -1,    35,    21,    22,    23,    39,    -1,    -1,
      27,    -1,    -1,    -1,    31,    -1,    33,    -1,    35,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    63,    -1,    -1,    -1,     3,     4,     5,    21,    22,
      23,    -1,    59,    60,    27,    -1,    63,    -1,    31,    -1,
      33,    -1,    35,    21,    22,    23,    39,    -1,    -1,    27,
      28,    -1,    -1,    31,    -1,    33,    -1,    35,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      63,    15,    -1,    -1,     3,     4,     5,    21,    22,    23,
      -1,    59,    60,    27,    -1,    63,    -1,    31,    -1,    33,
      -1,    35,    21,    22,    23,    -1,    -1,    -1,    27,    28,
      -1,    -1,    31,    -1,    33,    -1,    35,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    63,
      -1,    -1,    -1,     3,     4,     5,    21,    22,    23,    -1,
      59,    60,    27,    28,    63,    -1,    31,    -1,    33,    -1,
      35,    21,    22,    23,    -1,    -1,    -1,    27,    28,    -1,
      -1,    31,    -1,    33,    -1,    35,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    63,    -1,
      -1,    -1,     3,     4,     5,    21,    22,    23,    -1,    59,
      60,    27,    -1,    63,    -1,    31,    -1,    33,    -1,    35,
      21,    22,    23,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      31,    -1,    33,    -1,    35,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    -1,    59,    60,
      27,    -1,    63,    -1,    31,    -1,    33,     4,    35,     6,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    18,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      27,    28,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     6,     7,     8,    16,    17,    18,    23,    27,
      74,    75,    76,    77,    79,    80,    81,    82,    83,    86,
      87,    93,   126,   127,   128,   134,   137,    83,    93,    94,
      86,     0,    76,    15,    84,    85,    86,    80,    80,    80,
      40,   100,    27,    38,    87,     4,    40,     4,    40,    83,
      93,    28,    15,    26,    48,   100,     3,     4,     5,    11,
      12,    13,    14,    15,    21,    22,    23,    27,    31,    33,
      35,    41,    59,    60,    63,    64,    66,    67,    68,    69,
      70,    71,    78,    79,    80,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     123,   124,    28,    80,    90,    91,    92,     4,    39,   107,
     119,    40,    82,    83,   129,   130,   131,    40,     4,   135,
     136,    85,    86,    40,    95,   106,    62,     4,    15,    15,
      15,   105,   105,   126,    27,   119,   119,    27,   119,    27,
      27,    97,    27,    27,   107,    62,    41,    79,   101,    41,
      97,    15,    26,    30,    61,    29,    32,    34,    33,    46,
      47,    42,    43,    44,    45,    36,    37,    21,    22,    23,
      24,    25,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,   122,    19,    20,    27,    38,    59,    60,
     118,    27,    38,    86,    88,    89,    93,    28,    26,    39,
     129,   131,   131,    41,   130,    86,   132,   133,   135,    48,
      26,    41,    95,    96,    97,    15,    15,    28,    28,   126,
     105,   105,    66,    15,   105,   105,    62,    97,    41,   106,
     109,   105,   110,   111,   112,   113,   114,   114,   115,   115,
     115,   115,   116,   116,   117,   117,   118,   118,   118,   106,
       4,     4,    28,   105,   125,   105,    28,    88,    90,    39,
     107,    27,    38,    89,    10,    92,    41,    15,    26,    41,
     107,   136,    26,    41,   118,    28,    28,    28,    27,    15,
     105,    15,    28,    97,    62,    26,    28,    39,    28,    28,
      39,    28,    90,    39,   107,   133,    41,    95,    97,    97,
     105,    28,   105,    15,    15,   105,    97,   107,   105,    28,
      39,    65,    28,    97,    28,    28,   105,    28,   105,    15,
      97,    15,    97,    97,    28,    97,    28,    28,   105,    97,
      97,    97,    28,    97
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 96 "parser.y"
    {TinyParserAppendBlock((yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 4:
#line 97 "parser.y"
    {TinyParserAppendBlock((yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 5:
#line 99 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 6:
#line 100 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 7:
#line 103 "parser.y"
    {assignType((yyvsp[(2) - (3)].ast_node), (yyvsp[(1) - (3)].ast_node)); (yyval.ast_node) = createBinaryTreeNode(kFuncDef, (yyvsp[(2) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 8:
#line 104 "parser.y"
    {assignType((yyvsp[(1) - (2)].ast_node), INT_TYPE); (yyval.ast_node) = createBinaryTreeNode(kFuncDef, (yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 9:
#line 107 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node); ;}
    break;

  case 10:
#line 108 "parser.y"
    {addNext((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node));;}
    break;

  case 11:
#line 111 "parser.y"
    { assignType((yyvsp[(2) - (3)].ast_node), (yyvsp[(1) - (3)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (3)].ast_node); ;}
    break;

  case 12:
#line 112 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 13:
#line 115 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); ;}
    break;

  case 14:
#line 116 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs(NULL, (yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 15:
#line 117 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node));;}
    break;

  case 16:
#line 118 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs(NULL, (yyvsp[(1) - (1)].ast_node));;}
    break;

  case 17:
#line 119 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node));;}
    break;

  case 18:
#line 120 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs(NULL, (yyvsp[(1) - (1)].ast_node));;}
    break;

  case 22:
#line 129 "parser.y"
    { (yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 23:
#line 130 "parser.y"
    { addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 24:
#line 132 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 25:
#line 133 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kVarInit, (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 26:
#line 135 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (2)].ast_node); addLeftMost((yyval.ast_node), (yyvsp[(1) - (2)].ast_node)); ;}
    break;

  case 27:
#line 136 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 28:
#line 139 "parser.y"
    {(yyval.ast_node) = createVarDecl(NULL, (yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 29:
#line 140 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node); ;}
    break;

  case 30:
#line 141 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node);;}
    break;

  case 31:
#line 142 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node);;}
    break;

  case 32:
#line 143 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node);;}
    break;

  case 33:
#line 144 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node);;}
    break;

  case 34:
#line 147 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 35:
#line 148 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (2)].ast_node); addLeftMost((yyval.ast_node), (yyvsp[(1) - (2)].ast_node));;}
    break;

  case 36:
#line 149 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 37:
#line 152 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node);;}
    break;

  case 38:
#line 153 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node); ;}
    break;

  case 39:
#line 154 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 40:
#line 155 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node);;}
    break;

  case 41:
#line 156 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, NULL); ;}
    break;

  case 42:
#line 157 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node);;}
    break;

  case 43:
#line 158 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 44:
#line 159 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node);;}
    break;

  case 45:
#line 160 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, NULL); ;}
    break;

  case 46:
#line 163 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node); ;}
    break;

  case 47:
#line 164 "parser.y"
    {addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 48:
#line 167 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 49:
#line 168 "parser.y"
    {addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 50:
#line 171 "parser.y"
    {assignType((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 51:
#line 172 "parser.y"
    {assignType((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 53:
#line 176 "parser.y"
    {(yyval.ast_node) = createPtrType((yyvsp[(2) - (2)].ast_node)); (yyval.ast_node) = createFeaturedType((yyvsp[(2) - (2)].ast_node), NULL);;}
    break;

  case 54:
#line 177 "parser.y"
    {(yyval.ast_node) = createPtrType(NULL); ;}
    break;

  case 55:
#line 178 "parser.y"
    {(yyval.ast_node) = createFeaturedType((yyvsp[(2) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); (yyval.ast_node) = createPtrType((yyval.ast_node)); ;}
    break;

  case 56:
#line 179 "parser.y"
    {(yyval.ast_node) = createPtrType((yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 59:
#line 187 "parser.y"
    {(yyval.ast_node) = createExprTree((yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 60:
#line 188 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kInitList, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 61:
#line 189 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kInitList, (yyvsp[(2) - (4)].ast_node)); ;}
    break;

  case 62:
#line 191 "parser.y"
    { (yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 63:
#line 192 "parser.y"
    { addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 70:
#line 203 "parser.y"
    {(yyval.ast_node) = createLabledStmt((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 71:
#line 204 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kCase, (yyvsp[(2) - (4)].ast_node), (yyvsp[(4) - (4)].ast_node)); ;}
    break;

  case 73:
#line 208 "parser.y"
    {(yyval.ast_node) = createExprTree((yyvsp[(1) - (2)].ast_node));;}
    break;

  case 75:
#line 212 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kScope, (yyvsp[(2) - (4)].ast_node), (yyvsp[(3) - (4)].ast_node)); ;}
    break;

  case 76:
#line 213 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kScope, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 77:
#line 214 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kScope, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 78:
#line 215 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kScope, NULL); ;}
    break;

  case 79:
#line 218 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 80:
#line 219 "parser.y"
    {addNext((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 81:
#line 222 "parser.y"
    {(yyval.ast_node) = createTrinaryTreeNode(kIfStmt, (yyvsp[(3) - (5)].ast_node), (yyvsp[(5) - (5)].ast_node), NULL); ;}
    break;

  case 82:
#line 223 "parser.y"
    {(yyval.ast_node) = createTrinaryTreeNode(kIfStmt, (yyvsp[(3) - (7)].ast_node), (yyvsp[(5) - (7)].ast_node), (yyvsp[(7) - (7)].ast_node)); ;}
    break;

  case 83:
#line 224 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kSwitchStmt, (yyvsp[(3) - (5)].ast_node), (yyvsp[(5) - (5)].ast_node)); ;}
    break;

  case 84:
#line 227 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kWhileStmt, createExprTree((yyvsp[(3) - (5)].ast_node)), (yyvsp[(5) - (5)].ast_node)); ;}
    break;

  case 85:
#line 228 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kDoWhileStmt, (yyvsp[(2) - (7)].ast_node), createExprTree((yyvsp[(5) - (7)].ast_node))); ;}
    break;

  case 86:
#line 229 "parser.y"
    {(yyval.ast_node) = createForStmt((yyvsp[(3) - (9)].ast_node), (yyvsp[(5) - (9)].ast_node), (yyvsp[(7) - (9)].ast_node), (yyvsp[(9) - (9)].ast_node)); ;}
    break;

  case 87:
#line 230 "parser.y"
    {(yyval.ast_node) = createForStmt((yyvsp[(3) - (8)].ast_node), (yyvsp[(5) - (8)].ast_node), NULL, (yyvsp[(8) - (8)].ast_node)); ;}
    break;

  case 88:
#line 231 "parser.y"
    {(yyval.ast_node) = createForStmt((yyvsp[(3) - (8)].ast_node), NULL, (yyvsp[(6) - (8)].ast_node), (yyvsp[(8) - (8)].ast_node)); ;}
    break;

  case 89:
#line 232 "parser.y"
    {(yyval.ast_node) = createForStmt((yyvsp[(3) - (7)].ast_node), NULL, NULL, (yyvsp[(7) - (7)].ast_node)); ;}
    break;

  case 90:
#line 233 "parser.y"
    {(yyval.ast_node) = createForStmt(NULL, (yyvsp[(4) - (8)].ast_node), (yyvsp[(6) - (8)].ast_node), (yyvsp[(8) - (8)].ast_node)); ;}
    break;

  case 91:
#line 234 "parser.y"
    {(yyval.ast_node) = createForStmt(NULL, (yyvsp[(4) - (7)].ast_node), NULL, (yyvsp[(7) - (7)].ast_node)); ;}
    break;

  case 92:
#line 235 "parser.y"
    {(yyval.ast_node) = createForStmt(NULL, NULL, (yyvsp[(5) - (7)].ast_node), (yyvsp[(7) - (7)].ast_node)); ;}
    break;

  case 93:
#line 236 "parser.y"
    {(yyval.ast_node) = createForStmt(NULL, NULL, NULL, (yyvsp[(6) - (6)].ast_node)); ;}
    break;

  case 94:
#line 239 "parser.y"
    {addChild((yyvsp[(1) - (3)].ast_node), (yyvsp[(2) - (3)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node); ;}
    break;

  case 95:
#line 240 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 96:
#line 241 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 97:
#line 242 "parser.y"
    {(yyvsp[(2) - (3)].ast_node) = createExprTree((yyvsp[(2) - (3)].ast_node)); addChild((yyvsp[(1) - (3)].ast_node), (yyvsp[(2) - (3)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node); ;}
    break;

  case 98:
#line 243 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 100:
#line 248 "parser.y"
    {(yyval.ast_node) = createBinaryOpTree(",", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 102:
#line 251 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node); addChild((yyval.ast_node), (yyvsp[(1) - (3)].ast_node)); addChild((yyval.ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 104:
#line 255 "parser.y"
    {(yyval.ast_node) = createTrinaryOpTree((yyvsp[(1) - (5)].ast_node), (yyvsp[(3) - (5)].ast_node), (yyvsp[(5) - (5)].ast_node));;}
    break;

  case 106:
#line 259 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("||", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 108:
#line 263 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("&&", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 110:
#line 267 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("|", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 112:
#line 271 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("^", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 114:
#line 275 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("&", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 116:
#line 279 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("==", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 117:
#line 280 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("!=", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 119:
#line 284 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree(">", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 120:
#line 285 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("<", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 121:
#line 286 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree(">=", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 122:
#line 287 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("<=", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 124:
#line 291 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("<<", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 125:
#line 292 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree(">>", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 127:
#line 296 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("+", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 128:
#line 297 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("-", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 130:
#line 301 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("*", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 131:
#line 302 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("/", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 132:
#line 303 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("%", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 134:
#line 307 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kCast, (yyvsp[(2) - (4)].ast_node), (yyvsp[(4) - (4)].ast_node)); ;}
    break;

  case 136:
#line 311 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("++_", (yyvsp[(2) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 137:
#line 312 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("--_", (yyvsp[(2) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 138:
#line 313 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node); addChild((yyval.ast_node), (yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 139:
#line 314 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("sizeof", (yyvsp[(2) - (2)].ast_node));;}
    break;

  case 140:
#line 315 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("sizeof", (yyvsp[(3) - (4)].ast_node));;}
    break;

  case 141:
#line 318 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 142:
#line 319 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kSubScript, (yyvsp[(1) - (4)].ast_node), (yyvsp[(3) - (4)].ast_node)); ;}
    break;

  case 143:
#line 320 "parser.y"
    {(yyval.ast_node) = createStructMember((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node), "."); ;}
    break;

  case 144:
#line 321 "parser.y"
    {(yyval.ast_node) = createStructMember((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node), "->"); ;}
    break;

  case 145:
#line 322 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("_++", (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 146:
#line 323 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("_--", (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 147:
#line 324 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 148:
#line 328 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 149:
#line 329 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 150:
#line 330 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 151:
#line 331 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node);;}
    break;

  case 152:
#line 334 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "=", 1); ;}
    break;

  case 153:
#line 335 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "&", 1);;}
    break;

  case 154:
#line 336 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "/", 1);;}
    break;

  case 155:
#line 337 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "+", 1);;}
    break;

  case 156:
#line 338 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "-", 1);;}
    break;

  case 157:
#line 339 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "*", 1);;}
    break;

  case 158:
#line 340 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "<", 1);;}
    break;

  case 159:
#line 341 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, ">", 1);;}
    break;

  case 160:
#line 342 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "|", 1);;}
    break;

  case 161:
#line 343 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "^", 1);;}
    break;

  case 162:
#line 344 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "%", 1);;}
    break;

  case 163:
#line 347 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "+", 1);;}
    break;

  case 164:
#line 348 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "-", 1);;}
    break;

  case 165:
#line 349 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "&", 1);;}
    break;

  case 166:
#line 350 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "!", 1);;}
    break;

  case 167:
#line 351 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "~", 1);;}
    break;

  case 168:
#line 352 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "*", 1);;}
    break;

  case 169:
#line 356 "parser.y"
    { (yyval.ast_node) = createFunctionCallTree((yyvsp[(1) - (3)].ast_node), NULL);;}
    break;

  case 170:
#line 357 "parser.y"
    {(yyval.ast_node) = createFunctionCallTree((yyvsp[(1) - (4)].ast_node), (yyvsp[(3) - (4)].ast_node));;}
    break;

  case 171:
#line 360 "parser.y"
    {(yyval.ast_node) = createArgList((yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 172:
#line 361 "parser.y"
    {addChild((yyval.ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 176:
#line 371 "parser.y"
    {add_type((yyvsp[(2) - (5)].ast_node)->val_); addChild((yyvsp[(1) - (5)].ast_node), (yyvsp[(2) - (5)].ast_node)); addChild((yyvsp[(1) - (5)].ast_node), (yyvsp[(4) - (5)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (5)].ast_node);;}
    break;

  case 177:
#line 372 "parser.y"
    {addChild((yyvsp[(1) - (4)].ast_node), EMPTY_NODE); addChild((yyvsp[(1) - (4)].ast_node), (yyvsp[(3) - (4)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node);;}
    break;

  case 178:
#line 373 "parser.y"
    {addChild((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); addChild((yyvsp[(1) - (2)].ast_node), EMPTY_NODE); (yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 179:
#line 376 "parser.y"
    {(yyval.ast_node) = createAstNode(kStructType, NULL, 0); ;}
    break;

  case 180:
#line 377 "parser.y"
    {(yyval.ast_node) = createAstNode(kUnionType, NULL, 0); ;}
    break;

  case 181:
#line 380 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 182:
#line 381 "parser.y"
    {addNext((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 183:
#line 384 "parser.y"
    {assignType((yyvsp[(2) - (3)].ast_node), (yyvsp[(1) - (3)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (3)].ast_node);;}
    break;

  case 184:
#line 386 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node));;}
    break;

  case 185:
#line 387 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs(NULL, (yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 186:
#line 388 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); ;}
    break;

  case 187:
#line 389 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs(NULL, (yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 188:
#line 392 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 189:
#line 393 "parser.y"
    {addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 191:
#line 401 "parser.y"
    {add_type((yyvsp[(2) - (5)].ast_node)->val_); (yyval.ast_node) = createBinaryTreeNode(kEnumType, (yyvsp[(2) - (5)].ast_node), (yyvsp[(4) - (5)].ast_node)); ;}
    break;

  case 192:
#line 402 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kEnumType, NULL, (yyvsp[(3) - (4)].ast_node));;}
    break;

  case 193:
#line 403 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kEnumType, (yyvsp[(2) - (2)].ast_node), NULL); ;}
    break;

  case 194:
#line 406 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 195:
#line 407 "parser.y"
    {addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 196:
#line 410 "parser.y"
    {(yyval.ast_node) = createEnumerator((yyvsp[(1) - (1)].ast_node), NULL); ;}
    break;

  case 197:
#line 411 "parser.y"
    {(yyval.ast_node) = createEnumerator((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 198:
#line 414 "parser.y"
    { (yyval.ast_node) = createAstNode(kEnumType, NULL, 0); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2774 "./tiny_compiler_yacc.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 418 "parser.y"

int yyerror(char* s) {
    printf("tinyParser: \033[31merror:\033[0m %s at %s:%d:%d\n", s, TinyParserGetPwd(), TinyParserGetLine(), TinyParserGetColumn() - TinyParserGetCurTokLen());
    show_lexer_error(TinyParserGetPwd(), TinyParserGetColumn() - TinyParserGetCurTokLen(), TinyParserGetLine());
    return 1;
}


