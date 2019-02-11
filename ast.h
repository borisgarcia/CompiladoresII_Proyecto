#ifndef _AST_H
#define _AST_H
#include <iostream>
#include <memory>
#include <list>
#include <unordered_map>

using namespace std;

class ASTNode{
   public:
    ASTNode(){};
    ~ASTNode(){};
};
class Expr;
class Stmt;

#define YYSTYPE_IS_DECLARED 1
typedef ASTNode *YYSTYPE;

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

class ArrayExpr : public Expr {
    public:
        IdExpr(string id,int pos) : id(id),pos(pos) {};
        ~IdExpr() {};

        int eval() override;
        string id;
        int pos;
};

class StringConstantExpr: public Expr{
    public:
        StringConstantExpr(string str):str(str){};
        ~StringConstantExpr(){};
        int eval() override{return 0};

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
        AssignStmt(string id, Expr * expr) : id(id) { this->expr = expr; };

        void exec() override;

        string id;
        Expr * expr;
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
        PrintStmt(Expr * expr) { this->expr = expr; };
        PrintStmt(string str) : str(str) {};
        ~PrintStmt() {};

        void exec() override;

    private:
        Expr * expr;
        string str;
};

class IfStmt : public Stmt {
    public:
        IfStmt(Expr * cond, Stmt * left, Stmt * right) {
            this->cond = cond;
            this->trueBlk = left;
            this->falseBlk = right;
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

        void exec() override;

        Expr * cond;
        Stmt * init, * block, * end;
};

class FieldDeclStmt: public Stmt{
    public:
        FieldDeclStmt(string type,list<string> fields,int value)
        {

        }

        string type;
        vector<string> fields;
        int value;
};

class MethodDecStmt: public Stmt{
    public:
        MethodDecStmt(string type, unordered_map<string,string>ids,Stmt* block){}
        
        void exec() override;
        string type;
        unordered_map<string,string> ids;
        Stmt * block;

};

class MethodCallStmt: public Stmt{
    public:
        MethodCallStmt(string id,list<int>parametros){}

        string id;
        list<int> parametros;
};

class WhileStmt: public Stmt{
    public: 
        WhileStmt(Expr * cond, Expr * block){
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
            return return_->eval();
        };

        Expr * return_;

};

#endif /* _AST_H */