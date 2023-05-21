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
#line 258 "./tiny_compiler_yacc.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 271 "./tiny_compiler_yacc.c"

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
#define YYLAST   1103

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  199
/* YYNRULES -- Number of states.  */
#define YYNSTATES  346

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
       0,     0,     3,     5,     7,    10,    12,    14,    17,    21,
      24,    26,    29,    33,    36,    39,    41,    44,    46,    49,
      51,    53,    55,    57,    59,    63,    65,    69,    72,    74,
      76,    80,    85,    89,    94,    98,   100,   103,   105,   109,
     114,   118,   122,   125,   130,   134,   138,   141,   143,   147,
     149,   153,   156,   159,   161,   164,   166,   170,   173,   175,
     178,   180,   184,   189,   191,   195,   197,   199,   201,   203,
     205,   207,   211,   216,   220,   223,   225,   230,   234,   238,
     241,   243,   246,   252,   260,   266,   272,   280,   290,   299,
     308,   316,   325,   333,   341,   348,   352,   355,   358,   362,
     365,   367,   371,   373,   377,   379,   385,   387,   391,   393,
     397,   399,   403,   405,   409,   411,   415,   417,   421,   425,
     427,   431,   435,   439,   443,   445,   449,   453,   455,   459,
     463,   465,   469,   473,   477,   479,   484,   486,   489,   492,
     495,   498,   503,   505,   510,   514,   518,   521,   524,   526,
     528,   530,   532,   536,   538,   540,   542,   544,   546,   548,
     550,   552,   554,   556,   558,   560,   562,   564,   566,   568,
     570,   574,   579,   581,   585,   587,   589,   591,   597,   602,
     605,   607,   609,   611,   614,   618,   621,   623,   626,   628,
     630,   634,   636,   642,   647,   650,   652,   656,   658,   662
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      74,     0,    -1,    75,    -1,    76,    -1,    75,    76,    -1,
      77,    -1,    79,    -1,     9,    79,    -1,    80,    86,   100,
      -1,    86,   100,    -1,    79,    -1,    78,    79,    -1,    80,
      84,    15,    -1,    80,    15,    -1,    81,    80,    -1,    81,
      -1,    82,    80,    -1,    82,    -1,    83,    80,    -1,    83,
      -1,     8,    -1,   126,    -1,     7,    -1,    85,    -1,    84,
      26,    85,    -1,    86,    -1,    86,    48,    95,    -1,    93,
      87,    -1,    87,    -1,     4,    -1,    27,    86,    28,    -1,
      87,    38,   107,    39,    -1,    87,    38,    39,    -1,    87,
      27,    90,    28,    -1,    87,    27,    28,    -1,    93,    -1,
      93,    89,    -1,    89,    -1,    27,    88,    28,    -1,    89,
      38,   107,    39,    -1,    38,   107,    39,    -1,    89,    38,
      39,    -1,    38,    39,    -1,    89,    27,    90,    28,    -1,
      27,    90,    28,    -1,    89,    27,    28,    -1,    27,    28,
      -1,    91,    -1,    91,    26,    10,    -1,    92,    -1,    91,
      26,    92,    -1,    80,    86,    -1,    80,    88,    -1,    80,
      -1,    23,    94,    -1,    23,    -1,    23,    94,    93,    -1,
      23,    93,    -1,    83,    -1,    94,    83,    -1,   106,    -1,
      40,    96,    41,    -1,    40,    96,    26,    41,    -1,    95,
      -1,    96,    26,    95,    -1,    98,    -1,    99,    -1,   100,
      -1,   102,    -1,   103,    -1,   104,    -1,     4,    62,    97,
      -1,    70,   107,    62,    97,    -1,    71,    62,    97,    -1,
     105,    15,    -1,    15,    -1,    40,    78,   101,    41,    -1,
      40,   101,    41,    -1,    40,    78,    41,    -1,    40,    41,
      -1,    97,    -1,   101,    97,    -1,    64,    27,   105,    28,
      97,    -1,    64,    27,   105,    28,    97,    65,    97,    -1,
      69,    27,   105,    28,    97,    -1,    66,    27,   105,    28,
      97,    -1,    67,    97,    66,    27,   105,    28,    15,    -1,
      68,    27,   105,    15,   105,    15,   105,    28,    97,    -1,
      68,    27,   105,    15,   105,    15,    28,    97,    -1,    68,
      27,   105,    15,    15,   105,    28,    97,    -1,    68,    27,
     105,    15,    15,    28,    97,    -1,    68,    27,    15,   105,
      15,   105,    28,    97,    -1,    68,    27,    15,   105,    15,
      28,    97,    -1,    68,    27,    15,    15,   105,    28,    97,
      -1,    68,    27,    15,    15,    28,    97,    -1,    11,     4,
      15,    -1,    13,    15,    -1,    12,    15,    -1,    14,   105,
      15,    -1,    14,    15,    -1,   106,    -1,   105,    26,   106,
      -1,   107,    -1,   119,   122,   106,    -1,   108,    -1,   108,
      61,   105,    62,   107,    -1,   109,    -1,   108,    30,   109,
      -1,   110,    -1,   109,    29,   110,    -1,   111,    -1,   110,
      32,   111,    -1,   112,    -1,   111,    34,   112,    -1,   113,
      -1,   112,    33,   113,    -1,   114,    -1,   113,    46,   114,
      -1,   113,    47,   114,    -1,   115,    -1,   114,    42,   115,
      -1,   114,    43,   115,    -1,   114,    44,   115,    -1,   114,
      45,   115,    -1,   116,    -1,   115,    36,   116,    -1,   115,
      37,   116,    -1,   117,    -1,   116,    21,   117,    -1,   116,
      22,   117,    -1,   118,    -1,   117,    23,   118,    -1,   117,
      24,   118,    -1,   117,    25,   118,    -1,   119,    -1,    27,
     126,    28,   118,    -1,   120,    -1,    59,   119,    -1,    60,
     119,    -1,   123,   118,    -1,    63,   119,    -1,    63,    27,
     126,    28,    -1,   121,    -1,   120,    38,   105,    39,    -1,
     120,    19,     4,    -1,   120,    20,     4,    -1,   120,    59,
      -1,   120,    60,    -1,   124,    -1,     3,    -1,     5,    -1,
       4,    -1,    27,   105,    28,    -1,    48,    -1,    57,    -1,
      52,    -1,    49,    -1,    50,    -1,    51,    -1,    54,    -1,
      55,    -1,    58,    -1,    56,    -1,    53,    -1,    21,    -1,
      22,    -1,    33,    -1,    31,    -1,    35,    -1,    23,    -1,
     120,    27,    28,    -1,   120,    27,   125,    28,    -1,   105,
      -1,   125,    26,   105,    -1,     6,    -1,   127,    -1,   134,
      -1,   128,     4,    40,   129,    41,    -1,   128,    40,   129,
      41,    -1,   128,     4,    -1,    16,    -1,    17,    -1,   130,
      -1,   129,   130,    -1,   131,   132,    15,    -1,    82,   131,
      -1,    82,    -1,    83,   131,    -1,    83,    -1,   133,    -1,
     132,    26,   133,    -1,    86,    -1,   137,     4,    40,   135,
      41,    -1,   137,    40,   135,    41,    -1,   137,     4,    -1,
     136,    -1,   135,    26,   136,    -1,     4,    -1,     4,    48,
     107,    -1,    18,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    95,    95,    97,    98,   100,   101,   102,   105,   106,
     109,   110,   113,   114,   117,   118,   119,   120,   121,   122,
     125,   127,   129,   131,   132,   134,   135,   137,   138,   141,
     142,   143,   144,   145,   146,   149,   150,   151,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   165,   166,   169,
     170,   173,   174,   175,   178,   179,   180,   181,   184,   185,
     189,   190,   191,   193,   194,   197,   198,   199,   200,   201,
     202,   205,   206,   207,   210,   211,   214,   215,   216,   217,
     220,   221,   224,   225,   226,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   241,   242,   243,   244,   245,
     249,   250,   252,   253,   256,   257,   260,   261,   264,   265,
     268,   269,   272,   273,   276,   277,   280,   281,   282,   285,
     286,   287,   288,   289,   292,   293,   294,   297,   298,   299,
     302,   303,   304,   305,   308,   309,   312,   313,   314,   315,
     316,   317,   320,   321,   322,   323,   324,   325,   326,   330,
     331,   332,   333,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   349,   350,   351,   352,   353,   354,
     358,   359,   362,   363,   367,   369,   370,   373,   374,   375,
     378,   379,   382,   383,   386,   388,   389,   390,   391,   394,
     395,   398,   403,   404,   405,   408,   409,   412,   413,   416
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
       0,    73,    74,    75,    75,    76,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    80,    80,    80,    80,
      81,    82,    83,    84,    84,    85,    85,    86,    86,    87,
      87,    87,    87,    87,    87,    88,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    90,    90,    91,
      91,    92,    92,    92,    93,    93,    93,    93,    94,    94,
      95,    95,    95,    96,    96,    97,    97,    97,    97,    97,
      97,    98,    98,    98,    99,    99,   100,   100,   100,   100,
     101,   101,   102,   102,   102,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   104,   104,   104,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   113,   113,   113,   114,
     114,   114,   114,   114,   115,   115,   115,   116,   116,   116,
     117,   117,   117,   117,   118,   118,   119,   119,   119,   119,
     119,   119,   120,   120,   120,   120,   120,   120,   120,   121,
     121,   121,   121,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   123,   123,   123,   123,   123,   123,
     124,   124,   125,   125,   126,   126,   126,   127,   127,   127,
     128,   128,   129,   129,   130,   131,   131,   131,   131,   132,
     132,   133,   134,   134,   134,   135,   135,   136,   136,   137
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     3,     2,
       1,     2,     3,     2,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     3,     1,     3,     2,     1,     1,
       3,     4,     3,     4,     3,     1,     2,     1,     3,     4,
       3,     3,     2,     4,     3,     3,     2,     1,     3,     1,
       3,     2,     2,     1,     2,     1,     3,     2,     1,     2,
       1,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     1,     4,     3,     3,     2,
       1,     2,     5,     7,     5,     5,     7,     9,     8,     8,
       7,     8,     7,     7,     6,     3,     2,     2,     3,     2,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     4,     1,     2,     2,     2,
       2,     4,     1,     4,     3,     3,     2,     2,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     1,     3,     1,     1,     1,     5,     4,     2,
       1,     1,     1,     2,     3,     2,     1,     2,     1,     1,
       3,     1,     5,     4,     2,     1,     3,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    29,   174,    22,    20,     0,   180,   181,   199,    55,
       0,     0,     2,     3,     5,     6,     0,    15,    17,    19,
       0,    28,     0,    21,   175,     0,   176,     0,     7,     0,
      58,    57,    54,     0,     1,     4,    13,     0,    23,    25,
      14,    16,    18,     0,     9,     0,     0,    27,   179,     0,
     194,     0,    25,    59,    56,    30,    12,     0,     0,     8,
     149,   151,   150,     0,     0,     0,     0,    75,   164,   165,
     169,     0,   167,   166,   168,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    80,    65,
      66,    67,     0,    68,    69,    70,     0,   100,   102,   104,
     106,   108,   110,   112,   114,   116,   119,   124,   127,   130,
     134,   136,   142,     0,   148,    34,    53,     0,    47,    49,
     151,    32,     0,   134,     0,   186,   188,     0,   182,     0,
       0,   197,     0,   195,    24,     0,    26,    60,     0,     0,
      97,    96,    99,     0,     0,     0,     0,   137,   138,     0,
     140,     0,     0,     0,     0,     0,     0,     0,    78,    11,
       0,    77,    81,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   156,   157,   158,   155,   163,
     159,   160,   162,   154,   161,     0,     0,     0,     0,     0,
     146,   147,   139,     0,     0,    51,    52,    37,    35,    33,
       0,    31,     0,   185,   187,   178,   183,   191,     0,   189,
       0,     0,     0,   193,    63,     0,    71,    95,    98,   152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      76,   101,   107,     0,   109,   111,   113,   115,   117,   118,
     120,   121,   122,   123,   125,   126,   128,   129,   131,   132,
     133,   103,   144,   145,   170,   172,     0,     0,    46,     0,
       0,    42,     0,     0,     0,    36,    48,    50,   177,   184,
       0,   192,   198,   196,     0,    61,   135,   141,     0,     0,
       0,     0,     0,     0,     0,    72,     0,     0,   171,   143,
      38,    44,    40,    45,     0,    41,     0,   190,    62,    64,
      82,    85,     0,     0,     0,     0,     0,     0,    84,   105,
     173,    43,    39,     0,     0,    94,     0,     0,     0,     0,
       0,     0,    83,    86,    93,    92,     0,    90,     0,     0,
       0,    91,    89,    88,     0,    87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    86,    15,   116,    17,    18,
      19,    37,    38,    20,    21,   206,   207,   117,   118,   119,
      22,    32,   136,   225,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   195,
     113,   114,   266,    23,    24,    25,   127,   128,   129,   218,
     219,    26,   132,   133,    27
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -195
static const yytype_int16 yypact[] =
{
     320,  -195,  -195,  -195,  -195,   395,  -195,  -195,  -195,     9,
     105,    21,   320,  -195,  -195,  -195,   103,   395,   395,   395,
      40,    32,    54,  -195,  -195,    11,  -195,    16,  -195,   103,
    -195,  -195,     9,     2,  -195,  -195,  -195,    84,  -195,    23,
    -195,  -195,  -195,   290,  -195,   272,   642,    32,    93,   166,
      96,    71,    76,  -195,  -195,  -195,  -195,   105,   649,  -195,
    -195,    78,  -195,   159,   152,   177,   692,  -195,  -195,  -195,
    -195,   197,  -195,  -195,  -195,  -195,   986,   986,  1001,   168,
     185,   566,   198,   221,  1035,   142,   359,  -195,  -195,  -195,
    -195,  -195,   428,  -195,  -195,  -195,   116,  -195,  -195,   -19,
     194,   226,   225,   243,   -12,   146,   133,    46,   220,  -195,
     491,     6,  -195,  1035,  -195,  -195,    34,   241,   247,  -195,
    -195,  -195,   246,  -195,   166,   166,   166,    97,  -195,   105,
      71,   234,    43,  -195,  -195,   649,  -195,  -195,   566,   276,
    -195,  -195,  -195,   151,   111,   271,  1035,  -195,  -195,   197,
    -195,  1035,  1035,   244,   713,  1035,   253,   566,  -195,  -195,
     497,  -195,  -195,  -195,  1035,  1035,  1035,  1035,  1035,  1035,
    1035,  1035,  1035,  1035,  1035,  1035,  1035,  1035,  1035,  1035,
    1035,  1035,  1035,  1035,  -195,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,  1035,   305,   315,   756,  1035,
    -195,  -195,  -195,  1065,   790,  -195,  -195,   141,    35,  -195,
     464,  -195,   158,  -195,  -195,  -195,  -195,  -195,   170,  -195,
      75,  1035,    71,  -195,  -195,    86,  -195,  -195,  -195,  -195,
    1035,   294,   181,   236,   312,   805,   179,   237,   566,  -195,
    -195,  -195,   194,   -16,   226,   225,   243,   -12,   146,   146,
     133,   133,   133,   133,    46,    46,   220,   220,  -195,  -195,
    -195,  -195,  -195,  -195,  -195,   314,   240,    -2,  -195,   313,
     316,  -195,   303,   389,   839,   141,  -195,  -195,  -195,  -195,
     105,  -195,  -195,  -195,   581,  -195,  -195,  -195,   566,   566,
    1035,   854,   195,   888,   566,  -195,  1035,  1035,  -195,  -195,
    -195,  -195,  -195,  -195,   317,  -195,   309,  -195,  -195,  -195,
     281,  -195,   255,   566,   288,   903,   937,   196,  -195,  -195,
     314,  -195,  -195,   566,   336,  -195,   566,   566,   292,   566,
     306,   952,  -195,  -195,  -195,  -195,   566,  -195,   566,   566,
     307,  -195,  -195,  -195,   566,  -195
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -195,  -195,  -195,   340,  -195,  -195,    12,    31,  -195,   -31,
      -4,  -195,   298,   -10,   -21,   165,   161,  -194,  -195,   169,
      -5,  -195,  -122,  -195,   -52,  -195,  -195,    44,   297,  -195,
    -195,  -195,   -64,   -35,   -43,  -195,   213,   217,   219,   216,
     218,    45,    65,    57,    67,  -105,   -24,  -195,  -195,  -195,
    -195,  -195,  -195,   -57,  -195,  -195,   265,  -115,   129,  -195,
     113,  -195,   261,   176,  -195
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      33,    47,   143,   122,    31,    30,    39,   144,   202,   270,
     164,   165,   216,   224,   145,    48,     3,    28,   125,    52,
      50,    34,   123,   137,   164,   196,   197,    54,    53,   153,
      55,    16,     9,   198,   171,   172,    29,   299,     1,     1,
     162,   156,   166,    16,   199,   126,   296,    52,    40,    41,
      42,    49,   147,   148,   150,    87,    51,     9,     1,    45,
     123,   203,   203,    43,    44,   200,   201,   179,   180,   222,
      46,    58,   204,   204,    29,   131,   258,   259,   260,   304,
      43,    10,   144,    59,   223,   144,   226,   232,   233,   123,
     236,   237,   231,   125,   125,   125,   125,   216,   159,    56,
     137,   222,   243,     2,     3,   239,   205,     1,   162,     1,
      57,   208,   284,     6,     7,     8,   281,    29,    36,   217,
     126,   126,   126,   126,    58,   286,     9,   285,     9,   241,
      10,   163,    10,   124,   265,   267,   130,   164,   215,   229,
     138,   123,   164,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     261,   272,   309,   139,     2,     3,   228,   140,   273,   177,
     178,   292,     2,     3,     6,     7,     8,   164,   282,   274,
     123,   125,     6,     7,     8,   279,   295,    47,   173,   174,
     175,   176,   141,    33,   293,   151,   280,   123,   208,   278,
      60,   120,    62,     2,   157,   164,   123,   164,   126,   288,
     315,   331,   152,     6,     7,     8,   248,   249,    68,    69,
      70,   164,   164,   167,    71,   154,   312,   314,    72,   317,
      73,   306,    74,   320,   254,   255,   310,   311,   250,   251,
     252,   253,   318,   181,   182,   183,   256,   257,   155,   137,
     123,   328,   330,   319,   213,   214,    76,    77,   168,   169,
      78,   325,   164,   164,   289,   294,   297,   340,   298,   209,
     217,   332,   123,   210,   334,   335,   170,   337,     2,     3,
       4,   164,   221,   324,   341,   211,   342,   343,     6,     7,
       8,   227,   345,    60,    61,    62,     2,     3,     4,   230,
     115,    63,    64,    65,    66,    67,     6,     7,     8,   262,
     234,    68,    69,    70,   164,   238,   326,    71,   164,   263,
     336,    72,   287,    73,     1,    74,     2,     3,     4,     5,
      43,    75,   164,   164,   338,   344,     6,     7,     8,   290,
     164,   300,   302,     9,   301,   321,   323,    10,   322,    76,
      77,   333,    35,    78,    79,   134,    80,    81,    82,    83,
      84,    85,    60,    61,    62,     2,     3,     4,   269,   275,
      63,    64,    65,    66,    67,     6,     7,     8,   242,   277,
      68,    69,    70,   160,   244,   246,    71,   245,   247,   212,
      72,   220,    73,   307,    74,     2,     3,     4,   283,    43,
     158,     2,     3,     4,     0,     6,     7,     8,     0,     0,
       0,     6,     7,     8,     0,     0,     0,   303,    76,    77,
       0,     0,    78,    79,     0,    80,    81,    82,    83,    84,
      85,    60,    61,    62,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,     0,     0,     0,     0,     0,    68,
      69,    70,     0,     0,     0,    71,     0,     0,     0,    72,
       0,    73,     0,    74,     0,     0,     0,     0,    43,   161,
       2,     3,     4,     0,   276,     0,     0,     0,     0,     0,
       6,     7,     8,     0,     0,     0,     0,    76,    77,     0,
       0,    78,    79,     0,    80,    81,    82,    83,    84,    85,
      60,    61,    62,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,     0,     0,     0,     0,     0,    68,    69,
      70,     0,     0,     0,    71,     0,     0,     0,    72,     0,
      73,     0,    74,     0,     0,     0,     0,    43,   240,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       0,     0,     0,     0,     0,     0,    76,    77,     0,     0,
      78,    79,     0,    80,    81,    82,    83,    84,    85,    60,
      61,    62,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,     0,     0,    60,   120,    62,    68,    69,    70,
       0,     0,     0,    71,     0,     0,     0,    72,     0,    73,
       0,    74,    68,    69,    70,     0,    43,     0,    71,     0,
       0,     0,    72,     0,    73,     0,    74,     0,     0,     0,
       0,   135,   308,     0,     0,    76,    77,     0,     0,    78,
      79,     0,    80,    81,    82,    83,    84,    85,     0,     0,
      76,    77,     0,     0,    78,    60,   120,    62,     0,     0,
       0,     0,    60,   120,    62,     0,     0,     0,     0,     0,
       0,     0,     0,    68,    69,    70,     0,     0,     0,    71,
      68,    69,    70,    72,     0,    73,    71,    74,     0,     0,
      72,   121,    73,     0,    74,     0,     0,     0,     0,   135,
       0,     0,     0,     0,     0,    60,   120,    62,     0,     0,
       0,    76,    77,     0,     0,    78,     0,   142,    76,    77,
       0,     0,    78,    68,    69,    70,    60,   120,    62,    71,
       0,     0,     0,    72,     0,    73,     0,    74,   235,     0,
       0,     0,     0,     0,    68,    69,    70,     0,     0,     0,
      71,     0,     0,     0,    72,     0,    73,     0,    74,     0,
       0,    76,    77,     0,     0,    78,     0,     0,     0,    60,
     120,    62,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,     0,     0,    78,    68,    69,    70,
       0,     0,     0,    71,   264,     0,     0,    72,     0,    73,
       0,    74,     0,    60,   120,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,   120,
      62,    68,    69,    70,     0,    76,    77,    71,     0,    78,
     291,    72,     0,    73,     0,    74,    68,    69,    70,   271,
       0,     0,    71,     0,     0,     0,    72,     0,    73,     0,
      74,     0,    60,   120,    62,     0,     0,     0,     0,    76,
      77,     0,     0,    78,     0,     0,     0,    60,   120,    62,
      68,    69,    70,     0,    76,    77,    71,     0,    78,     0,
      72,     0,    73,     0,    74,    68,    69,    70,   305,     0,
       0,    71,   313,     0,     0,    72,     0,    73,     0,    74,
       0,    60,   120,    62,     0,     0,     0,     0,    76,    77,
       0,     0,    78,   316,     0,     0,    60,   120,    62,    68,
      69,    70,     0,    76,    77,    71,     0,    78,     0,    72,
       0,    73,     0,    74,    68,    69,    70,     0,     0,     0,
      71,   327,     0,     0,    72,     0,    73,     0,    74,     0,
      60,   120,    62,     0,     0,     0,     0,    76,    77,     0,
       0,    78,     0,     0,     0,    60,   120,    62,    68,    69,
      70,     0,    76,    77,    71,   329,    78,     0,    72,     0,
      73,     0,    74,    68,    69,    70,     0,     0,     0,    71,
     339,     0,     0,    72,     0,    73,     0,    74,     0,    60,
     120,    62,     0,     0,     0,     0,    76,    77,     0,     0,
      78,     0,     0,     0,    60,   120,    62,    68,    69,    70,
       0,    76,    77,   146,     0,    78,     0,    72,     0,    73,
       0,    74,    68,    69,    70,     0,     0,     0,   149,     0,
       0,     0,    72,     0,    73,     0,    74,     0,    60,   120,
      62,     0,     0,     0,     0,    76,    77,     0,     0,    78,
       0,     0,     0,     0,     0,     0,    68,    69,    70,     0,
      76,    77,    71,     0,    78,     0,    72,     0,    73,     1,
      74,     2,     3,     4,     0,     0,     0,     0,     0,     0,
       0,     6,     7,     8,     0,     0,     0,     0,     9,     0,
       0,     0,   203,   268,    76,    77,     0,     0,    78,     0,
       0,     0,     0,   204
};

