#ifndef _EXPR_LEXER_H
#define _EXPR_LEXER_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>

enum class Token {
    KwBool              = 0,
    KwBreak             = 1,
    KwContinue          = 2,
    KwClass             = 3,
    KwElse              = 4,
    KwExtends           = 5,
    KwFalse             = 6,
    KwFor               = 7,
    KwIf                = 8,
    KwInt               = 9,
    KwNew               = 10,
    KwNull              = 11,
    KwReturn            = 12,
    KwRot               = 13,
    KwTrue              = 14,
    KwVoid              = 15,
    KwWhile             = 16,
    KwPrint             = 17,
    
    OpenBrace           = 100,
    CloseBrace          = 101,
    OpenBracket         = 102,
    CloseBracket        = 103,
    Comma               = 104,
    Semicolon           = 105,
    OpenPar             = 106,
    ClosePar            = 107,
    
    Not                 = 108,
    OpAdd               = 109,
    OpSub               = 110,
    OpDiv               = 111,
    OpMul               = 112,
    OpMod               = 113,
    Assign              = 114,

    OpGreater           = 115,
    OpLess              = 116,
    OpGreaterEqual      = 117,
    OpLessEqual         = 118,
    NotEqual            = 119,
    OpAnd               = 120,
    OpOr                = 121,
    OpEqual             = 122,
    SLL                 = 123,
    SLR                 = 124,

    StringConstant      = 200,
    CharConstant        = 201,
    Number              = 202,
    Id                  = 203,

    Error               = 998,
    Eof                 = 999,
};

class ExprLexer {
public:
    ExprLexer(std::istream &in): ctx(in) {}
    Token getNextToken();
    int getLineNo() { return lineNo; }
    std::string getText() { return text; }

private:
    struct Context {
        std::istream& in;
        char buf[1024];
        char *lim;
        char *cur;
        char *tok;
        bool eof;
        
        bool fill(size_t need);

        Context(std::istream &in)
            : in(in)
            , lim(buf + 1024)
            , cur(lim)
            , tok(lim)
            , eof(false)
        {}
    };

    Token makeToken(const char *txt, int len, Token tk) {
        std::string tt(txt, len);
        text = std::move(tt);
        return tk;
    }

private:
    int lineNo;
    Context ctx;
    std::string text;
    int state;
};
#endif
