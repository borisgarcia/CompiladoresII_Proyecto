#include "ast.h"

extern int yylineno;
unordered_map<string, Vars> varsMap;
unordered_map<string, Methods> methodMap;
/*
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
*/
//Stmt
/*
void PrintStmt::exec(){
    if(expr != NULL)
        cout << expr->eval() << endl;
    else
        cout << str;
}

void AssignStmt::exec() {
    int value = expr->eval();
    varsMap[id] = value;
}

void MethodDecStmt::exec()
{
    Methods m;
    m.tipo = tipo;
    m.id = id;
    m.parametros = parametros;
    m.block = this->block;
    methodMap.insert({id,m});
}

void DeclarStmt::exec()
{
    for(int x = 0;x<variables.size();x++)
    {
        Vars v;
        v.tipo = tipo;
        v.id = variables.at();
        v.value = 0;
        varsMap.insert({id,v});
    }
}

void FieldDeclStmt::exec()
{

    for(int x = 0;x<fields.size();x++)
    {
        Vars v;
        v.tipo = type;
        v.id = fields.at(x);
        v.value = 0;
        varsMap.insert({id,v});
    }
}

void FieldDeclStmt_2::exec()
{
    Vars v;
    v.tipo = type;
    v.id = id;
    v.value = value;
    varsMap.insert({id,v});
}

void MethodCallStmt::exec()
{

}
*/