#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <sstream>
#include <memory>
#include <cstring>
#include "doctest.h"
#include "expr_lexer.h"

const char *test1 = "45 + 10 / 87 * 45 - 0";
const char *test2 = "var = _var_1 + _var_2";
const char *test4 = "(56 / 54) - (34 * 789);";
const char *test5 = "//Line comment\n"
                    "45 // Line Comment\n"
                    "+ // Line Comment\n"
                    "10 // Line Comment\n"
                    "//";

const char *test6 = "/* Block comment */\n"
                    "/* Block comment */ 45 /* Block comment */ + /* + Block comment */ 10\n";

const char *test7 = "/* Block comment ### \n"
                    " Block comment !!! ### */45/* Block comment ### \n"
                    " Block comment !!! ### */ + 10/* Block comment ### \n"
                    " Block comment !!! ### */";
const char *test8 = "int a = 10;int b = 20;";
const char *keywords = "else extends false bool break continue class for if int new null return rot true void while System.out.println System.out.print";
const char *operators = "{}[],;()=-!+*/<<>><>%<=>===!=&&||";
const char *stringConst = "\"hola\"";


TEST_CASE("String Constant")
{
    std::istringstream in;

    in.str(stringConst);
    ExprLexer l(in);

    Token tk = l.getNextToken();
    CHECK(tk == Token::StringConstant);
    CHECK(l.getText() == "hola");

}

TEST_CASE("Operators")
{
    std::istringstream in;

    in.str(operators);
    ExprLexer l(in);

    Token tk = l.getNextToken();
    CHECK(tk == Token::OpenBrace);
    tk = l.getNextToken();
    CHECK(tk == Token::CloseBrace);
    tk = l.getNextToken();
    CHECK(tk == Token::OpenBracket);
    tk = l.getNextToken();
    CHECK(tk == Token::CloseBracket);
    tk = l.getNextToken();
    CHECK(tk == Token::Comma);
    tk = l.getNextToken();
    CHECK(tk == Token::Semicolon);
    tk = l.getNextToken();
    CHECK(tk == Token::OpenPar);
    tk = l.getNextToken();
    CHECK(tk == Token::ClosePar);
    tk = l.getNextToken();
    CHECK(tk == Token::Assign);
    tk = l.getNextToken();
    CHECK(tk == Token::OpSub);
    tk = l.getNextToken();
    CHECK(tk == Token::Not);
    tk = l.getNextToken();
    CHECK(tk == Token::OpAdd);
    tk = l.getNextToken();
    CHECK(tk == Token::OpMul);
    tk = l.getNextToken();
    CHECK(tk == Token::OpDiv);
    tk = l.getNextToken();
    CHECK(tk == Token::SLL);
    tk = l.getNextToken();
    CHECK(tk == Token::SLR);
    tk = l.getNextToken();
    CHECK(tk == Token::OpLess);
    tk = l.getNextToken();
    CHECK(tk == Token::OpGreater);
    tk = l.getNextToken();
    CHECK(tk == Token::OpMod);
    tk = l.getNextToken();
    CHECK(tk == Token::OpLessEqual);
    tk = l.getNextToken();
    CHECK(tk == Token::OpGreaterEqual);
    tk = l.getNextToken();
    CHECK(tk == Token::OpEqual);
    tk = l.getNextToken();
    CHECK(tk == Token::NotEqual);
    tk = l.getNextToken();
    CHECK(tk == Token::OpAnd);
    tk = l.getNextToken();
    CHECK(tk == Token::OpOr);
}

TEST_CASE("Keywords")
{
    std::istringstream in;

    in.str(keywords);
    ExprLexer l(in);

    Token tk = l.getNextToken();
    CHECK(tk == Token::KwElse);

    tk = l.getNextToken();
    CHECK(tk == Token::KwExtends);

    tk = l.getNextToken();
    CHECK(tk == Token::KwFalse);

    tk = l.getNextToken();
    CHECK(tk == Token::KwBool);

    tk = l.getNextToken();
    CHECK(tk == Token::KwBreak);

    tk = l.getNextToken();
    CHECK(tk == Token::KwContinue);

    tk = l.getNextToken();
    CHECK(tk == Token::KwClass);

    tk = l.getNextToken();
    CHECK(tk == Token::KwFor);

    tk = l.getNextToken();
    CHECK(tk == Token::KwIf);

    tk = l.getNextToken();
    CHECK(tk == Token::KwInt);

    tk = l.getNextToken();
    CHECK(tk == Token::KwNew);

    tk = l.getNextToken();
    CHECK(tk == Token::KwNull);

    tk = l.getNextToken();
    CHECK(tk == Token::KwReturn);

    tk = l.getNextToken();
    CHECK(tk == Token::KwRot);

    tk = l.getNextToken();
    CHECK(tk == Token::KwTrue);

    tk = l.getNextToken();
    CHECK(tk == Token::KwVoid);

    tk = l.getNextToken();
    CHECK(tk == Token::KwWhile);

    tk = l.getNextToken();
    CHECK(tk == Token::KwPrintln);

    tk = l.getNextToken();
    CHECK(tk == Token::KwPrint);
}

