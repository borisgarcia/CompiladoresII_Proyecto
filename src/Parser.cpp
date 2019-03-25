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
  ASTNode * input;
  bool state_ment_boolean;
  bool method_dec_boolean;
  
  void yyerror(const char *msg) 
  {
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
#define YYLAST   382

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  201

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
       0,    90,    90,    91,    94,    98,   101,   104,   109,   110,
     113,   114,   115,   116,   119,   122,   127,   128,   131,   132,
     135,   138,   139,   142,   143,   146,   150,   154,   158,   164,
     167,   168,   171,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   185,   188,   189,   192,   193,   196,   199,   200,
     201,   202,   203,   206,   207,   208,   209,   210,   212,   213,
     215,   216,   219,   220,   223,   224,   228,   229,   230,   231,
     232,   233,   234,   237,   238,   239,   240,   243,   244,   245,
     246,   247,   248,   249,   252,   253,   254,   255,   258,   259,
     262,   263,   266,   267,   268,   269
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
  "method-call_stmt", "method-call_expr", "method-call_params",
  "method-call_params_p", "argument", "lvalue", "expr", "bin-op",
  "arith-op", "rel-op", "eq-op", "cond-op", "constant", YY_NULLPTR
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

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -6,     1,    18,   -12,   -95,     8,   -95,    31,   -95,   -95,
      16,   -95,   -95,    48,    22,   -95,   -95,   -95,    24,    51,
     -95,    23,    62,    23,     6,    64,   -95,    34,    75,   -95,
     106,    84,    82,   -95,   -95,   -95,   -95,    88,    96,   -95,
     100,    23,   -95,   -95,   100,   -95,   132,   142,   -95,   -95,
     -95,   107,   -19,   103,   104,   108,   110,   105,   111,   112,
     116,   120,   122,   -95,   153,   -95,   167,   -95,   -95,   128,
     129,   131,   -95,   105,   105,   -95,   -95,   157,   105,    27,
     141,   145,   146,   147,   105,   105,   105,   151,   -95,   -95,
     292,   -95,   -95,   -95,   -95,   -95,   -95,   105,    26,    26,
     150,   105,   -95,    73,   -95,   -95,   -95,   -95,   -95,   -95,
     105,   166,     7,   -95,   292,   156,   -95,    92,   204,   105,
      26,    26,   152,   105,   222,   292,   320,   -95,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   240,   -95,   154,   292,   163,   -95,   258,
     153,   -95,   292,   -95,   105,   -95,   157,   105,   100,    35,
     164,   165,   -95,   276,   -95,   320,   320,   308,   308,   330,
      39,    39,    39,    39,    85,   159,   -95,    85,    30,    30,
     100,   -95,   -95,   -95,   -95,   292,   -95,   186,   188,   -95,
     -95,   -95,   -95,   -95,   157,   100,   -95,    79,   -95,   100,
     -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    22,     0,    21,     3,
       0,     6,     7,     0,     0,     2,     4,     5,    32,     0,
      11,    17,     0,    17,     0,     0,     8,     0,    16,    19,
       0,     0,     0,    92,    93,    95,    94,     0,    32,    10,
       0,     0,    20,    13,     0,     9,     0,     0,    15,    18,
      14,     0,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,    41,     0,    26,    28,     0,
       0,     0,    12,     0,    59,    37,    40,     0,     0,    64,
       0,     0,     0,     0,     0,     0,     0,     0,    67,    66,
      47,    69,    73,    74,    76,    75,    68,     0,     0,     0,
       0,     0,    32,     0,    31,    23,    25,    27,    33,    34,
       0,     0,     0,    58,    61,    64,    46,     0,     0,    59,
       0,     0,     0,     0,     0,    70,    71,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,     0,    63,     0,    51,     0,
       0,    29,    42,    65,     0,    48,     0,     0,     0,     0,
       0,     0,    56,     0,    72,    77,    78,    80,    79,    83,
      85,    84,    87,    86,    89,    90,    91,    88,    81,    82,
       0,    49,    50,    52,    30,    60,    45,     0,    44,    53,
      54,    55,    57,    36,     0,     0,    35,     0,    43,     0,
      38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -95,   192,   -95,   210,   198,   -95,   181,     2,
     -40,   -95,   162,   -95,   -23,   174,   -74,   -95,    52,   -95,
     -95,   -95,   139,   -95,   -94,   -46,   -38,   -95,   -95,   -95,
     -95,   -95,   252
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,    11,    19,    12,    27,    28,    29,    30,
      65,    66,    67,   103,    20,    68,    69,   196,   117,    87,
      70,    88,   112,   113,   145,    89,   146,    91,    92,    93,
      94,    95,    96
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      48,    71,    39,   116,    50,   147,     1,    13,     3,    33,
      34,    73,    13,     6,     7,    74,     5,     8,     4,    90,
      71,     6,     7,    35,    36,     8,   160,   161,     6,    33,
      34,    71,     8,    79,   144,   111,   114,     9,    14,   154,
     118,   104,   155,    35,    36,    15,   124,   125,   126,    64,
      80,    81,    82,    83,    22,    18,    21,    73,    23,   143,
      84,   119,    85,   149,    86,    31,    24,   154,    64,    40,
     189,    38,   152,   133,   134,   135,   136,   137,   138,   139,
     140,   114,   186,    25,    26,   163,   137,   138,   139,   140,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   150,   151,    41,    33,    34,
      71,   156,    79,    42,   199,    43,   185,    44,   188,   187,
     116,    45,    35,    36,   156,   157,    46,   184,    47,    80,
      81,    82,    83,   138,   139,    51,    75,    76,    72,    84,
     193,    85,    77,    86,    78,    97,    98,     6,    71,    52,
      99,     8,    53,    54,   100,   198,   101,    55,    56,   200,
     102,   108,   109,    57,   115,    58,    59,    60,    61,    62,
      47,    63,     6,   110,    52,   120,     8,    53,    54,   121,
     122,   123,    55,    56,   127,   148,    73,   162,    57,   181,
      58,    59,    60,    61,    62,    47,   105,   153,   182,   190,
     191,   195,    16,   128,   129,   130,   131,   132,   139,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   194,
      17,    32,    49,   128,   129,   130,   131,   132,   106,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   158,
     107,   128,   129,   130,   131,   132,   197,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   164,   159,   128,
     129,   130,   131,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   180,    37,   128,   129,   130,
     131,   132,     0,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   183,     0,   128,   129,   130,   131,   132,
       0,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   192,     0,   128,   129,   130,   131,   132,     0,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   128,
     129,   130,   131,   132,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   128,   129,     0,     0,   132,
       0,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   132,     0,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142
};

