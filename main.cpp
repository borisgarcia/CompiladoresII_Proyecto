#include <unordered_map>
#include <fstream>
#include <iostream>
#include "ast.h"
#include "error.h"
#include "lexer.h"

using namespace std;

void usage(char * progName){
    cout << "Usage " << progName << " <fileName> [<-Dvar=<num>>]*" << endl;
}

function<int()> globalFn;

int yylex(){ return globalFn(); }

int main(int argc, char * argv[]){
    if(argc < 2 || argv[1][0] == '-'){
        usage(argv[0]);
        return -1;
    }

    ifstream file(argv[1]);

    if(!file.is_open()){
        cout << "Couln't open file: " << argv[1] << endl;
        return -1;
    }

    Lexer * lex = new Lexer(file);
    globalFn = [=](){ return lex->nextToken(); };

    extern int yylineno;
    extern int yyparse();

    try{
        yyparse();
        extern Stmt * prg;
        prg->exec();
    }catch(TError & e){
        cerr << "\nError at line: " << e.getLineNo() << ": " << e.getErrorMessage() << endl;
    }
    return 0;
}