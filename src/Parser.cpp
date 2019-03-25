/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 5 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <iostream>
  #include <fstream>
  #include <list>
  #include <unordered_map>
  #include "expr_lexer.h"
  #include "tokens.h"
  #include "ast.h"

  using namespace std;
  extern int lineNo;
  extern int yylex();
  
  int errors;
  bool state_ment_boolean;
  bool method_dec_boolean;
  
  void yyerror(const char *msg) {
        std::cerr << "Parsing Error: " <<"Line: "<<lineNo<<"-" <<msg<<'\n';
        errors++;
  }

  

#line 92 "../src/Parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "tokens.h".  */
#ifndef YY_YY_SRC_TOKENS_H_INCLUDED
# define YY_YY_SRC_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 2 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:355  */

#include "ast.h"

#line 126 "../src/Parser.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    intConstant = 258,
    CharConstant = 259,
    KwBool = 260,
    KwVoid = 261,
    Id = 262,
    StringConstant = 263,
    KwInt = 264,
    KwBreak = 265,
    KwContinue = 266,
    KwClass = 267,
    KwElse = 268,
    KwExtends = 269,
    KwFor = 270,
    KwIf = 271,
    KwFalse = 272,
    KwTrue = 273,
    KwNew = 274,
    KwNull = 275,
    KwReturn = 276,
    KwRot = 277,
    KwWhile = 278,
    KwPrint = 279,
    KwPrintln = 280,
    KwRead = 281,
    KwRandom = 282,
    OpenBrace = 283,
    CloseBrace = 284,
    OpenBracket = 285,
    CloseBracket = 286,
    Comma = 287,
    Semicolon = 288,
    OpenPar = 289,
    ClosePar = 290,
    Not = 291,
    OpAdd = 292,
    OpSub = 293,
    OpDiv = 294,
    OpMul = 295,
    OpMod = 296,
    Assign = 297,
    OpGreater = 298,
    OpLess = 299,
    OpGreaterEqual = 300,
    OpLessEqual = 301,
    NotEqual = 302,
    OpAnd = 303,
    OpOr = 304,
    OpEqual = 305,
    SLL = 306,
    SLR = 307,
    Eof = 308,
    Error = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:355  */

        Statement * stmt_t;
        Expression * expr_t;
        ASTNode * ast_t;
        char * str_t;
        int int_t;

#line 201 "../src/Parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_TOKENS_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 218 "../src/Parser.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   389

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    91,    91,    92,    95,   103,   106,   114,   119,   120,
     123,   124,   125,   126,   129,   133,   139,   140,   143,   144,
     147,   150,   151,   154,   155,   158,   167,   176,   180,   186,
     189,   190,   193,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   207,   210,   211,   214,   215,   218,   221,   222,
     223,   224,   225,   228,   229,   230,   231,   232,   235,   236,
     239,   240,   243,   244,   248,   249,   250,   251,   252,   253,
     254,   257,   258,   259,   260,   263,   264,   265,   266,   267,
     268,   269,   272,   273,   274,   275,   278,   279,   282,   283,
     286,   287,   288,   289
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "intConstant", "CharConstant", "KwBool",
  "KwVoid", "Id", "StringConstant", "KwInt", "KwBreak", "KwContinue",
  "KwClass", "KwElse", "KwExtends", "KwFor", "KwIf", "KwFalse", "KwTrue",
  "KwNew", "KwNull", "KwReturn", "KwRot", "KwWhile", "KwPrint",
  "KwPrintln", "KwRead", "KwRandom", "\"{\"", "\"}\"", "\"[\"", "\"]\"",
  "\",\"", "\";\"", "\"(\"", "\")\"", "\"!\"", "\"+\"", "\"-\"", "\"/\"",
  "\"*\"", "\"%\"", "\"=\"", "\">\"", "\"<\"", "\">=\"", "\"<=\"",
  "\"!=\"", "\"&&\"", "\"||\"", "\"==\"", "\"<<\"", "\">>\"",
  "\"end of input\"", "Error", "$accept", "program", "program_body",
  "field_decl", "mult-field", "method_decl", "params", "params_p",
  "parametro", "type", "block", "block_p", "var-decl", "var-decl_p", "id",
  "statement", "assign", "else_opt", "for_assign", "return_expr",
  "method-call_stmt", "method-call_expr", "method-call_params", "argument",
  "lvalue", "expr", "bin-op", "arith-op", "rel-op", "eq-op", "cond-op",
  "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

