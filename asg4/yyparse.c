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
     TOK_ROOT = 258,
     TOK_TYPEID = 259,
     TOK_FIELD = 260,
     TOK_INDEX = 261,
     TOK_POS = 262,
     TOK_NEG = 263,
     TOK_CALL = 264,
     TOK_NEWARRAY = 265,
     TOK_NEWSTRING = 266,
     TOK_IFELSE = 267,
     TOK_RETURNVOID = 268,
     TOK_BLOCK = 269,
     TOK_VARDECLINIT = 270,
     TOK_FUNCTION = 271,
     TOK_PARAMLIST = 272,
     TOK_PROTOTYPE = 273,
     TOK_WHILE = 274,
     TOK_IDENT = 275,
     TOK_CHARCON = 276,
     TOK_INTCON = 277,
     TOK_STRINGCON = 278,
     TOK_NEW = 279,
     TOK_NULL = 280,
     TOK_STRING = 281,
     TOK_STRUCT = 282,
     TOK_VOID = 283,
     TOK_BOOL = 284,
     TOK_CHAR = 285,
     TOK_INT = 286,
     TOK_RETURN = 287,
     TOK_FALSE = 288,
     TOK_TRUE = 289,
     TOK_LE = 290,
     TOK_GE = 291,
     TOK_ELSE = 292,
     TOK_IF = 293,
     TOK_GT = 294,
     TOK_LT = 295,
     TOK_NE = 296,
     TOK_EQ = 297
   };
#endif
/* Tokens.  */
#define TOK_ROOT 258
#define TOK_TYPEID 259
#define TOK_FIELD 260
#define TOK_INDEX 261
#define TOK_POS 262
#define TOK_NEG 263
#define TOK_CALL 264
#define TOK_NEWARRAY 265
#define TOK_NEWSTRING 266
#define TOK_IFELSE 267
#define TOK_RETURNVOID 268
#define TOK_BLOCK 269
#define TOK_VARDECLINIT 270
#define TOK_FUNCTION 271
#define TOK_PARAMLIST 272
#define TOK_PROTOTYPE 273
#define TOK_WHILE 274
#define TOK_IDENT 275
#define TOK_CHARCON 276
#define TOK_INTCON 277
#define TOK_STRINGCON 278
#define TOK_NEW 279
#define TOK_NULL 280
#define TOK_STRING 281
#define TOK_STRUCT 282
#define TOK_VOID 283
#define TOK_BOOL 284
#define TOK_CHAR 285
#define TOK_INT 286
#define TOK_RETURN 287
#define TOK_FALSE 288
#define TOK_TRUE 289
#define TOK_LE 290
#define TOK_GE 291
#define TOK_ELSE 292
#define TOK_IF 293
#define TOK_GT 294
#define TOK_LT 295
#define TOK_NE 296
#define TOK_EQ 297




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

// Authors: bpross@ucsc.edu, esteggal@ucsc.edu
// TA: Richard Halpert
// Professor: Wesley Mackey
// CMPS 104a
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "lyutils.h"
#include "astree.h"
#include "astree.rep.h"


#define YYDEBUG 1
#define YYERROR_VERBOSE 1
#define YYPRINT yyprint
#define YYMALLOC yycalloc

