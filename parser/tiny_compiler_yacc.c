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




/* Copy the first part of user declarations.  */
#line 2 "parser.y"

  #include <stdio.h>
  #include "parser.h"
  #include "../exceptions/parser_error.h"
  #include "../sematics/sematics.h"
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
#line 19 "parser.y"
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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1121

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  200
/* YYNRULES -- Number of states.  */
#define YYNSTATES  350

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   328

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
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    17,    21,
      24,    26,    29,    33,    36,    39,    42,    44,    47,    49,
      51,    53,    55,    57,    61,    63,    67,    70,    72,    74,
      78,    83,    87,    92,    96,    98,   101,   103,   107,   112,
     116,   120,   123,   128,   132,   136,   139,   141,   145,   147,
     151,   154,   157,   159,   162,   164,   168,   171,   173,   176,
     178,   182,   187,   189,   193,   195,   197,   199,   201,   203,
     205,   209,   214,   218,   221,   223,   228,   232,   236,   239,
     241,   244,   250,   258,   264,   270,   278,   288,   297,   306,
     314,   323,   331,   339,   346,   350,   353,   356,   360,   363,
     365,   369,   371,   375,   377,   383,   385,   389,   391,   395,
     397,   401,   403,   407,   409,   413,   415,   419,   423,   425,
     429,   433,   437,   441,   443,   447,   451,   453,   457,   461,
     463,   467,   471,   475,   477,   482,   484,   487,   490,   493,
     496,   501,   503,   508,   512,   516,   519,   522,   524,   528,
     533,   535,   539,   541,   543,   545,   549,   551,   553,   555,
     557,   559,   561,   563,   565,   567,   569,   571,   573,   575,
     577,   579,   581,   583,   586,   588,   590,   592,   594,   600,
     605,   608,   610,   612,   614,   617,   621,   624,   626,   629,
     631,   633,   637,   639,   645,   650,   653,   655,   659,   661,
     665
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      75,     0,    -1,    76,    -1,    77,    -1,    76,    77,    -1,
      78,    -1,    80,    -1,     9,    80,    -1,    81,    87,   101,
      -1,    87,   101,    -1,    80,    -1,    79,    80,    -1,    81,
      85,    15,    -1,    81,    15,    -1,    82,    81,    -1,    83,
      81,    -1,    83,    -1,    84,    81,    -1,    84,    -1,     8,
      -1,   128,    -1,     7,    -1,    86,    -1,    85,    27,    86,
      -1,    87,    -1,    87,    49,    96,    -1,    94,    88,    -1,
      88,    -1,     4,    -1,    28,    87,    29,    -1,    88,    39,
     108,    40,    -1,    88,    39,    40,    -1,    88,    28,    91,
      29,    -1,    88,    28,    29,    -1,    94,    -1,    94,    90,
      -1,    90,    -1,    28,    89,    29,    -1,    90,    39,   108,
      40,    -1,    39,   108,    40,    -1,    90,    39,    40,    -1,
      39,    40,    -1,    90,    28,    91,    29,    -1,    28,    91,
      29,    -1,    90,    28,    29,    -1,    28,    29,    -1,    92,
      -1,    92,    27,    10,    -1,    93,    -1,    92,    27,    93,
      -1,    81,    87,    -1,    81,    89,    -1,    81,    -1,    24,
      95,    -1,    24,    -1,    24,    95,    94,    -1,    24,    94,
      -1,    84,    -1,    95,    84,    -1,   107,    -1,    41,    97,
      42,    -1,    41,    97,    27,    42,    -1,    96,    -1,    97,
      27,    96,    -1,    99,    -1,   100,    -1,   101,    -1,   103,
      -1,   104,    -1,   105,    -1,     4,    63,    98,    -1,    71,
     108,    63,    98,    -1,    72,    63,    98,    -1,   106,    15,
      -1,    15,    -1,    41,    79,   102,    42,    -1,    41,   102,
      42,    -1,    41,    79,    42,    -1,    41,    42,    -1,    98,
      -1,   102,    98,    -1,    65,    28,   106,    29,    98,    -1,
      65,    28,   106,    29,    98,    66,    98,    -1,    70,    28,
     106,    29,    98,    -1,    67,    28,   106,    29,    98,    -1,
      68,    98,    67,    28,   106,    29,    15,    -1,    69,    28,
     106,    15,   106,    15,   106,    29,    98,    -1,    69,    28,
     106,    15,   106,    15,    29,    98,    -1,    69,    28,   106,
      15,    15,   106,    29,    98,    -1,    69,    28,   106,    15,
      15,    29,    98,    -1,    69,    28,    15,   106,    15,   106,
      29,    98,    -1,    69,    28,    15,   106,    15,    29,    98,
      -1,    69,    28,    15,    15,   106,    29,    98,    -1,    69,
      28,    15,    15,    29,    98,    -1,    11,     4,    15,    -1,
      13,    15,    -1,    12,    15,    -1,    14,   106,    15,    -1,
      14,    15,    -1,   107,    -1,   106,    27,   107,    -1,   108,
      -1,   120,   125,   107,    -1,   109,    -1,   109,    62,   106,
      63,   108,    -1,   110,    -1,   109,    31,   110,    -1,   111,
      -1,   110,    30,   111,    -1,   112,    -1,   111,    33,   112,
      -1,   113,    -1,   112,    35,   113,    -1,   114,    -1,   113,
      34,   114,    -1,   115,    -1,   114,    47,   115,    -1,   114,
      48,   115,    -1,   116,    -1,   115,    43,   116,    -1,   115,
      44,   116,    -1,   115,    45,   116,    -1,   115,    46,   116,
      -1,   117,    -1,   116,    37,   117,    -1,   116,    38,   117,
      -1,   118,    -1,   117,    22,   118,    -1,   117,    23,   118,
      -1,   119,    -1,   118,    24,   119,    -1,   118,    25,   119,
      -1,   118,    26,   119,    -1,   120,    -1,    28,   127,    29,
     119,    -1,   121,    -1,    60,   120,    -1,    61,   120,    -1,
     126,   119,    -1,    64,   120,    -1,    64,    28,   128,    29,
      -1,   124,    -1,   121,    39,   106,    40,    -1,   121,    20,
       4,    -1,   121,    21,     4,    -1,   121,    60,    -1,   121,
      61,    -1,   122,    -1,   121,    28,    29,    -1,   121,    28,
     123,    29,    -1,   107,    -1,   123,    27,   107,    -1,     3,
      -1,     5,    -1,     4,    -1,    28,   106,    29,    -1,    49,
      -1,    58,    -1,    53,    -1,    50,    -1,    51,    -1,    52,
      -1,    55,    -1,    56,    -1,    59,    -1,    57,    -1,    54,
      -1,    22,    -1,    23,    -1,    34,    -1,    32,    -1,    36,
      -1,    24,    -1,   133,    89,    -1,   133,    -1,     6,    -1,
     129,    -1,   136,    -1,   130,     4,    41,   131,    42,    -1,
     130,    41,   131,    42,    -1,   130,     4,    -1,    17,    -1,
      18,    -1,   132,    -1,   131,   132,    -1,   133,   134,    15,
      -1,    83,   133,    -1,    83,    -1,    84,   133,    -1,    84,
      -1,   135,    -1,   134,    27,   135,    -1,    87,    -1,   139,
       4,    41,   137,    42,    -1,   139,    41,   137,    42,    -1,
     139,     4,    -1,   138,    -1,   137,    27,   138,    -1,     4,
      -1,     4,    49,   108,    -1,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    95,    95,    97,    98,   100,   101,   102,   105,   106,
     109,   110,   113,   114,   124,   125,   126,   127,   128,   131,
     133,   135,   137,   138,   140,   141,   143,   144,   147,   148,
     149,   150,   151,   152,   155,   156,   157,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   171,   172,   175,   176,
     179,   180,   181,   184,   185,   186,   187,   190,   191,   195,
     196,   197,   199,   200,   203,   204,   205,   206,   207,   208,
     211,   212,   213,   216,   217,   220,   221,   222,   223,   226,
     227,   230,   231,   232,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   247,   248,   249,   250,   251,   256,
     257,   259,   260,   263,   264,   267,   268,   271,   272,   275,
     276,   279,   280,   283,   284,   287,   288,   289,   292,   293,
     294,   295,   296,   299,   300,   301,   304,   305,   306,   309,
     310,   311,   312,   315,   316,   319,   320,   321,   322,   323,
     324,   327,   328,   329,   330,   331,   332,   333,   336,   337,
     340,   341,   344,   345,   346,   347,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   363,   364,   365,
     366,   367,   368,   374,   375,   378,   380,   381,   385,   386,
     387,   390,   391,   394,   395,   398,   405,   406,   407,   408,
     411,   412,   415,   420,   421,   422,   425,   426,   429,   430,
     433
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ID", "STR", "TYPE", "CONST",
  "STATIC", "TYPE_DEF", "VARGS", "GOTO", "BREAK", "CONTINUE", "RETURN",
  "SEMI", "HEADER", "STRUCT", "UNION", "ENUM", "DOT", "ARROW", "ADD",
  "SUB", "MULT", "DIV", "MOD", "COMMA", "LB", "RB", "LOGIC_AND",
  "LOGIC_OR", "LOGIC_NOT", "BIT_OR", "BIT_AND", "BIT_XOR", "BIT_NOT",
  "LSHIFT", "RSHIFT", "LSBSCRPT", "RSBSCRPT", "LSCOPE", "RSCOPE", "GT",
  "LT", "GE", "LE", "EQ", "NEQ", "ASSIGN", "A_PLUS", "A_SUB", "A_MULT",
  "A_DIV", "A_MOD", "A_LS", "A_RS", "A_XOR", "A_AND", "A_OR", "PP", "SS",
  "T1", "T2", "SIZE_OF", "IF", "ELSE", "WHILE", "DO", "FOR", "SWITCH",
  "CASE", "DEFAULT", "\"then\"", "$accept", "program_unit",
  "translation_unit", "external_decl", "function_definition", "decl_list",
  "decl", "decl_specs", "storage_class_spec", "type_spec",
  "type_qualifier", "init_declarator_list", "init_declarator",
  "declarator", "direct_declarator", "abstract_declarator",
  "direct_abstract_declarator", "param_type_list", "param_list",
  "param_decl", "pointer", "type_qualifier_list", "initializer",
  "initializer_list", "stat", "labeled_stat", "exp_stat", "compound_stat",
  "stat_list", "selection_stat", "iteration_stat", "jump_stat",
  "expression", "expression11", "expression10", "expression9",
  "expression8", "expression7", "expression6", "expression5",
  "expression4", "expression3", "expression2", "expression1", "term",
  "factor", "unaries", "postfix", "function_call", "args_list", "single",
  "aop", "uop", "type_name_cast", "type_name", "struct_or_union_spec",
  "struct_or_union", "struct_decl_list", "struct_decl",
  "spec_qualifier_list", "struct_declarator_list", "struct_declarator",
  "enum_spec", "enumerator_list", "enumerator", "enum_const", 0
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
     325,   326,   327,   328
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    76,    77,    77,    77,    78,    78,
      79,    79,    80,    80,    81,    81,    81,    81,    81,    82,
      83,    84,    85,    85,    86,    86,    87,    87,    88,    88,
      88,    88,    88,    88,    89,    89,    89,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    91,    91,    92,    92,
      93,    93,    93,    94,    94,    94,    94,    95,    95,    96,
      96,    96,    97,    97,    98,    98,    98,    98,    98,    98,
      99,    99,    99,   100,   100,   101,   101,   101,   101,   102,
     102,   103,   103,   103,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   105,   105,   105,   105,   105,   106,
     106,   107,   107,   108,   108,   109,   109,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   114,   115,   115,
     115,   115,   115,   116,   116,   116,   117,   117,   117,   118,
     118,   118,   118,   119,   119,   120,   120,   120,   120,   120,
     120,   121,   121,   121,   121,   121,   121,   121,   122,   122,
     123,   123,   124,   124,   124,   124,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   126,   126,   126,
     126,   126,   126,   127,   127,   128,   128,   128,   129,   129,
     129,   130,   130,   131,   131,   132,   133,   133,   133,   133,
     134,   134,   135,   136,   136,   136,   137,   137,   138,   138,
     139
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     3,     2,
       1,     2,     3,     2,     2,     2,     1,     2,     1,     1,
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
       4,     1,     4,     3,     3,     2,     2,     1,     3,     4,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     5,     4,
       2,     1,     1,     1,     2,     3,     2,     1,     2,     1,
       1,     3,     1,     5,     4,     2,     1,     3,     1,     3,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    28,   175,    21,    19,     0,   181,   182,   200,    54,
       0,     0,     2,     3,     5,     6,     0,     0,    16,    18,
       0,    27,     0,    20,   176,     0,   177,     0,     7,     0,
      57,    56,    53,     0,     1,     4,    13,     0,    22,    24,
      14,    15,    17,     0,     9,     0,     0,    26,   180,     0,
     195,     0,    24,    58,    55,    29,    12,     0,     0,     8,
     152,   154,   153,     0,     0,     0,     0,    74,   167,   168,
     172,     0,   170,   169,   171,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    79,    64,
      65,    66,     0,    67,    68,    69,     0,    99,   101,   103,
     105,   107,   109,   111,   113,   115,   118,   123,   126,   129,
     133,   135,   147,   141,     0,    33,    52,     0,    46,    48,
     154,    31,     0,   133,     0,   187,   189,     0,   183,     0,
       0,   198,     0,   196,    23,     0,    25,    59,     0,     0,
      96,    95,    98,     0,     0,     0,   174,     0,   136,   137,
       0,   139,     0,     0,     0,     0,     0,     0,     0,    77,
      11,     0,    76,    80,    73,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   156,   159,   160,   161,   158,
     166,   162,   163,   165,   157,   164,     0,     0,     0,     0,
       0,   145,   146,   138,     0,     0,    50,    51,    36,    34,
      32,     0,    30,     0,   186,   188,   179,   184,   192,     0,
     190,     0,     0,     0,   194,    62,     0,    70,    94,    97,
     155,     0,     0,   173,    34,     0,     0,     0,     0,     0,
       0,     0,     0,    72,    75,   100,   106,     0,   108,   110,
     112,   114,   116,   117,   119,   120,   121,   122,   124,   125,
     127,   128,   130,   131,   132,   102,   143,   144,   148,   150,
       0,     0,    45,     0,     0,    41,     0,     0,     0,    35,
      47,    49,   178,   185,     0,   193,   199,   197,     0,    60,
     134,   140,     0,     0,     0,     0,     0,     0,     0,    71,
       0,     0,   149,   142,    37,    43,    39,    44,     0,    40,
       0,   191,    61,    63,    81,    84,     0,     0,     0,     0,
       0,     0,    83,   104,   151,    42,    38,     0,     0,    93,
       0,     0,     0,     0,     0,     0,    82,    85,    92,    91,
       0,    89,     0,     0,     0,    90,    88,    87,     0,    86
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    86,    15,   116,    17,    18,
      19,    37,    38,    20,    21,   273,   208,   274,   118,   119,
      22,    32,   136,   226,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   270,
     113,   196,   114,   145,    23,    24,    25,   127,   128,   129,
     219,   220,    26,   132,   133,    27
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -195
static const yytype_int16 yypact[] =
{
     308,  -195,  -195,  -195,  -195,   316,  -195,  -195,  -195,    24,
     104,    16,   308,  -195,  -195,  -195,   103,   316,   316,   316,
      -8,    -3,    33,  -195,  -195,     9,  -195,    14,  -195,   103,
    -195,  -195,    24,    95,  -195,  -195,  -195,     8,  -195,    84,
    -195,  -195,  -195,   277,  -195,   384,   503,    -3,    89,   260,
      94,    70,    31,  -195,  -195,  -195,  -195,   104,   579,  -195,
    -195,    76,  -195,   139,   168,   178,   695,  -195,  -195,  -195,
    -195,   627,  -195,  -195,  -195,  -195,   974,   974,   989,   141,
     177,   557,   191,   192,  1023,   137,   347,  -195,  -195,  -195,
    -195,  -195,   417,  -195,  -195,  -195,   114,  -195,  -195,    -5,
     199,   195,   203,   201,    62,   198,   135,   166,   200,  -195,
    1062,   156,  -195,  -195,  1023,  -195,    10,   210,   218,  -195,
    -195,  -195,   212,  -195,   260,   260,   260,   185,  -195,   104,
      70,   215,    58,  -195,  -195,   579,  -195,  -195,   557,   250,
    -195,  -195,  -195,   151,     3,   232,    87,  1023,  -195,  -195,
     661,  -195,  1023,  1023,   202,   711,  1023,   209,   557,  -195,
    -195,   487,  -195,  -195,  -195,  1023,  1023,  1023,  1023,  1023,
    1023,  1023,  1023,  1023,  1023,  1023,  1023,  1023,  1023,  1023,
    1023,  1023,  1023,  1023,  1023,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  -195,  1023,   282,   289,   745,
    1023,  -195,  -195,  -195,  1057,   760,  -195,  -195,    45,    37,
    -195,   387,  -195,   204,  -195,  -195,  -195,  -195,  -195,   152,
    -195,    74,  1023,    70,  -195,  -195,    75,  -195,  -195,  -195,
    -195,  1023,  1071,  -195,    54,   268,    48,   111,   270,   807,
     155,   179,   557,  -195,  -195,  -195,   199,   -17,   195,   203,
     201,    62,   198,   198,   135,   135,   135,   135,   166,   166,
     200,   200,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
     205,    39,  -195,   274,   278,  -195,   280,   796,   814,    45,
    -195,  -195,  -195,  -195,   104,  -195,  -195,  -195,   433,  -195,
    -195,  -195,   557,   557,  1023,   829,   159,   876,   557,  -195,
    1023,  1023,  -195,  -195,  -195,  -195,  -195,  -195,   281,  -195,
     299,  -195,  -195,  -195,   255,  -195,   246,   557,   275,   891,
     925,   172,  -195,  -195,  -195,  -195,  -195,   557,   325,  -195,
     557,   557,   279,   557,   345,   940,  -195,  -195,  -195,  -195,
     557,  -195,   557,   557,   349,  -195,  -195,  -195,   557,  -195
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -195,  -195,  -195,   331,  -195,  -195,    19,    51,  -195,   -28,
      -4,  -195,   300,   -10,   -19,   -87,  -194,   -37,  -195,   145,
      55,  -195,  -124,  -195,   -80,  -195,  -195,     0,   287,  -195,
    -195,  -195,   -64,   -31,   -42,  -195,   197,   214,   208,   216,
     196,    42,   154,    18,    68,   -70,   -24,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,   230,  -195,  -195,   244,  -118,   -54,
    -195,   100,  -195,   257,   162,  -195
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      33,   154,   143,    47,   122,    30,    39,   144,   117,   217,
     165,   225,   163,    48,     1,   279,    34,   146,    50,    52,
      44,   125,   123,    56,    28,    45,   166,   137,    53,   207,
     165,     3,   230,    43,     9,    57,    46,     1,   204,    59,
     279,     1,   157,   125,   203,   126,   300,    52,     9,   205,
      49,    16,   148,   149,   151,    51,    29,   167,   227,   233,
     123,    10,    87,    16,    31,   204,   165,   126,    40,    41,
      42,   214,   215,   277,   131,   165,   205,   292,   243,   303,
      58,   163,   232,   144,   278,   223,   144,    54,   236,   237,
     123,   240,   241,   205,    29,   217,   125,   125,   125,   125,
     224,   223,   288,   247,   137,   160,   206,     1,     1,   172,
     173,     9,   262,   263,   264,   232,   285,   289,    36,   218,
     126,   126,   126,   126,    55,    43,   205,     9,     9,   164,
     124,    10,    10,    58,   245,   130,   271,    29,   165,   138,
     293,   165,   123,   139,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   290,   299,   276,   313,   265,   229,   283,   269,   152,
     297,   209,   178,   179,   319,   296,   197,   198,   165,   284,
     286,   123,   165,   140,   199,   125,   165,   335,   180,   181,
      47,     2,     3,   141,    33,   200,   258,   259,   123,   165,
     158,   234,     6,     7,     8,   153,   165,   123,   298,   126,
       2,     3,   314,   315,   252,   253,   201,   202,   322,   155,
     156,     6,     7,     8,   182,   183,   184,   216,   169,   168,
     316,   318,   301,   321,   302,   171,   310,   329,   170,   210,
     308,   174,   175,   176,   177,   211,   282,   336,   260,   261,
     338,   339,   212,   341,   123,   332,   334,   137,   323,   209,
     345,   231,   346,   347,   222,   228,     2,     3,   349,   238,
     324,   344,   242,   165,   218,   328,   123,     6,     7,     8,
      60,    61,    62,     2,     3,     4,   266,   234,    63,    64,
      65,    66,    67,   267,     6,     7,     8,   291,   294,    68,
      69,    70,   165,   304,   330,    71,   165,   305,   340,    72,
     325,    73,     1,    74,     2,     3,     4,     5,    43,    75,
     306,   327,     2,     3,     4,     6,     7,     8,   254,   255,
     256,   257,     9,     6,     7,     8,    10,    76,    77,   326,
     337,    78,    79,    35,    80,    81,    82,    83,    84,    85,
      60,    61,    62,     2,     3,     4,   281,   134,    63,    64,
      65,    66,    67,   246,     6,     7,     8,   251,   213,    68,
      69,    70,   165,   161,   342,    71,   165,   249,   348,    72,
     235,    73,   248,    74,   311,   287,   250,   221,    43,   159,
       2,     3,     4,     2,     3,     4,     0,   280,     0,     0,
       0,     6,     7,     8,     6,     7,     8,    76,    77,     0,
       0,    78,    79,   115,    80,    81,    82,    83,    84,    85,
      60,    61,    62,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,     0,     0,     0,    60,   120,    62,    68,
      69,    70,     0,     0,     0,    71,     0,     0,     0,    72,
       0,    73,     0,    74,     0,    68,    69,    70,    43,   162,
       0,    71,     0,     0,     0,    72,     0,    73,     0,    74,
       0,     0,     0,     0,   135,   312,     0,    76,    77,     0,
       0,    78,    79,     0,    80,    81,    82,    83,    84,    85,
      60,    61,    62,    76,    77,     0,     0,    78,    63,    64,
      65,    66,    67,     0,     0,     0,    60,   120,    62,    68,
      69,    70,     0,     0,     0,    71,     0,     0,     0,    72,
       0,    73,     0,    74,     0,    68,    69,    70,    43,   244,
       0,    71,     0,     0,     0,    72,     0,    73,     0,    74,
       0,     0,     0,   121,     0,     0,     0,    76,    77,     0,
       0,    78,    79,     0,    80,    81,    82,    83,    84,    85,
      60,    61,    62,    76,    77,     0,     0,    78,    63,    64,
      65,    66,    67,     0,     0,     0,     0,     0,     0,    68,
      69,    70,    60,   120,    62,    71,     0,     0,     0,    72,
       0,    73,     0,    74,     0,     0,     0,     0,    43,     0,
       0,    68,    69,    70,     0,     0,     0,    71,     0,     0,
       0,    72,     0,    73,     0,    74,     0,    76,    77,     0,
     135,    78,    79,     0,    80,    81,    82,    83,    84,    85,
      60,   120,    62,     2,     3,     0,     0,     0,     0,    76,
      77,     0,     0,    78,     6,     7,     8,     0,     0,    68,
      69,    70,     0,     0,     0,    71,     0,     0,     0,    72,
       0,    73,     0,    74,    60,   120,    62,     2,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       8,     0,     0,    68,    69,    70,     0,    76,    77,    71,
       0,    78,     0,    72,     0,    73,     0,    74,    60,   120,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,     0,     0,     0,    60,   120,    62,    68,    69,    70,
       0,    76,    77,    71,     0,    78,   239,    72,     0,    73,
       0,    74,     0,    68,    69,    70,     0,     0,     0,    71,
       0,     0,     0,    72,     0,    73,     0,    74,    60,   120,
      62,     0,     0,     0,     0,    76,    77,     0,     0,    78,
       0,     0,     0,    60,   120,    62,     0,    68,    69,    70,
       0,    76,    77,    71,   268,    78,     0,    72,     0,    73,
       0,    74,    68,    69,    70,     0,     0,     0,    71,     0,
       0,     0,    72,     0,    73,     0,    74,     0,     0,     0,
     275,     0,     2,     3,     4,    76,    77,     0,     0,    78,
      60,   120,    62,     6,     7,     8,     0,    60,   120,    62,
      76,    77,   295,     0,    78,   307,     0,     0,     0,    68,
      69,    70,    60,   120,    62,    71,    68,    69,    70,    72,
       0,    73,    71,    74,     0,     0,    72,     0,    73,     0,
      74,    68,    69,    70,   309,     0,     0,    71,   317,     0,
       0,    72,     0,    73,     0,    74,     0,    76,    77,     0,
       0,    78,     0,     0,    76,    77,     0,     0,    78,    60,
     120,    62,     0,     0,     0,     0,     0,     0,     0,    76,
      77,   320,     0,    78,    60,   120,    62,     0,    68,    69,
      70,     0,     0,     0,    71,     0,     0,     0,    72,     0,
      73,     0,    74,    68,    69,    70,     0,     0,     0,    71,
     331,     0,     0,    72,     0,    73,     0,    74,    60,   120,
      62,     0,     0,     0,     0,     0,    76,    77,     0,     0,
      78,     0,     0,    60,   120,    62,     0,    68,    69,    70,
       0,    76,    77,    71,   333,    78,     0,    72,     0,    73,
       0,    74,    68,    69,    70,     0,     0,     0,    71,   343,
       0,     0,    72,     0,    73,     0,    74,    60,   120,    62,
       0,     0,     0,     0,     0,    76,    77,     0,     0,    78,
       0,     0,    60,   120,    62,     0,    68,    69,    70,     0,
      76,    77,   147,     0,    78,     0,    72,     0,    73,     0,
      74,    68,    69,    70,     0,     0,     0,   150,     0,     0,
       0,    72,     0,    73,     0,    74,    60,   120,    62,     0,
       0,     0,     0,     0,    76,    77,     0,     0,    78,     0,
       0,     0,     0,     0,     0,    68,    69,    70,     0,    76,
      77,    71,     0,    78,     0,    72,     0,    73,     0,    74,
       0,     1,     0,     2,     3,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     7,     8,     2,     3,     4,
       0,     9,     0,    76,    77,   204,   272,    78,     6,     7,
       8,     0,     0,     0,     0,     9,   205,     0,     0,   232,
     272,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     205,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195
};

