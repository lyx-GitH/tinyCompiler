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
#define YYLAST   1049

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  204
/* YYNRULES -- Number of states.  */
#define YYNSTATES  354

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
     205,   209,   212,   214,   219,   223,   227,   230,   232,   235,
     241,   249,   257,   259,   262,   267,   271,   275,   278,   284,
     292,   302,   311,   320,   328,   337,   345,   353,   360,   364,
     367,   370,   374,   377,   379,   383,   385,   389,   391,   397,
     399,   403,   405,   409,   411,   415,   417,   421,   423,   427,
     429,   433,   437,   439,   443,   447,   451,   455,   457,   461,
     465,   467,   471,   475,   477,   481,   485,   489,   491,   496,
     498,   501,   504,   507,   510,   515,   517,   522,   526,   530,
     533,   536,   538,   542,   547,   549,   553,   555,   557,   559,
     563,   565,   567,   569,   571,   573,   575,   577,   579,   581,
     583,   585,   587,   589,   591,   593,   595,   597,   600,   602,
     604,   606,   608,   614,   619,   622,   624,   626,   628,   631,
     635,   638,   640,   643,   645,   647,   651,   653,   659,   664,
     667,   669,   673,   675,   679
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      75,     0,    -1,    76,    -1,    77,    -1,    76,    77,    -1,
      78,    -1,    80,    -1,     9,    80,    -1,    81,    87,   101,
      -1,    87,   101,    -1,    80,    -1,    79,    80,    -1,    81,
      85,    15,    -1,    81,    15,    -1,    82,    81,    -1,    83,
      81,    -1,    83,    -1,    84,    81,    -1,    84,    -1,     8,
      -1,   130,    -1,     7,    -1,    86,    -1,    85,    27,    86,
      -1,    87,    -1,    87,    49,    96,    -1,    94,    88,    -1,
      88,    -1,     4,    -1,    28,    87,    29,    -1,    88,    39,
     110,    40,    -1,    88,    39,    40,    -1,    88,    28,    91,
      29,    -1,    88,    28,    29,    -1,    94,    -1,    94,    90,
      -1,    90,    -1,    28,    89,    29,    -1,    90,    39,   110,
      40,    -1,    39,   110,    40,    -1,    90,    39,    40,    -1,
      39,    40,    -1,    90,    28,    91,    29,    -1,    28,    91,
      29,    -1,    90,    28,    29,    -1,    28,    29,    -1,    92,
      -1,    92,    27,    10,    -1,    93,    -1,    92,    27,    93,
      -1,    81,    87,    -1,    81,    89,    -1,    81,    -1,    24,
      95,    -1,    24,    -1,    24,    95,    94,    -1,    24,    94,
      -1,    84,    -1,    95,    84,    -1,   109,    -1,    41,    97,
      42,    -1,    41,    97,    27,    42,    -1,    96,    -1,    97,
      27,    96,    -1,    99,    -1,   100,    -1,   101,    -1,   103,
      -1,   106,    -1,   107,    -1,     4,    63,    98,    -1,   108,
      15,    -1,    15,    -1,    41,    79,   102,    42,    -1,    41,
     102,    42,    -1,    41,    79,    42,    -1,    41,    42,    -1,
      98,    -1,   102,    98,    -1,    65,    28,   108,    29,    98,
      -1,    65,    28,   108,    29,    98,    66,    98,    -1,    70,
      28,   108,    29,    41,   104,    42,    -1,   105,    -1,   104,
     105,    -1,    71,   110,    63,   102,    -1,    72,    63,   102,
      -1,    71,   110,    63,    -1,    72,    63,    -1,    67,    28,
     108,    29,    98,    -1,    68,    98,    67,    28,   108,    29,
      15,    -1,    69,    28,   108,    15,   108,    15,   108,    29,
      98,    -1,    69,    28,   108,    15,   108,    15,    29,    98,
      -1,    69,    28,   108,    15,    15,   108,    29,    98,    -1,
      69,    28,   108,    15,    15,    29,    98,    -1,    69,    28,
      15,   108,    15,   108,    29,    98,    -1,    69,    28,    15,
     108,    15,    29,    98,    -1,    69,    28,    15,    15,   108,
      29,    98,    -1,    69,    28,    15,    15,    29,    98,    -1,
      11,     4,    15,    -1,    13,    15,    -1,    12,    15,    -1,
      14,   108,    15,    -1,    14,    15,    -1,   109,    -1,   108,
      27,   109,    -1,   110,    -1,   122,   127,   109,    -1,   111,
      -1,   111,    62,   108,    63,   110,    -1,   112,    -1,   111,
      31,   112,    -1,   113,    -1,   112,    30,   113,    -1,   114,
      -1,   113,    33,   114,    -1,   115,    -1,   114,    35,   115,
      -1,   116,    -1,   115,    34,   116,    -1,   117,    -1,   116,
      47,   117,    -1,   116,    48,   117,    -1,   118,    -1,   117,
      43,   118,    -1,   117,    44,   118,    -1,   117,    45,   118,
      -1,   117,    46,   118,    -1,   119,    -1,   118,    37,   119,
      -1,   118,    38,   119,    -1,   120,    -1,   119,    22,   120,
      -1,   119,    23,   120,    -1,   121,    -1,   120,    24,   121,
      -1,   120,    25,   121,    -1,   120,    26,   121,    -1,   122,
      -1,    28,   129,    29,   121,    -1,   123,    -1,    60,   122,
      -1,    61,   122,    -1,   128,   121,    -1,    64,   122,    -1,
      64,    28,   129,    29,    -1,   126,    -1,   123,    39,   108,
      40,    -1,   123,    20,     4,    -1,   123,    21,     4,    -1,
     123,    60,    -1,   123,    61,    -1,   124,    -1,   123,    28,
      29,    -1,   123,    28,   125,    29,    -1,   109,    -1,   125,
      27,   109,    -1,     3,    -1,     5,    -1,     4,    -1,    28,
     108,    29,    -1,    49,    -1,    58,    -1,    53,    -1,    50,
      -1,    51,    -1,    52,    -1,    55,    -1,    56,    -1,    59,
      -1,    57,    -1,    54,    -1,    22,    -1,    23,    -1,    34,
      -1,    32,    -1,    36,    -1,    24,    -1,   135,    89,    -1,
     135,    -1,     6,    -1,   131,    -1,   138,    -1,   132,     4,
      41,   133,    42,    -1,   132,    41,   133,    42,    -1,   132,
       4,    -1,    17,    -1,    18,    -1,   134,    -1,   133,   134,
      -1,   135,   136,    15,    -1,    83,   135,    -1,    83,    -1,
      84,   135,    -1,    84,    -1,   137,    -1,   136,    27,   137,
      -1,    87,    -1,   141,     4,    41,   139,    42,    -1,   141,
      41,   139,    42,    -1,   141,     4,    -1,   140,    -1,   139,
      27,   140,    -1,     4,    -1,     4,    49,   110,    -1,    19,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,    98,    99,   101,   102,   103,   106,   107,
     110,   111,   114,   115,   125,   126,   127,   128,   129,   132,
     134,   136,   138,   139,   141,   142,   144,   145,   148,   149,
     150,   151,   152,   153,   156,   157,   158,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   172,   173,   176,   177,
     180,   181,   182,   185,   186,   187,   188,   191,   192,   196,
     197,   198,   200,   201,   204,   205,   206,   207,   208,   209,
     212,   215,   216,   219,   220,   221,   222,   225,   226,   229,
     230,   231,   234,   235,   238,   239,   240,   241,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   256,   257,
     258,   259,   260,   265,   266,   268,   269,   272,   273,   276,
     277,   280,   281,   284,   285,   288,   289,   292,   293,   296,
     297,   298,   301,   302,   303,   304,   305,   308,   309,   310,
     313,   314,   315,   318,   319,   320,   321,   324,   325,   328,
     329,   330,   331,   332,   333,   336,   337,   338,   339,   340,
     341,   342,   345,   346,   349,   350,   353,   354,   355,   356,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   372,   373,   374,   375,   376,   377,   383,   384,   387,
     389,   390,   394,   395,   396,   399,   400,   403,   404,   407,
     414,   415,   416,   417,   420,   421,   424,   429,   430,   431,
     434,   435,   438,   439,   442
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
  "stat_list", "selection_stat", "case_list", "case_stat",
  "iteration_stat", "jump_stat", "expression", "expression11",
  "expression10", "expression9", "expression8", "expression7",
  "expression6", "expression5", "expression4", "expression3",
  "expression2", "expression1", "term", "factor", "unaries", "postfix",
  "function_call", "args_list", "single", "aop", "uop", "type_name_cast",
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
      99,   100,   100,   101,   101,   101,   101,   102,   102,   103,
     103,   103,   104,   104,   105,   105,   105,   105,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   107,   107,
     107,   107,   107,   108,   108,   109,   109,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   116,   117,   117,   117,   117,   117,   118,   118,   118,
     119,   119,   119,   120,   120,   120,   120,   121,   121,   122,
     122,   122,   122,   122,   122,   123,   123,   123,   123,   123,
     123,   123,   124,   124,   125,   125,   126,   126,   126,   126,
     127,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   128,   128,   128,   128,   128,   128,   129,   129,   130,
     130,   130,   131,   131,   131,   132,   132,   133,   133,   134,
     135,   135,   135,   135,   136,   136,   137,   138,   138,   138,
     139,   139,   140,   140,   141
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
       3,     2,     1,     4,     3,     3,     2,     1,     2,     5,
       7,     7,     1,     2,     4,     3,     3,     2,     5,     7,
       9,     8,     8,     7,     8,     7,     7,     6,     3,     2,
       2,     3,     2,     1,     3,     1,     3,     1,     5,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     4,     1,
       2,     2,     2,     2,     4,     1,     4,     3,     3,     2,
       2,     1,     3,     4,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     5,     4,     2,     1,     1,     1,     2,     3,
       2,     1,     2,     1,     1,     3,     1,     5,     4,     2,
       1,     3,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    28,   179,    21,    19,     0,   185,   186,   204,    54,
       0,     0,     2,     3,     5,     6,     0,     0,    16,    18,
       0,    27,     0,    20,   180,     0,   181,     0,     7,     0,
      57,    56,    53,     0,     1,     4,    13,     0,    22,    24,
      14,    15,    17,     0,     9,     0,     0,    26,   184,     0,
     199,     0,    24,    58,    55,    29,    12,     0,     0,     8,
     156,   158,   157,     0,     0,     0,     0,    72,   171,   172,
     176,     0,   174,   173,   175,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    77,    64,    65,    66,
       0,    67,    68,    69,     0,   103,   105,   107,   109,   111,
     113,   115,   117,   119,   122,   127,   130,   133,   137,   139,
     151,   145,     0,    33,    52,     0,    46,    48,   158,    31,
       0,   137,     0,   191,   193,     0,   187,     0,     0,   202,
       0,   200,    23,     0,    25,    59,     0,     0,   100,    99,
     102,     0,     0,     0,   178,     0,   140,   141,     0,   143,
       0,     0,     0,     0,     0,    75,    11,     0,    74,    78,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   160,   163,   164,   165,   162,   170,   166,   167,   169,
     161,   168,     0,     0,     0,     0,     0,   149,   150,   142,
       0,     0,    50,    51,    36,    34,    32,     0,    30,     0,
     190,   192,   183,   188,   196,     0,   194,     0,     0,     0,
     198,    62,     0,    70,    98,   101,   159,     0,     0,   177,
      34,     0,     0,     0,     0,     0,     0,     0,    73,   104,
     110,     0,   112,   114,   116,   118,   120,   121,   123,   124,
     125,   126,   128,   129,   131,   132,   134,   135,   136,   106,
     147,   148,   152,   154,     0,     0,    45,     0,     0,    41,
       0,     0,     0,    35,    47,    49,   182,   189,     0,   197,
     203,   201,     0,    60,   138,   144,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   153,   146,    37,    43,    39,
      44,     0,    40,     0,   195,    61,    63,    79,    88,     0,
       0,     0,     0,     0,     0,     0,   108,   155,    42,    38,
       0,     0,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,    80,    89,    96,    95,     0,    93,     0,
       0,     0,     0,    87,    81,    83,    94,    92,    91,     0,
      86,    85,    90,    84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    84,    15,   114,    17,    18,
      19,    37,    38,    20,    21,   267,   204,   268,   116,   117,
      22,    32,   134,   222,    86,    87,    88,    89,    90,    91,
     331,   332,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   264,   111,   192,   112,   143,    23,    24,    25,   125,
     126,   127,   215,   216,    26,   130,   131,    27
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -127
static const yytype_int16 yypact[] =
{
     332,  -127,  -127,  -127,  -127,   274,  -127,  -127,  -127,    79,
      31,    45,   332,  -127,  -127,  -127,   138,   274,   274,   274,
     -16,   -17,    81,  -127,  -127,     2,  -127,    17,  -127,   138,
    -127,  -127,    79,    -6,  -127,  -127,  -127,     0,  -127,    66,
    -127,  -127,  -127,   301,  -127,   203,    14,   -17,    30,   187,
      36,    77,    42,  -127,  -127,  -127,  -127,    31,   663,  -127,
    -127,    50,  -127,   113,   126,   136,   685,  -127,  -127,  -127,
    -127,   641,  -127,  -127,  -127,  -127,   927,   927,   949,   146,
     164,   573,   179,   206,   369,  -127,  -127,  -127,  -127,  -127,
     437,  -127,  -127,  -127,   213,  -127,  -127,    -5,   140,   205,
     238,   209,   167,   302,   284,   341,   122,  -127,   431,   124,
    -127,  -127,   971,  -127,    25,   249,   259,  -127,  -127,  -127,
     250,  -127,   187,   187,   187,   161,  -127,    31,    77,   246,
      72,  -127,  -127,   663,  -127,  -127,   573,   287,  -127,  -127,
    -127,   224,   208,   282,   147,   971,  -127,  -127,   641,  -127,
     971,   971,   260,   707,   971,  -127,  -127,   505,  -127,  -127,
    -127,   971,   971,   971,   971,   971,   971,   971,   971,   971,
     971,   971,   971,   971,   971,   971,   971,   971,   971,   971,
     971,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,   971,   313,   327,   729,   971,  -127,  -127,  -127,
    1010,   751,  -127,  -127,   160,    37,  -127,   406,  -127,   183,
    -127,  -127,  -127,  -127,  -127,   226,  -127,   112,   971,    77,
    -127,  -127,   149,  -127,  -127,  -127,  -127,   971,   438,  -127,
     169,   305,   229,   235,   316,   773,   230,   240,  -127,  -127,
     140,    -3,   205,   238,   209,   167,   302,   302,   284,   284,
     284,   284,   341,   341,   122,   122,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,   247,   142,  -127,   329,   338,  -127,
     345,   281,   795,   160,  -127,  -127,  -127,  -127,    31,  -127,
    -127,  -127,   589,  -127,  -127,  -127,   573,   573,   971,   817,
     244,   839,   354,   971,   971,  -127,  -127,  -127,  -127,  -127,
    -127,   373,  -127,   358,  -127,  -127,  -127,   340,  -127,   267,
     573,   299,   861,   883,   245,   307,  -127,  -127,  -127,  -127,
     573,   389,  -127,   573,   573,   303,   573,   330,   905,   971,
     346,    40,  -127,  -127,  -127,  -127,  -127,   573,  -127,   573,
     573,   367,   352,   573,  -127,  -127,  -127,  -127,  -127,   573,
     573,   573,  -127,   573
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,   405,  -127,  -127,     4,    51,  -127,    94,
      35,  -127,   361,    23,   -18,  -104,  -126,   -42,  -127,   212,
      -4,  -127,  -121,  -127,   -74,  -127,  -127,    69,   -82,  -127,
    -127,    89,  -127,  -127,   -58,     3,   -45,  -127,   264,   257,
     262,   256,   261,   221,   182,   225,   231,   -78,   -46,  -127,
    -127,  -127,  -127,  -127,  -127,   283,  -127,  -127,  -127,   310,
    -111,   -51,  -127,   157,  -127,   315,   228,  -127
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     121,   120,   157,   115,    47,    31,    48,   152,   141,    28,
     203,    45,   221,   142,   213,    56,   159,    60,   118,    62,
     144,    50,    46,    55,   161,    43,   162,    57,    54,     1,
     146,   147,   149,    33,   199,     1,    68,    69,    70,    39,
     229,     1,    71,    49,    30,    34,    72,    85,    73,     9,
      74,    16,    52,   200,   119,     9,    29,   163,    51,    10,
     293,   135,   223,    16,   201,   200,   121,    53,    40,    41,
      42,   122,   210,   211,    76,    77,   201,   128,    78,   273,
      52,   129,   344,   159,   124,     1,     3,   142,   156,    44,
     142,    58,   232,   233,    29,   236,   237,   144,   213,   219,
     256,   257,   258,     9,   273,   241,   124,    43,    59,    10,
     205,   329,   330,   136,   220,    58,   121,   137,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,    29,   135,   202,   265,   219,
     230,   138,     1,   123,   193,   194,   178,   179,   180,   284,
     214,   139,   195,    36,   279,   121,   270,   124,   124,   124,
     124,   306,     9,   196,   239,   123,    10,     2,     3,   161,
     164,     9,   121,   280,   150,   228,   282,   290,     6,     7,
       8,   121,   296,   124,   197,   198,   201,    47,   271,     2,
       3,   283,   151,     2,     3,   259,   205,   228,   263,   272,
       6,     7,     8,   212,     6,     7,     8,   153,   201,     2,
       3,     4,   307,   308,   168,   169,   123,   123,   123,   123,
       6,     7,     8,    33,   230,   276,   121,   303,   160,   301,
     309,   311,   113,   314,   154,   161,   322,   226,   165,   225,
     161,   277,   123,   167,   124,   291,   333,   121,   316,   335,
     336,   161,   338,   278,   325,   327,   161,   161,   286,   312,
     328,   351,   161,   346,   287,   347,   348,   161,   353,   292,
     341,   161,   161,   166,   294,   352,   295,   159,   206,   159,
       2,     3,     4,   121,   342,   135,   207,     2,     3,     4,
     208,     6,     7,     8,   161,   218,   321,   317,     6,     7,
       8,   214,   224,   123,    60,    61,    62,     2,     3,     4,
     300,   227,    63,    64,    65,    66,    67,   260,     6,     7,
       8,   174,   175,    68,    69,    70,   161,   234,   323,    71,
     161,   261,   337,    72,   285,    73,     1,    74,     2,     3,
       4,     5,    43,    75,   288,   170,   171,   172,   173,     6,
       7,     8,   248,   249,   250,   251,     9,   161,   297,   339,
      10,    76,    77,   176,   177,    78,    79,   298,    80,    81,
      82,    83,    60,    61,    62,     2,     3,     4,   329,   330,
      63,    64,    65,    66,    67,   299,     6,     7,     8,   246,
     247,    68,    69,    70,   161,   315,   349,    71,   319,   252,
     253,    72,   318,    73,   334,    74,   320,   254,   255,   343,
      43,   155,     2,     3,     4,   350,   274,    35,   132,   275,
     345,   242,   244,     6,     7,     8,   240,   243,   245,    76,
      77,   231,   209,    78,    79,   304,    80,    81,    82,    83,
      60,    61,    62,   217,     2,     3,     4,   281,    63,    64,
      65,    66,    67,     0,     0,     6,     7,     8,     0,    68,
      69,    70,     9,     0,     0,    71,   228,   266,     0,    72,
       0,    73,     0,    74,     0,     0,     0,   201,    43,   158,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,     0,     0,     0,     0,     0,    76,    77,     0,
       0,    78,    79,     0,    80,    81,    82,    83,    60,    61,
      62,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,     0,     0,     0,     0,     0,     0,    68,    69,    70,
       0,     0,     0,    71,     0,     0,     0,    72,     0,    73,
       0,    74,     0,     0,     0,     0,    43,   238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,     0,     0,    78,
      79,     0,    80,    81,    82,    83,    60,    61,    62,     0,
       0,     0,     0,     0,    63,    64,    65,    66,    67,     0,
       0,     0,    60,   118,    62,    68,    69,    70,     0,     0,
       0,    71,     0,     0,     0,    72,     0,    73,     0,    74,
       0,    68,    69,    70,    43,     0,     0,    71,     0,     0,
       0,    72,     0,    73,     0,    74,     0,     0,     0,     0,
     133,   305,     0,    76,    77,     0,     0,    78,    79,     0,
      80,    81,    82,    83,    60,   118,    62,     2,     3,    76,
      77,     0,     0,    78,     0,     0,     0,     0,     6,     7,
       8,     0,     0,    68,    69,    70,    60,   118,    62,    71,
       0,     0,     0,    72,     0,    73,     0,    74,     0,     0,
       0,     0,     0,     0,     0,    68,    69,    70,    60,   118,
      62,    71,     0,     0,     0,    72,     0,    73,     0,    74,
     140,    76,    77,     0,   133,    78,     0,    68,    69,    70,
      60,   118,    62,    71,     0,     0,     0,    72,     0,    73,
       0,    74,   235,    76,    77,     0,     0,    78,     0,    68,
      69,    70,    60,   118,    62,    71,     0,     0,     0,    72,
       0,    73,     0,    74,     0,    76,    77,     0,     0,    78,
       0,    68,    69,    70,    60,   118,    62,    71,   262,     0,
       0,    72,     0,    73,     0,    74,     0,    76,    77,     0,
       0,    78,     0,    68,    69,    70,    60,   118,    62,    71,
       0,     0,     0,    72,     0,    73,     0,    74,   289,    76,
      77,   269,     0,    78,     0,    68,    69,    70,    60,   118,
      62,    71,     0,     0,     0,    72,     0,    73,     0,    74,
       0,    76,    77,     0,     0,    78,     0,    68,    69,    70,
      60,   118,    62,    71,     0,     0,     0,    72,     0,    73,
       0,    74,     0,    76,    77,   302,     0,    78,     0,    68,
      69,    70,    60,   118,    62,    71,   310,     0,     0,    72,
       0,    73,     0,    74,   313,    76,    77,     0,     0,    78,
       0,    68,    69,    70,    60,   118,    62,    71,     0,     0,
       0,    72,     0,    73,     0,    74,     0,    76,    77,     0,
       0,    78,     0,    68,    69,    70,    60,   118,    62,    71,
     324,     0,     0,    72,     0,    73,     0,    74,     0,    76,
      77,     0,     0,    78,     0,    68,    69,    70,    60,   118,
      62,    71,   326,     0,     0,    72,     0,    73,     0,    74,
       0,    76,    77,     0,     0,    78,     0,    68,    69,    70,
      60,   118,    62,    71,   340,     0,     0,    72,     0,    73,
       0,    74,     0,    76,    77,     0,     0,    78,     0,    68,
      69,    70,    60,   118,    62,   145,     0,     0,     0,    72,
       0,    73,     0,    74,     0,    76,    77,     0,     0,    78,
       0,    68,    69,    70,    60,   118,    62,   148,     0,     0,
       0,    72,     0,    73,     0,    74,     0,    76,    77,     0,
       0,    78,     0,    68,    69,    70,     0,     0,     0,    71,
       0,     0,     0,    72,     0,    73,     0,    74,     0,    76,
      77,     0,     0,    78,     1,     0,     2,     3,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     6,     7,     8,
       0,    76,    77,     0,     9,    78,     0,     0,   200,   266,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   201
};

