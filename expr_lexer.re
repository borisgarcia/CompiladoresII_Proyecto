#include <cstdio>
#include "expr_lexer.h"

/*!max:re2c*/

bool ExprLexer::Context::fill(size_t need)
{
    if(eof)
        return false;
    
    const size_t free = tok - buf;
    if(free<need)
        return false;

    memmove(buf, tok, lim-tok);
    lim -= free;
    cur -= free;
    tok -= free;
    in.read(buf,free);
    lim += in.gcount();
        
    if(lim < buf + free)
    {
        eof = true;
        memset(lim,0,YYMAXFILL);
        lim+=YYMAXFILL;
    }
    return true;
}

Token ExprLexer::getNextToken() {
    
    while(1)
    {
        ctx.tok = ctx.cur;
        if(ctx.cur == 0 && ctx.eof)
            return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::Eof);
        /*!re2c

        re2c:define:YYCTYPE = char;
        re2c:define:YYCURSOR = ctx.cur;
        re2c:define:YYLIMIT = ctx.lim;
        re2c:define:YYFILL = "if (!ctx.fill(@@)) makeToken(ctx.tok,ctx.cur-ctx.tok,Token::Eof);";
        re2c:define:YYFILL:naked = 1;

        */

        if(state == 0){goto init;}
        else if(state == 1){goto linecomment;}
        else if(state == 2){goto blockcomment;}

        init:
        /*!re2c        
            "/*"                        {state = 2; continue;}
            "//"                        {state = 1; continue;}
            [ \t\n]                     {state = 0; continue;}

            "bool"                      {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::KwBool);}
            "break"                     {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::KwBreak);}
            "continue"                  {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::KwContinue);}
            "class"                     {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::KwClass);}
            "else"                      {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::KwElse);}
            "extends"                   {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::KwExtends);}
            "false"                     {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::KwFalse);}
            "for"                       {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::KwFor);}
            "if"                        {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::KwIf);}
            "int"                       {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::KwInt);}
            "new"                       {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::KwNew);}
            "null"                      {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::KwNull);}
            "return"                    {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::KwReturn);}
            "rot"                       {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::KwRot);}
            "true"                      {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::KwTrue);}
            "void"                      {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::KwVoid);}
            "while"                     {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::KwWhile);}
            
            "+"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::OpAdd);}
            "-"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::OpSub);}
            "*"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::OpMul);}
            "/"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::OpDiv);}
            "%"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::OpMod);}
            "="                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::Assign);}
            
            "("                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::OpenPar);}
            ")"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::ClosePar);}
            "["                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::OpenBracket);}
            "]"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::CloseBracket);}
            "{"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::OpenBrace);}
            "}"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::CloseBrace);}
            ";"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::Semicolon);}
            ","                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::Comma);}

            ">"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::OpGreater);}
            "<"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::OpLess);}
            ">="                        {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::OpGreaterEqual);}
            "<="                        {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::OpLessEqual);}
            "!="                        {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::NotEqual);}
            "&&"                        {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::OpAnd);}
            "||"                        {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::OpOr);}
            "=="                        {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::OpEqual);}
            "<<"                        {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::SLL);}
            ">>"                        {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::SLR);}
            
            [0-9.]+                      {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::Number);}
            [_a-zA-Z][_a-zA-Z0-9]*      {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::Id);}
            
            *                           {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::Error);}
            "\x00"                      {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::Eof);}    
        */
        linecomment:
        /*!re2c
            "\n" {state = 0; continue;}
            * {state = 1; continue;}
            "\x00" {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::Eof);}   
        */
        blockcomment:
        /*!re2c
            "*\/" {state = 0; continue;}
            * {state = 2; continue;}
            "\x00" {return makeToken(ctx.tok,ctx.cur-ctx.tok,Token::Eof);} 

        */
    }

}