#define YYPACT_NINF -94

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-94)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,    11,    38,    37,   -94,     8,   -94,    48,   -94,   -94,
      16,   -94,   -94,    49,    45,   -94,   -94,   -94,    24,    41,
     -94,    23,    66,    23,     6,    64,   -94,    69,    73,   -94,
      99,    79,    77,   -94,   -94,   -94,   -94,    80,    84,   -94,
      88,    23,   -94,   -94,    88,   -94,   117,   141,   -94,   -94,
     -94,    92,   -19,    91,    94,    98,   100,   104,   101,   102,
     103,   107,   109,   -94,   118,   -94,   166,   -94,   -94,   111,
     112,   113,   -94,   104,   104,   -94,   -94,   126,   104,    27,
     115,   119,   125,   127,   104,   104,   104,   130,   -94,   -94,
     291,   -94,   -94,   -94,   -94,   -94,   -94,   104,    26,    26,
     137,   104,   -94,    50,   -94,   -94,   -94,   -94,   -94,   -94,
     104,   165,   -27,   291,   144,   -94,    53,   203,   104,    26,
      26,   143,   104,   221,   291,   319,   -94,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   239,   -94,   145,   291,   148,   -94,   257,   118,
     -94,   291,   -94,   104,   -94,   126,   104,    88,     7,   149,
     150,   -94,   275,   -94,   319,   319,   307,   307,   329,    28,
      28,    28,    28,    39,   139,   -94,    39,   339,   339,    88,
     -94,   -94,   -94,   -94,   291,   -94,   185,   147,   -94,   -94,
     -94,   -94,   -94,   126,    88,   -94,    35,   -94,    88,   -94
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    22,     0,    21,     3,
       0,     6,     7,     0,     0,     2,     4,     5,    32,     0,
      12,    17,     0,    17,     0,     0,     8,     0,    16,    19,
       0,     0,     0,    90,    91,    93,    92,     0,    32,    10,
       0,     0,    20,    13,     0,     9,     0,     0,    15,    18,
      14,     0,    62,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,    41,     0,    26,    28,     0,
       0,     0,    11,     0,     0,    37,    40,     0,     0,    62,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    64,
      47,    67,    71,    72,    74,    73,    66,     0,     0,     0,
       0,     0,    32,     0,    31,    23,    25,    27,    33,    34,
       0,     0,     0,    59,    62,    46,     0,     0,     0,     0,
       0,     0,     0,     0,    68,    69,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    60,     0,    61,     0,    51,     0,     0,
      29,    42,    63,     0,    48,     0,     0,     0,     0,     0,
       0,    56,     0,    70,    75,    76,    78,    77,    81,    83,
      82,    85,    84,    87,    88,    89,    86,    79,    80,     0,
      49,    50,    52,    30,    58,    45,     0,    44,    53,    54,
      55,    57,    36,     0,     0,    35,     0,    43,     0,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -94,   -94,   -94,   169,   -94,   176,   174,   -94,   157,     2,
     -40,   -94,   133,   -94,   -23,   134,   -74,   -94,    14,   -94,
     -94,   -94,    83,   -93,   -46,   -38,   -94,   -94,   -94,   -94,
     -94,   195
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,    11,    19,    12,    27,    28,    29,    30,
      65,    66,    67,   103,    20,    68,    69,   195,   116,    87,
      70,    88,   112,   144,    89,   145,    91,    92,    93,    94,
      95,    96
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      48,    71,    39,   115,    50,   153,   146,    13,   154,    33,
      34,    73,    13,     6,     7,    74,     1,     8,     3,    90,
      71,     6,     7,    35,    36,     8,   159,   160,     6,    33,
      34,    71,     8,    79,   143,   111,   113,     9,     4,   153,
     117,   104,   188,    35,    36,    15,   123,   124,   125,    64,
      80,    81,    82,    83,    22,    14,    18,    73,    23,   142,
      84,   118,    85,   148,    86,     5,    24,   155,    64,    31,
     198,    38,   151,    25,    26,   136,   137,   138,   139,    21,
     113,   185,   149,   150,   162,   155,   156,   137,   138,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,    40,    41,    42,    33,    34,    71,
      43,    79,    44,    45,    46,   184,    47,   187,   186,   115,
      51,    35,    36,    72,    75,   102,   183,    76,    80,    81,
      82,    83,    77,   114,    78,    97,    98,    99,    84,   192,
      85,   100,    86,   101,   108,   109,     6,    71,    52,   119,
       8,    53,    54,   120,   197,   110,    55,    56,   199,   121,
     194,   122,    57,   126,    58,    59,    60,    61,    62,    47,
      63,     6,   147,    52,    73,     8,    53,    54,   161,    16,
     180,    55,    56,   181,   189,   190,    17,    57,   138,    58,
      59,    60,    61,    62,    47,   105,   152,    32,    49,   106,
     107,   158,   127,   128,   129,   130,   131,   196,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   193,    37,
       0,     0,   127,   128,   129,   130,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   157,     0,
     127,   128,   129,   130,   131,     0,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   163,     0,   127,   128,
     129,   130,   131,     0,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   179,     0,   127,   128,   129,   130,
     131,     0,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   182,     0,   127,   128,   129,   130,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     191,     0,   127,   128,   129,   130,   131,     0,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   127,   128,
     129,   130,   131,     0,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   127,   128,     0,     0,   131,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     131,     0,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   132,   133,   134,   135,   136,   137,   138,   139
};