static const yytype_int16 yycheck[] =
{
      10,    81,    66,    22,    46,     9,    16,    71,    45,   127,
      27,   135,    92,     4,     4,   209,     0,    71,     4,    29,
      20,    49,    46,    15,     5,    28,    31,    58,    32,   116,
      27,     7,    29,    41,    24,    27,    39,     4,    28,    39,
     234,     4,    84,    71,   114,    49,    63,    57,    24,    39,
      41,     0,    76,    77,    78,    41,     5,    62,   138,   146,
      84,    28,    43,    12,     9,    28,    27,    71,    17,    18,
      19,   125,   126,    28,     4,    27,    39,    29,   158,    40,
      49,   161,    28,   147,    39,    27,   150,    32,   152,   153,
     114,   155,   156,    39,    43,   213,   124,   125,   126,   127,
      42,    27,    27,   167,   135,    86,   116,     4,     4,    47,
      48,    24,   182,   183,   184,    28,    42,    42,    15,   129,
     124,   125,   126,   127,    29,    41,    39,    24,    24,    15,
      41,    28,    28,    49,   165,    41,   200,    86,    27,    63,
      29,    27,   166,     4,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   231,   242,   205,   288,   196,    15,    15,   199,    28,
      15,   116,    37,    38,    15,   239,    20,    21,    27,    27,
     222,   205,    27,    15,    28,   213,    27,    15,    22,    23,
     209,     6,     7,    15,   204,    39,   178,   179,   222,    27,
      63,   146,    17,    18,    19,    28,    27,   231,    29,   213,
       6,     7,   292,   293,   172,   173,    60,    61,   298,    28,
      28,    17,    18,    19,    24,    25,    26,    42,    33,    30,
     294,   295,    27,   297,    29,    34,   278,   317,    35,    29,
     277,    43,    44,    45,    46,    27,    42,   327,   180,   181,
     330,   331,    40,   333,   278,   319,   320,   288,   300,   204,
     340,    29,   342,   343,    49,    15,     6,     7,   348,    67,
     301,   335,    63,    27,   284,    29,   300,    17,    18,    19,
       3,     4,     5,     6,     7,     8,     4,   232,    11,    12,
      13,    14,    15,     4,    17,    18,    19,    29,    28,    22,
      23,    24,    27,    29,    29,    28,    27,    29,    29,    32,
      29,    34,     4,    36,     6,     7,     8,     9,    41,    42,
      40,    66,     6,     7,     8,    17,    18,    19,   174,   175,
     176,   177,    24,    17,    18,    19,    28,    60,    61,    40,
      15,    64,    65,    12,    67,    68,    69,    70,    71,    72,
       3,     4,     5,     6,     7,     8,   211,    57,    11,    12,
      13,    14,    15,   166,    17,    18,    19,   171,   124,    22,
      23,    24,    27,    86,    29,    28,    27,   169,    29,    32,
     150,    34,   168,    36,   284,   223,   170,   130,    41,    42,
       6,     7,     8,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    17,    18,    19,    17,    18,    19,    60,    61,    -1,
      -1,    64,    65,    29,    67,    68,    69,    70,    71,    72,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    11,    12,
      13,    14,    15,    -1,    -1,    -1,     3,     4,     5,    22,
      23,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,    32,
      -1,    34,    -1,    36,    -1,    22,    23,    24,    41,    42,
      -1,    28,    -1,    -1,    -1,    32,    -1,    34,    -1,    36,
      -1,    -1,    -1,    -1,    41,    42,    -1,    60,    61,    -1,
      -1,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
       3,     4,     5,    60,    61,    -1,    -1,    64,    11,    12,
      13,    14,    15,    -1,    -1,    -1,     3,     4,     5,    22,
      23,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,    32,
      -1,    34,    -1,    36,    -1,    22,    23,    24,    41,    42,
      -1,    28,    -1,    -1,    -1,    32,    -1,    34,    -1,    36,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    60,    61,    -1,
      -1,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
       3,     4,     5,    60,    61,    -1,    -1,    64,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      23,    24,     3,     4,     5,    28,    -1,    -1,    -1,    32,
      -1,    34,    -1,    36,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    22,    23,    24,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    32,    -1,    34,    -1,    36,    -1,    60,    61,    -1,
      41,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    60,
      61,    -1,    -1,    64,    17,    18,    19,    -1,    -1,    22,
      23,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,    32,
      -1,    34,    -1,    36,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      19,    -1,    -1,    22,    23,    24,    -1,    60,    61,    28,
      -1,    64,    -1,    32,    -1,    34,    -1,    36,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    -1,    -1,     3,     4,     5,    22,    23,    24,
      -1,    60,    61,    28,    -1,    64,    15,    32,    -1,    34,
      -1,    36,    -1,    22,    23,    24,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    32,    -1,    34,    -1,    36,     3,     4,
       5,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,
      -1,    -1,    -1,     3,     4,     5,    -1,    22,    23,    24,
      -1,    60,    61,    28,    29,    64,    -1,    32,    -1,    34,
      -1,    36,    22,    23,    24,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    32,    -1,    34,    -1,    36,    -1,    -1,    -1,
      40,    -1,     6,     7,     8,    60,    61,    -1,    -1,    64,
       3,     4,     5,    17,    18,    19,    -1,     3,     4,     5,
      60,    61,    15,    -1,    64,    29,    -1,    -1,    -1,    22,
      23,    24,     3,     4,     5,    28,    22,    23,    24,    32,
      -1,    34,    28,    36,    -1,    -1,    32,    -1,    34,    -1,
      36,    22,    23,    24,    40,    -1,    -1,    28,    29,    -1,
      -1,    32,    -1,    34,    -1,    36,    -1,    60,    61,    -1,
      -1,    64,    -1,    -1,    60,    61,    -1,    -1,    64,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    15,    -1,    64,     3,     4,     5,    -1,    22,    23,
      24,    -1,    -1,    -1,    28,    -1,    -1,    -1,    32,    -1,
      34,    -1,    36,    22,    23,    24,    -1,    -1,    -1,    28,
      29,    -1,    -1,    32,    -1,    34,    -1,    36,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,
      64,    -1,    -1,     3,     4,     5,    -1,    22,    23,    24,
      -1,    60,    61,    28,    29,    64,    -1,    32,    -1,    34,
      -1,    36,    22,    23,    24,    -1,    -1,    -1,    28,    29,
      -1,    -1,    32,    -1,    34,    -1,    36,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,
      -1,    -1,     3,     4,     5,    -1,    22,    23,    24,    -1,
      60,    61,    28,    -1,    64,    -1,    32,    -1,    34,    -1,
      36,    22,    23,    24,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    32,    -1,    34,    -1,    36,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,    60,
      61,    28,    -1,    64,    -1,    32,    -1,    34,    -1,    36,
      -1,     4,    -1,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,     6,     7,     8,
      -1,    24,    -1,    60,    61,    28,    29,    64,    17,    18,
      19,    -1,    -1,    -1,    -1,    24,    39,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     6,     7,     8,     9,    17,    18,    19,    24,
      28,    75,    76,    77,    78,    80,    81,    82,    83,    84,
      87,    88,    94,   128,   129,   130,   136,   139,    80,    81,
      84,    94,    95,    87,     0,    77,    15,    85,    86,    87,
      81,    81,    81,    41,   101,    28,    39,    88,     4,    41,
       4,    41,    87,    84,    94,    29,    15,    27,    49,   101,
       3,     4,     5,    11,    12,    13,    14,    15,    22,    23,
      24,    28,    32,    34,    36,    42,    60,    61,    64,    65,
      67,    68,    69,    70,    71,    72,    79,    80,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   124,   126,    29,    81,    91,    92,    93,
       4,    40,   108,   120,    41,    83,    84,   131,   132,   133,
      41,     4,   137,   138,    86,    41,    96,   107,    63,     4,
      15,    15,    15,   106,   106,   127,   133,    28,   120,   120,
      28,   120,    28,    28,    98,    28,    28,   108,    63,    42,
      80,   102,    42,    98,    15,    27,    31,    62,    30,    33,
      35,    34,    47,    48,    43,    44,    45,    46,    37,    38,
      22,    23,    24,    25,    26,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,   125,    20,    21,    28,
      39,    60,    61,   119,    28,    39,    87,    89,    90,    94,
      29,    27,    40,   131,   133,   133,    42,   132,    87,   134,
     135,   137,    49,    27,    42,    96,    97,    98,    15,    15,
      29,    29,    28,    89,    94,   128,   106,   106,    67,    15,
     106,   106,    63,    98,    42,   107,   110,   106,   111,   112,
     113,   114,   115,   115,   116,   116,   116,   116,   117,   117,
     118,   118,   119,   119,   119,   107,     4,     4,    29,   107,
     123,   106,    29,    89,    91,    40,   108,    28,    39,    90,
      10,    93,    42,    15,    27,    42,   108,   138,    27,    42,
     119,    29,    29,    29,    28,    15,   106,    15,    29,    98,
      63,    27,    29,    40,    29,    29,    40,    29,    91,    40,
     108,   135,    42,    96,    98,    98,   106,    29,   106,    15,
      15,   106,    98,   108,   107,    29,    40,    66,    29,    98,
      29,    29,   106,    29,   106,    15,    98,    15,    98,    98,
      29,    98,    29,    29,   106,    98,    98,    98,    29,    98
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
#line 97 "parser.y"
    {TinyParserAppendBlock((yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 4:
#line 98 "parser.y"
    {TinyParserAppendBlock((yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 5:
#line 100 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 6:
#line 101 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 7:
#line 102 "parser.y"
    {assert_valid_typedefs((yyvsp[(2) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 8:
#line 105 "parser.y"
    {assignType((yyvsp[(2) - (3)].ast_node), (yyvsp[(1) - (3)].ast_node)); (yyval.ast_node) = createBinaryTreeNode(kFuncDef, (yyvsp[(2) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 9:
#line 106 "parser.y"
    {assignType((yyvsp[(1) - (2)].ast_node), INT_TYPE); (yyval.ast_node) = createBinaryTreeNode(kFuncDef, (yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 10:
#line 109 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node); ;}
    break;

  case 11:
#line 110 "parser.y"
    {addNext((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node));;}
    break;

  case 12:
#line 113 "parser.y"
    { assignType((yyvsp[(2) - (3)].ast_node), (yyvsp[(1) - (3)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (3)].ast_node); ;}
    break;

  case 13:
#line 114 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs((yyvsp[(1) - (2)].ast_node));;}
    break;

  case 14:
#line 124 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 15:
#line 125 "parser.y"
    {addNext((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 16:
#line 126 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node); ;}
    break;

  case 17:
#line 127 "parser.y"
    {addNext((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 18:
#line 128 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 22:
#line 137 "parser.y"
    { (yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 23:
#line 138 "parser.y"
    { addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 24:
#line 140 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 25:
#line 141 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kVarInit, (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 26:
#line 143 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (2)].ast_node); addLeftMost((yyval.ast_node), (yyvsp[(1) - (2)].ast_node)); ;}
    break;

  case 27:
#line 144 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 28:
#line 147 "parser.y"
    {(yyval.ast_node) = createVarDecl(NULL, (yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 29:
#line 148 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node); ;}
    break;

  case 30:
#line 149 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node);;}
    break;

  case 31:
#line 150 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node);;}
    break;

  case 32:
#line 151 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node); (yyval.ast_node)->type_ = kFuncDecl; ;}
    break;

  case 33:
#line 152 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node); (yyval.ast_node)->type_ = kFuncDecl; ;}
    break;

  case 34:
#line 155 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 35:
#line 156 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (2)].ast_node); addLeftMost((yyval.ast_node), (yyvsp[(1) - (2)].ast_node));;}
    break;

  case 36:
#line 157 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 37:
#line 160 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node);;}
    break;

  case 38:
#line 161 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node); ;}
    break;

  case 39:
#line 162 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 40:
#line 163 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node);;}
    break;

  case 41:
#line 164 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, NULL); ;}
    break;

  case 42:
#line 165 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node);;}
    break;

  case 43:
#line 166 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 44:
#line 167 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node);;}
    break;

  case 45:
#line 168 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, NULL); ;}
    break;

  case 46:
#line 171 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node); ;}
    break;

  case 47:
#line 172 "parser.y"
    {addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 48:
#line 175 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 49:
#line 176 "parser.y"
    {addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 50:
#line 179 "parser.y"
    {assignType((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 51:
#line 180 "parser.y"
    {assignType((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 53:
#line 184 "parser.y"
    {(yyval.ast_node) = createPtrType(NULL); (yyval.ast_node) = createFeaturedType((yyvsp[(2) - (2)].ast_node), (yyval.ast_node));;}
    break;

  case 54:
#line 185 "parser.y"
    {(yyval.ast_node) = createPtrType(NULL); ;}
    break;

  case 55:
#line 186 "parser.y"
    {(yyval.ast_node) = createFeaturedType((yyvsp[(2) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); (yyval.ast_node) = createPtrType((yyval.ast_node)); ;}
    break;

  case 56:
#line 187 "parser.y"
    {(yyval.ast_node) = createPtrType((yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 59:
#line 195 "parser.y"
    {(yyval.ast_node) = createExprTree((yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 60:
#line 196 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kInitList, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 61:
#line 197 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kInitList, (yyvsp[(2) - (4)].ast_node)); ;}
    break;

  case 62:
#line 199 "parser.y"
    { (yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 63:
#line 200 "parser.y"
    { addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 70:
#line 211 "parser.y"
    {(yyval.ast_node) = createLabledStmt((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 71:
#line 212 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kCase, (yyvsp[(2) - (4)].ast_node), (yyvsp[(4) - (4)].ast_node)); ;}
    break;

  case 73:
#line 216 "parser.y"
    {(yyval.ast_node) = createExprTree((yyvsp[(1) - (2)].ast_node));;}
    break;

  case 75:
#line 220 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kScope, (yyvsp[(2) - (4)].ast_node), (yyvsp[(3) - (4)].ast_node)); ;}
    break;

  case 76:
#line 221 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kScope, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 77:
#line 222 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kScope, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 78:
#line 223 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kScope, NULL); ;}
    break;

  case 79:
#line 226 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 80:
#line 227 "parser.y"
    {addNext((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 81:
#line 230 "parser.y"
    {(yyval.ast_node) = createTrinaryTreeNode(kIfStmt, (yyvsp[(3) - (5)].ast_node), (yyvsp[(5) - (5)].ast_node), NULL); ;}
    break;

  case 82:
#line 231 "parser.y"
    {(yyval.ast_node) = createTrinaryTreeNode(kIfStmt, (yyvsp[(3) - (7)].ast_node), (yyvsp[(5) - (7)].ast_node), (yyvsp[(7) - (7)].ast_node)); ;}
    break;

  case 83:
#line 232 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kSwitchStmt, (yyvsp[(3) - (5)].ast_node), (yyvsp[(5) - (5)].ast_node)); ;}
    break;

  case 84:
#line 235 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kWhileStmt, createExprTree((yyvsp[(3) - (5)].ast_node)), (yyvsp[(5) - (5)].ast_node)); ;}
    break;

  case 85:
#line 236 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kDoWhileStmt, (yyvsp[(2) - (7)].ast_node), createExprTree((yyvsp[(5) - (7)].ast_node))); ;}
    break;

  case 86:
#line 237 "parser.y"
    {(yyval.ast_node) = createForStmt((yyvsp[(3) - (9)].ast_node), (yyvsp[(5) - (9)].ast_node), (yyvsp[(7) - (9)].ast_node), (yyvsp[(9) - (9)].ast_node)); ;}
    break;

  case 87:
#line 238 "parser.y"
    {(yyval.ast_node) = createForStmt((yyvsp[(3) - (8)].ast_node), (yyvsp[(5) - (8)].ast_node), NULL, (yyvsp[(8) - (8)].ast_node)); ;}
    break;

  case 88:
#line 239 "parser.y"
    {(yyval.ast_node) = createForStmt((yyvsp[(3) - (8)].ast_node), NULL, (yyvsp[(6) - (8)].ast_node), (yyvsp[(8) - (8)].ast_node)); ;}
    break;

  case 89:
#line 240 "parser.y"
    {(yyval.ast_node) = createForStmt((yyvsp[(3) - (7)].ast_node), NULL, NULL, (yyvsp[(7) - (7)].ast_node)); ;}
    break;

  case 90:
#line 241 "parser.y"
    {(yyval.ast_node) = createForStmt(NULL, (yyvsp[(4) - (8)].ast_node), (yyvsp[(6) - (8)].ast_node), (yyvsp[(8) - (8)].ast_node)); ;}
    break;

  case 91:
#line 242 "parser.y"
    {(yyval.ast_node) = createForStmt(NULL, (yyvsp[(4) - (7)].ast_node), NULL, (yyvsp[(7) - (7)].ast_node)); ;}
    break;

  case 92:
#line 243 "parser.y"
    {(yyval.ast_node) = createForStmt(NULL, NULL, (yyvsp[(5) - (7)].ast_node), (yyvsp[(7) - (7)].ast_node)); ;}
    break;

  case 93:
#line 244 "parser.y"
    {(yyval.ast_node) = createForStmt(NULL, NULL, NULL, (yyvsp[(6) - (6)].ast_node)); ;}
    break;

  case 94:
#line 247 "parser.y"
    {addChild((yyvsp[(1) - (3)].ast_node), (yyvsp[(2) - (3)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node); ;}
    break;

  case 95:
#line 248 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 96:
#line 249 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 97:
#line 250 "parser.y"
    {(yyvsp[(2) - (3)].ast_node) = createExprTree((yyvsp[(2) - (3)].ast_node)); addChild((yyvsp[(1) - (3)].ast_node), (yyvsp[(2) - (3)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node); ;}
    break;

  case 98:
#line 251 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 100:
#line 257 "parser.y"
    {(yyval.ast_node) = createBinaryOpTree(",", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 102:
#line 260 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node); addChild((yyval.ast_node), (yyvsp[(1) - (3)].ast_node)); addChild((yyval.ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 104:
#line 264 "parser.y"
    {(yyval.ast_node) = createTrinaryOpTree((yyvsp[(1) - (5)].ast_node), (yyvsp[(3) - (5)].ast_node), (yyvsp[(5) - (5)].ast_node));;}
    break;

  case 106:
#line 268 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("||", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 108:
#line 272 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("&&", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 110:
#line 276 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("|", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 112:
#line 280 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("^", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 114:
#line 284 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("&", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 116:
#line 288 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("==", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 117:
#line 289 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("!=", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 119:
#line 293 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree(">", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 120:
#line 294 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("<", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 121:
#line 295 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree(">=", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 122:
#line 296 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("<=", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 124:
#line 300 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("<<", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 125:
#line 301 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree(">>", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 127:
#line 305 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("+", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 128:
#line 306 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("-", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 130:
#line 310 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("*", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 131:
#line 311 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("/", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 132:
#line 312 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("%", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 134:
#line 316 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kCast, (yyvsp[(2) - (4)].ast_node), (yyvsp[(4) - (4)].ast_node)); ;}
    break;

  case 136:
#line 320 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("++_", (yyvsp[(2) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 137:
#line 321 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("--_", (yyvsp[(2) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 138:
#line 322 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node); addChild((yyval.ast_node), (yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 139:
#line 323 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("sizeof", (yyvsp[(2) - (2)].ast_node));;}
    break;

  case 140:
#line 324 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("sizeof", (yyvsp[(3) - (4)].ast_node));;}
    break;

  case 141:
#line 327 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 142:
#line 328 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kSubScript, (yyvsp[(1) - (4)].ast_node), (yyvsp[(3) - (4)].ast_node)); ;}
    break;

  case 143:
#line 329 "parser.y"
    {(yyval.ast_node) = createStructMember((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node), "."); ;}
    break;

  case 144:
#line 330 "parser.y"
    {(yyval.ast_node) = createStructMember((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node), "->"); ;}
    break;

  case 145:
#line 331 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("_++", (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 146:
#line 332 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("_--", (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 147:
#line 333 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 148:
#line 336 "parser.y"
    { (yyval.ast_node) = createFunctionCallTree((yyvsp[(1) - (3)].ast_node), NULL);;}
    break;

  case 149:
#line 337 "parser.y"
    {(yyval.ast_node) = createFunctionCallTree((yyvsp[(1) - (4)].ast_node), (yyvsp[(3) - (4)].ast_node));;}
    break;

  case 150:
#line 340 "parser.y"
    {(yyval.ast_node) = createArgList((yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 151:
#line 341 "parser.y"
    {addChild((yyval.ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 152:
#line 344 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 153:
#line 345 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 154:
#line 346 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 155:
#line 347 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node);;}
    break;

  case 156:
#line 350 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "=", 1); ;}
    break;

  case 157:
#line 351 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "&=", 1);;}
    break;

  case 158:
#line 352 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "/=", 1);;}
    break;

  case 159:
#line 353 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "+=", 1);;}
    break;

  case 160:
#line 354 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "-=", 1);;}
    break;

  case 161:
#line 355 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "*=", 1);;}
    break;

  case 162:
#line 356 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "<<=", 1);;}
    break;

  case 163:
#line 357 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, ">>=", 1);;}
    break;

  case 164:
#line 358 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "|=", 1);;}
    break;

  case 165:
#line 359 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "^=", 1);;}
    break;

  case 166:
#line 360 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "%=", 1);;}
    break;

  case 167:
#line 363 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "+", 1);;}
    break;

  case 168:
#line 364 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "-", 1);;}
    break;

  case 169:
#line 365 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "&", 1);;}
    break;

  case 170:
#line 366 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "!", 1);;}
    break;

  case 171:
#line 367 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "~", 1);;}
    break;

  case 172:
#line 368 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "*", 1);;}
    break;

  case 173:
#line 374 "parser.y"
    {assignType((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 174:
#line 375 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs((yyvsp[(1) - (1)].ast_node));;}
    break;

  case 178:
#line 385 "parser.y"
    {add_hidden_type((yyvsp[(2) - (5)].ast_node)->val_); addChild((yyvsp[(1) - (5)].ast_node), (yyvsp[(2) - (5)].ast_node)); addChild((yyvsp[(1) - (5)].ast_node), (yyvsp[(4) - (5)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (5)].ast_node);;}
    break;

  case 179:
#line 386 "parser.y"
    {addChild((yyvsp[(1) - (4)].ast_node), EMPTY_NODE); addChild((yyvsp[(1) - (4)].ast_node), (yyvsp[(3) - (4)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node);;}
    break;

  case 180:
#line 387 "parser.y"
    {addChild((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); addChild((yyvsp[(1) - (2)].ast_node), EMPTY_NODE); (yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 181:
#line 390 "parser.y"
    {(yyval.ast_node) = createAstNode(kStructType, NULL, 0); ;}
    break;

  case 182:
#line 391 "parser.y"
    {(yyval.ast_node) = createAstNode(kUnionType, NULL, 0); ;}
    break;

  case 183:
#line 394 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 184:
#line 395 "parser.y"
    {addNext((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 185:
#line 398 "parser.y"
    {assignType((yyvsp[(2) - (3)].ast_node), (yyvsp[(1) - (3)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (3)].ast_node);;}
    break;

  case 186:
#line 405 "parser.y"
    {addNext((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 187:
#line 406 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 188:
#line 407 "parser.y"
    {addNext((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 189:
#line 408 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node); ;}
    break;

  case 190:
#line 411 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 191:
#line 412 "parser.y"
    {addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 193:
#line 420 "parser.y"
    {add_hidden_type((yyvsp[(2) - (5)].ast_node)->val_); (yyval.ast_node) = createBinaryTreeNode(kEnumType, (yyvsp[(2) - (5)].ast_node), (yyvsp[(4) - (5)].ast_node)); ;}
    break;

  case 194:
#line 421 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kEnumType, NULL, (yyvsp[(3) - (4)].ast_node));;}
    break;

  case 195:
#line 422 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kEnumType, (yyvsp[(2) - (2)].ast_node), NULL); ;}
    break;

  case 196:
#line 425 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 197:
#line 426 "parser.y"
    {addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 198:
#line 429 "parser.y"
    {(yyval.ast_node) = createEnumerator((yyvsp[(1) - (1)].ast_node), NULL); ;}
    break;

  case 199:
#line 430 "parser.y"
    {(yyval.ast_node) = createEnumerator((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 200:
#line 433 "parser.y"
    { (yyval.ast_node) = createAstNode(kEnumType, NULL, 0); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2799 "./tiny_compiler_yacc.c"
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


#line 437 "parser.y"

int yyerror(char* s) {
    TinyParserRaiseError(s);
    return 1;
}


