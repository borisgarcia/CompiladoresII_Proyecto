/* ../src/ast.h.  Generated automatically by treecc */
#ifndef __yy____src_ast_h
#define __yy____src_ast_h
#line 3 "/home/boris/Desktop/Proyecto/src/AST.tc"

    #include <iostream>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unordered_map>
    #include <string>
    #include <vector>
    #include <sstream>
    #include "ident_handler.h"
    
    using namespace std;

    class ASTNode;
    class Statement;
    class Expression;
    class NumExpr;
    
    using string_t = std::string;
    void addToNodeList(ASTNode *&lst, ASTNode *node);
    
#line 26 "../src/ast.h"

#include <new>

const int ASTNode_kind = 1;
const int Program_kind = 2;
const int FnDec_kind = 3;
const int stringNode_kind = 4;
const int FieldDecStmt_kind = 5;
const int FieldDecStmt_2_kind = 6;
const int nodeList_kind = 7;
const int FnParamsDec_kind = 8;
const int Expression_kind = 9;
const int Statement_kind = 40;
const int NumExpr_kind = 10;
const int StringConstantExpr_kind = 11;
const int CharExpr_kind = 12;
const int BoolExpr_kind = 13;
const int OneExpr_kind = 14;
const int BinExpr_kind = 17;
const int IdExpr_kind = 33;
const int IdArrayExpr_kind = 34;
const int ArrayDec_kind = 35;
const int NextIntExpr_kind = 36;
const int ReadExpr_kind = 37;
const int PrintExpr_kind = 38;
const int FunctionCallExpr_kind = 39;
const int NotExpr_kind = 15;
const int NegExpr_kind = 16;
const int AddExpr_kind = 18;
const int SubExpr_kind = 19;
const int MulExpr_kind = 20;
const int DivExpr_kind = 21;
const int SRLExpr_kind = 22;
const int SLLExpr_kind = 23;
const int ModExpr_kind = 24;
const int LesExpr_kind = 25;
const int GreExpr_kind = 26;
const int LeEExpr_kind = 27;
const int GrEExpr_kind = 28;
const int EquExpr_kind = 29;
const int NEqExpr_kind = 30;
const int AndExpr_kind = 31;
const int Or_Expr_kind = 32;
const int WhileStmt_kind = 41;
const int ForStmt_kind = 42;
const int IfStmt_kind = 43;
const int AssignStmt_kind = 44;
const int PrintStmt_kind = 45;
const int ReadStmt_kind = 46;
const int NextIntStmt_kind = 47;
const int ReturnStmt_kind = 48;
const int ContinueStmt_kind = 49;
const int BreakStmt_kind = 50;
const int FunctionCallStmt_kind = 51;
const int VarDecStmt_kind = 52;
const int BlockStmt_kind = 53;

class ASTNode;
class Program;
class FnDec;
class stringNode;
class FieldDecStmt;
class FieldDecStmt_2;
class nodeList;
class FnParamsDec;
class Expression;
class Statement;
class NumExpr;
class StringConstantExpr;
class CharExpr;
class BoolExpr;
class OneExpr;
class BinExpr;
class IdExpr;
class IdArrayExpr;
class ArrayDec;
class NextIntExpr;
class ReadExpr;
class PrintExpr;
class FunctionCallExpr;
class NotExpr;
class NegExpr;
class AddExpr;
class SubExpr;
class MulExpr;
class DivExpr;
class SRLExpr;
class SLLExpr;
class ModExpr;
class LesExpr;
class GreExpr;
class LeEExpr;
class GrEExpr;
class EquExpr;
class NEqExpr;
class AndExpr;
class Or_Expr;
class WhileStmt;
class ForStmt;
class IfStmt;
class AssignStmt;
class PrintStmt;
class ReadStmt;
class NextIntStmt;
class ReturnStmt;
class ContinueStmt;
class BreakStmt;
class FunctionCallStmt;
class VarDecStmt;
class BlockStmt;

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
#line 151 "../src/ast.h"
private:

	static YYNODESTATE *state__;

public:

	static YYNODESTATE *getState()
		{
			if(state__) return state__;
			state__ = new YYNODESTATE();
			return state__;
		}

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

	void *operator new(size_t);
	void operator delete(void *, size_t);

protected:

	ASTNode();