static const yytype_int16 yycheck[] =
{
      40,    47,    25,    77,    44,    32,    99,     5,    35,     3,
       4,    30,    10,     5,     6,    34,    12,     9,     7,    57,
      66,     5,     6,    17,    18,     9,   119,   120,     5,     3,
       4,    77,     9,     7,     8,    73,    74,    29,     0,    32,
      78,    64,    35,    17,    18,    29,    84,    85,    86,    47,
      24,    25,    26,    27,    30,     7,     7,    30,    34,    97,
      34,    34,    36,   101,    38,    28,    42,    32,    66,     3,
      35,     7,   110,    32,    33,    47,    48,    49,    50,    34,
     118,   155,    32,    33,   122,    32,    33,    48,    49,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    35,    32,     7,     3,     4,   155,
      31,     7,    35,    33,    30,   153,    28,   157,   156,   193,
       3,    17,    18,    31,    33,     7,   149,    33,    24,    25,
      26,    27,    34,     7,    34,    34,    34,    34,    34,   179,
      36,    34,    38,    34,    33,    33,     5,   193,     7,    34,
       9,    10,    11,    34,   194,    42,    15,    16,   198,    34,
      13,    34,    21,    33,    23,    24,    25,    26,    27,    28,
      29,     5,    35,     7,    30,     9,    10,    11,    35,    10,
      35,    15,    16,    35,    35,    35,    10,    21,    49,    23,
      24,    25,    26,    27,    28,    29,    31,    23,    41,    66,
      66,   118,    37,    38,    39,    40,    41,   193,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    33,    24,
      -1,    -1,    37,    38,    39,    40,    41,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    35,    -1,
      37,    38,    39,    40,    41,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    35,    -1,    37,    38,
      39,    40,    41,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    35,    -1,    37,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    35,    -1,    37,    38,    39,    40,    41,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      35,    -1,    37,    38,    39,    40,    41,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    37,    38,
      39,    40,    41,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    37,    38,    -1,    -1,    41,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    43,    44,    45,    46,    47,    48,    49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    56,     7,     0,    28,     5,     6,     9,    29,
      57,    58,    60,    64,     7,    29,    58,    60,     7,    59,
      69,    34,    30,    34,    42,    32,    33,    61,    62,    63,
      64,     3,    61,     3,     4,    17,    18,    86,     7,    69,
      35,    32,     7,    31,    35,    33,    30,    28,    65,    63,
      65,     3,     7,    10,    11,    15,    16,    21,    23,    24,
      25,    26,    27,    29,    64,    65,    66,    67,    70,    71,
      75,    79,    31,    30,    34,    33,    33,    34,    34,     7,
      24,    25,    26,    27,    34,    36,    38,    74,    76,    79,
      80,    81,    82,    83,    84,    85,    86,    34,    34,    34,
      34,    34,     7,    68,    69,    29,    67,    70,    33,    33,
      42,    80,    77,    80,     7,    71,    73,    80,    34,    34,
      34,    34,    34,    80,    80,    80,    33,    37,    38,    39,
      40,    41,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    80,     8,    78,    80,    78,    35,    80,    32,
      33,    80,    31,    32,    35,    32,    33,    35,    77,    78,
      78,    35,    80,    35,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    35,
      35,    35,    35,    69,    80,    71,    80,    65,    35,    35,
      35,    35,    65,    33,    13,    72,    73,    65,    35,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    57,    57,    57,    57,    58,    58,
      59,    59,    59,    59,    60,    60,    61,    61,    62,    62,
      63,    64,    64,    65,    65,    66,    66,    66,    66,    67,
      68,    68,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    72,    72,    73,    73,    74,    75,    75,
      75,    75,    75,    76,    76,    76,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    80,    80,    80,    80,
      80,    81,    81,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    83,    83,    83,    83,    84,    84,    85,    85,
      86,    86,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     2,     2,     1,     1,     3,     5,
       3,     6,     1,     4,     6,     6,     1,     0,     3,     1,
       2,     1,     1,     3,     2,     2,     1,     2,     1,     3,
       3,     1,     1,     2,     2,     6,     5,     2,     9,     3,
       2,     1,     3,     2,     0,     3,     1,     1,     4,     4,
       4,     3,     4,     4,     4,     4,     3,     4,     3,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     2,     2,
       3,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 91 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = new BlockStmt((yyvsp[-1].ast_t));}
