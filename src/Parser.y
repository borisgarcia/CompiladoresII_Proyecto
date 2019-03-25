
%code requires {
#include "ast.h"
}
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
  bool state_ment_boolean;
  bool method_dec_boolean;
  
  void yyerror(const char *msg) {
        std::cerr << "Parsing Error: " <<"Line: "<<lineNo<<"-" <<msg<<'\n';
        errors++;
  }

  
%}

%union{
        Statement * stmt_t;
        Expression * expr_t;
        ASTNode * ast_t;
        char * str_t;
        int int_t;
}

%type<ast_t> program program_body id mult-field method_decl params params_p block_p var-decl_p parametro for_assign field_decl method-call_params
%type<expr_t> return_expr method-call_expr argument lvalue expr bin-op arith-op rel-op cond-op
%type<expr_t> eq-op constant
%type<stmt_t> var-decl statement assign else_opt method-call_stmt block
%type<str_t> type

%token<int_t> intConstant CharConstant
%token<str_t> KwBool KwVoid Id StringConstant KwInt
%token KwBreak KwContinue KwClass KwElse KwExtends KwFor KwIf KwFalse KwTrue
%token KwNew KwNull KwReturn KwRot KwWhile KwPrint KwPrintln KwRead KwRandom  

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

program: KwClass Id "{" program_body "}"{$$ = new BlockStmt($4);}
|        KwClass Id "{" "}" {$$=nullptr;}
;       

program_body:   program_body field_decl{
                if(method_dec_boolean)
                {
                        yyerror("Can't declare fields after methods!");
                        exit(0);
                }
                addToNodeList($1,$2);$$=$1;
        }
        |       program_body method_decl{
                addToNodeList($1,$2);$$=$1;
        }
        |       field_decl{
                if(method_dec_boolean)
                {
                        yyerror("Can't declare fields after methods!");
                        exit(0);
                }
                $$ = nullptr; addToNodeList($$,$1);
        }
        |       method_decl{
                $$ = nullptr; addToNodeList($$,$1);
        }
;

field_decl:     type mult-field ";"                 {$$ = new FieldDecStmt_2($1,$2);}
            |   type Id Assign constant ";"         {$$ = new FieldDecStmt($1,$2,$4);}
;

mult-field:     mult-field "," id                            {addToNodeList($1,$3);$$=$1;}
        |       mult-field "," Id "[" intConstant "]"        {addToNodeList($1,new ArrayDec($3,$5));$$=$1;}
        |       id                                           {$$ = nullptr; addToNodeList($$,$1);}
        |       Id "[" intConstant "]"                       {$$ = nullptr; addToNodeList($$,new ArrayDec($1,$3));}
;

method_decl:    type Id "(" params ")" block    {
                                                        $$ = new FnDec($1,$2,$4,$6);
                                                        method_dec_boolean = true;
                                                }
        |       KwVoid Id "(" params ")" block  {
                                                        $$ = new FnDec($1,$2,$4,$6);
                                                        method_dec_boolean = true;
                                                }
;

params: params_p        {$$=$1;}
|       %empty          {$$=nullptr;}
;

params_p:       params_p "," parametro    {addToNodeList($1,$3);$$=$1;}
        |       parametro                 {$$ = nullptr; addToNodeList($$,$1);}
;

parametro:      type Id {$$=new FnParamsDec($1,$2);}
;

type:           KwInt   {$$ = $1;}
        |       KwBool  {$$ = $1;}
;

block:  "{" block_p "}"     {$$ = new BlockStmt($2);}
|       "{" "}"             {$$ = nullptr;}
;

block_p: block_p var-decl{
                if(state_ment_boolean)
                {
                        yyerror("Can't declare variables after statements!");
                        exit(0);
                }
                addToNodeList($1,$2);
                $$=$1;
        }
        |   var-decl{
                if(state_ment_boolean)
                {
                        yyerror("Can't declare variables after statements!");
                        exit(0);
                }
                $$ = nullptr; 
                addToNodeList($$,$1);                                                
        }
        |   block_p statement{
                addToNodeList($1,$2);
                $$=$1;
        }
        |   statement{
                $$ = nullptr; 
                addToNodeList($$,$1);  
        }       
;

var-decl: type var-decl_p ";"   {$$ = new VarDecStmt($1,$2);}
;

var-decl_p:     var-decl_p "," id       {addToNodeList($1,$3);$$=$1;}
        |       id                      {$$ = nullptr; addToNodeList($$,$1);}
;

id:     Id      {$$ = new stringNode($1);}
;

