/* ../src/ast.h.  Generated automatically by treecc */
#ifndef __yy____src_ast_h
#define __yy____src_ast_h
#line 4 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"

    #include <iostream>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unordered_map>
    #include <string>
    #include <vector>
    class ASTNode;
    class Statement;
    class Expression;
    using StmtList = std::vector<Statement*>;
    using ExprList = std::vector<Expression*>;
    using string_t = std::string;
    using stringList = std::vector<std::string>;
    using intList = std::vector<int>;
    using int_t = int;
#line 22 "../src/ast.h"

#include <new>

const int ASTNode_kind = 1;
const int Expression_kind = 2;
const int Statement_kind = 3;
const int OneExpr_kind = 4;
const int NumExpr_kind = 7;
const int NextIntExpr_kind = 8;
const int ReadExpr_kind = 9;
const int PrintExpr_kind = 10;
const int FunctionCallExpr_kind = 11;
const int IdExpr_kind = 12;
const int IdArrayExpr_kind = 13;
const int BinExpr_kind = 14;
const int NotExpr_kind = 5;
const int UnaExpr_kind = 6;
const int AddExpr_kind = 15;
const int SubExpr_kind = 16;
const int MulExpr_kind = 17;
const int DivExpr_kind = 18;
const int SRLExpr_kind = 19;
const int SLLExpr_kind = 20;
const int ModExpr_kind = 21;
const int LesExpr_kind = 22;
const int GreExpr_kind = 23;
const int LeTExpr_kind = 24;
const int GrTExpr_kind = 25;
const int EquExpr_kind = 26;
const int NEqExpr_kind = 27;
const int AndExpr_kind = 28;
const int Or_Expr_kind = 29;
const int MultipleExpr_kind = 30;
const int FieldDecStmt_kind = 31;
const int PrintLNStmt_kind = 32;
const int PrintStmt_kind = 33;
const int ReadStmt_kind = 34;
const int NextIntStmt_kind = 35;
const int FunctionCallStmt_kind = 36;
const int AssignStmt_kind = 37;
const int ForStmt_kind = 38;
const int BlockStmt_kind = 39;
const int IfStmt_kind = 40;
const int WhileStmt_kind = 41;
const int ReturnStmt_kind = 42;
const int BreakStmt_kind = 43;
const int ContinueStmt_kind = 44;

class ASTNode;
class Expression;
class Statement;
class OneExpr;
class NumExpr;
class NextIntExpr;
class ReadExpr;
class PrintExpr;
class FunctionCallExpr;
class IdExpr;
class IdArrayExpr;
class BinExpr;
class NotExpr;
class UnaExpr;
class AddExpr;
class SubExpr;
class MulExpr;
class DivExpr;
class SRLExpr;
class SLLExpr;
class ModExpr;
class LesExpr;
class GreExpr;
class LeTExpr;
class GrTExpr;
class EquExpr;
class NEqExpr;
class AndExpr;
class Or_Expr;
class MultipleExpr;
class FieldDecStmt;
class PrintLNStmt;
class PrintStmt;
class ReadStmt;
class NextIntStmt;
class FunctionCallStmt;
class AssignStmt;
class ForStmt;
class BlockStmt;
class IfStmt;
class WhileStmt;
class ReturnStmt;
class BreakStmt;
class ContinueStmt;

class YYNODESTATE
{
public:

	YYNODESTATE();
	virtual ~YYNODESTATE();

#line 1 "cpp_skel.h"
private:

	struct YYNODESTATE_block *blocks__;
	struct YYNODESTATE_push *push_stack__;
	int used__;
#line 129 "../src/ast.h"
public:

