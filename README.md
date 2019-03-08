# CompiladoresII_Proyecto
Proyecto de la Clase de Compiladores II

El proyecto de la clase consistirá en construir un compilador para un lenguaje llamado Decaf.

Para el Lexer se utilizo la libreria Re2c.

El Parser esta construido en Bison.

Gramatica:

program: KwClass Id "{" program_body "}" {}
|        KwClass Id "{" "}" {}
;

program_body:   program_body field_decl         {}
        |       program_body method_decl        {}
        |       field_decl                      {}
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

method_decl:    type Id "(" params ")" block {}
        |       KwVoid Id "(" params ")" block {}
;

params:         params "," type Id    {}
        |       type Id               {}
        |                             {}
;

type:           KwInt   {}
        |       KwBool  {}
;

block:  "{" block_p "}"     {}
|       "{" "}"             {}
;

block_p:    block_p var-decl    {}
        |   block_p statement   {}
        |   statement           {}
        |   var-decl            {}
;

var-decl:   type  var-decl_p ";"   {}
;

var-decl_p:     var-decl_p "," Id       {}
        |       Id                      {}
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

method-call_params:  method-call_params "," expr  {}
                |       expr                      {}
;

argument:   StringConstant  {}
        |   expr            {}
;

lvalue:  Id                     {}
       | Id "[" expr "]"        {}
;

expr:   lvalue                  {}
|       method-call_expr        {}
|       constant                {}
|       bin-op                  {}
|       "!" expr                {}
|       "-" expr                {}
|       "(" expr ")"            {}
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
