#include <unordered_map>
#include <fstream>
#include <iostream>
#include "expr_lexer.h"

using namespace std;

extern int yyparse();
ExprLexer * lex;
int yylex(){ 
    return lex->getNextToken(); 
}

int main(int argc, char * argv[]){
    if(argc < 2){
        std::cout<<"Se necesitan 2 parametros"<<std::endl;
        return -1;
    }

    ifstream file(argv[1]);

    if(!file.is_open()){
        cout << "Couln't open file: " << argv[1] << endl;
        return -1;
    }
    
    lex = new ExprLexer(file);    
   
    try{
        yyparse();
        std::cout<<"Success!\n";
    }catch(...){
       std::cout<<"Parsing Error\n";
    }
    return 0;
}