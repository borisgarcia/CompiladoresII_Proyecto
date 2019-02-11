%code requires{
    #include "ast.h"
}

%{
  #include <stdio.h>

  extern int yylex();

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
        unordered_map<string,string> mapa;
}

%type <stmt_t> assign else_opt method-call for_assign statement block_p block method-decl
%type <stmt_t> field-decl program_body
%type <expr_t> constant lvalue factor arith-op_4 arith-op_3 arith-op_2 arith-op
%type <expr_t> rel-op eq-op cond-op_2 cond-op argument
%type <str_t>   type
%type <mapa> method-decl_p
%type <list_str_t> mult-field var-decl_p

%token Add Sub Multi Div
%token KwPrint KwIf KwElse
%token Equal
%token OpenPar ClosePar
%token Number
%token Ident
%token Semicolon
%token OpMenor OpMayor OpMenorIgual OpMayorIgual OpDistinto OpIgual
%token OpenBraces CloseBraces
%token Text
%token Eof "end of input"
%token Error

%%

program: KwClass Id ‘{’ program_body ‘}’ { ((Stmt*)$4)->exec(); }
;

program_body: program_body field-decl   {$$ = $1; ((BlockStmt *)$$)->add((Stmt*)$2);}
            | program_body method-decl  {$$ = $1; ((BlockStmt *)$$)->add((Stmt*)$2);}
            | method-decl               {StmtList list; list.push_back((Stmt*)$1); $$ = new BlockStmt(list);}
            | field-decl                {StmtList list; list.push_back((Stmt*)$1); $$ = new BlockStmt(list);}
            |                           {$$ = NULL;} 
;

field-decl:   type mult-field ';'       {$$ = new }
            | type Id ‘=’ constant ‘;’
;


mult-field:     mult-field ',' Id                       {$1.push_back($3);$$=$1;}
        |       mult-field ',' Id '[' intConstant ']'   {$1.push_back($3);$$=$1;}
        |       Id                                      {list<string>temp; temp.push_back($1); $$=temp;}
        |       Id '[' intConstant ']'                  {list<string>temp; temp.push_back($1); $$=temp;}
;

method-decl:   type  Id  '(' type Id + ')' block {$$=new MethodDecStmt($1,$2,$4);}
;

method-decl_p:          method-decl_p type Id   {$$.insert({std::string($2),$3});$$=$1;}
                |       type Id                 {unordered_map<string,string>temp;temp.insert({std::string($1,$2)});$$=temp;}
;

type:           KwVoid  {$$ = "void";}
        |       KwInt   {$$ = "int";}
        |       KwBool  {$$ = "bool";}
;

block:  '{' block_p '}'     {$$ = $2;}
;

block_p:    block_p var-decl    {$$ = $1; ((BlockStmt *)$$)->add((Stmt*)$2);}
        |   block_p statement   {$$ = $1; ((BlockStmt *)$$)->add((Stmt*)$2);}
        |   statement           {StmtList list; list.push_back((Stmt*)$1); $$ = new BlockStmt(list);}
        |   var-decl            {StmtList list; list.push_back((Stmt*)$1); $$ = new BlockStmt(list);}
;

var-decl:   KwInt  Id ';'   {$$ = new DeclarStmt($1,$2);}
        |   KwBool Id ';'   {$$ = new DeclarStmt($1,$2);}
;

var-decl_p:     mult-field ',' Id       {$1.push_back($3);$$=$1;}
        |       Id                      {list<string>temp; temp.push_back($1); $$=temp;}
;

statement:  assign                                              {$$ = $1;}
        |   method-call                                         {$$ = $1;}
        |   KwIf '(' expr ')' block else_opt                    {$$ = new IfStmt((Expr*)$3,(Stmt*)$5,(Stmt*)$6);}
        |   KwWhile '(' expr ')' block                          {$$ = new WhileStmt((Expr*)$3,(Stmt*)$5);}
        |   KwBreak ';'                                         {$$ = new BreakStmt();}
        |   KwFor '(' for_assign ';' expr ';' for_assign ')'    {$$ = new ForStmt();}
        |   KwReturn return_expr_opt ';'                        {$$ = new ReturnStmt((Expr*)$2);}
        |   KwContinue ';'                                      {$$ = new ContinueStmt();}
        |   block                                               {$$ = $1;}
