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

    using StmtList = std::vector<Statement*>;
    using ExprList = std::vector<Expression*>;
    using stringList = std::vector<std::string>;
    using intList = std::vector<int>;
    
    using string_t = std::string;

#line 30 "../src/ast.h"

#include <new>

const int ASTNode_kind = 1;
const int Expression_kind = 2;
const int OneExpr_kind = 3;
const int NumExpr_kind = 6;
const int StringConstant_kind = 7;
const int CharExpr_kind = 8;
const int BinExpr_kind = 9;
const int NotExpr_kind = 4;
const int NegExpr_kind = 5;
const int AddExpr_kind = 10;
const int SubExpr_kind = 11;
const int MulExpr_kind = 12;
const int DivExpr_kind = 13;
const int SRLExpr_kind = 14;
const int SLLExpr_kind = 15;
const int ModExpr_kind = 16;
const int LesExpr_kind = 17;
const int GreExpr_kind = 18;
const int LeEExpr_kind = 19;
const int GrEExpr_kind = 20;
const int EquExpr_kind = 21;
const int NEqExpr_kind = 22;
const int AndExpr_kind = 23;
const int Or_Expr_kind = 24;

class ASTNode;
class Expression;
class OneExpr;
class NumExpr;
class StringConstant;
class CharExpr;
class BinExpr;
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
#line 97 "../src/ast.h"
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

	virtual bool genCode(IdentsHandler identHandler) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~ASTNode();

};

class Expression : public ASTNode
{
protected:

	Expression();

public:

	virtual bool genCode(IdentsHandler identHandler) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Expression();

};

class OneExpr : public Expression
{
protected:

	OneExpr(Expression * expr);

public:

	Expression * expr;

	virtual bool genCode(IdentsHandler identHandler) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~OneExpr();

};

class NumExpr : public Expression
{
public:

	NumExpr(int value);

public:

	int value;

	virtual bool genCode(IdentsHandler identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~NumExpr();

};

class StringConstant : public Expression
{
public:

	StringConstant(string_t value);

public:

	string_t value;

	virtual bool genCode(IdentsHandler identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~StringConstant();

};

class CharExpr : public Expression
{
public:

	CharExpr(int value);

public:

	int value;

	virtual bool genCode(IdentsHandler identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~CharExpr();

};

class BinExpr : public Expression
{
protected:

	BinExpr(Expression * expr1, Expression * expr2);

public:

	Expression * expr1;
	Expression * expr2;

	virtual bool genCode(IdentsHandler identHandler) = 0;

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BinExpr();

};

class NotExpr : public OneExpr
{
public:

	NotExpr(Expression * expr);

public:

	virtual bool genCode(IdentsHandler identHandler);

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

	virtual bool genCode(IdentsHandler identHandler);

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

	virtual bool genCode(IdentsHandler identHandler);

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

	virtual bool genCode(IdentsHandler identHandler);

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

	virtual bool genCode(IdentsHandler identHandler);

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

	virtual bool genCode(IdentsHandler identHandler);

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

	virtual bool genCode(IdentsHandler identHandler);

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

	virtual bool genCode(IdentsHandler identHandler);

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

	virtual bool genCode(IdentsHandler identHandler);

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

	virtual bool genCode(IdentsHandler identHandler);

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

	virtual bool genCode(IdentsHandler identHandler);

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

	virtual bool genCode(IdentsHandler identHandler);

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

	virtual bool genCode(IdentsHandler identHandler);

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

	virtual bool genCode(IdentsHandler identHandler);

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

	virtual bool genCode(IdentsHandler identHandler);

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

	virtual bool genCode(IdentsHandler identHandler);

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

	virtual bool genCode(IdentsHandler identHandler);

	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Or_Expr();

};



#endif