static void *yycalloc (size_t size);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 1
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 213 "yyparse.c"

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
# if YYENABLE_NLS
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   522

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNRULES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,     2,     2,    48,     2,     2,
      53,    54,    46,    44,    58,    45,    52,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    56,
       2,    39,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    55,     2,     2,     2,     2,
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
      35,    36,    37,    38,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    18,    22,    23,
      29,    34,    39,    42,    46,    48,    51,    55,    59,    62,
      64,    66,    68,    70,    72,    74,    76,    80,    83,    85,
      88,    90,    92,    94,    96,    98,   100,   103,   108,   114,
     119,   122,   127,   130,   134,   138,   141,   145,   148,   152,
     156,   160,   164,   168,   172,   176,   180,   184,   186,   188,
     190,   192,   196,   199,   204,   210,   216,   220,   224,   227,
     231,   233,   235,   240,   243,   245,   247,   249,   251,   253,
     255
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,    61,    -1,    61,    62,    -1,    61,    70,
      -1,    61,    63,    -1,    61,     1,    55,    -1,    61,     1,
      56,    -1,    -1,    27,    20,    57,    65,    55,    -1,    66,
      64,    54,    68,    -1,    66,    64,    54,    56,    -1,    53,
      66,    -1,    64,    58,    66,    -1,    53,    -1,    66,    56,
      -1,    65,    66,    56,    -1,    67,    10,    20,    -1,    67,
      20,    -1,    28,    -1,    29,    -1,    30,    -1,    31,    -1,
      26,    -1,     4,    -1,    20,    -1,    57,    69,    55,    -1,
      57,    55,    -1,    56,    -1,    69,    70,    -1,    70,    -1,
      68,    -1,    71,    -1,    72,    -1,    73,    -1,    75,    -1,
      76,    56,    -1,    66,    39,    76,    56,    -1,    19,    53,
      76,    54,    70,    -1,    74,    70,    37,    70,    -1,    74,
      70,    -1,    38,    53,    76,    54,    -1,    32,    56,    -1,
      32,    76,    56,    -1,    76,    44,    76,    -1,    44,    76,
      -1,    76,    45,    76,    -1,    45,    76,    -1,    76,    39,
      76,    -1,    76,    43,    76,    -1,    76,    42,    76,    -1,
      76,    41,    76,    -1,    76,    40,    76,    -1,    76,    35,
      76,    -1,    76,    36,    76,    -1,    76,    52,    76,    -1,
      76,    46,    76,    -1,    77,    -1,    78,    -1,    80,    -1,
      81,    -1,    53,    76,    54,    -1,    49,    76,    -1,    24,
      20,    53,    54,    -1,    24,    26,    53,    76,    54,    -1,
      24,    67,    50,    76,    51,    -1,    20,    79,    54,    -1,
      20,    53,    54,    -1,    53,    76,    -1,    79,    58,    76,
      -1,    53,    -1,    20,    -1,    76,    50,    76,    51,    -1,
      76,    52,    -1,     5,    -1,    22,    -1,    21,    -1,    23,
      -1,    33,    -1,    34,    -1,    25,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    55,    56,    57,    58,    59,    60,    63,
      66,    69,    76,    77,    78,    82,    83,    86,    87,    90,
      91,    92,    93,    94,    95,    96,    99,   100,   101,   104,
     105,   108,   109,   110,   111,   112,   113,   116,   119,   122,
     123,   125,   128,   129,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   153,   154,   155,   158,   159,   162,   163,
     164,   167,   168,   169,   170,   173,   174,   175,   176,   177,
     178
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_ROOT", "TOK_TYPEID", "TOK_FIELD",
  "TOK_INDEX", "TOK_POS", "TOK_NEG", "TOK_CALL", "TOK_NEWARRAY",
  "TOK_NEWSTRING", "TOK_IFELSE", "TOK_RETURNVOID", "TOK_BLOCK",
  "TOK_VARDECLINIT", "TOK_FUNCTION", "TOK_PARAMLIST", "TOK_PROTOTYPE",
  "TOK_WHILE", "TOK_IDENT", "TOK_CHARCON", "TOK_INTCON", "TOK_STRINGCON",
  "TOK_NEW", "TOK_NULL", "TOK_STRING", "TOK_STRUCT", "TOK_VOID",
  "TOK_BOOL", "TOK_CHAR", "TOK_INT", "TOK_RETURN", "TOK_FALSE", "TOK_TRUE",
  "TOK_LE", "TOK_GE", "TOK_ELSE", "TOK_IF", "'='", "TOK_GT", "TOK_LT",
  "TOK_NE", "TOK_EQ", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'['",
  "']'", "'.'", "'('", "')'", "'}'", "';'", "'{'", "','", "$accept",
  "start", "program", "structdef", "function", "paramlist", "identdecls",
  "identdecl", "basetype", "block", "state_list", "statement",
  "vardeclinit", "whilehead", "ifelse", "ifhead", "returnhead", "expr",
  "allocator", "call", "call_list", "variable", "constant", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    61,
     294,   295,   296,   297,    43,    45,    42,    47,    37,    33,
      91,    93,    46,    40,    41,   125,    59,   123,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    61,    61,    61,    61,    61,    62,
      63,    63,    64,    64,    64,    65,    65,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    68,    68,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    71,    72,    73,
      73,    74,    75,    75,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    77,    77,    78,    78,    79,    79,
      79,    80,    80,    80,    80,    81,    81,    81,    81,    81,
      81
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     3,     0,     5,
       4,     4,     2,     3,     1,     2,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     4,     5,     4,
       2,     4,     2,     3,     3,     2,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     3,     2,     4,     5,     5,     3,     3,     2,     3,
       1,     1,     4,     2,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,     0,    24,    74,     0,    71,    76,
      75,    77,     0,    80,    23,     0,    19,    20,    21,    22,
       0,    78,    79,     0,     0,     0,     0,     0,    28,     0,
       3,     5,     0,     0,    31,     4,    32,    33,    34,     0,
      35,     0,    57,    58,    59,    60,     6,     7,     0,    70,
       0,    25,    23,     0,     0,    71,    42,     0,     0,    45,
      47,    62,     0,    27,     0,     0,    30,     0,    14,     0,
       0,    18,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,    36,     0,    67,    68,    66,
       0,     0,     0,     0,     0,    43,     0,    61,    26,    29,
       0,    25,    12,     0,     0,    17,     0,    53,    54,    48,
      52,    51,    50,    49,    44,    46,    56,     0,    55,     0,
      69,    63,     0,     0,     0,     0,    41,    37,    11,    10,
      13,    39,    72,    38,    64,    65,     9,     0,    15,    16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    30,    31,    69,   124,    64,    33,    34,
      65,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      50,    44,    45
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -49
static const yytype_int16 yypact[] =
{
     -49,     5,   104,   -49,   -20,   -49,   -49,   -29,    -8,   -49,
     -49,   -49,    30,   -49,   -49,     8,   -49,   -49,   -49,   -49,
      18,   -49,   -49,    -9,   268,   268,   268,   268,   -49,   146,
     -49,   -49,   -36,    -6,   -49,   -49,   -49,   -49,   -49,   230,
     -49,   300,   -49,   -49,   -49,   -49,   -49,   -49,   268,   268,
     -48,    -7,    -5,    -3,    -4,     4,   -49,   318,   268,   -23,
     -23,   -23,   354,   -49,    10,   188,   -49,   268,   303,   -33,
      45,   -49,    31,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   275,   -49,   374,   -49,   470,   -49,
     268,    15,   268,   268,   303,   -49,   394,   -49,   -49,   -49,
     336,   -49,   -49,   -38,   303,   -49,   230,   -37,   -37,   470,
     -37,   -37,   -37,   -37,   -30,   -30,   -23,   434,   -49,   230,
     470,   -49,   414,   452,    90,    14,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,    16,   -49,   -49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -49,   -49,   -49,   -49,   -49,   -49,   -49,    -2,    63,   -27,
     -49,   -28,   -49,   -49,   -49,   -49,   -49,     6,   -49,   -49,
     -49,   -49,   -49
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -26
static const yytype_int16 yytable[] =
{
      32,    66,   -25,    67,    70,     3,    89,    80,    81,    82,
      90,    72,   -25,    83,    71,    84,    82,    68,   128,    29,
      83,   103,    84,     6,    48,   104,    57,    83,    54,    84,
      59,    60,    61,    62,     5,    46,    47,    99,    55,     9,
      10,    11,    12,    13,    58,    49,    91,    93,    92,    67,
      51,    21,    22,    94,    86,    88,    52,    49,    16,    17,
      18,    19,    24,    25,    96,   105,   102,    26,   106,   121,
     138,    27,   139,   100,    56,    53,   129,     0,   131,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   133,   125,     0,     5,     0,   120,     0,   122,   123,
       0,     0,   130,     0,    -2,     4,     0,     0,     5,     6,
     101,     0,     0,     0,     0,     0,    14,     0,    16,    17,
      18,    19,   137,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     0,
       0,     0,    23,     0,     0,   136,     0,     0,    24,    25,
       5,     6,     0,    26,     0,     0,     0,    27,     0,     0,
      28,    29,     0,     0,     0,     7,     8,     9,    10,    11,
      12,    13,    14,     0,    16,    17,    18,    19,    20,    21,
      22,     0,     0,     0,    23,     0,     0,     0,     0,     0,
      24,    25,     5,     6,     0,    26,     0,     0,     0,    27,
       0,    63,    28,    29,     0,     0,     0,     7,     8,     9,
      10,    11,    12,    13,    14,     0,    16,    17,    18,    19,
      20,    21,    22,     0,     0,     0,    23,     0,     0,     0,
       0,     0,    24,    25,     5,     6,     0,    26,     0,     0,
       0,    27,     0,    98,    28,    29,     0,     0,     0,     7,
       8,     9,    10,    11,    12,    13,    14,     0,    16,    17,
      18,    19,    20,    21,    22,     0,     0,     0,    23,     0,
       0,     0,     0,     6,    24,    25,     0,     0,     0,    26,
       6,     0,     0,    27,     0,     0,    28,    29,    55,     9,
      10,    11,    12,    13,     0,    55,     9,    10,    11,    12,
      13,    21,    22,     0,     0,     0,     0,     5,    21,    22,
       0,     0,    24,    25,     0,     0,     0,    26,     0,     0,
       0,    27,     0,   101,    26,     0,     0,     0,    27,    14,
       0,    16,    17,    18,    19,    73,    74,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    82,     0,     0,     0,
      83,     0,    84,    73,    74,     0,    85,    75,    76,    77,
      78,    79,    80,    81,    82,     0,     0,     0,    83,     0,
      84,    73,    74,     0,    95,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,    83,     0,    84,    73,
      74,     0,   127,    75,    76,    77,    78,    79,    80,    81,
      82,     0,     0,     0,    83,     0,    84,     0,    97,    73,
      74,     0,     0,    75,    76,    77,    78,    79,    80,    81,
      82,     0,     0,     0,    83,     0,    84,     0,   119,    73,
      74,     0,     0,    75,    76,    77,    78,    79,    80,    81,
      82,     0,     0,     0,    83,     0,    84,     0,   126,    73,
      74,     0,     0,    75,    76,    77,    78,    79,    80,    81,
      82,     0,     0,     0,    83,     0,    84,     0,   134,    73,
      74,     0,     0,    75,    76,    77,    78,    79,    80,    81,
      82,     0,     0,     0,    83,   132,    84,    73,    74,     0,
       0,    75,    76,    77,    78,    79,    80,    81,    82,     0,
       0,     0,    83,   135,    84,    73,    74,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    82,     0,     0,     0,
      83,     0,    84
};

static const yytype_int8 yycheck[] =
{
       2,    29,    10,    39,    10,     0,    54,    44,    45,    46,
      58,    39,    20,    50,    20,    52,    46,    53,    56,    57,
      50,    54,    52,     5,    53,    58,    20,    50,    20,    52,
      24,    25,    26,    27,     4,    55,    56,    65,    20,    21,
      22,    23,    24,    25,    53,    53,    53,    50,    53,    39,
      20,    33,    34,    57,    48,    49,    26,    53,    28,    29,
      30,    31,    44,    45,    58,    20,    68,    49,    37,    54,
      56,    53,    56,    67,    56,    12,   103,    -1,   106,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,   119,    94,    -1,     4,    -1,    90,    -1,    92,    93,
      -1,    -1,   104,    -1,     0,     1,    -1,    -1,     4,     5,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    29,
      30,    31,   124,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    38,    -1,    -1,    55,    -1,    -1,    44,    45,
       4,     5,    -1,    49,    -1,    -1,    -1,    53,    -1,    -1,
      56,    57,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      44,    45,     4,     5,    -1,    49,    -1,    -1,    -1,    53,
      -1,    55,    56,    57,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    44,    45,     4,     5,    -1,    49,    -1,    -1,
      -1,    53,    -1,    55,    56,    57,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,     5,    44,    45,    -1,    -1,    -1,    49,
       5,    -1,    -1,    53,    -1,    -1,    56,    57,    20,    21,
      22,    23,    24,    25,    -1,    20,    21,    22,    23,    24,
      25,    33,    34,    -1,    -1,    -1,    -1,     4,    33,    34,
      -1,    -1,    44,    45,    -1,    -1,    -1,    49,    -1,    -1,
      -1,    53,    -1,    20,    49,    -1,    -1,    -1,    53,    26,
      -1,    28,    29,    30,    31,    35,    36,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      50,    -1,    52,    35,    36,    -1,    56,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    50,    -1,
      52,    35,    36,    -1,    56,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    50,    -1,    52,    35,
      36,    -1,    56,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    50,    -1,    52,    -1,    54,    35,
      36,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    50,    -1,    52,    -1,    54,    35,
      36,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    50,    -1,    52,    -1,    54,    35,
      36,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    50,    -1,    52,    -1,    54,    35,
      36,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    50,    51,    52,    35,    36,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    50,    51,    52,    35,    36,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      50,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    60,    61,     0,     1,     4,     5,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    38,    44,    45,    49,    53,    56,    57,
      62,    63,    66,    67,    68,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    80,    81,    55,    56,    53,    53,
      79,    20,    26,    67,    20,    20,    56,    76,    53,    76,
      76,    76,    76,    55,    66,    69,    70,    39,    53,    64,
      10,    20,    70,    35,    36,    39,    40,    41,    42,    43,
      44,    45,    46,    50,    52,    56,    76,    54,    76,    54,
      58,    53,    53,    50,    57,    56,    76,    54,    55,    70,
      76,    20,    66,    54,    58,    20,    37,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    54,
      76,    54,    76,    76,    65,    66,    54,    56,    56,    68,
      66,    70,    51,    70,    54,    51,    55,    66,    56,    56
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
# if YYLTYPE_IS_TRIVIAL
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
        case 2:
#line 52 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 3:
#line 55 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 4:
#line 56 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 5:
#line 57 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 6:
#line 58 "parser.y"
    { (yyval) = adopt1 ((yyval), (yyvsp[(1) - (3)])); ;}
    break;

  case 7:
#line 59 "parser.y"
    { (yyval) = adopt1 ((yyval), (yyvsp[(1) - (3)])); ;}
    break;

  case 8:
#line 60 "parser.y"
    { (yyval) = new_parseroot (); ;}
    break;

  case 9:
#line 63 "parser.y"
    { freeast2((yyvsp[(3) - (5)]),(yyvsp[(5) - (5)])); (yyvsp[(2) - (5)]) = adoptsym((yyvsp[(2) - (5)]),TOK_TYPEID); (yyval) = adopt2((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));;}
    break;

  case 10:
#line 66 "parser.y"
    { astree a = new_function();
                                               a = adopt2((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
                                               (yyval) = a; ;}
    break;

  case 11:
#line 69 "parser.y"
    { astree a = new_prototype();
                                               a = adopt1((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));
                                               freeast((yyvsp[(4) - (4)]));
                                               (yyval) = a; ;}
    break;

  case 12:
#line 76 "parser.y"
    { adopt1sym((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]), TOK_PARAMLIST); ;}
    break;

  case 13:
#line 77 "parser.y"
    { freeast((yyvsp[(2) - (3)])); adopt1((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 14:
#line 78 "parser.y"
    { adoptsym((yyvsp[(1) - (1)]), TOK_PARAMLIST); (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 15:
#line 82 "parser.y"
    { freeast((yyvsp[(2) - (2)])); (yyval) = (yyvsp[(1) - (2)]);  ;}
    break;

  case 16:
#line 83 "parser.y"
    { freeast((yyvsp[(3) - (3)])); (yyval) = adopt1((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])) ; ;}
    break;

  case 17:
#line 86 "parser.y"
    { (yyval) = adopt2((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 18:
#line 87 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 19:
#line 90 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 20:
#line 91 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 21:
#line 92 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 22:
#line 93 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 23:
#line 94 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 24:
#line 95 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 25:
#line 96 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 26:
#line 99 "parser.y"
    {freeast((yyvsp[(3) - (3)])); (yyval) = adopt1sym((yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),TOK_BLOCK); ;}
    break;

  case 27:
#line 100 "parser.y"
    {freeast((yyvsp[(2) - (2)])); (yyval) = adopt1sym((yyval),(yyvsp[(1) - (2)]),TOK_BLOCK); ;}
    break;

  case 28:
#line 101 "parser.y"
    {(yyval) = adoptsym((yyvsp[(1) - (1)]),TOK_BLOCK);;}
    break;

  case 29:
#line 104 "parser.y"
    {(yyval) = adopt1((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 30:
#line 105 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 31:
#line 108 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 32:
#line 109 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 33:
#line 110 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 34:
#line 111 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 35:
#line 112 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 36:
#line 113 "parser.y"
    { freeast((yyvsp[(2) - (2)])); (yyval) = (yyvsp[(1) - (2)]); ;}
    break;

  case 37:
#line 116 "parser.y"
    { freeast((yyvsp[(4) - (4)])); (yyval) = adopt2((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])) ; ;}
    break;

  case 38:
#line 119 "parser.y"
    { freeast2((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); (yyval) = adopt2((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])) ;;}
    break;

  case 39:
#line 122 "parser.y"
    { freeast((yyvsp[(3) - (4)])); (yyval) = adopt2((yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)])); ;}
    break;

  case 40:
#line 123 "parser.y"
    {  (yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); ;}
    break;

  case 41:
#line 125 "parser.y"
    { freeast2((yyvsp[(2) - (4)]),(yyvsp[(4) - (4)])); (yyval) = adopt1((yyvsp[(1) - (4)]),(yyvsp[(3) - (4)])); ;}
    break;

  case 42:
#line 128 "parser.y"
    { (yyval) = adopt1sym((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]), TOK_RETURNVOID) ; ;}
    break;

  case 43:
#line 129 "parser.y"
    { freeast((yyvsp[(3) - (3)]));  (yyval) = adopt1((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])) ; ;}
    break;

  case 44:
#line 132 "parser.y"
    { (yyval) = adopt2((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); ;}
    break;

  case 45:
#line 133 "parser.y"
    { (yyval) = adopt1sym((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), TOK_POS); ;}
    break;

  case 46:
#line 134 "parser.y"
    { (yyval) = adopt2((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); ;}
    break;

  case 47:
#line 135 "parser.y"
    { (yyval) = adopt1sym((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), TOK_NEG); ;}
    break;

  case 48:
#line 136 "parser.y"
    { (yyval) = adopt2((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); ;}
    break;

  case 49:
#line 137 "parser.y"
    { (yyval) = adopt2((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); ;}
    break;

  case 50:
#line 138 "parser.y"
    { (yyval) = adopt2((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); ;}
    break;

  case 51:
#line 139 "parser.y"
    { (yyval) = adopt2((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); ;}
    break;

  case 52:
#line 140 "parser.y"
    { (yyval) = adopt2((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); ;}
    break;

  case 53:
#line 141 "parser.y"
    { (yyval) = adopt2((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); ;}
    break;

  case 54:
#line 142 "parser.y"
    { (yyval) = adopt2((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); ;}
    break;

  case 55:
#line 143 "parser.y"
    { (yyval) = adopt2((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); ;}
    break;

  case 56:
#line 144 "parser.y"
    { (yyval) = adopt2((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); ;}
    break;

  case 57:
#line 145 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ; ;}
    break;

  case 58:
#line 146 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ; ;}
    break;

  case 59:
#line 147 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ; ;}
    break;

  case 60:
#line 148 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ; ;}
    break;

  case 61:
#line 149 "parser.y"
    { freeast2((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 62:
#line 150 "parser.y"
    { (yyval) = adopt1((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)])); ;}
    break;

  case 63:
#line 153 "parser.y"
    { freeast2((yyvsp[(3) - (4)]),(yyvsp[(4) - (4)])); (yyvsp[(2) - (4)]) = adoptsym((yyvsp[(2) - (4)]), TOK_TYPEID); (yyval) = adopt1((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)])) ;;}
    break;

  case 64:
#line 154 "parser.y"
    { freeast2((yyvsp[(3) - (5)]),(yyvsp[(5) - (5)])); (yyval) = adopt1sym((yyvsp[(1) - (5)]),(yyvsp[(4) - (5)]),TOK_NEWSTRING); ;}
    break;

  case 65:
#line 155 "parser.y"
    { freeast2((yyvsp[(3) - (5)]),(yyvsp[(5) - (5)])); (yyval) = adopt2sym((yyvsp[(1) - (5)]),(yyvsp[(2) - (5)]),(yyvsp[(4) - (5)]),TOK_NEWARRAY); ;}
    break;

  case 66:
#line 158 "parser.y"
    { freeast((yyvsp[(3) - (3)])); (yyval) = adopt1sym((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), TOK_CALL); ;}
    break;

  case 67:
#line 159 "parser.y"
    { freeast((yyvsp[(3) - (3)])); (yyval) = adopt1sym((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), TOK_CALL); ;}
    break;

  case 68:
#line 162 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); ;}
    break;

  case 69:
#line 163 "parser.y"
    { freeast((yyvsp[(2) - (3)])); (yyval) = adopt1((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])) ; ;}
    break;

  case 70:
#line 164 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 71:
#line 167 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 72:
#line 168 "parser.y"
    { freeast2((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); (yyval) = adopt1((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])) ; ;}
    break;

  case 73:
#line 169 "parser.y"
    { freeast((yyvsp[(2) - (2)])); (yyval) = (yyvsp[(1) - (2)]); ;}
    break;

  case 74:
#line 170 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 75:
#line 173 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ; ;}
    break;

  case 76:
#line 174 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ; ;}
    break;

  case 77:
#line 175 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ; ;}
    break;

  case 78:
#line 176 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ; ;}
    break;

  case 79:
#line 177 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ; ;}
    break;

  case 80:
#line 178 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2017 "yyparse.c"
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


#line 181 "parser.y"


const char *get_yytname (int symbol) {
    return yytname [YYTRANSLATE (symbol)];
}

static void *yycalloc (size_t size) {
   void *result = calloc (1, size);
   assert (result != NULL);
   return result;
}