static const yytype_int16 yycheck[] =
{
      40,    47,    25,    77,    44,    99,    12,     5,     7,     3,
       4,    30,    10,     5,     6,    34,    28,     9,     0,    57,
      66,     5,     6,    17,    18,     9,   120,   121,     5,     3,
       4,    77,     9,     7,     8,    73,    74,    29,     7,    32,
      78,    64,    35,    17,    18,    29,    84,    85,    86,    47,
      24,    25,    26,    27,    30,     7,    34,    30,    34,    97,
      34,    34,    36,   101,    38,     3,    42,    32,    66,    35,
      35,     7,   110,    43,    44,    45,    46,    47,    48,    49,
      50,   119,   156,    32,    33,   123,    47,    48,    49,    50,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,    32,    33,    32,     3,     4,
     156,    32,     7,     7,    35,    31,   154,    35,   158,   157,
     194,    33,    17,    18,    32,    33,    30,   150,    28,    24,
      25,    26,    27,    48,    49,     3,    33,    33,    31,    34,
     180,    36,    34,    38,    34,    34,    34,     5,   194,     7,
      34,     9,    10,    11,    34,   195,    34,    15,    16,   199,
       7,    33,    33,    21,     7,    23,    24,    25,    26,    27,
      28,    29,     5,    42,     7,    34,     9,    10,    11,    34,
      34,    34,    15,    16,    33,    35,    30,    35,    21,    35,
      23,    24,    25,    26,    27,    28,    29,    31,    35,    35,
      35,    13,    10,    37,    38,    39,    40,    41,    49,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    33,
      10,    23,    41,    37,    38,    39,    40,    41,    66,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    35,
      66,    37,    38,    39,    40,    41,   194,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    35,   119,    37,
      38,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    35,    24,    37,    38,    39,
      40,    41,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    35,    -1,    37,    38,    39,    40,    41,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    35,    -1,    37,    38,    39,    40,    41,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    37,
      38,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    37,    38,    -1,    -1,    41,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    41,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    56,     7,     0,    28,     5,     6,     9,    29,
      57,    58,    60,    64,     7,    29,    58,    60,     7,    59,
      69,    34,    30,    34,    42,    32,    33,    61,    62,    63,
      64,     3,    61,     3,     4,    17,    18,    87,     7,    69,
      35,    32,     7,    31,    35,    33,    30,    28,    65,    63,
      65,     3,     7,    10,    11,    15,    16,    21,    23,    24,
      25,    26,    27,    29,    64,    65,    66,    67,    70,    71,
      75,    80,    31,    30,    34,    33,    33,    34,    34,     7,
      24,    25,    26,    27,    34,    36,    38,    74,    76,    80,
      81,    82,    83,    84,    85,    86,    87,    34,    34,    34,
      34,    34,     7,    68,    69,    29,    67,    70,    33,    33,
      42,    81,    77,    78,    81,     7,    71,    73,    81,    34,
      34,    34,    34,    34,    81,    81,    81,    33,    37,    38,
      39,    40,    41,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    81,     8,    79,    81,    79,    35,    81,
      32,    33,    81,    31,    32,    35,    32,    33,    35,    77,
      79,    79,    35,    81,    35,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      35,    35,    35,    35,    69,    81,    71,    81,    65,    35,
      35,    35,    35,    65,    33,    13,    72,    73,    65,    35,
      65
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
      78,    78,    79,    79,    80,    80,    81,    81,    81,    81,
      81,    81,    81,    82,    82,    82,    82,    83,    83,    83,
      83,    83,    83,    83,    84,    84,    84,    84,    85,    85,
      86,    86,    87,    87,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     2,     2,     1,     1,     3,     5,
       3,     1,     6,     4,     6,     6,     1,     0,     3,     1,
       2,     1,     1,     3,     2,     2,     1,     2,     1,     3,
       3,     1,     1,     2,     2,     6,     5,     2,     9,     3,
       2,     1,     3,     2,     0,     3,     1,     1,     4,     4,
       4,     3,     4,     4,     4,     4,     3,     4,     1,     0,
       3,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       2,     2,     3,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1
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
#line 90 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {input = new Program((yyvsp[-1].ast_t));}
#line 1475 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 91 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {input=nullptr;}
#line 1481 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 95 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                addToNodeList((yyvsp[-1].ast_t),(yyvsp[0].ast_t));(yyval.ast_t)=(yyvsp[-1].ast_t);
        }
