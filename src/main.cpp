#include <unordered_map>
#include <fstream>
#include <iostream>
#include "expr_lexer.h"

using namespace std;
extern ASTNode *input;
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
    input = nullptr;
    yyparse();
    
    if(input!=nullptr)
    {
        IdentsHandler tmpHandler;
        if (!input->Func_Decl(tmpHandler)) {
            std::cerr << "Failed to load function declarations\n";
            return 1;
        }

        if (!input->gen_Code(tmpHandler)) {
            std::cerr << "Failed to generate code\n";
            return 1;
        }
        FuncDef *mainFD = tmpHandler.getFuncDef("main");

        if (mainFD == nullptr) {
            std::cerr << "Function 'main' has not been defined\n";
            return 1;
        }
        std::cout << "global main\n\n"
                << "extern printf\n\n"
                << "section .data\n";
        std::cout << "\nsection .text\n"
                    << input->code
                    << '\n';
    }

    return 0;
}