public:

	string_t code;
	string_t place;

	virtual bool Func_Decl(IdentsHandler & identHandler);
	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ASTNode();

};

class Program : public ASTNode
{
public:

	Program(ASTNode * dec_list);

public:

	ASTNode * dec_list;

	virtual bool Func_Decl(IdentsHandler & identHandler);
	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Program();

};

class FnDec : public ASTNode
{
public:

	FnDec(string_t type, string_t name, ASTNode * params, Statement * block);

public:

	string_t type;
	string_t name;
	ASTNode * params;
	Statement * block;

	virtual bool Func_Decl(IdentsHandler & identHandler);
	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FnDec();

};

class stringNode : public ASTNode
{
public:

	stringNode(string_t id);

public:

	string_t id;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~stringNode();

};

class FieldDecStmt : public ASTNode
{
public:

	FieldDecStmt(string_t type, string_t id, Expression * value);

public:

	string_t type;
	string_t id;
	Expression * value;

	virtual bool Func_Decl(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FieldDecStmt();

};

class FieldDecStmt_2 : public ASTNode
{
public:

	FieldDecStmt_2(string_t type, ASTNode * list);

public:

	string_t type;
	ASTNode * list;

	virtual bool Func_Decl(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FieldDecStmt_2();

};

class nodeList : public ASTNode
{
public:

	nodeList(ASTNode * node, nodeList * next);

public:

	ASTNode * node;
	nodeList * next;
	nodeList * last;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~nodeList();

};

class FnParamsDec : public ASTNode
{
public:

	FnParamsDec(string_t type, string_t id);

public:

	string_t type;
	string_t id;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FnParamsDec();

};

class Expression : public ASTNode
{
protected:

	Expression();

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Expression();

};

class Statement : public ASTNode
{
protected:

	Statement();

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Statement();

};

class NumExpr : public Expression
{
public:

	NumExpr(int value);

public:

	int value;

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NumExpr();

};

class StringConstantExpr : public Expression
{
public:

	StringConstantExpr(string_t value);

public:

	string_t value;

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~StringConstantExpr();

};

class CharExpr : public Expression
{
public:

	CharExpr(int value);

public:

	int value;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~CharExpr();

};

class BoolExpr : public Expression
{
public:

	BoolExpr(bool value);

public:

	bool value;

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BoolExpr();

};

class OneExpr : public Expression
{
protected:

	OneExpr(Expression * expr);

public:

	Expression * expr;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~OneExpr();

};

class BinExpr : public Expression
{
protected:

	BinExpr(Expression * expr1, Expression * expr2);

public:

	Expression * expr1;
	Expression * expr2;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BinExpr();

};

class IdExpr : public Expression
{
public:

	IdExpr(string_t id);

public:

	string_t id;

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IdExpr();

};

class IdArrayExpr : public Expression
{
public:

	IdArrayExpr(string_t id, Expression * pos);

public:

	string_t id;
	Expression * pos;

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IdArrayExpr();

};

class ArrayDec : public Expression
{
public:

	ArrayDec(string_t id, int size);

public:

	string_t id;
	int size;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ArrayDec();

};

class NextIntExpr : public Expression
{
public:

	NextIntExpr(Expression * expr);

public:

	Expression * expr;

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NextIntExpr();

};

class ReadExpr : public Expression
{
public:

	ReadExpr();

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ReadExpr();

};

class PrintExpr : public Expression
{
public:

	PrintExpr(Expression * expr);

public:

	Expression * expr;

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~PrintExpr();

};

class FunctionCallExpr : public Expression
{
public:

	FunctionCallExpr(string_t id, ASTNode * param_list);

public:

	string_t id;
	ASTNode * param_list;

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FunctionCallExpr();

};

class NotExpr : public OneExpr
{
public:

	NotExpr(Expression * expr);

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NotExpr();

};

class NegExpr : public OneExpr
{
public:

	NegExpr(Expression * expr);

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NegExpr();

};

class AddExpr : public BinExpr
{
public:

	AddExpr(Expression * expr1, Expression * expr2);

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AddExpr();

};

class SubExpr : public BinExpr
{
public:

	SubExpr(Expression * expr1, Expression * expr2);

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~SubExpr();

};

class MulExpr : public BinExpr
{
public:

	MulExpr(Expression * expr1, Expression * expr2);

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~MulExpr();

};

class DivExpr : public BinExpr
{
public:

