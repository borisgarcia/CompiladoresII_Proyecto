%{
  #include <stdio.h>
  #include <iostream>
  #include <fstream>
  #include <list>
  #include <unordered_map>
  #include "expr_lexer.h"
  #include "tokens.h"

  using namespace std;
  extern int lineNo;
  extern int yylex();
  int errors;
  
  void yyerror(const char *msg) {
        std::cerr << "Parsing Error" <<"Line: "<<lineNo<<"-" <<msg<<'\n';
        errors++;
  }

  #define YYERROR_VERBOSE 1
%}

%token KwBool KwBreak KwContinue KwClass KwElse KwExtends KwFalse KwFor KwIf KwInt KwNew KwNull KwReturn KwRot KwTrue KwVoid KwWhile KwPrint KwPrintln KwRead KwRandom  
%token OpenBrace "{"
%token CloseBrace "}"
%token OpenBracket "["
%token CloseBracket "]"
%token Comma ","
%token Semicolon ";"
%token OpenPar "("
%token ClosePar ")"  
%token Not "!" 
%token OpAdd "+"
%token OpSub "-"
%token OpDiv "/"
%token OpMul "*"
%token OpMod "%"
%token Assign "="
%token OpGreater ">"
%token OpLess "<"
%token OpGreaterEqual ">="
%token OpLessEqual "<="
%token NotEqual "!="
%token OpAnd "&&"
%token OpOr "||"
%token OpEqual "=="
%token SLL "<<"
%token SLR ">>"
%token intConstant CharConstant
%token Id StringConstant                       
%token Eof "end of input"
%token Error

%left "!"
%left "*" "/"
%left "+" "-"
%left "%"
%left "<<" ">>"
%left "<" "<=" ">=" ">"
%left "==" "!="
%left "&&"
%left "||"


%%

program: KwClass Id "{" program_body "}" {}

;

program_body: field_decl method-decl {}
;

field_decl:     field_decl field-decl_p   {}
        |       field-decl_p              {}
        |                                 {} 
;

field-decl_p:   type mult-field ";"                 {}
            |   type Id Assign constant ";"         {}
;

mult-field:     mult-field "," Id                                             {}
        |       mult-field "," Id "[" intConstant "]"        {}
        |       Id                                                              {}
        |       Id "[" intConstant "]"                         {}
;

method-decl:    program_body method-decl_p  {}
            |   method-decl_p               {}
            |
;

method-decl_p:    type Id "(" params ")" block {}
        |       KwVoid Id "(" params ")" block {}
;

params:         params "," type Id    {}
        |       type Id                 {}
        |                               {}
;

type:           KwInt   {}
        |       KwBool  {}
;

block:  "{" block_p "}"     {}
;

block_p:    block_p var-decl    {}
        |   block_p statement   {}
        |   statement           {}
        |   var-decl            {}
        |
;

var-decl:   type  var-decl_p ";"   {}
;

var-decl_p:     var-decl_p "," Id       {}
        |       Id                        {}
;

statement:  assign ";"                                                              {}
        |   method-call_stmt ";"                                                    {}
        |   KwIf "(" expr ")" block else_opt                                        {}
        |   KwWhile "(" expr ")" block                                              {}
        |   KwBreak ";"                                                             {}
        |   KwFor "(" for_assign ";" expr ";" for_assign ")" block                  {}
        |   KwReturn return_expr_opt ";"                                            {}
        |   KwContinue ";"                                                          {}
        |   block                                                                   {} 
;

assign: lvalue Assign expr {}
;

else_opt:   KwElse block    {}
            |               {}
;

for_assign: for_assign "," assign   {}
        |   assign                    {}
;

return_expr_opt:        expr   {}
                |              {}
;

method-call_stmt:       Id "(" method-call_params ")"    {}
                |       KwPrint "(" argument ")"                                {}
                |       KwPrintln "(" argument ")"                               {}
                |       KwRead "(" ")"                      {}
                |       KwRandom "(" expr ")"               {}
;

method-call_expr:       Id "(" method-call_params ")"    {}
                |       KwPrint "(" argument ")"                               {}
                |       KwPrintln "(" argument ")"                               {}
                |       KwRead "(" ")"                      {}
                |       KwRandom "(" expr ")"               {}
;

method-call_params:  method-call_params "," expr  {}
                |       expr                            {}
;

argument:   StringConstant  {}
        |   expr            {}
;

lvalue:  Id                     {}
       | Id "[" expr "]"        {}
;

expr:   lvalue          {}
|       method-call_expr     {}
|       constant        {}
|       bin-op          {}
|       "!" expr        {}
|       "-" expr        {}
|       "(" expr ")"    {}
;

bin-op: arith-op        {}
|       rel-op          {}
|       cond-op         {}
|       eq-op           {}
;

arith-op:  expr "+"  expr   {}
        |  expr "-"  expr   {}
        |  expr "*"  expr   {}       
        |  expr "/"  expr   {}       
        |  expr "<<" expr   {}       
        |  expr ">>" expr   {}       
        |  expr "%"  expr   {}
;

rel-op: expr "<"  expr   {}
|       expr ">"  expr   {}
|       expr "<=" expr   {}
|       expr ">=" expr   {}
;

eq-op:  expr "==" expr  {}
|       expr "!=" expr  {}       
;

cond-op: expr "&&" expr   {}
|        expr "||" expr   {}
;

constant: intConstant   {}
        | CharConstant  {}
        | KwTrue        {}
        | KwFalse       {}
;
%%