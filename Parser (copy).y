%code requires{
    #include "ast.h"
}

%{
  #include <stdio.h>
  #include <iostream>
  #include <fstream>
  #include <list>
  #include <unordered_map>

  using namespace std;

  int yylex();
  extern char * yyfilename;
  extern int yylineno;
  int errors;
  
  void yyerror(const char *msg) {
        std::cerr << yylineno << ":" << msg << '\n';
        errors++;
  }

  #define YYERROR_VERBOSE 1

%}

%union{
        Stmt * stmt_t;
        Expr * expr_t;
        char * str_t;
        int int_t;
        
        list<string> list_str_t;
        list<int> list_int_t;
        unordered_map<string,string> mapa;
}

%type<stmt_t> assign else_opt for_assign statement block_p block method-decl
%type<stmt_t> field-decl program_body var-decl print method-call
%type<expr_t> constant lvalue factor arith-op_4 arith-op_3 arith-op_2 arith-op
%type<expr_t> rel-op eq-op cond-op_2 cond-op argument return_expr_opt expr
%type<str_t> type
%type<mapa> method-decl_p
%type<list_str_t> mult-field var-decl_p
%type<list_int_t> method-call_expr
%type<int_t> method-call_2

%token KwBool KwBreak KwContinue KwClass KwElse KwExtends KwFalse KwFor KwIf KwInt KwNew KwNull KwReturn KwRot KwTrue KwVoid KwWhile KwPrint KwPrintln KwRead KwRandom  
%token OpenBrace CloseBrace OpenBracket CloseBracket Comma Semicolon OpenPar ClosePar    
%token Not OpAdd OpSub OpDiv OpMul OpMod Assign
%token OpGreater OpLess OpGreaterEqual OpLessEqual NotEqual OpAnd OpOr OpEqual SLL SLR 
%token<int_t> intConstant CharConstant
%token<str_t> Id StringConstant                       
%token Eof "end of input"
%token Error

%%

program: KwClass Id OpenBrace program_body CloseBrace { ($4)->exec(); }
;

program_body: program_body field-decl   {$$ = $1; ((BlockStmt*)$$)->addStmt($2);}
            | program_body method-decl  {$$ = $1; ((BlockStmt*)$$)->addStmt($2);}
            | method-decl               {$$ = new BlockStmt();((BlockStmt*)$$)->addStmt($1);}
            | field-decl                {$$ = new BlockStmt();((BlockStmt*)$$)->addStmt($1);}
            |                           {$$ = NULL;} 
;

field-decl:   type mult-field Semicolon                 {$$ = new FieldDeclStmt($1,$2);}
            | type Id Assign constant Semicolon         {$$ = new FieldDeclStmt_2($1,$2,$4);}
;

mult-field:     mult-field Comma Id                                             {$1.push_back($3);$$=$1;}
        |       mult-field Comma Id OpenBracket intConstant CloseBracket        {$1.push_back($3);$$=$1;}
        |       Id                                                              {list<string>temp; temp.push_back($1); $$=temp;}
        |       Id OpenBracket intConstant CloseBracket                         {list<string>temp; temp.push_back($1); $$=temp;}
;

method-decl:    type    Id  OpenPar method-decl_p ClosePar block {$$=new MethodDecStmt($1,$2,$4,$6);}
        |       KwVoid  Id  OpenPar method-decl_p ClosePar block {$$=new MethodDecStmt(std::string("void"),$2,$4,$6);}
;

method-decl_p:  method-decl_p type Id   {$$.insert({std::string($2),$3});$$=$1;}
        |       type Id                 {unordered_map<string,string>temp;temp.insert({std::string($1),std::string($2)});$$=temp;}
;

type:           KwInt   {$$ = "int";}
        |       KwBool  {$$ = "bool";}
;

block:  OpenBrace block_p CloseBrace     {$$ = $2;}
;

block_p:    block_p var-decl    {$$ = $1; ((BlockStmt*)$$)->addStmt($2);}
        |   block_p statement   {$$ = $1; ((BlockStmt*)$$)->addStmt($2);}
        |   statement           {$$ = new BlockStmt();((BlockStmt*)$$)->addStmt($1);}
        |   var-decl            {$$ = new BlockStmt();((BlockStmt*)$$)->addStmt($1);}
;

var-decl:   type  var-decl_p Semicolon   {$$ = new DeclarStmt($1,$2);}
;

var-decl_p:     var-decl_p Comma Id       {$1.push_back($3);$$=$1;}
        |       Id                        {list<string>temp; temp.push_back($1); $$=temp;}
;

