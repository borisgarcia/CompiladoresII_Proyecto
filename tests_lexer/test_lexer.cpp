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
const char *test9 = "System.out.println ( z ) ;";

const char *test10 = "void main() { }";
const char *test11 = "if(x > 5){}";
const char *test12 = "for(int x = 0;x>5;x = x + 1){}";
const char *test13 = "while(true) { }";
const char *test14 = "\"Hola\" \'L\'";

TEST_CASE("Operations with Numbers") {
    std::istringstream in;

    in.str(test1);
    ExprLexer l(in);
    Token tk = l.getNextToken();
    
    CHECK( tk == Token::Number);
    tk = l.getNextToken();
    CHECK( tk == Token::OpAdd);
    tk = l.getNextToken();
    CHECK( tk == Token::Number);
    tk = l.getNextToken();
    CHECK( tk == Token::OpDiv);
    tk = l.getNextToken();
    CHECK( tk == Token::Number);
    tk = l.getNextToken();
    CHECK( tk == Token::OpMul);
    tk = l.getNextToken();
    CHECK( tk == Token::Number);
    tk = l.getNextToken();
    CHECK( tk == Token::OpSub);
    tk = l.getNextToken();
    CHECK( tk == Token::Number);
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
    CHECK( tk == Token::Number );
    CHECK( l.getText() == "56" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpDiv );
    CHECK( l.getText() == "/" );
    tk = l.getNextToken();
    CHECK( tk == Token::Number );
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
    CHECK( tk == Token::Number );
    CHECK( l.getText() == "34" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpMul );
    CHECK( l.getText() == "*" );
    tk = l.getNextToken();
    CHECK( tk == Token::Number );
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

    CHECK( tk == Token::Number );
    CHECK( l.getText() == "45" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpAdd );
    CHECK( l.getText() == "+" );
    tk = l.getNextToken();
    CHECK( tk == Token::Number );
    CHECK( l.getText() == "10" );
    tk = l.getNextToken();
    CHECK( tk == Token::Eof );
}

TEST_CASE("Block comments 1") {
    std::istringstream in;

    in.str(test6);
    ExprLexer l(in);
    Token tk = l.getNextToken();

    CHECK( tk == Token::Number );
    CHECK( l.getText() == "45" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpAdd );
    CHECK( l.getText() == "+" );
    tk = l.getNextToken();
    CHECK( tk == Token::Number );
    CHECK( l.getText() == "10" );
    tk = l.getNextToken();
    CHECK( tk == Token::Eof );
}

TEST_CASE("Block comments 2") {
    std::istringstream in;

    in.str(test7);
    ExprLexer l(in);
    Token tk = l.getNextToken();

    CHECK( tk == Token::Number );
    CHECK( l.getText() == "45" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpAdd );
    CHECK( l.getText() == "+" );
    tk = l.getNextToken();
    CHECK( tk == Token::Number );
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
    CHECK( tk == Token::Number );
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
    CHECK( tk == Token::Number );
    CHECK( l.getText() == "20" );
    tk = l.getNextToken();
    CHECK( tk == Token::Semicolon );
    CHECK( l.getText() == ";" );
    tk = l.getNextToken();
    CHECK( tk == Token::Eof );
}

/*TEST_CASE("Print Statement") {
    std::istringstream in;

    in.str(test9);
    ExprLexer l(in);
    Token tk = l.getNextToken();

    CHECK( tk == Token::KwPrint );
    CHECK( l.getText() == "System.out.println" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpenPar );
    CHECK( l.getText() == "(" );
    tk = l.getNextToken();
    CHECK( tk == Token::Id );
    CHECK( l.getText() == "z" );
    tk = l.getNextToken();
    CHECK( tk == Token::ClosePar );
    CHECK( l.getText() == ")" );
    tk = l.getNextToken();
    CHECK( tk == Token::Semicolon );
    CHECK( l.getText() == ";" );
    tk = l.getNextToken();
}*/

