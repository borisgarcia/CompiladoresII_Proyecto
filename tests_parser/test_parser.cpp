#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <sstream>
#include <memory>
#include <cstring>
#include <functional>
#include "expr_lexer.h"

extern int yyparse();
ExprLexer * l;
int yylex(){
    return l->getNextToken();
}

const char * test1 = "class Class1 { \n"
                        "int a = 10;\n"
                        "int b = 20;\n"
                        "void main() {\n"
                            "System.out.println(a + b);\n"
                        "}\n"
                    "}";
const char * test2 = "class Class1 { \n"
                        "int a = 10;\n"
                        "int b = 20;\n"
                        "void main() {\n"
                            "for(a = 0;a < 10;a=a+1){ \n"
                                "System.out.println(a + b);\n"
                            "}\n"
                        "}\n"
                    "}";

const char * test3 = "class Class1 { \n"
                        "int a = 10;\n"
                        "void main() {\n"
                            "while(a==10){ \n"
                                "System.out.println(a + b);\n"
                                "a = a-1;\n"
                            "}\n"
                        "}\n"
                    "}";

const char * test4 = "class Class1 { \n"
                        "void main() {\n"
                            "a = a-1;\n"
                            "a = a+1;\n"
                            "a = a*1;\n"
                            "a = a/1;\n"
                        "}\n"
                    "}";

const char * test5 = "class Class1 { \n"
                        "int a = 10;\n"
                        "int b = 20;\n"
                        "void main() {\n"
                            "System.out.println(a + b);\n"
                            "System.out.print(a + b);\n"
                            "Random.nextInt(a + b);\n"
                            "b = System.in.read();\n"
                        "}\n"
                    "}";
const char * test6 = "class Class1 { \n"
                        "int a = 10;\n"
                        "int b = 20;\n"
                        "void main() {\n"
                            "if(a > b){\n"
                                "System.out.print(a + b);\n"
                                "Random.nextInt(a + b);\n"
                            "}\n"
                        "}\n"
                    "}";
/*const char * test2 =
const char * test3 =
const char * test4 =
const char * test5 =
const char * test6 =*/


TEST_CASE("Test Print") {
    std::istringstream in;
    in.str(test1);
    l = new ExprLexer(in);
    bool parseSuccess = false;
    if(yyparse()==0) {
        parseSuccess = true;
    }
    else{
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}

TEST_CASE("Test For") {
    std::istringstream in;
    in.str(test2);
    l = new ExprLexer(in);
    bool parseSuccess = false;
    
    if(yyparse()==0) {
        parseSuccess = true;
    }
    else{
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}

TEST_CASE("Test For") {
    std::istringstream in;
    in.str(test3);
    l = new ExprLexer(in);
    bool parseSuccess = false;
    
    if(yyparse()==0) {
        parseSuccess = true;
    }
    else{
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}

TEST_CASE("Test For") {
    std::istringstream in;
    in.str(test4);
    l = new ExprLexer(in);
    bool parseSuccess = false;
    
    if(yyparse()==0) {
        parseSuccess = true;
    }
    else{
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}

TEST_CASE("Test For") {
    std::istringstream in;
    in.str(test5);
    l = new ExprLexer(in);
    bool parseSuccess = false;
    
    if(yyparse()==0) {
        parseSuccess = true;
    }
    else{
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}
TEST_CASE("Test For") {
    std::istringstream in;
    in.str(test6);
    l = new ExprLexer(in);
    bool parseSuccess = false;
    
    if(yyparse()==0) {
        parseSuccess = true;
    }
    else{
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}
/*
TEST_CASE("Test Comments") {   
    Lexer lexer("../Files/test_comment.txt");
    Parser parser(lexer);
    
    bool parseSuccess = false;
    try {
        parser.initParser();
        parseSuccess = true;
    } catch (...) {
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}

TEST_CASE("Test For") {   
    Lexer lexer("../Files/test_for.txt");
    Parser parser(lexer);
    
    bool parseSuccess = false;
    try {
        parser.initParser();
        parseSuccess = true;
    } catch (...) {
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}

TEST_CASE("If Test") {   
    Lexer lexer("../Files/test_if_else.txt");
    Parser parser(lexer);
    
    bool parseSuccess = false;
    try {
        parser.initParser();
        parseSuccess = true;
    } catch (...) {
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}

TEST_CASE("Main Test") {   
    Lexer lexer("../Files/test_main.txt");
    Parser parser(lexer);
    
    bool parseSuccess = false;
    try {
        parser.initParser();
        parseSuccess = true;
    } catch (...) {
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}

TEST_CASE("Test Method") {   
    Lexer lexer("../Files/test_method.txt");
    Parser parser(lexer);
    
    bool parseSuccess = false;
    try {
        parser.initParser();
        parseSuccess = true;
    } catch (...) {
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}

TEST_CASE("Test While") {   
    Lexer lexer("../Files/test_method.txt");
    Parser parser(lexer);
    
    bool parseSuccess = false;
    try {
        parser.initParser();
        parseSuccess = true;
    } catch (...) {
        parseSuccess = false;
    }
    CHECK(parseSuccess);
}
*/