static const yytype_int16 yycheck[] =
{
      10,    22,    66,    46,     9,     9,    16,    71,   113,   203,
      26,    30,   127,   135,    71,     4,     7,     5,    49,    29,
       4,     0,    46,    58,    26,    19,    20,    32,    32,    81,
      28,     0,    23,    27,    46,    47,     5,    39,     4,     4,
      92,    84,    61,    12,    38,    49,    62,    57,    17,    18,
      19,    40,    76,    77,    78,    43,    40,    23,     4,    27,
      84,    27,    27,    40,    20,    59,    60,    21,    22,    26,
      38,    48,    38,    38,    43,     4,   181,   182,   183,   273,
      40,    27,   146,    39,    41,   149,   138,   151,   152,   113,
     154,   155,   149,   124,   125,   126,   127,   212,    86,    15,
     135,    26,   166,     6,     7,   157,   116,     4,   160,     4,
      26,   116,    26,    16,    17,    18,    41,    86,    15,   129,
     124,   125,   126,   127,    48,   230,    23,    41,    23,   164,
      27,    15,    27,    40,   198,   199,    40,    26,    41,    28,
      62,   165,    26,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     195,   204,   284,     4,     6,     7,    15,    15,    27,    36,
      37,   235,     6,     7,    16,    17,    18,    26,   221,    38,
     204,   212,    16,    17,    18,    15,   238,   208,    42,    43,
      44,    45,    15,   203,    15,    27,    26,   221,   203,    41,
       3,     4,     5,     6,    62,    26,   230,    26,   212,    28,
      15,    15,    27,    16,    17,    18,   171,   172,    21,    22,
      23,    26,    26,    29,    27,    27,   290,   291,    31,   293,
      33,   274,    35,   297,   177,   178,   288,   289,   173,   174,
     175,   176,   294,    23,    24,    25,   179,   180,    27,   284,
     274,   315,   316,   296,   125,   126,    59,    60,    32,    34,
      63,   313,    26,    26,    28,    28,    26,   331,    28,    28,
     280,   323,   296,    26,   326,   327,    33,   329,     6,     7,
       8,    26,    48,    28,   336,    39,   338,   339,    16,    17,
      18,    15,   344,     3,     4,     5,     6,     7,     8,    28,
      28,    11,    12,    13,    14,    15,    16,    17,    18,     4,
      66,    21,    22,    23,    26,    62,    28,    27,    26,     4,
      28,    31,    28,    33,     4,    35,     6,     7,     8,     9,
      40,    41,    26,    26,    28,    28,    16,    17,    18,    27,
      26,    28,    39,    23,    28,    28,    65,    27,    39,    59,
      60,    15,    12,    63,    64,    57,    66,    67,    68,    69,
      70,    71,     3,     4,     5,     6,     7,     8,   203,   208,
      11,    12,    13,    14,    15,    16,    17,    18,   165,   210,
      21,    22,    23,    86,   167,   169,    27,   168,   170,   124,
      31,   130,    33,   280,    35,     6,     7,     8,   222,    40,
      41,     6,     7,     8,    -1,    16,    17,    18,    -1,    -1,
      -1,    16,    17,    18,    -1,    -1,    -1,    28,    59,    60,
      -1,    -1,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    21,
      22,    23,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      -1,    33,    -1,    35,    -1,    -1,    -1,    -1,    40,    41,
       6,     7,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      16,    17,    18,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    -1,
      33,    -1,    35,    -1,    -1,    -1,    -1,    40,    41,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      63,    64,    -1,    66,    67,    68,    69,    70,    71,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    11,    12,    13,
      14,    15,    -1,    -1,     3,     4,     5,    21,    22,    23,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    -1,    33,
      -1,    35,    21,    22,    23,    -1,    40,    -1,    27,    -1,
      -1,    -1,    31,    -1,    33,    -1,    35,    -1,    -1,    -1,
      -1,    40,    41,    -1,    -1,    59,    60,    -1,    -1,    63,
      64,    -1,    66,    67,    68,    69,    70,    71,    -1,    -1,
      59,    60,    -1,    -1,    63,     3,     4,     5,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    -1,    -1,    -1,    27,
      21,    22,    23,    31,    -1,    33,    27,    35,    -1,    -1,
      31,    39,    33,    -1,    35,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    59,    60,    -1,    -1,    63,    -1,    15,    59,    60,
      -1,    -1,    63,    21,    22,    23,     3,     4,     5,    27,
      -1,    -1,    -1,    31,    -1,    33,    -1,    35,    15,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    31,    -1,    33,    -1,    35,    -1,
      -1,    59,    60,    -1,    -1,    63,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    63,    21,    22,    23,
      -1,    -1,    -1,    27,    28,    -1,    -1,    31,    -1,    33,
      -1,    35,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    21,    22,    23,    -1,    59,    60,    27,    -1,    63,
      15,    31,    -1,    33,    -1,    35,    21,    22,    23,    39,
      -1,    -1,    27,    -1,    -1,    -1,    31,    -1,    33,    -1,
      35,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    63,    -1,    -1,    -1,     3,     4,     5,
      21,    22,    23,    -1,    59,    60,    27,    -1,    63,    -1,
      31,    -1,    33,    -1,    35,    21,    22,    23,    39,    -1,
      -1,    27,    28,    -1,    -1,    31,    -1,    33,    -1,    35,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    63,    15,    -1,    -1,     3,     4,     5,    21,
      22,    23,    -1,    59,    60,    27,    -1,    63,    -1,    31,
      -1,    33,    -1,    35,    21,    22,    23,    -1,    -1,    -1,
      27,    28,    -1,    -1,    31,    -1,    33,    -1,    35,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    63,    -1,    -1,    -1,     3,     4,     5,    21,    22,
      23,    -1,    59,    60,    27,    28,    63,    -1,    31,    -1,
      33,    -1,    35,    21,    22,    23,    -1,    -1,    -1,    27,
      28,    -1,    -1,    31,    -1,    33,    -1,    35,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      63,    -1,    -1,    -1,     3,     4,     5,    21,    22,    23,
      -1,    59,    60,    27,    -1,    63,    -1,    31,    -1,    33,
      -1,    35,    21,    22,    23,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    31,    -1,    33,    -1,    35,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    -1,
      59,    60,    27,    -1,    63,    -1,    31,    -1,    33,     4,
      35,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    27,    28,    59,    60,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     6,     7,     8,     9,    16,    17,    18,    23,
      27,    74,    75,    76,    77,    79,    80,    81,    82,    83,
      86,    87,    93,   126,   127,   128,   134,   137,    79,    80,
      83,    93,    94,    86,     0,    76,    15,    84,    85,    86,
      80,    80,    80,    40,   100,    27,    38,    87,     4,    40,
       4,    40,    86,    83,    93,    28,    15,    26,    48,   100,
       3,     4,     5,    11,    12,    13,    14,    15,    21,    22,
      23,    27,    31,    33,    35,    41,    59,    60,    63,    64,
      66,    67,    68,    69,    70,    71,    78,    79,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   123,   124,    28,    80,    90,    91,    92,
       4,    39,   107,   119,    40,    82,    83,   129,   130,   131,
      40,     4,   135,   136,    85,    40,    95,   106,    62,     4,
      15,    15,    15,   105,   105,   126,    27,   119,   119,    27,
     119,    27,    27,    97,    27,    27,   107,    62,    41,    79,
     101,    41,    97,    15,    26,    30,    61,    29,    32,    34,
      33,    46,    47,    42,    43,    44,    45,    36,    37,    21,
      22,    23,    24,    25,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,   122,    19,    20,    27,    38,
      59,    60,   118,    27,    38,    86,    88,    89,    93,    28,
      26,    39,   129,   131,   131,    41,   130,    86,   132,   133,
     135,    48,    26,    41,    95,    96,    97,    15,    15,    28,
      28,   126,   105,   105,    66,    15,   105,   105,    62,    97,
      41,   106,   109,   105,   110,   111,   112,   113,   114,   114,
     115,   115,   115,   115,   116,   116,   117,   117,   118,   118,
     118,   106,     4,     4,    28,   105,   125,   105,    28,    88,
      90,    39,   107,    27,    38,    89,    10,    92,    41,    15,
      26,    41,   107,   136,    26,    41,   118,    28,    28,    28,
      27,    15,   105,    15,    28,    97,    62,    26,    28,    39,
      28,    28,    39,    28,    90,    39,   107,   133,    41,    95,
      97,    97,   105,    28,   105,    15,    15,   105,    97,   107,
     105,    28,    39,    65,    28,    97,    28,    28,   105,    28,
     105,    15,    97,    15,    97,    97,    28,    97,    28,    28,
     105,    97,    97,    97,    28,    97
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
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 14:
#line 117 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); ;}
    break;

  case 15:
#line 118 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs(NULL, (yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 16:
#line 119 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node));;}
    break;

  case 17:
#line 120 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs(NULL, (yyvsp[(1) - (1)].ast_node));;}
    break;

  case 18:
#line 121 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node));;}
    break;

  case 19:
#line 122 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs(NULL, (yyvsp[(1) - (1)].ast_node));;}
    break;

  case 23:
#line 131 "parser.y"
    { (yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 24:
#line 132 "parser.y"
    { addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 25:
#line 134 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 26:
#line 135 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kVarInit, (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 27:
#line 137 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (2)].ast_node); addLeftMost((yyval.ast_node), (yyvsp[(1) - (2)].ast_node)); ;}
    break;

  case 28:
#line 138 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 29:
#line 141 "parser.y"
    {(yyval.ast_node) = createVarDecl(NULL, (yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 30:
#line 142 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node); ;}
    break;

  case 31:
#line 143 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node);;}
    break;

  case 32:
#line 144 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node);;}
    break;

  case 33:
#line 145 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node);;}
    break;

  case 34:
#line 146 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node);;}
    break;

  case 35:
#line 149 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 36:
#line 150 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (2)].ast_node); addLeftMost((yyval.ast_node), (yyvsp[(1) - (2)].ast_node));;}
    break;

  case 37:
#line 151 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 38:
#line 154 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node);;}
    break;

  case 39:
#line 155 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node); ;}
    break;

  case 40:
#line 156 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 41:
#line 157 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node);;}
    break;

  case 42:
#line 158 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, NULL); ;}
    break;

  case 43:
#line 159 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node);;}
    break;

  case 44:
#line 160 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 45:
#line 161 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node);;}
    break;

  case 46:
#line 162 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, NULL); ;}
    break;

  case 47:
#line 165 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node); ;}
    break;

  case 48:
#line 166 "parser.y"
    {addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 49:
#line 169 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 50:
#line 170 "parser.y"
    {addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 51:
#line 173 "parser.y"
    {assignType((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 52:
#line 174 "parser.y"
    {assignType((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 54:
#line 178 "parser.y"
    {(yyval.ast_node) = createPtrType((yyvsp[(2) - (2)].ast_node)); (yyval.ast_node) = createFeaturedType((yyvsp[(2) - (2)].ast_node), NULL);;}
    break;

  case 55:
#line 179 "parser.y"
    {(yyval.ast_node) = createPtrType(NULL); ;}
    break;

  case 56:
#line 180 "parser.y"
    {(yyval.ast_node) = createFeaturedType((yyvsp[(2) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); (yyval.ast_node) = createPtrType((yyval.ast_node)); ;}
    break;

  case 57:
#line 181 "parser.y"
    {(yyval.ast_node) = createPtrType((yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 60:
#line 189 "parser.y"
    {(yyval.ast_node) = createExprTree((yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 61:
#line 190 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kInitList, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 62:
#line 191 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kInitList, (yyvsp[(2) - (4)].ast_node)); ;}
    break;

  case 63:
#line 193 "parser.y"
    { (yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 64:
#line 194 "parser.y"
    { addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 71:
#line 205 "parser.y"
    {(yyval.ast_node) = createLabledStmt((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 72:
#line 206 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kCase, (yyvsp[(2) - (4)].ast_node), (yyvsp[(4) - (4)].ast_node)); ;}
    break;

  case 74:
#line 210 "parser.y"
    {(yyval.ast_node) = createExprTree((yyvsp[(1) - (2)].ast_node));;}
    break;

  case 76:
#line 214 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kScope, (yyvsp[(2) - (4)].ast_node), (yyvsp[(3) - (4)].ast_node)); ;}
    break;

  case 77:
#line 215 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kScope, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 78:
#line 216 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kScope, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 79:
#line 217 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kScope, NULL); ;}
    break;

  case 80:
#line 220 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 81:
#line 221 "parser.y"
    {addNext((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 82:
#line 224 "parser.y"
    {(yyval.ast_node) = createTrinaryTreeNode(kIfStmt, (yyvsp[(3) - (5)].ast_node), (yyvsp[(5) - (5)].ast_node), NULL); ;}
    break;

  case 83:
#line 225 "parser.y"
    {(yyval.ast_node) = createTrinaryTreeNode(kIfStmt, (yyvsp[(3) - (7)].ast_node), (yyvsp[(5) - (7)].ast_node), (yyvsp[(7) - (7)].ast_node)); ;}
    break;

  case 84:
#line 226 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kSwitchStmt, (yyvsp[(3) - (5)].ast_node), (yyvsp[(5) - (5)].ast_node)); ;}
    break;

  case 85:
#line 229 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kWhileStmt, createExprTree((yyvsp[(3) - (5)].ast_node)), (yyvsp[(5) - (5)].ast_node)); ;}
    break;

  case 86:
#line 230 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kDoWhileStmt, (yyvsp[(2) - (7)].ast_node), createExprTree((yyvsp[(5) - (7)].ast_node))); ;}
    break;

  case 87:
#line 231 "parser.y"
    {(yyval.ast_node) = createForStmt((yyvsp[(3) - (9)].ast_node), (yyvsp[(5) - (9)].ast_node), (yyvsp[(7) - (9)].ast_node), (yyvsp[(9) - (9)].ast_node)); ;}
    break;

  case 88:
#line 232 "parser.y"
    {(yyval.ast_node) = createForStmt((yyvsp[(3) - (8)].ast_node), (yyvsp[(5) - (8)].ast_node), NULL, (yyvsp[(8) - (8)].ast_node)); ;}
    break;

  case 89:
#line 233 "parser.y"
    {(yyval.ast_node) = createForStmt((yyvsp[(3) - (8)].ast_node), NULL, (yyvsp[(6) - (8)].ast_node), (yyvsp[(8) - (8)].ast_node)); ;}
    break;

  case 90:
#line 234 "parser.y"
    {(yyval.ast_node) = createForStmt((yyvsp[(3) - (7)].ast_node), NULL, NULL, (yyvsp[(7) - (7)].ast_node)); ;}
    break;

  case 91:
#line 235 "parser.y"
    {(yyval.ast_node) = createForStmt(NULL, (yyvsp[(4) - (8)].ast_node), (yyvsp[(6) - (8)].ast_node), (yyvsp[(8) - (8)].ast_node)); ;}
    break;

  case 92:
#line 236 "parser.y"
    {(yyval.ast_node) = createForStmt(NULL, (yyvsp[(4) - (7)].ast_node), NULL, (yyvsp[(7) - (7)].ast_node)); ;}
    break;

  case 93:
#line 237 "parser.y"
    {(yyval.ast_node) = createForStmt(NULL, NULL, (yyvsp[(5) - (7)].ast_node), (yyvsp[(7) - (7)].ast_node)); ;}
    break;

  case 94:
#line 238 "parser.y"
    {(yyval.ast_node) = createForStmt(NULL, NULL, NULL, (yyvsp[(6) - (6)].ast_node)); ;}
    break;

  case 95:
#line 241 "parser.y"
    {addChild((yyvsp[(1) - (3)].ast_node), (yyvsp[(2) - (3)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node); ;}
    break;

  case 96:
#line 242 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 97:
#line 243 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 98:
#line 244 "parser.y"
    {(yyvsp[(2) - (3)].ast_node) = createExprTree((yyvsp[(2) - (3)].ast_node)); addChild((yyvsp[(1) - (3)].ast_node), (yyvsp[(2) - (3)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node); ;}
    break;

  case 99:
#line 245 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 101:
#line 250 "parser.y"
    {(yyval.ast_node) = createBinaryOpTree(",", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 103:
#line 253 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node); addChild((yyval.ast_node), (yyvsp[(1) - (3)].ast_node)); addChild((yyval.ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 105:
#line 257 "parser.y"
    {(yyval.ast_node) = createTrinaryOpTree((yyvsp[(1) - (5)].ast_node), (yyvsp[(3) - (5)].ast_node), (yyvsp[(5) - (5)].ast_node));;}
    break;

  case 107:
#line 261 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("||", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 109:
#line 265 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("&&", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 111:
#line 269 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("|", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 113:
#line 273 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("^", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 115:
#line 277 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("&", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 117:
#line 281 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("==", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 118:
#line 282 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("!=", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 120:
#line 286 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree(">", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 121:
#line 287 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("<", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 122:
#line 288 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree(">=", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 123:
#line 289 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("<=", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 125:
#line 293 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("<<", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 126:
#line 294 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree(">>", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 128:
#line 298 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("+", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 129:
#line 299 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("-", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 131:
#line 303 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("*", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 132:
#line 304 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("/", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 133:
#line 305 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("%", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 135:
#line 309 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kCast, (yyvsp[(2) - (4)].ast_node), (yyvsp[(4) - (4)].ast_node)); ;}
    break;

  case 137:
#line 313 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("++_", (yyvsp[(2) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 138:
#line 314 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("--_", (yyvsp[(2) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 139:
#line 315 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node); addChild((yyval.ast_node), (yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 140:
#line 316 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("sizeof", (yyvsp[(2) - (2)].ast_node));;}
    break;

  case 141:
#line 317 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("sizeof", (yyvsp[(3) - (4)].ast_node));;}
    break;

  case 142:
#line 320 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 143:
#line 321 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kSubScript, (yyvsp[(1) - (4)].ast_node), (yyvsp[(3) - (4)].ast_node)); ;}
    break;

  case 144:
#line 322 "parser.y"
    {(yyval.ast_node) = createStructMember((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node), "."); ;}
    break;

  case 145:
#line 323 "parser.y"
    {(yyval.ast_node) = createStructMember((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node), "->"); ;}
    break;

  case 146:
#line 324 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("_++", (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 147:
#line 325 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("_--", (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 148:
#line 326 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 149:
#line 330 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 150:
#line 331 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 151:
#line 332 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 152:
#line 333 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node);;}
    break;

  case 153:
#line 336 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "=", 1); ;}
    break;

  case 154:
#line 337 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "&", 1);;}
    break;

  case 155:
#line 338 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "/", 1);;}
    break;

  case 156:
#line 339 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "+", 1);;}
    break;

  case 157:
#line 340 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "-", 1);;}
    break;

  case 158:
#line 341 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "*", 1);;}
    break;

  case 159:
#line 342 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "<", 1);;}
    break;

  case 160:
#line 343 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, ">", 1);;}
    break;

  case 161:
#line 344 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "|", 1);;}
    break;

  case 162:
#line 345 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "^", 1);;}
    break;

  case 163:
#line 346 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "%", 1);;}
    break;

  case 164:
#line 349 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "+", 1);;}
    break;

  case 165:
#line 350 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "-", 1);;}
    break;

  case 166:
#line 351 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "&", 1);;}
    break;

  case 167:
#line 352 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "!", 1);;}
    break;

  case 168:
#line 353 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "~", 1);;}
    break;

  case 169:
#line 354 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "*", 1);;}
    break;

  case 170:
#line 358 "parser.y"
    { (yyval.ast_node) = createFunctionCallTree((yyvsp[(1) - (3)].ast_node), NULL);;}
    break;

  case 171:
#line 359 "parser.y"
    {(yyval.ast_node) = createFunctionCallTree((yyvsp[(1) - (4)].ast_node), (yyvsp[(3) - (4)].ast_node));;}
    break;

  case 172:
#line 362 "parser.y"
    {(yyval.ast_node) = createArgList((yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 173:
#line 363 "parser.y"
    {addChild((yyval.ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 177:
#line 373 "parser.y"
    {add_hidden_type((yyvsp[(2) - (5)].ast_node)->val_); addChild((yyvsp[(1) - (5)].ast_node), (yyvsp[(2) - (5)].ast_node)); addChild((yyvsp[(1) - (5)].ast_node), (yyvsp[(4) - (5)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (5)].ast_node);;}
    break;

  case 178:
#line 374 "parser.y"
    {addChild((yyvsp[(1) - (4)].ast_node), EMPTY_NODE); addChild((yyvsp[(1) - (4)].ast_node), (yyvsp[(3) - (4)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node);;}
    break;

  case 179:
#line 375 "parser.y"
    {addChild((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); addChild((yyvsp[(1) - (2)].ast_node), EMPTY_NODE); (yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 180:
#line 378 "parser.y"
    {(yyval.ast_node) = createAstNode(kStructType, NULL, 0); ;}
    break;

  case 181:
#line 379 "parser.y"
    {(yyval.ast_node) = createAstNode(kUnionType, NULL, 0); ;}
    break;

  case 182:
#line 382 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 183:
#line 383 "parser.y"
    {addNext((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 184:
#line 386 "parser.y"
    {assignType((yyvsp[(2) - (3)].ast_node), (yyvsp[(1) - (3)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (3)].ast_node);;}
    break;

  case 185:
#line 388 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node));;}
    break;

  case 186:
#line 389 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs(NULL, (yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 187:
#line 390 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); ;}
    break;

  case 188:
#line 391 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs(NULL, (yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 189:
#line 394 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 190:
#line 395 "parser.y"
    {addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 192:
#line 403 "parser.y"
    {add_hidden_type((yyvsp[(2) - (5)].ast_node)->val_); (yyval.ast_node) = createBinaryTreeNode(kEnumType, (yyvsp[(2) - (5)].ast_node), (yyvsp[(4) - (5)].ast_node)); ;}
    break;

  case 193:
#line 404 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kEnumType, NULL, (yyvsp[(3) - (4)].ast_node));;}
    break;

  case 194:
#line 405 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kEnumType, (yyvsp[(2) - (2)].ast_node), NULL); ;}
    break;

  case 195:
#line 408 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 196:
#line 409 "parser.y"
    {addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 197:
#line 412 "parser.y"
    {(yyval.ast_node) = createEnumerator((yyvsp[(1) - (1)].ast_node), NULL); ;}
    break;

  case 198:
#line 413 "parser.y"
    {(yyval.ast_node) = createEnumerator((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 199:
#line 416 "parser.y"
    { (yyval.ast_node) = createAstNode(kEnumType, NULL, 0); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2784 "./tiny_compiler_yacc.c"
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


#line 420 "parser.y"

int yyerror(char* s) {
    printf("tinyParser: \033[31merror:\033[0m %s at %s:%d:%d\n", s, TinyParserGetPwd(), TinyParserGetLine(), TinyParserGetColumn() - TinyParserGetCurTokLen());
    show_lexer_error(TinyParserGetPwd(), TinyParserGetColumn() - TinyParserGetCurTokLen(), TinyParserGetLine());
    return 1;
}