TEST_CASE("fn Statement") {
    std::istringstream in;

    in.str(test10);
    ExprLexer l(in);
    Token tk = l.getNextToken();

    CHECK( tk == Token::KwVoid);
    CHECK( l.getText() == "void" );
    tk = l.getNextToken();
    CHECK( tk == Token::Id );
    CHECK( l.getText() == "main" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpenPar);
    CHECK( l.getText() == "(" );
    tk = l.getNextToken();
    CHECK( tk == Token::ClosePar );
    CHECK( l.getText() == ")" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpenBrace );
    CHECK( l.getText() == "{" );
    tk = l.getNextToken();
    CHECK( tk == Token::CloseBrace );
    CHECK( l.getText() == "}" );
    tk = l.getNextToken();
}
TEST_CASE("if Statement") {
    std::istringstream in;

    in.str(test11);
    ExprLexer l(in);
    Token tk = l.getNextToken();

    CHECK( tk == Token::KwIf);
    CHECK( l.getText() == "if" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpenPar);
    CHECK( l.getText() == "(" );
    tk = l.getNextToken();
    CHECK( tk == Token::Id );
    CHECK( l.getText() == "x" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpGreater );
    CHECK( l.getText() == ">" );
    tk = l.getNextToken();
    CHECK( tk == Token::Number );
    CHECK( l.getText() == "5" );
    tk = l.getNextToken();
    CHECK( tk == Token::ClosePar );
    CHECK( l.getText() == ")" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpenBrace );
    CHECK( l.getText() == "{" );
    tk = l.getNextToken();
    CHECK( tk == Token::CloseBrace );
    CHECK( l.getText() == "}" );
    tk = l.getNextToken();
}
TEST_CASE("for Statement") {
    std::istringstream in;

    in.str(test12);
    ExprLexer l(in);
    Token tk = l.getNextToken();

    CHECK( tk == Token::KwFor);
    CHECK( l.getText() == "for" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpenPar);
    CHECK( l.getText() == "(" );
    tk = l.getNextToken();
    CHECK( tk == Token::KwInt );
    CHECK( l.getText() == "int" );
    tk = l.getNextToken();
    CHECK( tk == Token::Id );
    CHECK( l.getText() == "x" );
    tk = l.getNextToken();
    CHECK( tk == Token::Assign );
    CHECK( l.getText() == "=" );
    tk = l.getNextToken();
    CHECK( tk == Token::Number );
    CHECK( l.getText() == "0" );
    tk = l.getNextToken();
    CHECK( tk == Token::Semicolon );
    CHECK( l.getText() == ";" );
    tk = l.getNextToken();
    CHECK( tk == Token::Id );
    CHECK( l.getText() == "x" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpGreater );
    CHECK( l.getText() == ">" );
    tk = l.getNextToken();
    CHECK( tk == Token::Number );
    CHECK( l.getText() == "5" );
    tk = l.getNextToken();
    CHECK( tk == Token::Semicolon );
    CHECK( l.getText() == ";" );
    tk = l.getNextToken();
    CHECK( tk == Token::Id );
    CHECK( l.getText() == "x" );
    tk = l.getNextToken();
    CHECK( tk == Token::Assign );
    CHECK( l.getText() == "=" );
    tk = l.getNextToken();
    CHECK( tk == Token::Id );
    CHECK( l.getText() == "x" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpAdd );
    CHECK( l.getText() == "+" );
    tk = l.getNextToken();
    CHECK( tk == Token::Number );
    CHECK( l.getText() == "1" );
    tk = l.getNextToken();
    CHECK( tk == Token::ClosePar );
    CHECK( l.getText() == ")" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpenBrace );
    CHECK( l.getText() == "{" );
    tk = l.getNextToken();
    CHECK( tk == Token::CloseBrace );
    CHECK( l.getText() == "}" );
    tk = l.getNextToken();
}
TEST_CASE("while Statement") {
    std::istringstream in;

    in.str(test13);
    ExprLexer l(in);
    Token tk = l.getNextToken();

    CHECK( tk == Token::KwWhile);
    CHECK( l.getText() == "while" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpenPar);
    CHECK( l.getText() == "(" );
    tk = l.getNextToken();

    CHECK( tk == Token::KwTrue);
    CHECK( l.getText() == "true" );
    tk = l.getNextToken();

    CHECK( tk == Token::ClosePar );
    CHECK( l.getText() == ")" );
    tk = l.getNextToken();
    CHECK( tk == Token::OpenBrace );
    CHECK( l.getText() == "{" );
    tk = l.getNextToken();
    CHECK( tk == Token::CloseBrace );
    CHECK( l.getText() == "}" );
    tk = l.getNextToken();
}
TEST_CASE("String and Char") {
    std::istringstream in;

    in.str(test14);
    ExprLexer l(in);
    Token tk = l.getNextToken();

    CHECK( tk == Token::StringConstant);
    std::cout<<l.getText()<<"\n";
    tk = l.getNextToken();
    CHECK( tk == Token::CharConstant);
    CHECK( l.getText() == "L" );
    tk = l.getNextToken();
}