#include <cstdio>
#include "expr_lexer.h"

/*!max:re2c*/
int lineNo=1;

int ExprLexer::Context::fill(size_t need)
{
    if(eof)
        return 1;
    
    const size_t free = tok - buf;
    if(free<need)
        return 2;

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
    return 3;
}

int ExprLexer::getNextToken() {
    char * YYMARKER;
    const char * YYCTXMARKER;
    while(1)
    {
        ctx.tok = ctx.cur;
        if(ctx.cur == 0 && ctx.eof)
            return 0;
        /*!re2c
        re2c:define:YYCTYPE = char;
        re2c:define:YYCURSOR = ctx.cur;
        re2c:define:YYLIMIT = ctx.lim;
        re2c:define:YYFILL = "if (!ctx.fill(@@)) return 0;";
        re2c:define:YYFILL:naked = 0;
        */

        if(state == 0){goto init;}
        else if(state == 1){goto linecomment;}
        else if(state == 2){goto blockcomment;}
        else if(state == 3){goto char_c;}
        else if(state == 4){goto string_c;}
        else if(state == 5){goto print;}

        init:
        /*!re2c        
            "/*"                        {state = 2; continue;}
            "//"                        {state = 1; continue;}
            [ \t]                       {state = 0; continue;}
            [\n]                        {lineNo++;continue;}
            "\'"                        {state = 3; continue;}
            "\""                        {text = "";state = 4; continue;}
            "System"                    {state = 5; continue;}

            "bool"                      {
                                            yytokentype tok = makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwBool);
                                            yylval.str_t = strdup(text.c_str());
                                            return tok;                                            
                                        }
            "break"                     {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwBreak);}
            "continue"                  {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwContinue);}
            "class"                     {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwClass);}
            "else"                      {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwElse);}
            "extends"                   {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwExtends);}
            "false"                     {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwFalse);}
            "for"                       {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwFor);}
            "if"                        {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwIf);}
            "int"                       {
                                            yytokentype tok = makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwInt);
                                            yylval.str_t = strdup(text.c_str());
                                            return tok;
                                        }
            "new"                       {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwNew);}
            "null"                      {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwNull);}
            "return"                    {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwReturn);}
            "rot"                       {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwRot);}
            "true"                      {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwTrue);}
            "void"                      {
                                            yytokentype tok = makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwVoid);
                                            yylval.str_t = strdup(text.c_str());
                                            return tok;
                                        }
            "while"                     {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwWhile);}
        
            "+"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::OpAdd);}
            "-"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::OpSub);}
            "*"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::OpMul);}
            "/"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::OpDiv);}
            "%"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::OpMod);}
            "="                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::Assign);}
            
            "("                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::OpenPar);}
            ")"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::ClosePar);}
            "["                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::OpenBracket);}
            "]"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::CloseBracket);}
            "{"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::OpenBrace);}
            "}"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::CloseBrace);}
            ";"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::Semicolon);}
            ","                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::Comma);}

            ">"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::OpGreater);}
            "<"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::OpLess);}
            ">="                        {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::OpGreaterEqual);}
            "<="                        {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::OpLessEqual);}
            "!"                         {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::Not);}
            "!="                        {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::NotEqual);}
            "&&"                        {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::OpAnd);}
            "||"                        {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::OpOr);}
            "=="                        {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::OpEqual);}
            "<<"                        {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::SLL);}
            ">>"                        {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::SLR);}
            "System.out.println"        {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwPrintln);}
            "System.out.print"          {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwPrint);}
            "System.in.read"            {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwRead);}
            "Random.nextInt"            {return makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::KwRandom);}
            [0-9]+                      {
                                            yytokentype tok = makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::intConstant);
                                            yylval.int_t = atol(text.c_str());
                                            return tok;
                                        }
            [_a-zA-Z][_a-zA-Z0-9]*      {
                                            yytokentype tok = makeToken(ctx.tok,ctx.cur-ctx.tok,yytokentype::Id);
                                            yylval.str_t = strdup(text.c_str());
                                            return tok;
                                        }
            "\x00"                      {return 0;}
        */
        linecomment:
        /*!re2c
            "\n" {lineNo++; state = 0; continue;}
            * {state = 1; continue;}
        */
        blockcomment:
        /*!re2c
            "*\/" {state = 0; continue;}
            [\n]  {lineNo++; state = 2; continue;}
            * {state = 2; continue;}
            

        */
        char_c:
        /*!re2c
            "\'"                            {state = 0;yylval.str_t = strdup(text.c_str());return yytokentype::CharConstant;}
            [\x20\x21\x23-\x26\x28-\x7F]    {   
                                                std::string temp(ctx.tok, ctx.cur-ctx.tok);
                                                text = std::move(temp);
                                                state = 3; 
                                                continue;
                                            }
        */
        string_c:
        /*!re2c
            "\""                            {state = 0;yylval.str_t = strdup(text.c_str());return yytokentype::StringConstant;}
            [\x20\x21\x23-\x26\x28-\x7F]+   {   
                                                std::string temp(ctx.tok, ctx.cur-ctx.tok);
                                                text += std::move(temp);
                                                state = 4; 
                                                continue;
                                            }
        */
        print:
        /*!re2c
            * {state = 2; continue;}

        */
    }
}

/*

*/