#line 1489 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 98 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                addToNodeList((yyvsp[-1].ast_t),(yyvsp[0].ast_t));(yyval.ast_t)=(yyvsp[-1].ast_t);
        }
#line 1497 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 101 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                (yyval.ast_t) = nullptr; addToNodeList((yyval.ast_t),(yyvsp[0].ast_t));
        }
#line 1505 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 104 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                (yyval.ast_t) = nullptr; addToNodeList((yyval.ast_t),(yyvsp[0].ast_t));
        }
#line 1513 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 109 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = new FieldDecStmt_2((yyvsp[-2].str_t),(yyvsp[-1].ast_t));}
#line 1519 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 110 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = new FieldDecStmt((yyvsp[-4].str_t),(yyvsp[-3].str_t),(yyvsp[-1].expr_t));}
#line 1525 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 113 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {addToNodeList((yyvsp[-2].ast_t),(yyvsp[0].ast_t));(yyval.ast_t)=(yyvsp[-2].ast_t);}
#line 1531 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 114 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = nullptr; addToNodeList((yyval.ast_t),(yyvsp[0].ast_t));}
#line 1537 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 115 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {addToNodeList((yyvsp[-5].ast_t),new ArrayDec((yyvsp[-3].str_t),(yyvsp[-1].int_t)));(yyval.ast_t)=(yyvsp[-5].ast_t);}
#line 1543 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 116 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = nullptr; addToNodeList((yyval.ast_t),new ArrayDec((yyvsp[-3].str_t),(yyvsp[-1].int_t)));}
#line 1549 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 119 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                                                        (yyval.ast_t) = new FnDec((yyvsp[-5].str_t),(yyvsp[-4].str_t),(yyvsp[-2].ast_t),(yyvsp[0].stmt_t));
                                                }