static const yytype_int16 yycheck[] =
{
      46,    46,    84,    45,    22,     9,     4,    81,    66,     5,
     114,    28,   133,    71,   125,    15,    90,     3,     4,     5,
      71,     4,    39,    29,    27,    41,    31,    27,    32,     4,
      76,    77,    78,    10,   112,     4,    22,    23,    24,    16,
     144,     4,    28,    41,     9,     0,    32,    43,    34,    24,
      36,     0,    29,    28,    40,    24,     5,    62,    41,    28,
      63,    58,   136,    12,    39,    28,   112,    32,    17,    18,
      19,    41,   123,   124,    60,    61,    39,    41,    64,   205,
      57,     4,    42,   157,    49,     4,     7,   145,    84,    20,
     148,    49,   150,   151,    43,   153,   154,   148,   209,    27,
     178,   179,   180,    24,   230,   163,    71,    41,    39,    28,
     114,    71,    72,    63,    42,    49,   162,     4,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    84,   133,   114,   196,    27,
     144,    15,     4,    49,    20,    21,    24,    25,    26,   227,
     127,    15,    28,    15,    42,   201,   201,   122,   123,   124,
     125,   282,    24,    39,   161,    71,    28,     6,     7,    27,
      30,    24,   218,   218,    28,    28,    27,   235,    17,    18,
      19,   227,    40,   148,    60,    61,    39,   205,    28,     6,
       7,    42,    28,     6,     7,   192,   200,    28,   195,    39,
      17,    18,    19,    42,    17,    18,    19,    28,    39,     6,
       7,     8,   286,   287,    47,    48,   122,   123,   124,   125,
      17,    18,    19,   200,   228,    42,   272,   272,    15,   271,
     288,   289,    29,   291,    28,    27,   310,    29,    33,    15,
      27,    15,   148,    34,   209,    15,   320,   293,   293,   323,
     324,    27,   326,    27,   312,   313,    27,    27,    29,    15,
      15,   343,    27,   337,    29,   339,   340,    27,   350,    29,
     328,    27,    27,    35,    27,   349,    29,   351,    29,   353,
       6,     7,     8,   329,   329,   282,    27,     6,     7,     8,
      40,    17,    18,    19,    27,    49,    29,   294,    17,    18,
      19,   278,    15,   209,     3,     4,     5,     6,     7,     8,
      29,    29,    11,    12,    13,    14,    15,     4,    17,    18,
      19,    37,    38,    22,    23,    24,    27,    67,    29,    28,
      27,     4,    29,    32,    29,    34,     4,    36,     6,     7,
       8,     9,    41,    42,    28,    43,    44,    45,    46,    17,
      18,    19,   170,   171,   172,   173,    24,    27,    29,    29,
      28,    60,    61,    22,    23,    64,    65,    29,    67,    68,
      69,    70,     3,     4,     5,     6,     7,     8,    71,    72,
      11,    12,    13,    14,    15,    40,    17,    18,    19,   168,
     169,    22,    23,    24,    27,    41,    29,    28,    40,   174,
     175,    32,    29,    34,    15,    36,    66,   176,   177,    63,
      41,    42,     6,     7,     8,    63,    10,    12,    57,   207,
     331,   164,   166,    17,    18,    19,   162,   165,   167,    60,
      61,   148,   122,    64,    65,   278,    67,    68,    69,    70,
       3,     4,     5,   128,     6,     7,     8,   219,    11,    12,
      13,    14,    15,    -1,    -1,    17,    18,    19,    -1,    22,
      23,    24,    24,    -1,    -1,    28,    28,    29,    -1,    32,
      -1,    34,    -1,    36,    -1,    -1,    -1,    39,    41,    42,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    64,    65,    -1,    67,    68,    69,    70,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    32,    -1,    34,
      -1,    36,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,
      65,    -1,    67,    68,    69,    70,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,    -1,
      -1,    -1,     3,     4,     5,    22,    23,    24,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    32,    -1,    34,    -1,    36,
      -1,    22,    23,    24,    41,    -1,    -1,    28,    -1,    -1,
      -1,    32,    -1,    34,    -1,    36,    -1,    -1,    -1,    -1,
      41,    42,    -1,    60,    61,    -1,    -1,    64,    65,    -1,
      67,    68,    69,    70,     3,     4,     5,     6,     7,    60,
      61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    17,    18,
      19,    -1,    -1,    22,    23,    24,     3,     4,     5,    28,
      -1,    -1,    -1,    32,    -1,    34,    -1,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,     3,     4,
       5,    28,    -1,    -1,    -1,    32,    -1,    34,    -1,    36,
      15,    60,    61,    -1,    41,    64,    -1,    22,    23,    24,
       3,     4,     5,    28,    -1,    -1,    -1,    32,    -1,    34,
      -1,    36,    15,    60,    61,    -1,    -1,    64,    -1,    22,
      23,    24,     3,     4,     5,    28,    -1,    -1,    -1,    32,
      -1,    34,    -1,    36,    -1,    60,    61,    -1,    -1,    64,
      -1,    22,    23,    24,     3,     4,     5,    28,    29,    -1,
      -1,    32,    -1,    34,    -1,    36,    -1,    60,    61,    -1,
      -1,    64,    -1,    22,    23,    24,     3,     4,     5,    28,
      -1,    -1,    -1,    32,    -1,    34,    -1,    36,    15,    60,
      61,    40,    -1,    64,    -1,    22,    23,    24,     3,     4,
       5,    28,    -1,    -1,    -1,    32,    -1,    34,    -1,    36,
      -1,    60,    61,    -1,    -1,    64,    -1,    22,    23,    24,
       3,     4,     5,    28,    -1,    -1,    -1,    32,    -1,    34,
      -1,    36,    -1,    60,    61,    40,    -1,    64,    -1,    22,
      23,    24,     3,     4,     5,    28,    29,    -1,    -1,    32,
      -1,    34,    -1,    36,    15,    60,    61,    -1,    -1,    64,
      -1,    22,    23,    24,     3,     4,     5,    28,    -1,    -1,
      -1,    32,    -1,    34,    -1,    36,    -1,    60,    61,    -1,
      -1,    64,    -1,    22,    23,    24,     3,     4,     5,    28,
      29,    -1,    -1,    32,    -1,    34,    -1,    36,    -1,    60,
      61,    -1,    -1,    64,    -1,    22,    23,    24,     3,     4,
       5,    28,    29,    -1,    -1,    32,    -1,    34,    -1,    36,
      -1,    60,    61,    -1,    -1,    64,    -1,    22,    23,    24,
       3,     4,     5,    28,    29,    -1,    -1,    32,    -1,    34,
      -1,    36,    -1,    60,    61,    -1,    -1,    64,    -1,    22,
      23,    24,     3,     4,     5,    28,    -1,    -1,    -1,    32,
      -1,    34,    -1,    36,    -1,    60,    61,    -1,    -1,    64,
      -1,    22,    23,    24,     3,     4,     5,    28,    -1,    -1,
      -1,    32,    -1,    34,    -1,    36,    -1,    60,    61,    -1,
      -1,    64,    -1,    22,    23,    24,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    32,    -1,    34,    -1,    36,    -1,    60,
      61,    -1,    -1,    64,     4,    -1,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      -1,    60,    61,    -1,    24,    64,    -1,    -1,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     6,     7,     8,     9,    17,    18,    19,    24,
      28,    75,    76,    77,    78,    80,    81,    82,    83,    84,
      87,    88,    94,   130,   131,   132,   138,   141,    80,    81,
      84,    94,    95,    87,     0,    77,    15,    85,    86,    87,
      81,    81,    81,    41,   101,    28,    39,    88,     4,    41,
       4,    41,    87,    84,    94,    29,    15,    27,    49,   101,
       3,     4,     5,    11,    12,    13,    14,    15,    22,    23,
      24,    28,    32,    34,    36,    42,    60,    61,    64,    65,
      67,    68,    69,    70,    79,    80,    98,    99,   100,   101,
     102,   103,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   126,   128,    29,    81,    91,    92,    93,     4,    40,
     110,   122,    41,    83,    84,   133,   134,   135,    41,     4,
     139,   140,    86,    41,    96,   109,    63,     4,    15,    15,
      15,   108,   108,   129,   135,    28,   122,   122,    28,   122,
      28,    28,    98,    28,    28,    42,    80,   102,    42,    98,
      15,    27,    31,    62,    30,    33,    35,    34,    47,    48,
      43,    44,    45,    46,    37,    38,    22,    23,    24,    25,
      26,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,   127,    20,    21,    28,    39,    60,    61,   121,
      28,    39,    87,    89,    90,    94,    29,    27,    40,   133,
     135,   135,    42,   134,    87,   136,   137,   139,    49,    27,
      42,    96,    97,    98,    15,    15,    29,    29,    28,    89,
      94,   129,   108,   108,    67,    15,   108,   108,    42,   109,
     112,   108,   113,   114,   115,   116,   117,   117,   118,   118,
     118,   118,   119,   119,   120,   120,   121,   121,   121,   109,
       4,     4,    29,   109,   125,   108,    29,    89,    91,    40,
     110,    28,    39,    90,    10,    93,    42,    15,    27,    42,
     110,   140,    27,    42,   121,    29,    29,    29,    28,    15,
     108,    15,    29,    63,    27,    29,    40,    29,    29,    40,
      29,    91,    40,   110,   137,    42,    96,    98,    98,   108,
      29,   108,    15,    15,   108,    41,   110,   109,    29,    40,
      66,    29,    98,    29,    29,   108,    29,   108,    15,    71,
      72,   104,   105,    98,    15,    98,    98,    29,    98,    29,
      29,   108,   110,    63,    42,   105,    98,    98,    98,    29,
      63,   102,    98,   102
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
#line 98 "parser.y"
    {TinyParserAppendBlock((yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 4:
#line 99 "parser.y"
    {TinyParserAppendBlock((yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 5:
#line 101 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 6:
#line 102 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 7:
#line 103 "parser.y"
    {assert_valid_typedefs((yyvsp[(2) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 8:
#line 106 "parser.y"
    {assignType((yyvsp[(2) - (3)].ast_node), (yyvsp[(1) - (3)].ast_node)); (yyval.ast_node) = createBinaryTreeNode(kFuncDef, (yyvsp[(2) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 9:
#line 107 "parser.y"
    {assignType((yyvsp[(1) - (2)].ast_node), INT_TYPE); (yyval.ast_node) = createBinaryTreeNode(kFuncDef, (yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 10:
#line 110 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node); ;}
    break;

  case 11:
#line 111 "parser.y"
    {addNext((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node));;}
    break;

  case 12:
#line 114 "parser.y"
    { assignType((yyvsp[(2) - (3)].ast_node), (yyvsp[(1) - (3)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (3)].ast_node); ;}
    break;

  case 13:
#line 115 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs((yyvsp[(1) - (2)].ast_node));;}
    break;

  case 14:
#line 125 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 15:
#line 126 "parser.y"
    {addNext((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 16:
#line 127 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node); ;}
    break;

  case 17:
#line 128 "parser.y"
    {addNext((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 18:
#line 129 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 22:
#line 138 "parser.y"
    { (yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 23:
#line 139 "parser.y"
    { addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 24:
#line 141 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 25:
#line 142 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kVarInit, (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 26:
#line 144 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (2)].ast_node); addLeftMost((yyval.ast_node), (yyvsp[(1) - (2)].ast_node)); ;}
    break;

  case 27:
#line 145 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 28:
#line 148 "parser.y"
    {(yyval.ast_node) = createVarDecl(NULL, (yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 29:
#line 149 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node); ;}
    break;

  case 30:
#line 150 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node);;}
    break;

  case 31:
#line 151 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node);;}
    break;

  case 32:
#line 152 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node); (yyval.ast_node)->type_ = kFuncDecl; ;}
    break;

  case 33:
#line 153 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node); (yyval.ast_node)->type_ = kFuncDecl; ;}
    break;

  case 34:
#line 156 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 35:
#line 157 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (2)].ast_node); addLeftMost((yyval.ast_node), (yyvsp[(1) - (2)].ast_node));;}
    break;

  case 36:
#line 158 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 37:
#line 161 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node);;}
    break;

  case 38:
#line 162 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node); ;}
    break;

  case 39:
#line 163 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 40:
#line 164 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node);;}
    break;

  case 41:
#line 165 "parser.y"
    {(yyval.ast_node) = createArrType(NULL, NULL); ;}
    break;

  case 42:
#line 166 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, (yyvsp[(3) - (4)].ast_node)); addLeftMost((yyvsp[(1) - (4)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node);;}
    break;

  case 43:
#line 167 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 44:
#line 168 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, NULL); addLeftMost((yyvsp[(1) - (3)].ast_node), (yyval.ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node);;}
    break;

  case 45:
#line 169 "parser.y"
    {(yyval.ast_node) = createFuncType(NULL, NULL); ;}
    break;

  case 46:
#line 172 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node); ;}
    break;

  case 47:
#line 173 "parser.y"
    {addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 48:
#line 176 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 49:
#line 177 "parser.y"
    {addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 50:
#line 180 "parser.y"
    {assignType((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 51:
#line 181 "parser.y"
    {assignType((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 53:
#line 185 "parser.y"
    {(yyval.ast_node) = createPtrType(NULL); (yyval.ast_node) = createFeaturedType((yyvsp[(2) - (2)].ast_node), (yyval.ast_node));;}
    break;

  case 54:
#line 186 "parser.y"
    {(yyval.ast_node) = createPtrType(NULL); ;}
    break;

  case 55:
#line 187 "parser.y"
    {(yyval.ast_node) = createFeaturedType((yyvsp[(2) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); (yyval.ast_node) = createPtrType((yyval.ast_node)); ;}
    break;

  case 56:
#line 188 "parser.y"
    {(yyval.ast_node) = createPtrType((yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 59:
#line 196 "parser.y"
    {(yyval.ast_node) = createExprTree((yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 60:
#line 197 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kInitList, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 61:
#line 198 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kInitList, (yyvsp[(2) - (4)].ast_node)); ;}
    break;

  case 62:
#line 200 "parser.y"
    { (yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 63:
#line 201 "parser.y"
    { addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 70:
#line 212 "parser.y"
    {(yyval.ast_node) = createLabledStmt((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 71:
#line 215 "parser.y"
    {(yyval.ast_node) = createExprTree((yyvsp[(1) - (2)].ast_node));;}
    break;

  case 73:
#line 219 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kScope, (yyvsp[(2) - (4)].ast_node), (yyvsp[(3) - (4)].ast_node)); ;}
    break;

  case 74:
#line 220 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kScope, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 75:
#line 221 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kScope, (yyvsp[(2) - (3)].ast_node)); ;}
    break;

  case 76:
#line 222 "parser.y"
    {(yyval.ast_node) = createUnaryTreeNode(kScope, NULL); ;}
    break;

  case 77:
#line 225 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 78:
#line 226 "parser.y"
    {addNext((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 79:
#line 229 "parser.y"
    {(yyval.ast_node) = createTrinaryTreeNode(kIfStmt, (yyvsp[(3) - (5)].ast_node), (yyvsp[(5) - (5)].ast_node), NULL); ;}
    break;

  case 80:
#line 230 "parser.y"
    {(yyval.ast_node) = createTrinaryTreeNode(kIfStmt, (yyvsp[(3) - (7)].ast_node), (yyvsp[(5) - (7)].ast_node), (yyvsp[(7) - (7)].ast_node)); ;}
    break;

  case 81:
#line 231 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kSwitchStmt, (yyvsp[(3) - (7)].ast_node), (yyvsp[(6) - (7)].ast_node)); ;}
    break;

  case 82:
#line 234 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 83:
#line 235 "parser.y"
    {addNext((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 84:
#line 238 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kCase, (yyvsp[(2) - (4)].ast_node), (yyvsp[(4) - (4)].ast_node)); ;}
    break;

  case 85:
#line 239 "parser.y"
    {(yyval.ast_node) = createLableThroughName("default", (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 86:
#line 240 "parser.y"
    {(yyval.ast_node) =createBinaryTreeNode(kCase, (yyvsp[(2) - (3)].ast_node), NULL);;}
    break;

  case 87:
#line 241 "parser.y"
    {(yyval.ast_node) = createLableThroughName("default", NULL);;}
    break;

  case 88:
#line 244 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kWhileStmt, createExprTree((yyvsp[(3) - (5)].ast_node)), (yyvsp[(5) - (5)].ast_node)); ;}
    break;

  case 89:
#line 245 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kDoWhileStmt, (yyvsp[(2) - (7)].ast_node), createExprTree((yyvsp[(5) - (7)].ast_node))); ;}
    break;

  case 90:
#line 246 "parser.y"
    {(yyval.ast_node) = createForStmt((yyvsp[(3) - (9)].ast_node), (yyvsp[(5) - (9)].ast_node), (yyvsp[(7) - (9)].ast_node), (yyvsp[(9) - (9)].ast_node)); ;}
    break;

  case 91:
#line 247 "parser.y"
    {(yyval.ast_node) = createForStmt((yyvsp[(3) - (8)].ast_node), (yyvsp[(5) - (8)].ast_node), NULL, (yyvsp[(8) - (8)].ast_node)); ;}
    break;

  case 92:
#line 248 "parser.y"
    {(yyval.ast_node) = createForStmt((yyvsp[(3) - (8)].ast_node), NULL, (yyvsp[(6) - (8)].ast_node), (yyvsp[(8) - (8)].ast_node)); ;}
    break;

  case 93:
#line 249 "parser.y"
    {(yyval.ast_node) = createForStmt((yyvsp[(3) - (7)].ast_node), NULL, NULL, (yyvsp[(7) - (7)].ast_node)); ;}
    break;

  case 94:
#line 250 "parser.y"
    {(yyval.ast_node) = createForStmt(NULL, (yyvsp[(4) - (8)].ast_node), (yyvsp[(6) - (8)].ast_node), (yyvsp[(8) - (8)].ast_node)); ;}
    break;

  case 95:
#line 251 "parser.y"
    {(yyval.ast_node) = createForStmt(NULL, (yyvsp[(4) - (7)].ast_node), NULL, (yyvsp[(7) - (7)].ast_node)); ;}
    break;

  case 96:
#line 252 "parser.y"
    {(yyval.ast_node) = createForStmt(NULL, NULL, (yyvsp[(5) - (7)].ast_node), (yyvsp[(7) - (7)].ast_node)); ;}
    break;

  case 97:
#line 253 "parser.y"
    {(yyval.ast_node) = createForStmt(NULL, NULL, NULL, (yyvsp[(6) - (6)].ast_node)); ;}
    break;

  case 98:
#line 256 "parser.y"
    {addChild((yyvsp[(1) - (3)].ast_node), (yyvsp[(2) - (3)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node); ;}
    break;

  case 99:
#line 257 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 100:
#line 258 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 101:
#line 259 "parser.y"
    {(yyvsp[(2) - (3)].ast_node) = createExprTree((yyvsp[(2) - (3)].ast_node)); addChild((yyvsp[(1) - (3)].ast_node), (yyvsp[(2) - (3)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (3)].ast_node); ;}
    break;

  case 102:
#line 260 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 104:
#line 266 "parser.y"
    {(yyval.ast_node) = createBinaryOpTree(",", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 106:
#line 269 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node); addChild((yyval.ast_node), (yyvsp[(1) - (3)].ast_node)); addChild((yyval.ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 108:
#line 273 "parser.y"
    {(yyval.ast_node) = createTrinaryOpTree((yyvsp[(1) - (5)].ast_node), (yyvsp[(3) - (5)].ast_node), (yyvsp[(5) - (5)].ast_node));;}
    break;

  case 110:
#line 277 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("||", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 112:
#line 281 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("&&", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 114:
#line 285 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("|", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 116:
#line 289 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("^", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 118:
#line 293 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("&", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 120:
#line 297 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("==", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 121:
#line 298 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("!=", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 123:
#line 302 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree(">", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 124:
#line 303 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("<", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 125:
#line 304 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree(">=", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 126:
#line 305 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("<=", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 128:
#line 309 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("<<", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 129:
#line 310 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree(">>", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 131:
#line 314 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("+", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 132:
#line 315 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("-", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 134:
#line 319 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("*", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 135:
#line 320 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("/", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 136:
#line 321 "parser.y"
    { (yyval.ast_node) = createBinaryOpTree("%", (yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 138:
#line 325 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kCast, (yyvsp[(2) - (4)].ast_node), (yyvsp[(4) - (4)].ast_node)); ;}
    break;

  case 140:
#line 329 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("++_", (yyvsp[(2) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 141:
#line 330 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("--_", (yyvsp[(2) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 142:
#line 331 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (2)].ast_node); addChild((yyval.ast_node), (yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 143:
#line 332 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("sizeof", (yyvsp[(2) - (2)].ast_node));;}
    break;

  case 144:
#line 333 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("sizeof", (yyvsp[(3) - (4)].ast_node));;}
    break;

  case 145:
#line 336 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 146:
#line 337 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kSubScript, (yyvsp[(1) - (4)].ast_node), (yyvsp[(3) - (4)].ast_node)); ;}
    break;

  case 147:
#line 338 "parser.y"
    {(yyval.ast_node) = createStructMember((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node), "."); ;}
    break;

  case 148:
#line 339 "parser.y"
    {(yyval.ast_node) = createStructMember((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node), "->"); ;}
    break;

  case 149:
#line 340 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("_++", (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 150:
#line 341 "parser.y"
    {(yyval.ast_node) = createUnaryOpTree("_--", (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node)->type_ = KUAsign; ;}
    break;

  case 151:
#line 342 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 152:
#line 345 "parser.y"
    { (yyval.ast_node) = createFunctionCallTree((yyvsp[(1) - (3)].ast_node), NULL);;}
    break;

  case 153:
#line 346 "parser.y"
    {(yyval.ast_node) = createFunctionCallTree((yyvsp[(1) - (4)].ast_node), (yyvsp[(3) - (4)].ast_node));;}
    break;

  case 154:
#line 349 "parser.y"
    {(yyval.ast_node) = createArgList((yyvsp[(1) - (1)].ast_node)); ;}
    break;

  case 155:
#line 350 "parser.y"
    {addChild((yyval.ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 156:
#line 353 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 157:
#line 354 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 158:
#line 355 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 159:
#line 356 "parser.y"
    {(yyval.ast_node) = (yyvsp[(2) - (3)].ast_node);;}
    break;

  case 160:
#line 359 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "=", 1); ;}
    break;

  case 161:
#line 360 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "&", 1);;}
    break;

  case 162:
#line 361 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "/", 1);;}
    break;

  case 163:
#line 362 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "+", 1);;}
    break;

  case 164:
#line 363 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "-", 1);;}
    break;

  case 165:
#line 364 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "*", 1);;}
    break;

  case 166:
#line 365 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "<<", 1);;}
    break;

  case 167:
#line 366 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, ">>", 1);;}
    break;

  case 168:
#line 367 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "|", 1);;}
    break;

  case 169:
#line 368 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "^", 1);;}
    break;

  case 170:
#line 369 "parser.y"
    {(yyval.ast_node) = createAstNode(kAssign, "%", 1);;}
    break;

  case 171:
#line 372 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "+", 1);;}
    break;

  case 172:
#line 373 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "-", 1);;}
    break;

  case 173:
#line 374 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "&", 1);;}
    break;

  case 174:
#line 375 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "!", 1);;}
    break;

  case 175:
#line 376 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "~", 1);;}
    break;

  case 176:
#line 377 "parser.y"
    {(yyval.ast_node) = createAstNode(kUop, "*", 1);;}
    break;

  case 177:
#line 383 "parser.y"
    {assignType((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 178:
#line 384 "parser.y"
    {(yyval.ast_node) = maintainTypeSpecs((yyvsp[(1) - (1)].ast_node));;}
    break;

  case 182:
#line 394 "parser.y"
    {add_hidden_type((yyvsp[(2) - (5)].ast_node)->val_); addChild((yyvsp[(1) - (5)].ast_node), (yyvsp[(2) - (5)].ast_node)); addChild((yyvsp[(1) - (5)].ast_node), (yyvsp[(4) - (5)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (5)].ast_node);;}
    break;

  case 183:
#line 395 "parser.y"
    {addChild((yyvsp[(1) - (4)].ast_node), EMPTY_NODE); addChild((yyvsp[(1) - (4)].ast_node), (yyvsp[(3) - (4)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (4)].ast_node);;}
    break;

  case 184:
#line 396 "parser.y"
    {addChild((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); addChild((yyvsp[(1) - (2)].ast_node), EMPTY_NODE); (yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 185:
#line 399 "parser.y"
    {(yyval.ast_node) = createAstNode(kStructType, NULL, 0); ;}
    break;

  case 186:
#line 400 "parser.y"
    {(yyval.ast_node) = createAstNode(kUnionType, NULL, 0); ;}
    break;

  case 187:
#line 403 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 188:
#line 404 "parser.y"
    {addNext((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); ;}
    break;

  case 189:
#line 407 "parser.y"
    {assignType((yyvsp[(2) - (3)].ast_node), (yyvsp[(1) - (3)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (3)].ast_node);;}
    break;

  case 190:
#line 414 "parser.y"
    {addNext((yyvsp[(1) - (2)].ast_node), (yyvsp[(2) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(1) - (2)].ast_node);;}
    break;

  case 191:
#line 415 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 192:
#line 416 "parser.y"
    {addNext((yyvsp[(2) - (2)].ast_node), (yyvsp[(1) - (2)].ast_node)); (yyval.ast_node) = (yyvsp[(2) - (2)].ast_node);;}
    break;

  case 193:
#line 417 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node); ;}
    break;

  case 194:
#line 420 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 195:
#line 421 "parser.y"
    {addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 197:
#line 429 "parser.y"
    {add_hidden_type((yyvsp[(2) - (5)].ast_node)->val_); (yyval.ast_node) = createBinaryTreeNode(kEnumType, (yyvsp[(2) - (5)].ast_node), (yyvsp[(4) - (5)].ast_node)); ;}
    break;

  case 198:
#line 430 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kEnumType, NULL, (yyvsp[(3) - (4)].ast_node));;}
    break;

  case 199:
#line 431 "parser.y"
    {(yyval.ast_node) = createBinaryTreeNode(kEnumType, (yyvsp[(2) - (2)].ast_node), NULL); ;}
    break;

  case 200:
#line 434 "parser.y"
    {(yyval.ast_node) = (yyvsp[(1) - (1)].ast_node);;}
    break;

  case 201:
#line 435 "parser.y"
    {addNext((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node)); ;}
    break;

  case 202:
#line 438 "parser.y"
    {(yyval.ast_node) = createEnumerator((yyvsp[(1) - (1)].ast_node), NULL); ;}
    break;

  case 203:
#line 439 "parser.y"
    {(yyval.ast_node) = createEnumerator((yyvsp[(1) - (3)].ast_node), (yyvsp[(3) - (3)].ast_node));;}
    break;

  case 204:
#line 442 "parser.y"
    { (yyval.ast_node) = createAstNode(kEnumType, NULL, 0); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2814 "./tiny_compiler_yacc.c"
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


#line 446 "parser.y"

int yyerror(char* s) {
    TinyParserRaiseError(s);
    return 1;
}


