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
%token OpenBrace CloseBrace OpenBracket CloseBracket Comma Semicolon OpenPar ClosePar    
%token Not OpAdd OpSub OpDiv OpMul OpMod Assign
%token OpGreater OpLess OpGreaterEqual OpLessEqual NotEqual OpAnd OpOr OpEqual SLL SLR 
%token intConstant CharConstant
%token Id StringConstant                       
%token Eof "end of input"
%token Error

%%

program: KwClass Id OpenBrace program_body CloseBrace {}

;

program_body: program_body field-decl   {}
            | program_body method-decl  {}
            | method-decl               {}
            | field-decl                {}
            |                           {} 
;

field-decl:   type mult-field Semicolon                 {}
            | type Id Assign constant Semicolon         {}
;

mult-field:     mult-field Comma Id                                             {}
        |       mult-field Comma Id OpenBracket intConstant CloseBracket        {}
        |       Id                                                              {}
        |       Id OpenBracket intConstant CloseBracket                         {}
;

method-decl:    type Id OpenPar method-decl_p ClosePar block {}
        |       KwVoid Id OpenPar method-decl_p ClosePar block {}
;

method-decl_p:  method-decl_p Comma type Id   {}
        |       type Id                 {}
        |                               {}
;

type:           KwInt   {}
        |       KwBool  {}
;

block:  OpenBrace block_p CloseBrace     {}
;

block_p:    block_p var-decl    {}
        |   block_p statement   {}
        |   statement           {}
        |   var-decl            {}
        |
;

var-decl:   type  var-decl_p Semicolon   {}
;

var-decl_p:     var-decl_p Comma Id       {}
        |       Id                        {}
;

statement:  assign Semicolon                                                                 {}
        |   method-call Semicolon                                                            {}
        |   KwIf OpenPar expr ClosePar block else_opt                                        {}
        |   KwWhile OpenPar expr ClosePar block                                              {}
        |   KwBreak Semicolon                                                                {}
        |   KwFor OpenPar for_assign Semicolon expr Semicolon for_assign ClosePar block      {}
        |   KwReturn return_expr_opt Semicolon                                               {}
        |   KwContinue Semicolon                                                             {}
        |   block                                                                            {} 
;

for_assign: for_assign Comma assign   {}
        |   assign                    {}
;

return_expr_opt:        expr   {}
                |              {}
;

method-call:    Id OpenPar method-call_expr ClosePar    {}
        |       KwRandom OpenPar expr ClosePar          {}
        |       KwRead OpenPar ClosePar                 {}
        |       print                                   {}
;



method-call_expr:       method-call_expr Comma expr       {}
                |       expr                              {}
;

print:          KwPrint OpenPar argument ClosePar         {}      
        |       KwPrintln OpenPar argument ClosePar       {}      
;

else_opt:   KwElse block    {}
            |               {}
;

assign: lvalue Assign expr {}
;

argument:   StringConstant  {}
        |    expr            {}
;

expr:   cond-op             {}
        | '!' expr          {}
;

cond-op:    cond-op OpOr  cond-op_2  {}
        |   cond-op_2                {}
;

cond-op_2:    cond-op_2 OpAnd eq-op  {}
          |   eq-op                  {}
;

eq-op:      eq-op OpEqual  rel-op   {}
        |   eq-op NotEqual rel-op  {}
        |   rel-op                 {}
;

rel-op:     rel-op OpGreaterEqual arith-op      {}
        |   rel-op OpLessEqual arith-op         {}
        |   rel-op OpGreater arith-op           {}
        |   rel-op OpLess arith-op              {}
        |   arith-op                            {}
;

arith-op:     arith-op SLR arith-op_2 {}
          |   arith-op SLL arith-op_2 {}
          |   arith-op_2              {}
;

arith-op_2:   arith-op_2 OpMod arith-op_3  {}
          |   arith-op_3                   {}
;

arith-op_3:     arith-op_3 OpAdd arith-op_4 {}
            |   arith-op_3 OpSub arith-op_4 {}
            |   arith-op_4                  {}
;

arith-op_4:     arith-op_4 OpDiv factor    {}
            |   arith-op_4 OpMul factor    {}
            |   factor                     {}
;

factor: OpenPar expr ClosePar    {}
        | lvalue                 {}
        | method-call            {}
        | constant               {}
;

lvalue: Id                                       {}
       | Id OpenBracket expr CloseBracket        {}
;

constant: intConstant   {}
        | CharConstant  {}
        | KwTrue        {}
        | KwFalse       {}
;
%%