#line 1472 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 92 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t)=nullptr;}
#line 1478 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 95 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                if(method_dec_boolean)
                {
                        yyerror("Can't declare fields after methods!");
                        exit(0);
                }
                addToNodeList((yyvsp[-1].ast_t),(yyvsp[0].ast_t));(yyval.ast_t)=(yyvsp[-1].ast_t);
        }
#line 1491 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 103 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                addToNodeList((yyvsp[-1].ast_t),(yyvsp[0].ast_t));(yyval.ast_t)=(yyvsp[-1].ast_t);
        }
#line 1499 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 106 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                if(method_dec_boolean)
                {
                        yyerror("Can't declare fields after methods!");
                        exit(0);
                }
                (yyval.ast_t) = nullptr; addToNodeList((yyval.ast_t),(yyvsp[0].ast_t));
        }
#line 1512 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 114 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                (yyval.ast_t) = nullptr; addToNodeList((yyval.ast_t),(yyvsp[0].ast_t));
        }
#line 1520 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 119 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = new FieldDecStmt_2((yyvsp[-2].str_t),(yyvsp[-1].ast_t));}
#line 1526 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 120 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = new FieldDecStmt((yyvsp[-4].str_t),(yyvsp[-3].str_t),(yyvsp[-1].expr_t));}
#line 1532 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 123 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {addToNodeList((yyvsp[-2].ast_t),(yyvsp[0].ast_t));(yyval.ast_t)=(yyvsp[-2].ast_t);}
#line 1538 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 124 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {addToNodeList((yyvsp[-5].ast_t),new ArrayDec((yyvsp[-3].str_t),(yyvsp[-1].int_t)));(yyval.ast_t)=(yyvsp[-5].ast_t);}
#line 1544 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 125 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = nullptr; addToNodeList((yyval.ast_t),(yyvsp[0].ast_t));}
#line 1550 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 126 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = nullptr; addToNodeList((yyval.ast_t),new ArrayDec((yyvsp[-3].str_t),(yyvsp[-1].int_t)));}
#line 1556 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 129 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                                                        (yyval.ast_t) = new FnDec((yyvsp[-5].str_t),(yyvsp[-4].str_t),(yyvsp[-2].ast_t),(yyvsp[0].stmt_t));
                                                        method_dec_boolean = true;
                                                }