;

for_assign: for_assign ',' assign   {$$ = $1; ((BlockStmt *)$$)->add((Stmt*)$3);}
        |   assign                  {StmtList list; list.push_back((Stmt*)$1); $$ = new BlockStmt(list);}
;

method-call: Id '(' method-call_expr ')'  {$$ = new MethodCallStmt($1,$3,$5);}
;

method-call_expr:       method-call_expr ',' expr
                |       expr
;

else_opt:   KwElse block    { $$ = $2; }
            |               { $$ = NULL; }
;

assign: lvalue '=' expr { $$ = new AssignStmt((Expr*)$1,(Expr*)$3);}
;

argument:   stringConstant  {$$ = $1;}
            expr            {$$ = $1;}
;

expr:   cond-op         {$$ = $1;}
;

cond-op:    cond-op "||"  ond-op_2  {$$ = new OrExpr((Expr *)$1,(Expr *)$3);}
        |   cond-op_2               {$$ = $1;}
;

cond-op_2:    cond-op_2 "&&" eq-op  {$$ = new AndExpr((Expr *)$1,(Expr *)$3);}
          |   eq-op                 {$$ = $1;}
;

eq-op:      eq-op "==" rel-op  {$$ = new EqualExpr((Expr *)$1,(Expr *)$3);}
        |   eq-op "!=" rel-op  {$$ = new NotEquallExpr((Expr *)$1,(Expr *)$3);}
        |   rel-op             {$$ = $1;}
;

rel-op:     rel-op ">=" arith-op {$$ = new GEExpr((Expr *)$1,(Expr *)$3);}
        |   rel-op "<=" arith-op {$$ = new LEExpr((Expr *)$1,(Expr *)$3);}
        |   rel-op ">"  arith-op {$$ = new GExpr((Expr *)$1,(Expr *)$3);}
        |   rel-op "<"  arith-op {$$ = new LExpr((Expr *)$1,(Expr *)$3);}
        |   arith-op             {$$ = $1;}
;

arith-op:     arith-op ">>" arith-op_2 {$$ = new SRLExpr((Expr *)$1,(Expr *)$3);}
          |   arith-op "<<" arith-op_2 {$$ = new SLLExpr((Expr *)$1,(Expr *)$3);}
          |   arith-op_2               {$$ = $1;}
;

arith-op_2:   arith-op_2 "%" arith-op_3  {$$ = new ModExpr((Expr *)$1,(Expr *)$3);}
          |   arith-op_3                 {$$ = $1;}
;

arith-op_3:     arith-op_3 "+" arith-op_4 {$$ = new SumExpr((Expr *)$1,(Expr *)$3);}
            |   arith-op_3 "-" arith-op_4 {$$ = new SubExpr((Expr *)$1,(Expr *)$3);}
            |   arith-op_4                {$$ = $1;}
;

arith-op_4:     arith-op_4 "/" factor    {$$ = new DivExpr((Expr *)$1,(Expr *)$3);}
            |   arith-op_4 "*" factor    {$$ = new MulExpr((Expr *)$1,(Expr *)$3);}
            |   factor                   {$$ = $1;}
;

factor: '(' expr ')'    { $$ = $2; }
        | lvalue        { $$ = $1; }
        | method-call   { $$ = $1; }
        | constant      { $$ = $1; }
        | '!' expr      { $$ = new NotExpr((Expr*)$2); }
;

lvalue: Id              {$$ = new IdExpr($1);}
        Id '[' expr ']' {$$ = new IdArrayExpr($1,$3);}
;

constant: intConstant   { $$ = new NumExpr($1);}
        | CharConstant  { $$ = new CharExpr($1);}
        | KwTrue        { $$ = new BoolExpr($1);}
        | KwFalse       { $$ = new BoolExpr($1);}
;
%%