	NumExpr *NumExprCreate(int num);
	NextIntExpr *NextIntExprCreate(Expression * expr);
	ReadExpr *ReadExprCreate();
	PrintExpr *PrintExprCreate(Expression * expr);
	FunctionCallExpr *FunctionCallExprCreate(string_t * id, Expression * expr);
	IdExpr *IdExprCreate(string_t id);
	IdArrayExpr *IdArrayExprCreate(string_t id, int_t pos);
	NotExpr *NotExprCreate(Expression * expr1);
	UnaExpr *UnaExprCreate(Expression * expr1);
	AddExpr *AddExprCreate(Expression * expr1, Expression * expr2);
	SubExpr *SubExprCreate(Expression * expr1, Expression * expr2);
	MulExpr *MulExprCreate(Expression * expr1, Expression * expr2);
	DivExpr *DivExprCreate(Expression * expr1, Expression * expr2);
	SRLExpr *SRLExprCreate(Expression * expr1, Expression * expr2);
	SLLExpr *SLLExprCreate(Expression * expr1, Expression * expr2);
	ModExpr *ModExprCreate(Expression * expr1, Expression * expr2);
	LesExpr *LesExprCreate(Expression * expr1, Expression * expr2);
	GreExpr *GreExprCreate(Expression * expr1, Expression * expr2);
	LeTExpr *LeTExprCreate(Expression * expr1, Expression * expr2);
	GrTExpr *GrTExprCreate(Expression * expr1, Expression * expr2);
	EquExpr *EquExprCreate(Expression * expr1, Expression * expr2);
	NEqExpr *NEqExprCreate(Expression * expr1, Expression * expr2);
	AndExpr *AndExprCreate(Expression * expr1, Expression * expr2);
	Or_Expr *Or_ExprCreate(Expression * expr1, Expression * expr2);
	MultipleExpr *MultipleExprCreate(ExprList listaExprs);
	FieldDecStmt *FieldDecStmtCreate(string_t type, stringList lista);
	PrintLNStmt *PrintLNStmtCreate(Expression * expr);
	PrintStmt *PrintStmtCreate(Expression * expr);
	ReadStmt *ReadStmtCreate();
	NextIntStmt *NextIntStmtCreate(Expression * expr);
	FunctionCallStmt *FunctionCallStmtCreate(string_t id, Expression * expr);
	AssignStmt *AssignStmtCreate(string_t id, Expression * expr);
	ForStmt *ForStmtCreate(Statement * for_dec, Expression * cond, Statement * for_assign, Statement * block);
	BlockStmt *BlockStmtCreate(StmtList list);
	IfStmt *IfStmtCreate(Expression * cond, Statement * true_block, Statement * false_block);
	WhileStmt *WhileStmtCreate(Expression * cond, Statement * block);
	ReturnStmt *ReturnStmtCreate(Expression * expr);
	BreakStmt *BreakStmtCreate();
	ContinueStmt *ContinueStmtCreate();

public:

	void *alloc(size_t);
	void dealloc(void *, size_t);
	int push();
	void pop();
	void clear();
	virtual void failed();
	virtual char *currFilename();
	virtual long currLinenum();

};

class ASTNode
{
protected:

	int kind__;
	char *filename__;
	long linenum__;

public:

	int getKind() const { return kind__; }
	const char *getFilename() const { return filename__; }
	long getLinenum() const { return linenum__; }
	void setFilename(char *filename) { filename__ = filename; }
	void setLinenum(long linenum) { linenum__ = linenum; }

protected:

	friend class YYNODESTATE;

	ASTNode(YYNODESTATE *state__);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ASTNode();

};

class Expression : public ASTNode
{
protected:

	friend class YYNODESTATE;

	Expression(YYNODESTATE *state__);

public:

	virtual int eval() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Expression();

};

class Statement : public ASTNode
{
protected:

	friend class YYNODESTATE;

	Statement(YYNODESTATE *state__);

public:

	virtual void exec() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Statement();

};

class OneExpr : public Expression
{
protected:

	friend class YYNODESTATE;

	OneExpr(YYNODESTATE *state__, Expression * expr1);

public:

	Expression * expr1;

	virtual int eval() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~OneExpr();

};

class NumExpr : public Expression
{
protected:

	friend class YYNODESTATE;

	NumExpr(YYNODESTATE *state__, int num);

public:

	int num;

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NumExpr();

};