#line 1557 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 122 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                                                        (yyval.ast_t) = new FnDec((yyvsp[-5].str_t),(yyvsp[-4].str_t),(yyvsp[-2].ast_t),(yyvsp[0].stmt_t));
                                                }
#line 1565 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 127 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t)=(yyvsp[0].ast_t);}
#line 1571 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 128 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t)=nullptr;}
#line 1577 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 131 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {addToNodeList((yyvsp[-2].ast_t),(yyvsp[0].ast_t));(yyval.ast_t)=(yyvsp[-2].ast_t);}
#line 1583 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 132 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = nullptr; addToNodeList((yyval.ast_t),(yyvsp[0].ast_t));}
#line 1589 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 135 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    { (yyval.ast_t)= new FnParamsDec((yyvsp[-1].str_t),(yyvsp[0].str_t));}
#line 1595 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 138 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.str_t) = (yyvsp[0].str_t);}
#line 1601 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 139 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.str_t) = (yyvsp[0].str_t);}
#line 1607 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 142 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = new BlockStmt((yyvsp[-1].ast_t));}
#line 1613 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 143 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = nullptr;}
#line 1619 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 146 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                addToNodeList((yyvsp[-1].ast_t),(yyvsp[0].stmt_t));
                (yyval.ast_t)=(yyvsp[-1].ast_t);
        }
#line 1628 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 150 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                (yyval.ast_t) = nullptr; 
                addToNodeList((yyval.ast_t),(yyvsp[0].stmt_t));                                                
        }
#line 1637 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 154 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                addToNodeList((yyvsp[-1].ast_t),(yyvsp[0].stmt_t));
                (yyval.ast_t)=(yyvsp[-1].ast_t);
        }
#line 1646 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 158 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {
                (yyval.ast_t) = nullptr; 
                addToNodeList((yyval.ast_t),(yyvsp[0].stmt_t));  
        }
