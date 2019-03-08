%{
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
  extern bool state_ment_boolean;
  extern bool method_dec_boolean;
  
  void yyerror(const char *msg) {
        std::cerr << "Parsing Error" <<"Line: "<<lineNo<<"-" <<msg<<'\n';
        errors++;
  }
  YYNODESTATE *nodeState;
  #define YYERROR_VERBOSE 1
%}

%union{
        Statement * stmt_t;
        Expression * expr_t;
        char * str_t;
        int int_t;
}

%type<expr_t> constant cond-op eq-op rel-op arith-op bin-op expr 
%type<expr_t> lvalue argument method-call_expr method-call_params
%type<stmt_t> field_decl mult-field method_decl params params_p
%type<stmt_t> block block_p var-decl var-decl_p statement assign else_opt 
%type<stmt_t> for_assign return_expr method-call_stmt
%token KwBool KwBreak KwContinue KwClass KwElse KwExtends KwFalse KwFor KwIf KwInt 
%token KwNew KwNull KwReturn KwRot KwTrue KwVoid KwWhile KwPrint KwPrintln KwRead KwRandom  

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

program: KwClass Id "{" program_body "}"{
                                                $4->exec();
                                        }
|        KwClass Id "{" "}" {}
;       

program_body:   program_body field_decl         {
                                                        if(method_dec_boolean)
                                                        {
                                                                std::cerr << "PUTOELQUELOLEA" << std::endl;
                                                                exit(0);
                                                        }
                                                }
        |       program_body method_decl        {}
        |       field_decl                      {
                                                        if(method_dec_boolean)
                                                        {
                                                                std::cerr << "PUTOELQUELOLEA" << std::endl;
                                                                exit(0);
                                                        }
                                                }
        |       method_decl                     {}
;

field_decl:     type mult-field ";"                 {}
            |   type Id Assign constant ";"         {}
;

mult-field:     mult-field "," Id                            {}
        |       mult-field "," Id "[" intConstant "]"        {}
        |       Id                                           {}
        |       Id "[" intConstant "]"                       {}
;

method_decl:    type Id "(" params ")" block    {
                                                        method_dec_boolean = true;
                                                }
        |       KwVoid Id "(" params ")" block  {
                                                        method_dec_boolean = true;
                                                }
;

params: params_p        {$$ = $1;}
|                       {$$ = nullptr;}
;

params_p:       params "," type Id    {}
        |       type Id               {}
;

type:           KwInt   {$$=$1;}
        |       KwBool  {$$=$1;}
;

block:  "{" block_p "}"     {$$ = $2;}
|       "{" "}"             {$$ = nullptr;}
;

block_p:    block_p var-decl    {
                                        if(state_ment_boolean)
                                        {
                                                std::cerr << "PUTOELQUELOLEA" << std::endl;
                                                exit(0);
                                        }
                                }
        |   var-decl            {
                                        if(state_ment_boolean)
                                        {
                                                std::cerr << "PUTOELQUELOLEA" << std::endl;
                                                exit(0);
                                        }                                                
                                }
        |   block_p statement   {}
        |   statement           {}       
;

var-decl:   type  var-decl_p ";"   {}
;

var-decl_p:     var-decl_p "," Id       {}
        |       Id                      {}
;

statement:  assign ";"                                                  {$$ = $1; state_ment_boolean = true;}
        |   method-call_stmt ";"                                        {$$ = $1; state_ment_boolean = true;}
        |   KwIf "(" expr ")" block else_opt                            {state_ment_boolean = true;}
        |   KwWhile "(" expr ")" block                                  {state_ment_boolean = true;}
        |   KwBreak ";"                                                 {state_ment_boolean = true;}
        |   KwFor "(" for_assign ";" expr ";" for_assign ")" block      {state_ment_boolean = true;}
        |   KwReturn return_expr ";"                                    {$$ = $1; state_ment_boolean = true;}
        |   KwContinue ";"                                              {$$ = $1; state_ment_boolean = true;}
        |   block                                                       {$$ = $1; state_ment_boolean = true;} 
;

assign: lvalue Assign expr {$$ = new AssignStmt($1,$3);}
;

else_opt:   KwElse block    {$$ = $2;}
            |               {$$ = nullptr;}
;

for_assign: for_assign "," assign   {}
        |   assign                  {
                                        $$ = new BlockStmt();
                                        ((BlockStmt*)$$)->AddStmt($1);
                                    }
;

return_exp: expr   {$$=new ReturnStmt($1);}
;

method-call_stmt:       Id "(" method-call_params ")"    {}
                |       KwPrint "(" argument ")"         {}
                |       KwPrintln "(" argument ")"       {}
                |       KwRead "(" ")"                   {}
                |       KwRandom "(" expr ")"            {}
;

method-call_expr:       Id "(" method-call_params ")"    {}
                |       KwPrint "(" argument ")"         {}
                |       KwPrintln "(" argument ")"       {}
                |       KwRead "(" ")"                   {}
                |       KwRandom "(" expr ")"            {}
;

method-call_params: method-call_params "," expr {}
                |   expr                        {}
;

argument:   StringConstant  {}
        |   expr            {$$ = $1;}
;

lvalue:  Id                     {}
       | Id "[" expr "]"        {}
;

expr:   lvalue                  {$$ = $1;}
|       method-call_expr        {$$ = $1;}
|       constant                {$$ = $1;}
|       bin-op                  {$$ = $1;}
|       "!" expr                {$$ = $1;}
|       "-" expr                {$$ = $1;}
|       "(" expr ")"            {$$ = $2;}
;

bin-op: arith-op        {$$ = $1;}
|       rel-op          {$$ = $1;}
|       cond-op         {$$ = $1;}
|       eq-op           {$$ = $1;}
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