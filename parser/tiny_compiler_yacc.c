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




/* Copy the first part of user declarations.  */
#line 2 "parser.y"

  #include <stdio.h>
  #include "parser.h"
  #include "../exceptions/parser_error.h"
  #define YYDEBUG 1
  #define CDEBUG 1
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
#line 15 "parser.y"
{
    struct AstNode* ast_node;
}
/* Line 193 of yacc.c.  */
#line 260 "./tiny_compiler_yacc.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 273 "./tiny_compiler_yacc.c"

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   439

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNRULES -- Number of states.  */
#define YYNSTATES  205

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   330

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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    14,    17,    19,    22,
      24,    27,    29,    31,    33,    35,    37,    41,    43,    47,
      50,    52,    54,    58,    63,    67,    72,    76,    78,    81,
      83,    87,    92,    96,   100,   103,   108,   112,   116,   119,
     121,   125,   127,   131,   134,   137,   139,   142,   144,   148,
     151,   153,   156,   158,   162,   167,   169,   173,   175,   179,
     181,   185,   187,   193,   195,   199,   201,   205,   207,   211,
     213,   217,   219,   223,   225,   229,   233,   235,   239,   243,
     247,   251,   253,   257,   261,   263,   267,   271,   273,   277,
     281,   285,   287,   292,   294,   297,   300,   303,   306,   311,
     313,   318,   322,   326,   329,   332,   334,   336,   338,   340,
     344,   346,   348,   350,   352,   354,   356,   358,   360,   362,
     364,   366,   368,   370,   372,   374,   376,   378,   382,   387,
     389,   393,   395,   398,   401
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      77,     0,    -1,    78,    -1,    79,    -1,    78,    79,    -1,
      80,    84,    14,    -1,    81,    80,    -1,    81,    -1,    82,
      80,    -1,    82,    -1,    83,    80,    -1,    83,    -1,     8,
      -1,   118,    -1,     7,    -1,    85,    -1,    84,    25,    85,
      -1,    86,    -1,    86,    47,    95,    -1,    93,    87,    -1,
      87,    -1,     4,    -1,    26,    86,    27,    -1,    87,    37,
      99,    38,    -1,    87,    37,    38,    -1,    87,    26,    90,
      27,    -1,    87,    26,    27,    -1,    93,    -1,    93,    89,
      -1,    89,    -1,    26,    88,    27,    -1,    89,    37,    99,
      38,    -1,    37,    99,    38,    -1,    89,    37,    38,    -1,
      37,    38,    -1,    89,    26,    90,    27,    -1,    26,    90,
      27,    -1,    89,    26,    27,    -1,    26,    27,    -1,    91,
      -1,    91,    25,    13,    -1,    92,    -1,    91,    25,    92,
      -1,    80,    86,    -1,    80,    88,    -1,    80,    -1,    22,
      94,    -1,    22,    -1,    22,    94,    93,    -1,    22,    93,
      -1,    83,    -1,    94,    83,    -1,    98,    -1,    39,    96,
      40,    -1,    39,    96,    25,    40,    -1,    95,    -1,    96,
      25,    95,    -1,    98,    -1,    97,    25,    98,    -1,    99,
      -1,   111,   114,    98,    -1,   100,    -1,   100,    60,    97,
      61,    99,    -1,   101,    -1,   100,    29,   101,    -1,   102,
      -1,   101,    28,   102,    -1,   103,    -1,   102,    31,   103,
      -1,   104,    -1,   103,    33,   104,    -1,   105,    -1,   104,
      32,   105,    -1,   106,    -1,   105,    45,   106,    -1,   105,
      46,   106,    -1,   107,    -1,   106,    41,   107,    -1,   106,
      42,   107,    -1,   106,    43,   107,    -1,   106,    44,   107,
      -1,   108,    -1,   107,    35,   108,    -1,   107,    36,   108,
      -1,   109,    -1,   108,    20,   109,    -1,   108,    21,   109,
      -1,   110,    -1,   109,    22,   110,    -1,   109,    23,   110,
      -1,   109,    24,   110,    -1,   111,    -1,    26,   118,    27,
     110,    -1,   112,    -1,    58,   111,    -1,    59,   111,    -1,
     115,   110,    -1,    62,   111,    -1,    62,    26,   118,    27,
      -1,   113,    -1,   112,    37,    97,    38,    -1,   112,    18,
       4,    -1,   112,    19,     4,    -1,   112,    58,    -1,   112,
      59,    -1,   116,    -1,     3,    -1,     5,    -1,     4,    -1,
      26,    97,    27,    -1,    47,    -1,    56,    -1,    51,    -1,
      48,    -1,    49,    -1,    50,    -1,    53,    -1,    54,    -1,
      57,    -1,    55,    -1,    52,    -1,    20,    -1,    21,    -1,
      32,    -1,    30,    -1,    34,    -1,    22,    -1,   112,    26,
      27,    -1,   112,    26,   117,    27,    -1,    97,    -1,   117,
      25,    97,    -1,     6,    -1,    15,     4,    -1,    17,     4,
      -1,    16,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    84,    85,    88,    92,    93,    94,    95,
      96,    97,   100,   102,   104,   106,   107,   109,   110,   112,
     113,   116,   117,   118,   119,   120,   121,   124,   125,   126,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   140,
     141,   144,   145,   148,   149,   150,   153,   154,   155,   156,
     159,   160,   164,   165,   166,   168,   169,   224,   225,   227,
     228,   231,   232,   235,   236,   239,   240,   243,   244,   247,
     248,   251,   252,   255,   256,   257,   260,   261,   262,   263,
     264,   267,   268,   269,   272,   273,   274,   277,   278,   279,
     280,   283,   284,   287,   288,   289,   290,   291,   292,   295,
     296,   297,   298,   299,   300,   301,   305,   306,   307,   308,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   324,   325,   326,   327,   328,   329,   333,   334,   337,
     338,   350,   352,   353,   354
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ID", "STR", "TYPE", "CONST",
  "STATIC", "SIGNED", "UNSIGNED", "RET", "TYPE_DEF", "VARGS", "SEMI",
  "STRUCT", "UNION", "ENUM", "DOT", "ARROW", "ADD", "SUB", "MULT", "DIV",
  "MOD", "COMMA", "LB", "RB", "LOGIC_AND", "LOGIC_OR", "LOGIC_NOT",
  "BIT_OR", "BIT_AND", "BIT_XOR", "BIT_NOT", "LSHIFT", "RSHIFT",
  "LSBSCRPT", "RSBSCRPT", "LSCOPE", "RSCOPE", "GT", "LT", "GE", "LE", "EQ",
  "NEQ", "ASSIGN", "A_PLUS", "A_SUB", "A_MULT", "A_DIV", "A_MOD", "A_LS",
  "A_RS", "A_XOR", "A_AND", "A_OR", "PP", "SS", "T1", "T2", "SIZE_OF",
  "IF", "ELSE", "WHILE", "DO", "FOR", "SWITCH", "GOTO", "BREAK", "CASE",
  "DEFAULT", "CONTINUE", "RETURN", "\"then\"", "$accept", "input",
  "decl_list", "decl", "decl_specs", "storage_class_spec", "type_spec",
  "type_qualifier", "init_declarator_list", "init_declarator",
  "declarator", "direct_declarator", "abstract_declarator",
  "direct_abstract_declarator", "param_type_list", "param_list",
  "param_decl", "pointer", "type_qualifier_list", "initializer",
  "initializer_list", "expression", "expression11", "expression10",
  "expression9", "expression8", "expression7", "expression6",
  "expression5", "expression4", "expression3", "expression2",
  "expression1", "term", "factor", "unaries", "postfix", "single", "aop",
  "uop", "function_call", "args_list", "type_name", 0
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
     325,   326,   327,   328,   329,   330
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    78,    78,    79,    80,    80,    80,    80,
      80,    80,    81,    82,    83,    84,    84,    85,    85,    86,
      86,    87,    87,    87,    87,    87,    87,    88,    88,    88,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    90,
      90,    91,    91,    92,    92,    92,    93,    93,    93,    93,
      94,    94,    95,    95,    95,    96,    96,    97,    97,    98,
      98,    99,    99,   100,   100,   101,   101,   102,   102,   103,
     103,   104,   104,   105,   105,   105,   106,   106,   106,   106,
     106,   107,   107,   107,   108,   108,   108,   109,   109,   109,
     109,   110,   110,   111,   111,   111,   111,   111,   111,   112,
     112,   112,   112,   112,   112,   112,   113,   113,   113,   113,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   115,   115,   115,   115,   115,   115,   116,   116,   117,
     117,   118,   118,   118,   118
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     2,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     3,     1,     3,     2,
       1,     1,     3,     4,     3,     4,     3,     1,     2,     1,
       3,     4,     3,     3,     2,     4,     3,     3,     2,     1,
       3,     1,     3,     2,     2,     1,     2,     1,     3,     2,
       1,     2,     1,     3,     4,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     4,     1,     2,     2,     2,     2,     4,     1,
       4,     3,     3,     2,     2,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     1,
       3,     1,     2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   131,    14,    12,     0,     0,     0,     0,     2,     3,
       0,     7,     9,    11,    13,   132,   134,   133,     1,     4,
      21,    47,     0,     0,    15,    17,    20,     0,     6,     8,
      10,    50,    49,    46,     0,     5,     0,     0,     0,     0,
      19,    51,    48,    22,    16,   106,   108,   107,   121,   122,
     126,     0,   124,   123,   125,     0,     0,     0,     0,    18,
      52,    59,    61,    63,    65,    67,    69,    71,    73,    76,
      81,    84,    87,    91,    93,    99,     0,   105,    26,    45,
       0,    39,    41,    24,     0,    91,     0,    57,     0,    55,
       0,     0,    94,    95,     0,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,   113,   114,   115,   112,
     120,   116,   117,   119,   111,   118,     0,     0,     0,     0,
       0,   103,   104,    96,     0,     0,    43,    44,    29,    27,
      25,     0,    23,     0,   109,     0,     0,    53,     0,    64,
       0,    66,    68,    70,    72,    74,    75,    77,    78,    79,
      80,    82,    83,    85,    86,    88,    89,    90,    60,   101,
     102,   127,   129,     0,     0,    38,     0,     0,    34,     0,
       0,     0,    28,    40,    42,    58,    92,    54,    56,    98,
       0,     0,   128,   100,    30,    36,    32,    37,     0,    33,
       0,    62,   130,    35,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    79,    11,    12,    13,    23,    24,
      25,    26,   137,   138,    80,    81,    82,    27,    33,    59,
      90,    86,    87,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    85,    74,    75,   126,    76,
      77,   173,    14
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -126
static const yytype_int16 yypact[] =
{
     152,  -126,  -126,  -126,    19,    29,    54,    17,   152,  -126,
      47,   152,   152,   152,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,    55,    47,    71,  -126,   -21,    65,    23,  -126,  -126,
    -126,  -126,  -126,    55,    73,  -126,    47,   158,   192,   201,
      65,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,   115,  -126,  -126,  -126,   158,   314,   314,   334,  -126,
    -126,  -126,    -4,    56,    80,    74,    72,    36,    81,    98,
     130,   116,  -126,   365,    13,  -126,   377,  -126,  -126,    42,
      86,   117,  -126,  -126,   106,  -126,    76,  -126,   119,  -126,
      40,   377,  -126,  -126,   115,  -126,   377,   377,   377,   377,
     377,   377,   377,   377,   377,   377,   377,   377,   377,   377,
     377,   377,   377,   377,   377,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,   377,   144,   166,   221,
     377,  -126,  -126,  -126,   149,   264,  -126,  -126,    68,    37,
    -126,   371,  -126,   377,  -126,   377,     8,  -126,   145,    56,
      -9,    80,    74,    72,    36,    81,    81,    98,    98,    98,
      98,   130,   130,   116,   116,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,   160,    83,    -3,  -126,   156,   162,  -126,   153,
     335,   271,    68,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
     377,   377,  -126,  -126,  -126,  -126,  -126,  -126,   168,  -126,
     165,  -126,   160,  -126,  -126
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,  -126,   179,    75,  -126,  -126,    57,  -126,   174,
     -20,   -22,    62,    89,  -125,  -126,    70,   -18,  -126,   -47,
    -126,   -93,   -31,   -38,  -126,   118,   114,   131,   113,   128,
      79,    22,    85,    91,   -69,   -37,  -126,  -126,  -126,  -126,
    -126,  -126,   -41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      73,    84,    34,    32,   150,    40,    60,   133,    89,   177,
      88,    45,    46,    47,    73,    42,   143,    18,    73,    92,
      93,    95,   143,    15,    60,    96,    37,    20,    48,    49,
      50,   127,   128,    16,    51,   193,   172,   174,    52,   129,
      53,    20,    54,   165,   166,   167,    20,    55,   187,    22,
     130,    20,   190,   148,    73,   198,    97,    73,    17,   136,
      73,   139,     2,   134,    21,   146,    56,    57,   134,    21,
      58,   131,   132,    22,   135,    10,   186,    21,    31,   135,
     147,   102,   103,    10,    98,    35,    28,    29,    30,    73,
      41,    38,    73,    73,   180,   168,    36,   179,   202,   188,
      43,   143,    39,   144,   101,   181,    73,   100,   191,    73,
     192,    99,   185,   140,    34,    60,   139,    40,    45,    46,
      47,     1,   104,   105,   106,   107,   157,   158,   159,   160,
       4,     5,     6,   108,   109,    48,    49,    50,   112,   113,
     114,    51,   141,   200,   142,    52,   145,    53,   169,    54,
     110,   111,   201,    20,    73,     1,     2,     3,     1,     2,
       3,    45,    46,    47,     4,     5,     6,     4,     5,     6,
     170,    21,   189,    56,    57,   134,   175,    58,    48,    49,
      50,   155,   156,   194,    51,   143,   135,    19,    52,   195,
      53,   196,    54,   161,   162,   203,   176,    55,     1,     2,
       3,   163,   164,   204,    45,    46,    47,     4,     5,     6,
      44,   184,   151,   153,   149,     0,    56,    57,     0,    78,
      58,    48,    49,    50,    45,    46,    47,    51,   182,   154,
     152,    52,     0,    53,     0,    54,     0,     0,     0,    83,
       0,    48,    49,    50,     0,     0,     0,    51,   171,     0,
       0,    52,     0,    53,     0,    54,     0,     0,     0,    56,
      57,     0,     0,    58,     0,     0,     0,    45,    46,    47,
       0,     0,     0,     0,    45,    46,    47,     0,     0,    56,
      57,     0,     0,    58,    48,    49,    50,     0,     0,     0,
      51,    48,    49,    50,    52,     0,    53,    51,    54,     0,
       0,    52,   178,    53,     0,    54,     0,     0,     0,   199,
       0,     0,     0,     0,     0,     0,     0,    45,    46,    47,
       0,     0,    56,    57,     0,     0,    58,     0,     0,    56,
      57,     0,     0,    58,    48,    49,    50,    45,    46,    47,
      91,     1,     2,     3,    52,     0,    53,     0,    54,     0,
       4,     5,     6,     0,    48,    49,    50,     0,     0,     0,
      94,     0,   197,     0,    52,     0,    53,     0,    54,     0,
       0,     0,    56,    57,     0,     0,    58,     1,     2,     3,
      45,    46,    47,     0,   183,     0,     4,     5,     6,     0,
       0,     0,    56,    57,     0,     0,    58,    48,    49,    50,
       0,     0,     0,    51,     0,     0,     0,    52,     0,    53,
       0,    54,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    56,    57,     0,     0,    58
};