TEST_CASE("Operations with intConstants") {
    std::istringstream in;

    in.str(test1);
    ExprLexer l(in);
    Token tk = l.getNextToken();
    
    CHECK( tk == Token::intConstant);
    tk = l.getNextToken();
    CHECK( tk == Token::OpAdd);
    tk = l.getNextToken();
    CHECK( tk == Token::intConstant);
    tk = l.getNextToken();
    CHECK( tk == Token::OpDiv);
    tk = l.getNextToken();
    CHECK( tk == Token::intConstant);
    tk = l.getNextToken();
    CHECK( tk == Token::OpMul);
    tk = l.getNextToken();
    CHECK( tk == Token::intConstant);
    tk = l.getNextToken();
    CHECK( tk == Token::OpSub);
    tk = l.getNextToken();
    CHECK( tk == Token::intConstant);
    tk = l.getNextToken();
    CHECK( tk == Token::Eof);
}

TEST_CASE("Assign statement with variables") {
    std::istringstream in;

    in.str(test2);
    ExprLexer l(in);
    Token tk = l.getNextToken();

    CHECK( tk == Token::Id );
    tk = l.getNextToken();
    CHECK( tk == Token::Assign );
    tk = l.getNextToken();
    CHECK( tk == Token::Id );
    tk = l.getNextToken();
    CHECK( tk == Token::OpAdd );
    tk = l.getNextToken();
    CHECK( tk == Token::Id );
    tk = l.getNextToken();
    CHECK( tk == Token::Eof );
}

TEST_CASE("Complex expression") {
    std::istringstream in;

    in.str(test4);
    ExprLexer l(in);
    Token tk = l.getNextToken();

    CHECK( tk == Token::OpenPar );
    CHECK( l.getText() == "(" );
    tk = l.getNextToken();
    CHECK( tk == Token::intConstant );
    CHECK( l.getText() == "56" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpDiv );
    CHECK( l.getText() == "/" );
    tk = l.getNextToken();
    CHECK( tk == Token::intConstant );
    CHECK( l.getText() == "54" );
    tk = l.getNextToken();
    CHECK( tk == Token::ClosePar );
    CHECK( l.getText() == ")" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpSub );
    CHECK( l.getText() == "-" );

    tk = l.getNextToken();
    CHECK( tk == Token::OpenPar );
    CHECK( l.getText() == "(" );
    tk = l.getNextToken();
    CHECK( tk == Token::intConstant );
    CHECK( l.getText() == "34" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpMul );
    CHECK( l.getText() == "*" );
    tk = l.getNextToken();
    CHECK( tk == Token::intConstant );
    CHECK( l.getText() == "789" );
    tk = l.getNextToken();
    CHECK( tk == Token::ClosePar );
    CHECK( l.getText() == ")" );
    tk = l.getNextToken();
    CHECK( tk == Token::Semicolon );
    CHECK( l.getText() == ";" );
    tk = l.getNextToken();
    CHECK( tk == Token::Eof );
}

TEST_CASE("Line comments") {
    std::istringstream in;

    in.str(test5);
    ExprLexer l(in);
    Token tk = l.getNextToken();

    CHECK( tk == Token::intConstant );
    CHECK( l.getText() == "45" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpAdd );
    CHECK( l.getText() == "+" );
    tk = l.getNextToken();
    CHECK( tk == Token::intConstant );
    CHECK( l.getText() == "10" );
    tk = l.getNextToken();
    CHECK( tk == Token::Eof );
}

TEST_CASE("Block comments 1") {
    std::istringstream in;

    in.str(test6);
    ExprLexer l(in);
    Token tk = l.getNextToken();

    CHECK( tk == Token::intConstant );
    CHECK( l.getText() == "45" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpAdd );
    CHECK( l.getText() == "+" );
    tk = l.getNextToken();
    CHECK( tk == Token::intConstant );
    CHECK( l.getText() == "10" );
    tk = l.getNextToken();
    CHECK( tk == Token::Eof );
}

TEST_CASE("Block comments 2") {
    std::istringstream in;

    in.str(test7);
    ExprLexer l(in);
    Token tk = l.getNextToken();

    CHECK( tk == Token::intConstant );
    CHECK( l.getText() == "45" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpAdd );
    CHECK( l.getText() == "+" );
    tk = l.getNextToken();
    CHECK( tk == Token::intConstant );
    CHECK( l.getText() == "10" );
    tk = l.getNextToken();
    CHECK( tk == Token::Eof );
}

TEST_CASE("Declar Statement") {
    std::istringstream in;

    in.str(test8);
    ExprLexer l(in);
    Token tk = l.getNextToken();

    CHECK( tk == Token::KwInt );
    CHECK( l.getText() == "int" );
    tk = l.getNextToken();
    CHECK( tk == Token::Id );
    CHECK( l.getText() == "a" );
    tk = l.getNextToken();
    CHECK( tk == Token::Assign );
    CHECK( l.getText() == "=" );
    tk = l.getNextToken();
    CHECK( tk == Token::intConstant );
    CHECK( l.getText() == "10" );
    tk = l.getNextToken();
    CHECK( tk == Token::Semicolon );
    CHECK( l.getText() == ";" );
    tk = l.getNextToken();
    
    CHECK( tk == Token::KwInt );
    CHECK( l.getText() == "int" );
    tk = l.getNextToken();
    CHECK( tk == Token::Id );
    CHECK( l.getText() == "b" );
    tk = l.getNextToken();
    CHECK( tk == Token::Assign );
    CHECK( l.getText() == "=" );
    tk = l.getNextToken();
    CHECK( tk == Token::intConstant );
    CHECK( l.getText() == "20" );
    tk = l.getNextToken();
    CHECK( tk == Token::Semicolon );
    CHECK( l.getText() == ";" );
    tk = l.getNextToken();
    CHECK( tk == Token::Eof );
}
