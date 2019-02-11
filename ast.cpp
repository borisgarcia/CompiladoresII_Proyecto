#include "ast.h"

extern int yylineno;
unordered_map<string, int> varsMap;

int IdExpr::eval(){
    if(varsMap.find(id) != varsMap.end())
        return varsMap[id];
    else throw std::string("Error");
}

int IdArrayExpr::eval(){
    if(varsMap.find(id) != varsMap.end())
        return varsMap[id];
    else throw std::string("Error");
}

void PrintStmt::exec(){
    if(expr != NULL)
        cout << expr->eval() << endl;
    else
        cout << str;
}
/*
void ForStmt::exec(){
    function<void()> initFn, blockFn, endFn;
    function<int()> condFn;

    initFn = [=](){
        if(init != NULL)
            init->exec();
    };

    condFn = [=](){
        return cond == NULL ? 1 : cond->eval();
    };

    blockFn = [=](){
        if(block != NULL)
            block->exec();
    };

    endFn = [=](){
        if(end != NULL)
            end->exec();
    };

    for(initFn(); condFn(); endFn())
        blockFn();
}*/

void AssignStmt::exec() {
    int value = expr->eval();
    varsMap[id] = value;
}