	DivExpr(Expression * expr1, Expression * expr2);

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~DivExpr();

};

class SRLExpr : public BinExpr
{
public:

	SRLExpr(Expression * expr1, Expression * expr2);

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~SRLExpr();

};

class SLLExpr : public BinExpr
{
public:

	SLLExpr(Expression * expr1, Expression * expr2);

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~SLLExpr();

};

class ModExpr : public BinExpr
{
public:

	ModExpr(Expression * expr1, Expression * expr2);

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ModExpr();

};

class LesExpr : public BinExpr
{
public:

	LesExpr(Expression * expr1, Expression * expr2);

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LesExpr();

};

class GreExpr : public BinExpr
{
public:

	GreExpr(Expression * expr1, Expression * expr2);

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~GreExpr();

};

class LeEExpr : public BinExpr
{
public:

	LeEExpr(Expression * expr1, Expression * expr2);

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~LeEExpr();

};

class GrEExpr : public BinExpr
{
public:

	GrEExpr(Expression * expr1, Expression * expr2);

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~GrEExpr();

};

class EquExpr : public BinExpr
{
public:

	EquExpr(Expression * expr1, Expression * expr2);

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~EquExpr();

};

class NEqExpr : public BinExpr
{
public:

	NEqExpr(Expression * expr1, Expression * expr2);

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NEqExpr();

};

class AndExpr : public BinExpr
{
public:

	AndExpr(Expression * expr1, Expression * expr2);

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AndExpr();

};

class Or_Expr : public BinExpr
{
public:

	Or_Expr(Expression * expr1, Expression * expr2);

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Or_Expr();

};

class WhileStmt : public Statement
{
public:

	WhileStmt(Expression * cond, Statement * block);

public:

	Expression * cond;
	Statement * block;

	virtual bool Func_Decl(IdentsHandler & identHandler);
	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~WhileStmt();

};

class ForStmt : public Statement
{
public:

	ForStmt(ASTNode * for_dec, Expression * cond, ASTNode * for_assign, Statement * block);

public:

	ASTNode * for_dec;
	Expression * cond;
	ASTNode * for_assign;
	Statement * block;

	virtual bool Func_Decl(IdentsHandler & identHandler);
	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ForStmt();

};

class IfStmt : public Statement
{
public:

	IfStmt(Expression * cond, Statement * true_block, Statement * false_block);

public:

	Expression * cond;
	Statement * true_block;
	Statement * false_block;

	virtual bool Func_Decl(IdentsHandler & identHandler);
	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~IfStmt();

};

class AssignStmt : public Statement
{
public:

	AssignStmt(Expression * lhs, Expression * rhs);

public:

	Expression * lhs;
	Expression * rhs;

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AssignStmt();

};

class PrintStmt : public Statement
{
public:

	PrintStmt(Expression * expr, bool flag);

public:

	Expression * expr;
	bool flag;

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~PrintStmt();

};

class ReadStmt : public Statement
{
public:

	ReadStmt();

public:

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ReadStmt();

};

class NextIntStmt : public Statement
{
public:

	NextIntStmt(Expression * expr);

public:

	Expression * expr;

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NextIntStmt();

};

class ReturnStmt : public Statement
{
public:

	ReturnStmt(Expression * expr);

public:

	Expression * expr;
	string_t label;

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ReturnStmt();

};

class ContinueStmt : public Statement
{
public:

	ContinueStmt();

public:

	string_t label;

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ContinueStmt();

};

class BreakStmt : public Statement
{
public:

	BreakStmt();

public:

	string_t label;

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BreakStmt();

};

class FunctionCallStmt : public Statement
{
public:

	FunctionCallStmt(string_t id, ASTNode * param_list);

public:

	string_t id;
	ASTNode * param_list;

	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FunctionCallStmt();

};

class VarDecStmt : public Statement
{
public:

	VarDecStmt(string_t type, ASTNode * list);

public:

	string_t type;
	ASTNode * list;

	virtual bool Func_Decl(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~VarDecStmt();

};

class BlockStmt : public Statement
{
public:

	BlockStmt(ASTNode * stmt_list);

public:

	ASTNode * stmt_list;

	virtual bool Func_Decl(IdentsHandler & identHandler);
	virtual bool gen_Code(IdentsHandler & identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BlockStmt();

};



#endif