static const yytype_int16 yycheck[] =
{
      37,    39,    22,    21,    97,    27,    37,    76,    55,   134,
      51,     3,     4,     5,    51,    33,    25,     0,    55,    56,
      57,    58,    25,     4,    55,    29,    47,     4,    20,    21,
      22,    18,    19,     4,    26,    38,   129,   130,    30,    26,
      32,     4,    34,   112,   113,   114,     4,    39,    40,    26,
      37,     4,    61,    94,    91,   180,    60,    94,     4,    79,
      97,    79,     7,    26,    22,    25,    58,    59,    26,    22,
      62,    58,    59,    26,    37,     0,   145,    22,    21,    37,
      40,    45,    46,     8,    28,    14,    11,    12,    13,   126,
      33,    26,   129,   130,    26,   126,    25,   135,   191,   146,
      27,    25,    37,    27,    32,    37,   143,    33,    25,   146,
      27,    31,   143,    27,   134,   146,   134,   139,     3,     4,
       5,     6,    41,    42,    43,    44,   104,   105,   106,   107,
      15,    16,    17,    35,    36,    20,    21,    22,    22,    23,
      24,    26,    25,   181,    38,    30,    27,    32,     4,    34,
      20,    21,   190,     4,   191,     6,     7,     8,     6,     7,
       8,     3,     4,     5,    15,    16,    17,    15,    16,    17,
       4,    22,    27,    58,    59,    26,    27,    62,    20,    21,
      22,   102,   103,    27,    26,    25,    37,     8,    30,    27,
      32,    38,    34,   108,   109,    27,   134,    39,     6,     7,
       8,   110,   111,    38,     3,     4,     5,    15,    16,    17,
      36,   141,    98,   100,    96,    -1,    58,    59,    -1,    27,
      62,    20,    21,    22,     3,     4,     5,    26,   139,   101,
      99,    30,    -1,    32,    -1,    34,    -1,    -1,    -1,    38,
      -1,    20,    21,    22,    -1,    -1,    -1,    26,    27,    -1,
      -1,    30,    -1,    32,    -1,    34,    -1,    -1,    -1,    58,
      59,    -1,    -1,    62,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,    58,
      59,    -1,    -1,    62,    20,    21,    22,    -1,    -1,    -1,
      26,    20,    21,    22,    30,    -1,    32,    26,    34,    -1,
      -1,    30,    38,    32,    -1,    34,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    58,    59,    -1,    -1,    62,    -1,    -1,    58,
      59,    -1,    -1,    62,    20,    21,    22,     3,     4,     5,
      26,     6,     7,     8,    30,    -1,    32,    -1,    34,    -1,
      15,    16,    17,    -1,    20,    21,    22,    -1,    -1,    -1,
      26,    -1,    27,    -1,    30,    -1,    32,    -1,    34,    -1,
      -1,    -1,    58,    59,    -1,    -1,    62,     6,     7,     8,
       3,     4,     5,    -1,    13,    -1,    15,    16,    17,    -1,
      -1,    -1,    58,    59,    -1,    -1,    62,    20,    21,    22,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    30,    -1,    32,
      -1,    34,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    -1,    -1,    62
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,    15,    16,    17,    77,    78,    79,
      80,    81,    82,    83,   118,     4,     4,     4,     0,    79,
       4,    22,    26,    84,    85,    86,    87,    93,    80,    80,
      80,    83,    93,    94,    86,    14,    25,    47,    26,    37,
      87,    83,    93,    27,    85,     3,     4,     5,    20,    21,
      22,    26,    30,    32,    34,    39,    58,    59,    62,    95,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   115,   116,    27,    80,
      90,    91,    92,    38,    99,   111,    97,    98,   118,    95,
      96,    26,   111,   111,    26,   111,    29,    60,    28,    31,
      33,    32,    45,    46,    41,    42,    43,    44,    35,    36,
      20,    21,    22,    23,    24,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,   114,    18,    19,    26,
      37,    58,    59,   110,    26,    37,    86,    88,    89,    93,
      27,    25,    38,    25,    27,    27,    25,    40,   118,   101,
      97,   102,   103,   104,   105,   106,   106,   107,   107,   107,
     107,   108,   108,   109,   109,   110,   110,   110,    98,     4,
       4,    27,    97,   117,    97,    27,    88,    90,    38,    99,
      26,    37,    89,    13,    92,    98,   110,    40,    95,    27,
      61,    25,    27,    38,    27,    27,    38,    27,    90,    38,
      99,    99,    97,    27,    38
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
#line 84 "parser.y"
    {printf("parser got declare"); TinyParserAppendBlock((yyvsp[(1) - (1)].ast_node));;}
    break;

  case 4:
#line 85 "parser.y"
    {addNext((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node));;}
    break;

  case 5:
#line 88 "parser.y"
    { assignType((yyvsp[(2) - (3)].ast_node), (yyvsp[(1) - (3)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (3)].ast_node); ;}
    break;

  case 6:
#line 92 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); ;}
    break;

  case 7:
#line 93 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs(NULL, (yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 8:
#line 94 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node));;}
    break;

  case 9:
#line 95 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs(NULL, (yyvsp[(1) - (1)].ast_node));;}
    break;

  case 10:
#line 96 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node));;}
    break;

  case 11:
#line 97 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs(NULL, (yyvsp[(1) - (1)].ast_node));;}
    break;

  case 15:
#line 106 "parser.y"
    { (yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 16:
#line 107 "parser.y"
    { addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 17:
#line 109 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 18:
#line 110 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kVarInit, (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 19:
#line 112 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (2)].ast_node); addLeftMost((yyval.ast_node), (yyvsp[(1) - (2)].ast_node)); ;}
    break;

  case 20:
#line 113 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 21:
#line 116 "parser.y"
    {(yyval.ast_node) = createVarDecl(NULL, (yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 22:
#line 117 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node); ;}
    break;

  case 23:
#line 118 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node);;}
    break;

  case 24:
#line 119 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node);;}
    break;

  case 25:
#line 120 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node);;}
    break;

  case 26:
#line 121 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node);;}
    break;

  case 27:
#line 124 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 28:
#line 125 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (2)].ast_node); addLeftMost((yyval.ast_node), (yyvsp[(1) - (2)].ast_node));;}
    break;

  case 29:
#line 126 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 30:
#line 129 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node);;}
    break;

  case 31:
#line 130 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node); ;}
    break;

  case 32:
#line 131 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 33:
#line 132 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node);;}
    break;

  case 34:
#line 133 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, NULL); ;}
    break;

  case 35:
#line 134 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node);;}
    break;

  case 36:
#line 135 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 37:
#line 136 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node);;}
    break;

  case 38:
#line 137 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, NULL); ;}
    break;

  case 39:
#line 140 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node); ;}
    break;

  case 40:
#line 141 "parser.y"
    {addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 41:
#line 144 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 42:
#line 145 "parser.y"
    {addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 43:
#line 148 "parser.y"
    {assignType((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 44:
#line 149 "parser.y"
    {assignType((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 46:
#line 153 "parser.y"
    {(yyval.ast_node) = createPtrType((yyvsp[(2) - (2)].ast_node)); (yyval.ast_node) = createFeaturedType((yyvsp[(2) - (2)].ast_node), NULL);;}
    break;

  case 47:
#line 154 "parser.y"
    {(yyval.ast_node) = createPtrType(NULL); ;}
    break;

  case 48:
#line 155 "parser.y"
    {(yyval.ast_node) = createFeaturedType((yyvsp[(2) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); (yyval.ast_node) = createPtrType((yyval.ast_node)); ;}
    break;

  case 49:
#line 156 "parser.y"
    {(yyval.ast_node) = createPtrType((yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 52:
#line 164 "parser.y"
    {(yyval.ast_node) = createExprTree((yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 53:
#line 165 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kInitList, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 54:
#line 166 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kInitList, (yyvsp[(2) - (4)].ast_node)); ;}
    break;

  case 55:
#line 168 "parser.y"
    { (yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 56:
#line 169 "parser.y"
    { addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 58:
#line 225 "parser.y"
    {(yyval.ast_node) = createBinaryOpTree(",", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 60:
#line 228 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node); addChild((yyval.ast_node), (yyvsp[(1) - (3)].ast_node)); addChild((yyval.ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 62:
#line 232 "parser.y"
    {(yyval.ast_node) = createTrinaryOpTree((yyvsp[(1) - (5)].ast_node), (yyvsp[(3) - (5)].ast_node), (yyvsp[(5) - (5)].ast_node));;}
    break;

  case 64:
#line 236 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("||", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 66:
#line 240 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("&&", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 68:
#line 244 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("|", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 70:
#line 248 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("^", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 72:
#line 252 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("&", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 74:
#line 256 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("==", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 75:
#line 257 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("!=", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 77:
#line 261 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree(">", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 78:
#line 262 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("<", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 79:
#line 263 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree(">=", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 80:
#line 264 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("<=", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 82:
#line 268 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("<<", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 83:
#line 269 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree(">>", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 85:
#line 273 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("+", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 86:
#line 274 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("-", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 88:
#line 278 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("*", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 89:
#line 279 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("/", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 90:
#line 280 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("%", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 92:
#line 284 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kCast, (yyvsp[(2) - (4)].ast_node), (yyvsp[(4) - (4)].ast_node)); ;}
    break;

  case 94:
#line 288 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("++_", (yyvsp[(2) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 95:
#line 289 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("--_", (yyvsp[(2) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 96:
#line 290 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node); addChild((yyval.ast_node), (yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 97:
#line 291 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("sizeof", (yyvsp[(2) - (2)].ast_node));;}
    break;

  case 98:
#line 292 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("sizeof", (yyvsp[(3) - (4)].ast_node));;}
    break;

  case 99:
#line 295 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 100:
#line 296 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kSubScript, (yyvsp[(1) - (4)].ast_node), (yyvsp[(3) - (4)].ast_node)); ;}
    break;

  case 101:
#line 297 "parser.y"
    {(yyval.ast_node) = createStructMember((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node), "."); ;}
    break;

  case 102:
#line 298 "parser.y"
    {(yyval.ast_node) = createStructMember((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node), "->"); ;}
    break;

  case 103:
#line 299 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("_++", (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 104:
#line 300 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("_--", (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 105:
#line 301 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 106:
#line 305 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 107:
#line 306 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 108:
#line 307 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 109:
#line 308 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node);;}
    break;

  case 110:
#line 311 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "=", 1); ;}
    break;

  case 111:
#line 312 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "&", 1);;}
    break;

  case 112:
#line 313 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "/", 1);;}
    break;

  case 113:
#line 314 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "+", 1);;}
    break;

  case 114:
#line 315 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "-", 1);;}
    break;

  case 115:
#line 316 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "*", 1);;}
    break;

  case 116:
#line 317 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "<", 1);;}
    break;

  case 117:
#line 318 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, ">", 1);;}
    break;

  case 118:
#line 319 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "|", 1);;}
    break;

  case 119:
#line 320 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "^", 1);;}
    break;

  case 120:
#line 321 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "%", 1);;}
    break;

  case 121:
#line 324 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "+", 1);;}
    break;

  case 122:
#line 325 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "-", 1);;}
    break;

  case 123:
#line 326 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "&", 1);;}
    break;

  case 124:
#line 327 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "!", 1);;}
    break;

  case 125:
#line 328 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "~", 1);;}
    break;

  case 126:
#line 329 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "*", 1);;}
    break;

  case 127:
#line 333 "parser.y"
    { (yyval.ast_node) = createFunctionCallTree((yyvsp[(1) - (3)].ast_node), NULL);;}
    break;

  case 128:
#line 334 "parser.y"
    {(yyval.ast_node) = createFunctionCallTree((yyvsp[(1) - (4)].ast_node), (yyvsp[(3) - (4)].ast_node));;}
    break;

  case 129:
#line 337 "parser.y"
    {(yyval.ast_node) = createArgList((yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 130:
#line 338 "parser.y"
    {addChild((yyval.ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 132:
#line 352 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (2)].ast_node); (yyval.ast_node)->type_ = kType; ;}
    break;

  case 133:
#line 353 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (2)].ast_node); (yyval.ast_node)->type_ = kType; ;}
    break;

  case 134:
#line 354 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (2)].ast_node); (yyval.ast_node)->type_ = kType;;}
    break;


/* Line 1267 of yacc.c.  */
#line 2281 "./tiny_compiler_yacc.c"
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


#line 360 "parser.y"

int yyerror(char* s) {
    printf("tinyParser: \033[31merror:\033[0m %s at %s:%d:%d\n", s, TinyParserGetPwd(), TinyParserGetLine(), TinyParserGetColumn() - TinyParserGetCurTokLen());
    show_lexer_error(TinyParserGetPwd(), TinyParserGetColumn() - TinyParserGetCurTokLen(), TinyParserGetLine());
    return 1;
}