statement:  assign ";"                                                  {state_ment_boolean = true;$$ = $1;}
        |   method-call_stmt ";"                                        {state_ment_boolean = true;$$ = $1;}
        |   KwIf "(" expr ")" block else_opt                            {state_ment_boolean = true;$$ = new IfStmt($3,$5,$6);}
        |   KwWhile "(" expr ")" block                                  {state_ment_boolean = true;$$ = new WhileStmt($3,$5);}
        |   KwBreak ";"                                                 {state_ment_boolean = true;$$ = new BreakStmt();}
        |   KwFor "(" for_assign ";" expr ";" for_assign ")" block      {state_ment_boolean = true;$$ = new ForStmt($3,$5,$7,$9);}
        |   KwReturn return_expr ";"                                    {state_ment_boolean = true;$$ = new ReturnStmt($2);}
        |   KwContinue ";"                                              {state_ment_boolean = true;$$ = new ContinueStmt();}
        |   block                                                       {state_ment_boolean = true;$$ = $1;} 
;

assign: lvalue Assign expr {$$ = new AssignStmt($1,$3);}
;

else_opt:   KwElse block    {$$ = $2;}
            | %empty        {$$ = nullptr;}
;

for_assign: for_assign "," assign   {addToNodeList($1,$3);$$=$1;}
        |   assign                  {$$ = nullptr; addToNodeList($$,$1);}
;

return_expr: expr   {$$ = $1;}
;

method-call_stmt:       Id "(" method-call_params ")"    {$$ = new FunctionCallStmt($1,$3);}
                |       KwPrint "(" argument ")"         {$$ = new PrintStmt($3);}
                |       KwPrintln "(" argument ")"       {$$ = new PrintlnStmt($3);}
                |       KwRead "(" ")"                   {$$ = new ReadStmt();}
                |       KwRandom "(" expr ")"            {$$ = new NextIntStmt($3);}
;

method-call_expr:       Id "(" method-call_params ")"    {$$ = new FunctionCallExpr($1,$3);}
                |       KwPrint "(" argument ")"         {$$ = new PrintExpr($3);}
                |       KwPrintln "(" argument ")"       {$$ = new PrintExpr($3);}
                |       KwRead "(" ")"                   {$$ = new ReadExpr();}
                |       KwRandom "(" expr ")"            {$$ = new NextIntExpr($3);}
;

method-call_params: method-call_params "," expr {addToNodeList($1,$3);$$=$1;}
                |   expr                        {$$ = nullptr; addToNodeList($$,$1);}
;

argument:   StringConstant  {$$ = new StringConstantExpr($1);}
        |   expr            {$$ = $1;}
;

lvalue:   Id                     {$$=new IdExpr($1);}
        | Id "[" expr "]"        {$$=new IdArrayExpr($1,$3);}

;

expr:   lvalue                  {$$ = $1;}
|       method-call_expr        {$$ = $1;}
|       constant                {$$ = $1;}
|       bin-op                  {$$ = $1;}
|       "!" expr                {$$ = $2;}
|       "-" expr                {$$ = $2;}
|       "(" expr ")"            {$$ = $2;}
;

bin-op: arith-op        {$$ = $1;}
|       rel-op          {$$ = $1;}
|       cond-op         {$$ = $1;}
|       eq-op           {$$ = $1;}
;

arith-op:  expr "+"  expr   {$$ = new AddExpr($1,$3);}
        |  expr "-"  expr   {$$ = new SubExpr($1,$3);}
        |  expr "*"  expr   {$$ = new MulExpr($1,$3);}       
        |  expr "/"  expr   {$$ = new DivExpr($1,$3);}       
        |  expr "<<" expr   {$$ = new SRLExpr($1,$3);}       
        |  expr ">>" expr   {$$ = new SLLExpr($1,$3);}       
        |  expr "%"  expr   {$$ = new ModExpr($1,$3);}
;

rel-op: expr "<"  expr   {$$ = new LesExpr($1,$3);}
|       expr ">"  expr   {$$ = new GreExpr($1,$3);}
|       expr "<=" expr   {$$ = new LeEExpr($1,$3);}
|       expr ">=" expr   {$$ = new GrEExpr($1,$3);}
;

eq-op:  expr "==" expr  {$$ = new EquExpr($1,$3);}
|       expr "!=" expr  {$$ = new NEqExpr($1,$3);}       
;

cond-op: expr "&&" expr   {$$ = new AndExpr($1,$3);}
|        expr "||" expr   {$$ = new Or_Expr($1,$3);}
;

constant: intConstant   {$$=new NumExpr($1);}
        | CharConstant  {$$=new CharExpr($1);}
        | KwTrue        {$$=new BoolExpr(1);}
        | KwFalse       {$$=new BoolExpr(0);}
;
%%