#line 1565 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 133 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                                                        (yyval.ast_t) = new FnDec((yyvsp[-5].str_t),(yyvsp[-4].str_t),(yyvsp[-2].ast_t),(yyvsp[0].stmt_t));
                                                        method_dec_boolean = true;
                                                }
#line 1574 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 139 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t)=(yyvsp[0].ast_t);}
#line 1580 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 140 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t)=nullptr;}
#line 1586 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 143 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {addToNodeList((yyvsp[-2].ast_t),(yyvsp[0].ast_t));(yyval.ast_t)=(yyvsp[-2].ast_t);}
#line 1592 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 144 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = nullptr; addToNodeList((yyval.ast_t),(yyvsp[0].ast_t));}
#line 1598 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 147 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t)=new FnParamsDec((yyvsp[-1].str_t),(yyvsp[0].str_t));}
#line 1604 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 150 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.str_t) = (yyvsp[0].str_t);}
#line 1610 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 151 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.str_t) = (yyvsp[0].str_t);}
#line 1616 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 154 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = new BlockStmt((yyvsp[-1].ast_t));}
#line 1622 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 155 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = nullptr;}
#line 1628 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 158 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                if(state_ment_boolean)
                {
                        yyerror("Can't declare variables after statements!");
                        exit(0);
                }
                addToNodeList((yyvsp[-1].ast_t),(yyvsp[0].stmt_t));
                (yyval.ast_t)=(yyvsp[-1].ast_t);
        }
#line 1642 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 167 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                if(state_ment_boolean)
                {
                        yyerror("Can't declare variables after statements!");
                        exit(0);
                }
                (yyval.ast_t) = nullptr; 
                addToNodeList((yyval.ast_t),(yyvsp[0].stmt_t));                                                
        }
#line 1656 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 176 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                addToNodeList((yyvsp[-1].ast_t),(yyvsp[0].stmt_t));
                (yyval.ast_t)=(yyvsp[-1].ast_t);
        }
#line 1665 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 180 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                (yyval.ast_t) = nullptr; 
                addToNodeList((yyval.ast_t),(yyvsp[0].stmt_t));  
        }