class NextIntExpr : public Expression
{
protected:

	friend class YYNODESTATE;

	NextIntExpr(YYNODESTATE *state__, Expression * expr);

public:

	Expression * expr;

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NextIntExpr();

};

class ReadExpr : public Expression
{
protected:

	friend class YYNODESTATE;

	ReadExpr(YYNODESTATE *state__);

public:

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ReadExpr();

};

class PrintExpr : public Expression
{
protected:

	friend class YYNODESTATE;

	PrintExpr(YYNODESTATE *state__, Expression * expr);

public:

	Expression * expr;

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~PrintExpr();

};

class FunctionCallExpr : public Expression
{
protected:

	friend class YYNODESTATE;

	FunctionCallExpr(YYNODESTATE *state__, string_t * id, Expression * expr);

public:

	string_t * id;
	Expression * expr;

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FunctionCallExpr();

};

class IdExpr : public Expression
{
protected:

	friend class YYNODESTATE;

	IdExpr(YYNODESTATE *state__, string_t id);

public:

	string_t id;

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IdExpr();

};

class IdArrayExpr : public Expression
{
protected:

	friend class YYNODESTATE;

	IdArrayExpr(YYNODESTATE *state__, string_t id, int_t pos);

public:

	string_t id;
	int_t pos;

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IdArrayExpr();

};

class BinExpr : public Expression
{
protected:

	friend class YYNODESTATE;

	BinExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2);

public:

	Expression * expr1;
	Expression * expr2;

	virtual int eval() = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BinExpr();

};

class NotExpr : public OneExpr
{
protected:

	friend class YYNODESTATE;

	NotExpr(YYNODESTATE *state__, Expression * expr1);

public:

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NotExpr();

};

class UnaExpr : public OneExpr
{
protected:

	friend class YYNODESTATE;

	UnaExpr(YYNODESTATE *state__, Expression * expr1);

public:

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~UnaExpr();

};

class AddExpr : public BinExpr
{
protected:

	friend class YYNODESTATE;

	AddExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2);

public:

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AddExpr();

};

class SubExpr : public BinExpr
{
protected:

	friend class YYNODESTATE;

	SubExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2);

public:

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~SubExpr();

};

class MulExpr : public BinExpr
{
protected:

	friend class YYNODESTATE;

	MulExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2);

public:

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MulExpr();

};

class DivExpr : public BinExpr
{
protected:

	friend class YYNODESTATE;

	DivExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2);

public:

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DivExpr();

};

class SRLExpr : public BinExpr
{
protected:

	friend class YYNODESTATE;

	SRLExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2);

public:

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~SRLExpr();

};

class SLLExpr : public BinExpr
{
protected:

	friend class YYNODESTATE;

	SLLExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2);

public:

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~SLLExpr();

};

class ModExpr : public BinExpr
{
protected:

	friend class YYNODESTATE;

	ModExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2);

public:

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ModExpr();

};

class LesExpr : public BinExpr
{
protected:

	friend class YYNODESTATE;

	LesExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2);

public:

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LesExpr();

};

class GreExpr : public BinExpr
{
protected:

	friend class YYNODESTATE;

	GreExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2);

public:

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~GreExpr();

};

class LeTExpr : public BinExpr
{
protected:

	friend class YYNODESTATE;

	LeTExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2);

public:

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LeTExpr();

};

class GrTExpr : public BinExpr
{
protected:

	friend class YYNODESTATE;

	GrTExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2);

public:

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~GrTExpr();

};

class EquExpr : public BinExpr
{
protected:

	friend class YYNODESTATE;

	EquExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2);

public:

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~EquExpr();

};

class NEqExpr : public BinExpr
{
protected:

	friend class YYNODESTATE;

	NEqExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2);

public:

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NEqExpr();

};

class AndExpr : public BinExpr
{
protected:

	friend class YYNODESTATE;

	AndExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2);

public:

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AndExpr();

};

class Or_Expr : public BinExpr
{
protected:

	friend class YYNODESTATE;

	Or_Expr(YYNODESTATE *state__, Expression * expr1, Expression * expr2);

public:

	virtual int eval();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Or_Expr();

};

class MultipleExpr : public Statement
{
protected:

	friend class YYNODESTATE;

	MultipleExpr(YYNODESTATE *state__, ExprList listaExprs);

public:

	ExprList listaExprs;
	intList listaInts;

	virtual void exec();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MultipleExpr();

};

class FieldDecStmt : public Statement
{
protected:

	friend class YYNODESTATE;

	FieldDecStmt(YYNODESTATE *state__, string_t type, stringList lista);

public:

	string_t type;
	stringList lista;

	virtual void exec();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FieldDecStmt();

};

class PrintLNStmt : public Statement
{
protected:

	friend class YYNODESTATE;

	PrintLNStmt(YYNODESTATE *state__, Expression * expr);

public:

	Expression * expr;

	virtual void exec();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~PrintLNStmt();

};

class PrintStmt : public Statement
{
protected:

	friend class YYNODESTATE;

	PrintStmt(YYNODESTATE *state__, Expression * expr);

public:

	Expression * expr;

	virtual void exec();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~PrintStmt();

};

class ReadStmt : public Statement
{
protected:

	friend class YYNODESTATE;

	ReadStmt(YYNODESTATE *state__);

public:

	virtual void exec();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ReadStmt();

};

class NextIntStmt : public Statement
{
protected:

	friend class YYNODESTATE;

	NextIntStmt(YYNODESTATE *state__, Expression * expr);

public:

	Expression * expr;

	virtual void exec();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NextIntStmt();

};

class FunctionCallStmt : public Statement
{
protected:

	friend class YYNODESTATE;

	FunctionCallStmt(YYNODESTATE *state__, string_t id, Expression * expr);

public:

	string_t id;
	Expression * expr;

	virtual void exec();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FunctionCallStmt();

};

class AssignStmt : public Statement
{
protected:

	friend class YYNODESTATE;

	AssignStmt(YYNODESTATE *state__, string_t id, Expression * expr);

public:

	string_t id;
	Expression * expr;

	virtual void exec();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AssignStmt();

};

class ForStmt : public Statement
{
protected:

	friend class YYNODESTATE;

	ForStmt(YYNODESTATE *state__, Statement * for_dec, Expression * cond, Statement * for_assign, Statement * block);

public:

	Statement * for_dec;
	Expression * cond;
	Statement * for_assign;
	Statement * block;

	virtual void exec();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ForStmt();

};

class BlockStmt : public Statement
{
protected:

	friend class YYNODESTATE;

	BlockStmt(YYNODESTATE *state__, StmtList list);

public:

	StmtList list;

	virtual void exec();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BlockStmt();

};

class IfStmt : public Statement
{
protected:

	friend class YYNODESTATE;

	IfStmt(YYNODESTATE *state__, Expression * cond, Statement * true_block, Statement * false_block);

public:

	Expression * cond;
	Statement * true_block;
	Statement * false_block;

	virtual void exec();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IfStmt();

};

class WhileStmt : public Statement
{
protected:

	friend class YYNODESTATE;

	WhileStmt(YYNODESTATE *state__, Expression * cond, Statement * block);

public:

	Expression * cond;
	Statement * block;

	virtual void exec();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~WhileStmt();

};

class ReturnStmt : public Statement
{
protected:

	friend class YYNODESTATE;

	ReturnStmt(YYNODESTATE *state__, Expression * expr);

public:

	Expression * expr;

	virtual void exec();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ReturnStmt();

};

class BreakStmt : public Statement
{
protected:

	friend class YYNODESTATE;

	BreakStmt(YYNODESTATE *state__);

public:

	virtual void exec();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BreakStmt();

};

class ContinueStmt : public Statement
{
protected:

	friend class YYNODESTATE;

	ContinueStmt(YYNODESTATE *state__);

public:

	virtual void exec();

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ContinueStmt();

};



#endif