#line 1655 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 164 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = new VarDecStmt((yyvsp[-2].str_t),(yyvsp[-1].ast_t));}
#line 1661 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 167 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {addToNodeList((yyvsp[-2].ast_t),(yyvsp[0].ast_t));(yyval.ast_t)=(yyvsp[-2].ast_t);}
#line 1667 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 168 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = nullptr; addToNodeList((yyval.ast_t),(yyvsp[0].ast_t));}
#line 1673 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 171 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = new stringNode((yyvsp[0].str_t));}
#line 1679 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 174 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {state_ment_boolean = true;(yyval.stmt_t) = (yyvsp[-1].stmt_t);}
#line 1685 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 175 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {state_ment_boolean = true;(yyval.stmt_t) = (yyvsp[-1].stmt_t);}
#line 1691 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 176 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {state_ment_boolean = true;(yyval.stmt_t) = new IfStmt((yyvsp[-3].expr_t),(yyvsp[-1].stmt_t),(yyvsp[0].stmt_t));}
#line 1697 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 177 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {state_ment_boolean = true;(yyval.stmt_t) = new WhileStmt((yyvsp[-2].expr_t),(yyvsp[0].stmt_t));}
#line 1703 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 178 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {state_ment_boolean = true;(yyval.stmt_t) = new BreakStmt();}
#line 1709 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 179 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {state_ment_boolean = true;(yyval.stmt_t) = new ForStmt((yyvsp[-6].ast_t),(yyvsp[-4].expr_t),(yyvsp[-2].ast_t),(yyvsp[0].stmt_t));}
#line 1715 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 180 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {state_ment_boolean = true;(yyval.stmt_t) = new ReturnStmt((yyvsp[-1].expr_t));}
#line 1721 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 181 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {state_ment_boolean = true;(yyval.stmt_t) = new ContinueStmt();}
#line 1727 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 182 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {state_ment_boolean = true;(yyval.stmt_t) = (yyvsp[0].stmt_t);}
#line 1733 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 185 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = new AssignStmt((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1739 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 188 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = (yyvsp[0].stmt_t);}
#line 1745 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 189 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = nullptr;}
#line 1751 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 192 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {addToNodeList((yyvsp[-2].ast_t),(yyvsp[0].stmt_t));(yyval.ast_t)=(yyvsp[-2].ast_t);}
#line 1757 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 193 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = nullptr; addToNodeList((yyval.ast_t),(yyvsp[0].stmt_t));}
#line 1763 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 196 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1769 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 199 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = new FunctionCallStmt((yyvsp[-3].str_t),(yyvsp[-1].ast_t));}
#line 1775 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 200 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = new PrintStmt((yyvsp[-1].expr_t));}
#line 1781 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 201 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = new PrintlnStmt((yyvsp[-1].expr_t));}
#line 1787 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 202 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = new ReadStmt();}
#line 1793 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 203 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.stmt_t) = new NextIntStmt((yyvsp[-1].expr_t));}
#line 1799 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 206 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new FunctionCallExpr((yyvsp[-3].str_t),(yyvsp[-1].ast_t));}
#line 1805 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 207 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new PrintExpr((yyvsp[-1].expr_t));}
#line 1811 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 208 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new PrintExpr((yyvsp[-1].expr_t));}
#line 1817 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 209 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new ReadExpr();}
#line 1823 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 210 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new NextIntExpr((yyvsp[-1].expr_t));}
#line 1829 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 212 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t)=(yyvsp[0].ast_t);}
#line 1835 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 213 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t)=nullptr;}
#line 1841 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 215 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {addToNodeList((yyvsp[-2].ast_t),(yyvsp[0].expr_t));(yyval.ast_t)=(yyvsp[-2].ast_t);}
#line 1847 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 216 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.ast_t) = nullptr; addToNodeList((yyval.ast_t),(yyvsp[0].expr_t));}
#line 1853 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 219 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new StringConstantExpr((yyvsp[0].str_t));}
#line 1859 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 220 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1865 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 223 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new IdExpr((yyvsp[0].str_t));}
#line 1871 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 224 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new IdArrayExpr((yyvsp[-3].str_t),(yyvsp[-1].expr_t));}
#line 1877 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 228 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1883 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 229 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1889 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 230 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1895 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 231 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1901 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 232 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1907 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 233 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1913 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 234 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[-1].expr_t);}
#line 1919 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 237 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1925 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 238 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1931 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 239 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1937 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 240 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = (yyvsp[0].expr_t);}
#line 1943 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 243 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new AddExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1949 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 244 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new SubExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1955 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 245 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new MulExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1961 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 246 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new DivExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1967 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 247 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new SRLExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1973 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 248 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new SLLExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1979 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 249 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new ModExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1985 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 252 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new LesExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1991 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 253 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new GreExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 1997 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 254 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new LeEExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 2003 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 255 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new GrEExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 2009 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 258 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new EquExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 2015 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 259 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new NEqExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 2021 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 262 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new AndExpr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 2027 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 263 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t) = new Or_Expr((yyvsp[-2].expr_t),(yyvsp[0].expr_t));}
#line 2033 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 266 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new NumExpr((yyvsp[0].int_t));}
#line 2039 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 267 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new CharExpr((yyvsp[0].int_t));}
#line 2045 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 268 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new BoolExpr(1);}
#line 2051 "../src/Parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 269 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1646  */
    {(yyval.expr_t)=new BoolExpr(0);}
#line 2057 "../src/Parser.cpp" /* yacc.c:1646  */
    break;


#line 2061 "../src/Parser.cpp" /* yacc.c:1646  */
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
#line 271 "/home/boris/Desktop/Proyecto/src/Parser.y" /* yacc.c:1906  */