#line 1674 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 186 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = new VarDecStmt((yyvsp[-2].str_t),(yyvsp[-1].ast_t));}
#line 1680 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 189 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {addToNodeList((yyvsp[-2].ast_t),(yyvsp[0].ast_t));(yyval.ast_t)=(yyvsp[-2].ast_t);}
#line 1686 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 190 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = nullptr; addToNodeList((yyval.ast_t),(yyvsp[0].ast_t));}
#line 1692 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 193 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = new stringNode((yyvsp[0].str_t));}
#line 1698 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 196 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {state_ment_boolean = true;(yyval.stmt_t) = (yyvsp[-1].stmt_t);}
#line 1704 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 197 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {state_ment_boolean = true;(yyval.stmt_t) = (yyvsp[-1].stmt_t);}
#line 1710 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 198 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {state_ment_boolean = true;(yyval.stmt_t) = new IfStmt((yyvsp[-3].expr_t),(yyvsp[-1].stmt_t),(yyvsp[0].stmt_t));}
#line 1716 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 199 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {state_ment_boolean = true;(yyval.stmt_t) = new WhileStmt((yyvsp[-2].expr_t),(yyvsp[0].stmt_t));}
#line 1722 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 200 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {state_ment_boolean = true;(yyval.stmt_t) = new BreakStmt();}
#line 1728 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 201 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {state_ment_boolean = true;(yyval.stmt_t) = new ForStmt((yyvsp[-6].ast_t),(yyvsp[-4].expr_t),(yyvsp[-2].ast_t),(yyvsp[0].stmt_t));}
#line 1734 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 202 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {state_ment_boolean = true;(yyval.stmt_t) = new ReturnStmt((yyvsp[-1].expr_t));}
#line 1740 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 203 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {state_ment_boolean = true;(yyval.stmt_t) = new ContinueStmt();}
#line 1746 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 204 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {state_ment_boolean = true;(yyval.stmt_t) = (yyvsp[0].stmt_t);}
#line 1752 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 207 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = new AssignStmt((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1758 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 210 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = (yyvsp[0].stmt_t);}
#line 1764 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 211 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = nullptr;}
#line 1770 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 214 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {addToNodeList((yyvsp[-2].ast_t),(yyvsp[0].stmt_t));(yyval.ast_t)=(yyvsp[-2].ast_t);}
#line 1776 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 215 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = nullptr; addToNodeList((yyval.ast_t),(yyvsp[0].stmt_t));}
#line 1782 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 218 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1788 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 221 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = new FunctionCallStmt((yyvsp[-3].str_t),(yyvsp[-1].ast_t));}
#line 1794 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 222 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = new PrintStmt((yyvsp[-1].expr_t));}
#line 1800 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 223 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = new PrintlnStmt((yyvsp[-1].expr_t));}
#line 1806 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 224 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = new ReadStmt();}
#line 1812 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 225 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = new NextIntStmt((yyvsp[-1].expr_t));}
#line 1818 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 228 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new FunctionCallExpr((yyvsp[-3].str_t),(yyvsp[-1].ast_t));}
#line 1824 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 229 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new PrintExpr((yyvsp[-1].expr_t));}
#line 1830 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 230 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new PrintExpr((yyvsp[-1].expr_t));}
#line 1836 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 231 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new ReadExpr();}
#line 1842 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 232 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new NextIntExpr((yyvsp[-1].expr_t));}
#line 1848 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 235 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {addToNodeList((yyvsp[-2].ast_t),(yyvsp[0].expr_t));(yyval.ast_t)=(yyvsp[-2].ast_t);}
#line 1854 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 236 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = nullptr; addToNodeList((yyval.ast_t),(yyvsp[0].expr_t));}
#line 1860 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 239 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new StringConstantExpr((yyvsp[0].str_t));}
#line 1866 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 240 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1872 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 243 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new IdExpr((yyvsp[0].str_t));}
#line 1878 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 244 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new IdArrayExpr((yyvsp[-3].str_t),(yyvsp[-1].expr_t));}
#line 1884 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 248 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1890 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 249 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1896 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 250 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1902 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 251 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1908 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 252 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1914 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 253 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1920 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 254 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[-1].expr_t);}
#line 1926 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 257 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1932 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 258 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1938 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 259 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1944 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 260 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1950 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 263 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new AddExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1956 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 264 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new SubExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1962 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 265 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new MulExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1968 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 266 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new DivExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1974 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 267 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new SRLExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1980 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 268 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new SLLExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1986 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 269 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new ModExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1992 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 272 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new LesExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1998 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 273 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new GreExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 2004 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 274 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new LeEExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 2010 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 275 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new GrEExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 2016 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 278 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new EquExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 2022 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 279 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new NEqExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 2028 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 282 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new AndExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 2034 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 283 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new Or_Expr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 2040 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 286 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new NumExpr((yyvsp[0].int_t));}
#line 2046 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 287 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new CharExpr((yyvsp[0].int_t));}
#line 2052 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 288 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new BoolExpr(1);}
#line 2058 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 289 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new BoolExpr(0);}
#line 2064 "../src/Parser.cpp" /* yacc.c:1646  */
    break;


#line 2068 "../src/Parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 291 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1906  */

