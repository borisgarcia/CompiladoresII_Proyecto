/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_SRC_TOKENS_H_INCLUDED
# define YY_YY_SRC_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    KwBool = 258,
    KwBreak = 259,
    KwContinue = 260,
    KwClass = 261,
    KwElse = 262,
    KwExtends = 263,
    KwFalse = 264,
    KwFor = 265,
    KwIf = 266,
    KwInt = 267,
    KwNew = 268,
    KwNull = 269,
    KwReturn = 270,
    KwRot = 271,
    KwTrue = 272,
    KwVoid = 273,
    KwWhile = 274,
    KwPrint = 275,
    KwPrintln = 276,
    KwRead = 277,
    KwRandom = 278,
    OpenBrace = 279,
    CloseBrace = 280,
    OpenBracket = 281,
    CloseBracket = 282,
    Comma = 283,
    Semicolon = 284,
    OpenPar = 285,
    ClosePar = 286,
    Not = 287,
    OpAdd = 288,
    OpSub = 289,
    OpDiv = 290,
    OpMul = 291,
    OpMod = 292,
    Assign = 293,
    OpGreater = 294,
    OpLess = 295,
    OpGreaterEqual = 296,
    OpLessEqual = 297,
    NotEqual = 298,
    OpAnd = 299,
    OpOr = 300,
    OpEqual = 301,
    SLL = 302,
    SLR = 303,
    intConstant = 304,
    CharConstant = 305,
    Id = 306,
    StringConstant = 307,
    Eof = 308,
    Error = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_TOKENS_H_INCLUDED  */
