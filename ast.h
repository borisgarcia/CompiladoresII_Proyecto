#ifndef _AST_H
#define _AST_H
#include <iostream>
#include <memory>
#include <list>
#include <unordered_map>
#include <stdlib.h> 
#include <vector>


using namespace std;

class Expr;
class Stmt;

using StmtList = list<Stmt*>;

#define DEFINE_EXPR(name, oper) \
    class name##Expr: public BinaryExpr { \
        public: \
            name##Expr(Expr * expr1, Expr * expr2) : BinaryExpr(expr1, expr2) {}; \
            ~name##Expr() {}; \
            int eval() override { \
                return expr1->eval() oper expr2->eval(); \
            }; \
        }\

class Expr{
    public:
        Expr() {};
        ~Expr() {};
        virtual int eval() = 0;
};

class BinaryExpr : public Expr {
    public:
        BinaryExpr(Expr * expr1, Expr * expr2) {
            this->expr1 = expr1;
            this->expr2 = expr2;
        };
        ~BinaryExpr() {};

        Expr * expr1,  * expr2;
};

class NumExpr : public Expr {
    public:
        NumExpr(int value) : value(value) {};
        ~NumExpr() {};

        int eval() override { return value; };
    
    private:
        int value;
};

class IdExpr : public Expr {
    public:
        IdExpr(string id) : id(id) {};
        ~IdExpr() {};

        int eval() override;
        string id;

    private:
};

class NotExpr : public Expr {
    public:
        NotExpr(Expr * num){this->num = num;};
        ~NotExpr() {};

        int eval() override{
            return !num->eval();
        };
        Expr * num;
};

class RandomExpr : public Expr {
    public:
        RandomExpr(Expr * num) {this->num = num;};
        ~RandomExpr() {};

        int eval() override{
            return rand() % num->eval();
        };
        Expr * num;
};

class IdArrayExpr : public Expr {
    public:
        IdArrayExpr(string id,int pos) : id(id),pos(pos) {};
        ~IdArrayExpr() {};

        int eval() override;
        string id;
        int pos;
};

class StringConstantExpr: public Expr{
    public:
        StringConstantExpr(string str):str(str){};
        ~StringConstantExpr(){};
        int eval() override{return 0;};

        string getStr(){return str;};
        string str;      
};

DEFINE_EXPR(Add, +);
DEFINE_EXPR(Sub, -);
DEFINE_EXPR(Mul, *);
DEFINE_EXPR(Div, /);
DEFINE_EXPR(G, >);
DEFINE_EXPR(L, <);
DEFINE_EXPR(GE, >=);
DEFINE_EXPR(LE, <=);
DEFINE_EXPR(Equal, ==);
DEFINE_EXPR(NotEqual, !=);
DEFINE_EXPR(Or, &&);
DEFINE_EXPR(And, &&);
DEFINE_EXPR(SRL, >>);
DEFINE_EXPR(SLL, <<);
DEFINE_EXPR(Mod, %);

class Stmt{
    public:
        Stmt() {};
        ~Stmt() {};
        virtual void exec() = 0;
};

class AssignStmt : public Stmt {
    public:
        AssignStmt(Expr * id, Expr * expr) : id(id) { this->expr = expr; };

        void exec() override;

        Expr * id;
        Expr * expr;
};

class MethodDecStmt : public Stmt {
    public:
        MethodDecStmt(string tipo,string id, unordered_map<string,string>parametros,Stmt * block) : tipo(tipo),id(id),parametros(parametros) {this->block = block;};
        void exec() override;
        string id;
        string tipo;
        unordered_map<string,string>parametros;
        Stmt * block;
};

class DeclarStmt : public Stmt {
    public:
        DeclarStmt(string tipo, list<string>variables) : tipo(tipo),variables(variables) {};
        void exec() override;
        string tipo;
        list<string>variables;
};

class FieldDeclStmt: public Stmt{
    public:
        FieldDeclStmt(string type,list<string> fields) : type(type),fields(fields){};
        void exec() override;
        string type;
        list<string> fields;
        int value;
};

class FieldDeclStmt_2: public Stmt{
    public:
        FieldDeclStmt_2(string type,string id,int value) : type(type), id(id), value(value) {};
        
        void exec() override;
        string type;
        string id;
        int value;
};


class BlockStmt : public Stmt {
    public:
        BlockStmt() {}

        void addStmt(Stmt * stmt){
            lista.push_back(stmt);
        };

        StmtList getList() { return move(lista); };

        void exec() {
            for(auto & stmt : lista){
                stmt->exec();
            }
        };

    private:
        StmtList lista;
};

class PrintStmt : public Stmt {
    public:
        PrintStmt(Expr * expr,bool ln) : ln(ln){ this->expr = expr; };
        ~PrintStmt() {};

        void exec() override{
            if(ln)
                cout<<expr->eval()<<endl;
            else
                cout<<expr->eval();
        };

    private:
        Expr * expr;
        bool ln;
};

class NextIntStmt : public Stmt {
    public:
        NextIntStmt() {}
        ~NextIntStmt() {};
        void exec() override{
            cin>>num;
        };
        int getNum(){return num;}

    private:
        int num;
};

class IfStmt : public Stmt {
    public:
        IfStmt(Expr * cond, Stmt * stmtTrue, Stmt * stmtFalse) {
            this->cond = cond;
            this->trueBlk = stmtTrue;
            this->falseBlk = stmtFalse;
        };

        void exec() override{
            if(cond->eval())
                trueBlk->exec();
            else
                falseBlk->exec();
        };

        Expr * cond;
        Stmt * trueBlk, * falseBlk;
};

class ForStmt : public Stmt {
    public:
        ForStmt(Stmt * init, Expr * cond, Stmt * block, Stmt * end) {
            this->init = init;
            this->cond = cond;
            this->end = end;
            this->block = block;
        };

        void exec() override{
            init->exec();
            while(cond->eval())
            {
                block->exec();
                end->exec();
            }
        };

        Expr * cond;
        Stmt * init, * block, * end;
};

class MethodCallStmt: public Stmt{
    public:
        MethodCallStmt(string id,list<int>parametros){}

        string id;
        list<int> parametros;
};

class WhileStmt: public Stmt{
    public: 
        WhileStmt(Expr * cond, Stmt * block){
            this->cond = cond;
            this->block = block;
        };

        void exec() override{
            while(cond->eval())
            {
                block->exec();
            }
        };
        Expr * cond;
        Stmt * block;
};

class ReturnStmt: public Stmt{
    public:
        ReturnStmt(Expr * return_){
            this->return_ = return_;
        };

        void exec() override{
            return_->eval();
        };

        Expr * return_;

};

class BreakStmt: public Stmt{
    public:
        BreakStmt(){}
        void exec() override{};

};

class ContinueStmt: public Stmt{
    public:
        ContinueStmt(){}
        void exec() override{};
};

struct Methods{
    string tipo;
    string id;
    unordered_map<string,string> parametros;
    Stmt * block;
};

struct Vars{
    string tipo;
    string id;
    int value;
};


#endif /* _AST_H */