statement:  assign Semicolon                                                                 {$$ = $1;}
        |   method-call Semicolon                                                            {$$ = $1;}
        |   KwIf OpenPar expr ClosePar block else_opt                                        {$$ = new IfStmt($3,$5,$6);}
        |   KwWhile OpenPar expr ClosePar block                                              {$$ = new WhileStmt($3,$5);}
        |   KwBreak Semicolon                                                                {$$ = new BreakStmt();}
        |   KwFor OpenPar for_assign Semicolon expr Semicolon for_assign ClosePar block      {$$ = new ForStmt($3,$5,$7,$9);}
        |   KwReturn return_expr_opt Semicolon                                               {$$ = new ReturnStmt($2);}
        |   KwContinue Semicolon                                                             {$$ = new ContinueStmt();}
        |   block                                                                            {$$ = $1;} 
;

for_assign: for_assign Comma assign   {$$ = $1; ((BlockStmt*)$$)->addStmt($3);}
        |   assign                    {$$ = new BlockStmt();((BlockStmt*)$$)->addStmt($1);}
;

return_expr_opt:        expr   {$$ = $1;}
                |              {$$ = NULL;}
;

method-call:    Id OpenPar method-call_expr ClosePar    {$$ = new MethodCallStmt($1,$3);}
        |       KwRandom OpenPar expr ClosePar          {$$ = new RandomExpr($3);}
        |       KwRead OpenPar ClosePar                 {$$ = new NextIntStmt();}
        |       print                                   {$$ = $1;}
;



method-call_expr:       method-call_expr Comma expr       {$1.push_back($3->eval());$$=$1;}
                |       expr                              {list<int>temp; temp.push_back($1->eval()); $$=temp;}
;

print:          KwPrint OpenPar argument ClosePar         {$$ = new PrintStmt($3,false);}      
        |       KwPrintln OpenPar argument ClosePar       {$$ = new PrintStmt($3,true);}      
;

else_opt:   KwElse block    { $$ = $2; }
            |               { $$ = NULL; }
;

assign: lvalue Assign expr {$$ = new AssignStmt($1,$3);}
;

argument:   StringConstant  {$$ = new StringConstantExpr($1);}
        |    expr            {$$ = $1;}
;

expr:   cond-op             {$$ = $1;}
        | '!' expr               { $$ = new NotExpr($2);}
;

cond-op:    cond-op OpOr  cond-op_2  {$$ = new OrExpr($1,$3);}
        |   cond-op_2                {$$ = $1;}
;

cond-op_2:    cond-op_2 OpAnd eq-op  {$$ = new AndExpr($1,$3);}
          |   eq-op                  {$$ = $1;}
;

eq-op:      eq-op OpEqual  rel-op   {$$ = new EqualExpr($1,$3);}
        |   eq-op NotEqual rel-op  {$$ = new NotEqualExpr($1,$3);}
        |   rel-op                 {$$ = $1;}
;

rel-op:     rel-op OpGreaterEqual arith-op      {$$ = new GEExpr($1,$3);}
        |   rel-op OpLessEqual arith-op         {$$ = new LEExpr($1,$3);}
        |   rel-op OpGreater arith-op           {$$ = new GExpr($1,$3);}
        |   rel-op OpLess arith-op              {$$ = new LExpr($1,$3);}
        |   arith-op                            {$$ = $1;}
;

arith-op:     arith-op SLR arith-op_2 {$$ = new SRLExpr($1,$3);}
          |   arith-op SLL arith-op_2 {$$ = new SLLExpr($1,$3);}
          |   arith-op_2              {$$ = $1;}
;

arith-op_2:   arith-op_2 OpMod arith-op_3  {$$ = new ModExpr($1,$3);}
          |   arith-op_3                   {$$ = $1;}
;

arith-op_3:     arith-op_3 OpAdd arith-op_4 {$$ = new AddExpr($1,$3);}
            |   arith-op_3 OpSub arith-op_4 {$$ = new SubExpr($1,$3);}
            |   arith-op_4                  {$$ = $1;}
;

arith-op_4:     arith-op_4 OpDiv factor    {$$ = new DivExpr($1,$3);}
            |   arith-op_4 OpMul factor    {$$ = new MulExpr($1,$3);}
            |   factor                     {$$ = $1;}
;

factor: OpenPar expr ClosePar    { $$ = $2; }
        | lvalue                 { $$ = $1; }
        | method-call            { $$ = $1; }
        | constant               { $$ = $1; }
;

lvalue: Id                                      {$$ = new IdExpr($1);}
       | Id OpenBracket expr CloseBracket        {$$ = new IdArrayExpr($1,$3->eval());}
;

constant: intConstant   { $$ = new NumExpr($1);}
        | CharConstant  { $$ = new NumExpr($1);}
        | KwTrue        { $$ = new NumExpr(1);}
        | KwFalse       { $$ = new NumExpr(0);}
;
%%