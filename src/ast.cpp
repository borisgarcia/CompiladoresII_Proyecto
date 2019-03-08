/* ../src/ast.cpp.  Generated automatically by treecc */
#line 22 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"

    #include "ast.h"
    using namespace std;

    struct Context{
        string_t id;
        int_t value;
    };
    std::unordered_map<string_t,Context> vars;
    bool method_dec_boolean;
    bool state_ment_boolean;
#line 15 "../src/ast.cpp"

#define YYNODESTATE_REENTRANT 1
#define YYNODESTATE_TRACK_LINES 1
#define YYNODESTATE_USE_ALLOCATOR 1
#line 1 "cpp_skel.cc"
/*
 * treecc node allocation routines for C++.
 *
 * Copyright (C) 2001  Southern Storm Software, Pty Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * As a special exception, when this file is copied by treecc into
 * a treecc output file, you may use that output file without restriction.
 */

#ifndef YYNODESTATE_BLKSIZ
#define	YYNODESTATE_BLKSIZ	2048
#endif

/*
 * Types used by the allocation routines.
 */
struct YYNODESTATE_block
{
	char data__[YYNODESTATE_BLKSIZ];
	struct YYNODESTATE_block *next__;

};
struct YYNODESTATE_push
{
	struct YYNODESTATE_push *next__;
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
};

/*
 * Initialize the singleton instance.
 */
#ifndef YYNODESTATE_REENTRANT
YYNODESTATE *YYNODESTATE::state__ = 0;
#endif

/*
 * Some macro magic to determine the default alignment
 * on this machine.  This will compile down to a constant.
 */
#define	YYNODESTATE_ALIGN_CHECK_TYPE(type,name)	\
	struct _YYNODESTATE_align_##name { \
		char pad; \
		type field; \
	}
#define	YYNODESTATE_ALIGN_FOR_TYPE(type)	\
	((unsigned)(unsigned long)(&(((struct _YYNODESTATE_align_##type *)0)->field)))
#define	YYNODESTATE_ALIGN_MAX(a,b)	\
	((a) > (b) ? (a) : (b))
#define	YYNODESTATE_ALIGN_MAX3(a,b,c) \
	(YYNODESTATE_ALIGN_MAX((a), YYNODESTATE_ALIGN_MAX((b), (c))))
YYNODESTATE_ALIGN_CHECK_TYPE(int, int);
YYNODESTATE_ALIGN_CHECK_TYPE(long, long);
#if defined(WIN32) && !defined(__CYGWIN__)
YYNODESTATE_ALIGN_CHECK_TYPE(__int64, long_long);
#else
YYNODESTATE_ALIGN_CHECK_TYPE(long long, long_long);
#endif
YYNODESTATE_ALIGN_CHECK_TYPE(void *, void_p);
YYNODESTATE_ALIGN_CHECK_TYPE(float, float);
YYNODESTATE_ALIGN_CHECK_TYPE(double, double);
#define	YYNODESTATE_ALIGNMENT	\
	YYNODESTATE_ALIGN_MAX( \
			YYNODESTATE_ALIGN_MAX3	\
			(YYNODESTATE_ALIGN_FOR_TYPE(int), \
		     YYNODESTATE_ALIGN_FOR_TYPE(long), \
			 YYNODESTATE_ALIGN_FOR_TYPE(long_long)), \
  	     YYNODESTATE_ALIGN_MAX3 \
		 	(YYNODESTATE_ALIGN_FOR_TYPE(void_p), \
			 YYNODESTATE_ALIGN_FOR_TYPE(float), \
			 YYNODESTATE_ALIGN_FOR_TYPE(double)))

/*
 * Constructor for YYNODESTATE.
 */
YYNODESTATE::YYNODESTATE()
{
	/* Initialize the allocation state */
	blocks__ = 0;
	push_stack__ = 0;
	used__ = 0;

#ifndef YYNODESTATE_REENTRANT
	/* Register this object as the singleton instance */
	if(!state__)
	{
		state__ = this;
	}
#endif
}

/*
 * Destructor for YYNODESTATE.
 */
YYNODESTATE::~YYNODESTATE()
{
	/* Free all node memory */
	clear();

#ifndef YYNODESTATE_REENTRANT
	/* We are no longer the singleton instance */
	if(state__ == this)
	{
		state__ = 0;
	}
#endif
}

#ifdef YYNODESTATE_USE_ALLOCATOR

/*
 * Allocate a block of memory.
 */
void *YYNODESTATE::alloc(size_t size__)
{
	struct YYNODESTATE_block *block__;
	void *result__;

	/* Round the size to the next alignment boundary */
	size__ = (size__ + YYNODESTATE_ALIGNMENT - 1) &
				~(YYNODESTATE_ALIGNMENT - 1);

	/* Do we need to allocate a new block? */
	block__ = blocks__;
	if(!block__ || (used__ + size__) > YYNODESTATE_BLKSIZ)
	{
		if(size__ > YYNODESTATE_BLKSIZ)
		{
			/* The allocation is too big for the node pool */
			return (void *)0;
		}
		block__ = new YYNODESTATE_block;
		if(!block__)
		{
			/* The system is out of memory.  The programmer can
			   inherit the "failed" method to report the
			   out of memory state and/or abort the program */
			failed();
			return (void *)0;
		}
		block__->next__ = blocks__;
		blocks__ = block__;
		used__ = 0;
	}

	/* Allocate the memory and return it */
	result__ = (void *)(block__->data__ + used__);
	used__ += size__;
	return result__;
}

/*
 * Deallocate a block of memory.
 */
void YYNODESTATE::dealloc(void *ptr__, size_t size__)
{
	/* Nothing to do for this type of node allocator */
}

/*
 * Push the node allocation state.
 */
int YYNODESTATE::push()
{
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
	struct YYNODESTATE_push *push_item__;

	/* Save the current state of the node allocation pool */
	saved_block__ = blocks__;
	saved_used__ = used__;

	/* Allocate space for a push item */
	push_item__ = (struct YYNODESTATE_push *)
			alloc(sizeof(struct YYNODESTATE_push));
	if(!push_item__)
	{
		return 0;
	}

	/* Copy the saved information to the push item */
	push_item__->saved_block__ = saved_block__;
	push_item__->saved_used__ = saved_used__;

	/* Add the push item to the push stack */
	push_item__->next__ = push_stack__;
	push_stack__ = push_item__;
	return 1;
}

/*
 * Pop the node allocation state.
 */
void YYNODESTATE::pop()
{
	struct YYNODESTATE_push *push_item__;
	struct YYNODESTATE_block *saved_block__;
	struct YYNODESTATE_block *temp_block__;

	/* Pop the top of the push stack */
	push_item__ = push_stack__;
	if(push_item__ == 0)
	{
		saved_block__ = 0;
		used__ = 0;
	}
	else
	{
		saved_block__ = push_item__->saved_block__;
		used__ = push_item__->saved_used__;
		push_stack__ = push_item__->next__;
	}

	/* Free unnecessary blocks */
	while(blocks__ != saved_block__)
	{
		temp_block__ = blocks__;
		blocks__ = temp_block__->next__;
		delete temp_block__;
	}
}

/*
 * Clear the node allocation pool completely.
 */
void YYNODESTATE::clear()
{
	struct YYNODESTATE_block *temp_block__;
	while(blocks__ != 0)
	{
		temp_block__ = blocks__;
		blocks__ = temp_block__->next__;
		delete temp_block__;
	}
	push_stack__ = 0;
	used__ = 0;
}

#endif /* YYNODESTATE_USE_ALLOCATOR */

/*
 * Default implementation of functions which may be overridden.
 */
void YYNODESTATE::failed()
{
}

#ifdef YYNODESTATE_TRACK_LINES

char *YYNODESTATE::currFilename()
{
	return (char *)0;
}

long YYNODESTATE::currLinenum()
{
	return 0;
}

#endif
#line 295 "../src/ast.cpp"
NumExpr *YYNODESTATE::NumExprCreate(int num)
{
	void *buf__ = this->alloc(sizeof(NumExpr));
	if(buf__ == 0) return 0;
	return new (buf__) NumExpr(this, num);
}

NextIntExpr *YYNODESTATE::NextIntExprCreate(Expression * expr)
{
	void *buf__ = this->alloc(sizeof(NextIntExpr));
	if(buf__ == 0) return 0;
	return new (buf__) NextIntExpr(this, expr);
}

ReadExpr *YYNODESTATE::ReadExprCreate()
{
	void *buf__ = this->alloc(sizeof(ReadExpr));
	if(buf__ == 0) return 0;
	return new (buf__) ReadExpr(this);
}

PrintExpr *YYNODESTATE::PrintExprCreate(Expression * expr)
{
	void *buf__ = this->alloc(sizeof(PrintExpr));
	if(buf__ == 0) return 0;
	return new (buf__) PrintExpr(this, expr);
}

FunctionCallExpr *YYNODESTATE::FunctionCallExprCreate(string_t * id, Expression * expr)
{
	void *buf__ = this->alloc(sizeof(FunctionCallExpr));
	if(buf__ == 0) return 0;
	return new (buf__) FunctionCallExpr(this, id, expr);
}

IdExpr *YYNODESTATE::IdExprCreate(string_t id)
{
	void *buf__ = this->alloc(sizeof(IdExpr));
	if(buf__ == 0) return 0;
	return new (buf__) IdExpr(this, id);
}

IdArrayExpr *YYNODESTATE::IdArrayExprCreate(string_t id, int_t pos)
{
	void *buf__ = this->alloc(sizeof(IdArrayExpr));
	if(buf__ == 0) return 0;
	return new (buf__) IdArrayExpr(this, id, pos);
}

NotExpr *YYNODESTATE::NotExprCreate(Expression * expr1)
{
	void *buf__ = this->alloc(sizeof(NotExpr));
	if(buf__ == 0) return 0;
	return new (buf__) NotExpr(this, expr1);
}

UnaExpr *YYNODESTATE::UnaExprCreate(Expression * expr1)
{
	void *buf__ = this->alloc(sizeof(UnaExpr));
	if(buf__ == 0) return 0;
	return new (buf__) UnaExpr(this, expr1);
}

AddExpr *YYNODESTATE::AddExprCreate(Expression * expr1, Expression * expr2)
{
	void *buf__ = this->alloc(sizeof(AddExpr));
	if(buf__ == 0) return 0;
	return new (buf__) AddExpr(this, expr1, expr2);
}

SubExpr *YYNODESTATE::SubExprCreate(Expression * expr1, Expression * expr2)
{
	void *buf__ = this->alloc(sizeof(SubExpr));
	if(buf__ == 0) return 0;
	return new (buf__) SubExpr(this, expr1, expr2);
}

MulExpr *YYNODESTATE::MulExprCreate(Expression * expr1, Expression * expr2)
{
	void *buf__ = this->alloc(sizeof(MulExpr));
	if(buf__ == 0) return 0;
	return new (buf__) MulExpr(this, expr1, expr2);
}

DivExpr *YYNODESTATE::DivExprCreate(Expression * expr1, Expression * expr2)
{
	void *buf__ = this->alloc(sizeof(DivExpr));
	if(buf__ == 0) return 0;
	return new (buf__) DivExpr(this, expr1, expr2);
}

SRLExpr *YYNODESTATE::SRLExprCreate(Expression * expr1, Expression * expr2)
{
	void *buf__ = this->alloc(sizeof(SRLExpr));
	if(buf__ == 0) return 0;
	return new (buf__) SRLExpr(this, expr1, expr2);
}

SLLExpr *YYNODESTATE::SLLExprCreate(Expression * expr1, Expression * expr2)
{
	void *buf__ = this->alloc(sizeof(SLLExpr));
	if(buf__ == 0) return 0;
	return new (buf__) SLLExpr(this, expr1, expr2);
}

ModExpr *YYNODESTATE::ModExprCreate(Expression * expr1, Expression * expr2)
{
	void *buf__ = this->alloc(sizeof(ModExpr));
	if(buf__ == 0) return 0;
	return new (buf__) ModExpr(this, expr1, expr2);
}

LesExpr *YYNODESTATE::LesExprCreate(Expression * expr1, Expression * expr2)
{
	void *buf__ = this->alloc(sizeof(LesExpr));
	if(buf__ == 0) return 0;
	return new (buf__) LesExpr(this, expr1, expr2);
}

GreExpr *YYNODESTATE::GreExprCreate(Expression * expr1, Expression * expr2)
{
	void *buf__ = this->alloc(sizeof(GreExpr));
	if(buf__ == 0) return 0;
	return new (buf__) GreExpr(this, expr1, expr2);
}

LeTExpr *YYNODESTATE::LeTExprCreate(Expression * expr1, Expression * expr2)
{
	void *buf__ = this->alloc(sizeof(LeTExpr));
	if(buf__ == 0) return 0;
	return new (buf__) LeTExpr(this, expr1, expr2);
}

GrTExpr *YYNODESTATE::GrTExprCreate(Expression * expr1, Expression * expr2)
{
	void *buf__ = this->alloc(sizeof(GrTExpr));
	if(buf__ == 0) return 0;
	return new (buf__) GrTExpr(this, expr1, expr2);
}

EquExpr *YYNODESTATE::EquExprCreate(Expression * expr1, Expression * expr2)
{
	void *buf__ = this->alloc(sizeof(EquExpr));
	if(buf__ == 0) return 0;
	return new (buf__) EquExpr(this, expr1, expr2);
}

NEqExpr *YYNODESTATE::NEqExprCreate(Expression * expr1, Expression * expr2)
{
	void *buf__ = this->alloc(sizeof(NEqExpr));
	if(buf__ == 0) return 0;
	return new (buf__) NEqExpr(this, expr1, expr2);
}

AndExpr *YYNODESTATE::AndExprCreate(Expression * expr1, Expression * expr2)
{
	void *buf__ = this->alloc(sizeof(AndExpr));
	if(buf__ == 0) return 0;
	return new (buf__) AndExpr(this, expr1, expr2);
}

Or_Expr *YYNODESTATE::Or_ExprCreate(Expression * expr1, Expression * expr2)
{
	void *buf__ = this->alloc(sizeof(Or_Expr));
	if(buf__ == 0) return 0;
	return new (buf__) Or_Expr(this, expr1, expr2);
}

MultipleExpr *YYNODESTATE::MultipleExprCreate(ExprList listaExprs)
{
	void *buf__ = this->alloc(sizeof(MultipleExpr));
	if(buf__ == 0) return 0;
	return new (buf__) MultipleExpr(this, listaExprs);
}

FieldDecStmt *YYNODESTATE::FieldDecStmtCreate(string_t type, stringList lista)
{
	void *buf__ = this->alloc(sizeof(FieldDecStmt));
	if(buf__ == 0) return 0;
	return new (buf__) FieldDecStmt(this, type, lista);
}

PrintLNStmt *YYNODESTATE::PrintLNStmtCreate(Expression * expr)
{
	void *buf__ = this->alloc(sizeof(PrintLNStmt));
	if(buf__ == 0) return 0;
	return new (buf__) PrintLNStmt(this, expr);
}

PrintStmt *YYNODESTATE::PrintStmtCreate(Expression * expr)
{
	void *buf__ = this->alloc(sizeof(PrintStmt));
	if(buf__ == 0) return 0;
	return new (buf__) PrintStmt(this, expr);
}

ReadStmt *YYNODESTATE::ReadStmtCreate()
{
	void *buf__ = this->alloc(sizeof(ReadStmt));
	if(buf__ == 0) return 0;
	return new (buf__) ReadStmt(this);
}

NextIntStmt *YYNODESTATE::NextIntStmtCreate(Expression * expr)
{
	void *buf__ = this->alloc(sizeof(NextIntStmt));
	if(buf__ == 0) return 0;
	return new (buf__) NextIntStmt(this, expr);
}

FunctionCallStmt *YYNODESTATE::FunctionCallStmtCreate(string_t id, Expression * expr)
{
	void *buf__ = this->alloc(sizeof(FunctionCallStmt));
	if(buf__ == 0) return 0;
	return new (buf__) FunctionCallStmt(this, id, expr);
}

AssignStmt *YYNODESTATE::AssignStmtCreate(string_t id, Expression * expr)
{
	void *buf__ = this->alloc(sizeof(AssignStmt));
	if(buf__ == 0) return 0;
	return new (buf__) AssignStmt(this, id, expr);
}

ForStmt *YYNODESTATE::ForStmtCreate(Statement * for_dec, Expression * cond, Statement * for_assign, Statement * block)
{
	void *buf__ = this->alloc(sizeof(ForStmt));
	if(buf__ == 0) return 0;
	return new (buf__) ForStmt(this, for_dec, cond, for_assign, block);
}

BlockStmt *YYNODESTATE::BlockStmtCreate(StmtList list)
{
	void *buf__ = this->alloc(sizeof(BlockStmt));
	if(buf__ == 0) return 0;
	return new (buf__) BlockStmt(this, list);
}

IfStmt *YYNODESTATE::IfStmtCreate(Expression * cond, Statement * true_block, Statement * false_block)
{
	void *buf__ = this->alloc(sizeof(IfStmt));
	if(buf__ == 0) return 0;
	return new (buf__) IfStmt(this, cond, true_block, false_block);
}

WhileStmt *YYNODESTATE::WhileStmtCreate(Expression * cond, Statement * block)
{
	void *buf__ = this->alloc(sizeof(WhileStmt));
	if(buf__ == 0) return 0;
	return new (buf__) WhileStmt(this, cond, block);
}

ReturnStmt *YYNODESTATE::ReturnStmtCreate(Expression * expr)
{
	void *buf__ = this->alloc(sizeof(ReturnStmt));
	if(buf__ == 0) return 0;
	return new (buf__) ReturnStmt(this, expr);
}

BreakStmt *YYNODESTATE::BreakStmtCreate()
{
	void *buf__ = this->alloc(sizeof(BreakStmt));
	if(buf__ == 0) return 0;
	return new (buf__) BreakStmt(this);
}

ContinueStmt *YYNODESTATE::ContinueStmtCreate()
{
	void *buf__ = this->alloc(sizeof(ContinueStmt));
	if(buf__ == 0) return 0;
	return new (buf__) ContinueStmt(this);
}

ASTNode::ASTNode(YYNODESTATE *state__)
{
	this->kind__ = ASTNode_kind;
	this->filename__ = state__->currFilename();
	this->linenum__ = state__->currLinenum();
}

ASTNode::~ASTNode()
{
	// not used
}

int ASTNode::isA(int kind) const
{
	if(kind == ASTNode_kind)
		return 1;
	else
		return 0;
}

const char *ASTNode::getKindName() const
{
	return "ASTNode";
}

Expression::Expression(YYNODESTATE *state__)
	: ASTNode(state__)
{
	this->kind__ = Expression_kind;
}

Expression::~Expression()
{
	// not used
}

int Expression::isA(int kind) const
{
	if(kind == Expression_kind)
		return 1;
	else
		return ASTNode::isA(kind);
}

const char *Expression::getKindName() const
{
	return "Expression";
}

Statement::Statement(YYNODESTATE *state__)
	: ASTNode(state__)
{
	this->kind__ = Statement_kind;
}

Statement::~Statement()
{
	// not used
}

int Statement::isA(int kind) const
{
	if(kind == Statement_kind)
		return 1;
	else
		return ASTNode::isA(kind);
}

const char *Statement::getKindName() const
{
	return "Statement";
}

OneExpr::OneExpr(YYNODESTATE *state__, Expression * expr1)
	: Expression(state__)
{
	this->kind__ = OneExpr_kind;
	this->expr1 = expr1;
}

OneExpr::~OneExpr()
{
	// not used
}

int OneExpr::isA(int kind) const
{
	if(kind == OneExpr_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *OneExpr::getKindName() const
{
	return "OneExpr";
}

NumExpr::NumExpr(YYNODESTATE *state__, int num)
	: Expression(state__)
{
	this->kind__ = NumExpr_kind;
	this->num = num;
}

NumExpr::~NumExpr()
{
	// not used
}

int NumExpr::eval()
#line 54 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{
    return num;
}
#line 684 "../src/ast.cpp"

int NumExpr::isA(int kind) const
{
	if(kind == NumExpr_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *NumExpr::getKindName() const
{
	return "NumExpr";
}

NextIntExpr::NextIntExpr(YYNODESTATE *state__, Expression * expr)
	: Expression(state__)
{
	this->kind__ = NextIntExpr_kind;
	this->expr = expr;
}

NextIntExpr::~NextIntExpr()
{
	// not used
}

int NextIntExpr::eval()
#line 63 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{
    return rand() % expr->eval();
}
#line 716 "../src/ast.cpp"

int NextIntExpr::isA(int kind) const
{
	if(kind == NextIntExpr_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *NextIntExpr::getKindName() const
{
	return "NextIntExpr";
}

ReadExpr::ReadExpr(YYNODESTATE *state__)
	: Expression(state__)
{
	this->kind__ = ReadExpr_kind;
}

ReadExpr::~ReadExpr()
{
	// not used
}

int ReadExpr::eval()
#line 69 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{
    int_t a;
    cin>>a;
    return a;
}
#line 749 "../src/ast.cpp"

int ReadExpr::isA(int kind) const
{
	if(kind == ReadExpr_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *ReadExpr::getKindName() const
{
	return "ReadExpr";
}

PrintExpr::PrintExpr(YYNODESTATE *state__, Expression * expr)
	: Expression(state__)
{
	this->kind__ = PrintExpr_kind;
	this->expr = expr;
}

PrintExpr::~PrintExpr()
{
	// not used
}

int PrintExpr::eval()
#line 80 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{
    std::cerr << getFilename() << ":" << getLinenum() <<": error: assigning a void expression" << endl;
    exit(0);
}
#line 782 "../src/ast.cpp"

int PrintExpr::isA(int kind) const
{
	if(kind == PrintExpr_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *PrintExpr::getKindName() const
{
	return "PrintExpr";
}

FunctionCallExpr::FunctionCallExpr(YYNODESTATE *state__, string_t * id, Expression * expr)
	: Expression(state__)
{
	this->kind__ = FunctionCallExpr_kind;
	this->id = id;
	this->expr = expr;
}

FunctionCallExpr::~FunctionCallExpr()
{
	// not used
}

int FunctionCallExpr::eval()
#line 91 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{
    return 0;
}
#line 815 "../src/ast.cpp"

int FunctionCallExpr::isA(int kind) const
{
	if(kind == FunctionCallExpr_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *FunctionCallExpr::getKindName() const
{
	return "FunctionCallExpr";
}

IdExpr::IdExpr(YYNODESTATE *state__, string_t id)
	: Expression(state__)
{
	this->kind__ = IdExpr_kind;
	this->id = id;
}

IdExpr::~IdExpr()
{
	// not used
}

int IdExpr::eval()
#line 100 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{
    /*if(vars.find(id) != vars.end())
        return vars[id];
    else
    {
        std::cerr << "Id: "<<id<<" no Existe" << endl;
        exit(0);
    } */
    return 0;
}
#line 854 "../src/ast.cpp"

int IdExpr::isA(int kind) const
{
	if(kind == IdExpr_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *IdExpr::getKindName() const
{
	return "IdExpr";
}

IdArrayExpr::IdArrayExpr(YYNODESTATE *state__, string_t id, int_t pos)
	: Expression(state__)
{
	this->kind__ = IdArrayExpr_kind;
	this->id = id;
	this->pos = pos;
}

IdArrayExpr::~IdArrayExpr()
{
	// not used
}

int IdArrayExpr::eval()
#line 117 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{
    return 0;
}
#line 887 "../src/ast.cpp"

int IdArrayExpr::isA(int kind) const
{
	if(kind == IdArrayExpr_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *IdArrayExpr::getKindName() const
{
	return "IdArrayExpr";
}

BinExpr::BinExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2)
	: Expression(state__)
{
	this->kind__ = BinExpr_kind;
	this->expr1 = expr1;
	this->expr2 = expr2;
}

BinExpr::~BinExpr()
{
	// not used
}

int BinExpr::isA(int kind) const
{
	if(kind == BinExpr_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *BinExpr::getKindName() const
{
	return "BinExpr";
}

NotExpr::NotExpr(YYNODESTATE *state__, Expression * expr1)
	: OneExpr(state__, expr1)
{
	this->kind__ = NotExpr_kind;
}

NotExpr::~NotExpr()
{
	// not used
}

int NotExpr::eval()
#line 46 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ return !expr1->eval();}
#line 942 "../src/ast.cpp"

int NotExpr::isA(int kind) const
{
	if(kind == NotExpr_kind)
		return 1;
	else
		return OneExpr::isA(kind);
}

const char *NotExpr::getKindName() const
{
	return "NotExpr";
}

UnaExpr::UnaExpr(YYNODESTATE *state__, Expression * expr1)
	: OneExpr(state__, expr1)
{
	this->kind__ = UnaExpr_kind;
}

UnaExpr::~UnaExpr()
{
	// not used
}

int UnaExpr::eval()
#line 47 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ return -expr1->eval();}
#line 971 "../src/ast.cpp"

int UnaExpr::isA(int kind) const
{
	if(kind == UnaExpr_kind)
		return 1;
	else
		return OneExpr::isA(kind);
}

const char *UnaExpr::getKindName() const
{
	return "UnaExpr";
}

AddExpr::AddExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2)
	: BinExpr(state__, expr1, expr2)
{
	this->kind__ = AddExpr_kind;
}

AddExpr::~AddExpr()
{
	// not used
}

int AddExpr::eval()
#line 145 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ return expr1->eval() + expr2->eval();  }
#line 1000 "../src/ast.cpp"

int AddExpr::isA(int kind) const
{
	if(kind == AddExpr_kind)
		return 1;
	else
		return BinExpr::isA(kind);
}

const char *AddExpr::getKindName() const
{
	return "AddExpr";
}

SubExpr::SubExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2)
	: BinExpr(state__, expr1, expr2)
{
	this->kind__ = SubExpr_kind;
}

SubExpr::~SubExpr()
{
	// not used
}

int SubExpr::eval()
#line 146 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ return expr1->eval() - expr2->eval();  }
#line 1029 "../src/ast.cpp"

int SubExpr::isA(int kind) const
{
	if(kind == SubExpr_kind)
		return 1;
	else
		return BinExpr::isA(kind);
}

const char *SubExpr::getKindName() const
{
	return "SubExpr";
}

MulExpr::MulExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2)
	: BinExpr(state__, expr1, expr2)
{
	this->kind__ = MulExpr_kind;
}

MulExpr::~MulExpr()
{
	// not used
}

int MulExpr::eval()
#line 147 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ return expr1->eval() * expr2->eval();  }
#line 1058 "../src/ast.cpp"

int MulExpr::isA(int kind) const
{
	if(kind == MulExpr_kind)
		return 1;
	else
		return BinExpr::isA(kind);
}

const char *MulExpr::getKindName() const
{
	return "MulExpr";
}

DivExpr::DivExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2)
	: BinExpr(state__, expr1, expr2)
{
	this->kind__ = DivExpr_kind;
}

DivExpr::~DivExpr()
{
	// not used
}

int DivExpr::eval()
#line 149 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{
    if(expr2->eval() != 0)
        return expr1->eval() / expr2->eval();
    else
    {
        std::cerr << getFilename() << ":" << getLinenum() <<": division by zero" << endl;
        return 0;
    }	
}
#line 1095 "../src/ast.cpp"

int DivExpr::isA(int kind) const
{
	if(kind == DivExpr_kind)
		return 1;
	else
		return BinExpr::isA(kind);
}

const char *DivExpr::getKindName() const
{
	return "DivExpr";
}

SRLExpr::SRLExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2)
	: BinExpr(state__, expr1, expr2)
{
	this->kind__ = SRLExpr_kind;
}

SRLExpr::~SRLExpr()
{
	// not used
}

int SRLExpr::eval()
#line 158 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ return expr1->eval() >> expr2->eval(); }
#line 1124 "../src/ast.cpp"

int SRLExpr::isA(int kind) const
{
	if(kind == SRLExpr_kind)
		return 1;
	else
		return BinExpr::isA(kind);
}

const char *SRLExpr::getKindName() const
{
	return "SRLExpr";
}

SLLExpr::SLLExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2)
	: BinExpr(state__, expr1, expr2)
{
	this->kind__ = SLLExpr_kind;
}

SLLExpr::~SLLExpr()
{
	// not used
}

int SLLExpr::eval()
#line 159 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ return expr1->eval() << expr2->eval(); }
#line 1153 "../src/ast.cpp"

int SLLExpr::isA(int kind) const
{
	if(kind == SLLExpr_kind)
		return 1;
	else
		return BinExpr::isA(kind);
}

const char *SLLExpr::getKindName() const
{
	return "SLLExpr";
}

ModExpr::ModExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2)
	: BinExpr(state__, expr1, expr2)
{
	this->kind__ = ModExpr_kind;
}

ModExpr::~ModExpr()
{
	// not used
}

int ModExpr::eval()
#line 160 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ return expr1->eval() &  expr2->eval(); }
#line 1182 "../src/ast.cpp"

int ModExpr::isA(int kind) const
{
	if(kind == ModExpr_kind)
		return 1;
	else
		return BinExpr::isA(kind);
}

const char *ModExpr::getKindName() const
{
	return "ModExpr";
}

LesExpr::LesExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2)
	: BinExpr(state__, expr1, expr2)
{
	this->kind__ = LesExpr_kind;
}

LesExpr::~LesExpr()
{
	// not used
}

int LesExpr::eval()
#line 162 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ return expr1->eval() <  expr2->eval(); }
#line 1211 "../src/ast.cpp"

int LesExpr::isA(int kind) const
{
	if(kind == LesExpr_kind)
		return 1;
	else
		return BinExpr::isA(kind);
}

const char *LesExpr::getKindName() const
{
	return "LesExpr";
}

GreExpr::GreExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2)
	: BinExpr(state__, expr1, expr2)
{
	this->kind__ = GreExpr_kind;
}

GreExpr::~GreExpr()
{
	// not used
}

int GreExpr::eval()
#line 161 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ return expr1->eval() >  expr2->eval(); }
#line 1240 "../src/ast.cpp"

int GreExpr::isA(int kind) const
{
	if(kind == GreExpr_kind)
		return 1;
	else
		return BinExpr::isA(kind);
}

const char *GreExpr::getKindName() const
{
	return "GreExpr";
}

LeTExpr::LeTExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2)
	: BinExpr(state__, expr1, expr2)
{
	this->kind__ = LeTExpr_kind;
}

LeTExpr::~LeTExpr()
{
	// not used
}

int LeTExpr::eval()
#line 163 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ return expr1->eval() <= expr2->eval(); }
#line 1269 "../src/ast.cpp"

int LeTExpr::isA(int kind) const
{
	if(kind == LeTExpr_kind)
		return 1;
	else
		return BinExpr::isA(kind);
}

const char *LeTExpr::getKindName() const
{
	return "LeTExpr";
}

GrTExpr::GrTExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2)
	: BinExpr(state__, expr1, expr2)
{
	this->kind__ = GrTExpr_kind;
}

GrTExpr::~GrTExpr()
{
	// not used
}

int GrTExpr::eval()
#line 164 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ return expr1->eval() >= expr2->eval(); }
#line 1298 "../src/ast.cpp"

int GrTExpr::isA(int kind) const
{
	if(kind == GrTExpr_kind)
		return 1;
	else
		return BinExpr::isA(kind);
}

const char *GrTExpr::getKindName() const
{
	return "GrTExpr";
}

EquExpr::EquExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2)
	: BinExpr(state__, expr1, expr2)
{
	this->kind__ = EquExpr_kind;
}

EquExpr::~EquExpr()
{
	// not used
}

int EquExpr::eval()
#line 165 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ return expr1->eval() == expr2->eval(); }
#line 1327 "../src/ast.cpp"

int EquExpr::isA(int kind) const
{
	if(kind == EquExpr_kind)
		return 1;
	else
		return BinExpr::isA(kind);
}

const char *EquExpr::getKindName() const
{
	return "EquExpr";
}

NEqExpr::NEqExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2)
	: BinExpr(state__, expr1, expr2)
{
	this->kind__ = NEqExpr_kind;
}

NEqExpr::~NEqExpr()
{
	// not used
}

int NEqExpr::eval()
#line 166 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ return expr1->eval() != expr2->eval(); }
#line 1356 "../src/ast.cpp"

int NEqExpr::isA(int kind) const
{
	if(kind == NEqExpr_kind)
		return 1;
	else
		return BinExpr::isA(kind);
}

const char *NEqExpr::getKindName() const
{
	return "NEqExpr";
}

AndExpr::AndExpr(YYNODESTATE *state__, Expression * expr1, Expression * expr2)
	: BinExpr(state__, expr1, expr2)
{
	this->kind__ = AndExpr_kind;
}

AndExpr::~AndExpr()
{
	// not used
}

int AndExpr::eval()
#line 167 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ return expr1->eval() && expr2->eval(); }
#line 1385 "../src/ast.cpp"

int AndExpr::isA(int kind) const
{
	if(kind == AndExpr_kind)
		return 1;
	else
		return BinExpr::isA(kind);
}

const char *AndExpr::getKindName() const
{
	return "AndExpr";
}

Or_Expr::Or_Expr(YYNODESTATE *state__, Expression * expr1, Expression * expr2)
	: BinExpr(state__, expr1, expr2)
{
	this->kind__ = Or_Expr_kind;
}

Or_Expr::~Or_Expr()
{
	// not used
}

int Or_Expr::eval()
#line 168 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ return expr1->eval() || expr2->eval(); }
#line 1414 "../src/ast.cpp"

int Or_Expr::isA(int kind) const
{
	if(kind == Or_Expr_kind)
		return 1;
	else
		return BinExpr::isA(kind);
}

const char *Or_Expr::getKindName() const
{
	return "Or_Expr";
}

MultipleExpr::MultipleExpr(YYNODESTATE *state__, ExprList listaExprs)
	: Statement(state__)
{
	this->kind__ = MultipleExpr_kind;
	this->listaExprs = listaExprs;
}

MultipleExpr::~MultipleExpr()
{
	// not used
}

void MultipleExpr::exec()
#line 174 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ 
    for(int x = 0;x<listaExprs.size();x++)
        listaInts.push_back(listaExprs.at(x)->eval());
}
#line 1447 "../src/ast.cpp"

int MultipleExpr::isA(int kind) const
{
	if(kind == MultipleExpr_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *MultipleExpr::getKindName() const
{
	return "MultipleExpr";
}

FieldDecStmt::FieldDecStmt(YYNODESTATE *state__, string_t type, stringList lista)
	: Statement(state__)
{
	this->kind__ = FieldDecStmt_kind;
	this->type = type;
	this->lista = lista;
}

FieldDecStmt::~FieldDecStmt()
{
	// not used
}

void FieldDecStmt::exec()
#line 187 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{

}
#line 1480 "../src/ast.cpp"

int FieldDecStmt::isA(int kind) const
{
	if(kind == FieldDecStmt_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *FieldDecStmt::getKindName() const
{
	return "FieldDecStmt";
}

PrintLNStmt::PrintLNStmt(YYNODESTATE *state__, Expression * expr)
	: Statement(state__)
{
	this->kind__ = PrintLNStmt_kind;
	this->expr = expr;
}

PrintLNStmt::~PrintLNStmt()
{
	// not used
}

void PrintLNStmt::exec()
#line 198 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{
    std::cout<<expr->eval()<<"\n";
}
#line 1512 "../src/ast.cpp"

int PrintLNStmt::isA(int kind) const
{
	if(kind == PrintLNStmt_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *PrintLNStmt::getKindName() const
{
	return "PrintLNStmt";
}

PrintStmt::PrintStmt(YYNODESTATE *state__, Expression * expr)
	: Statement(state__)
{
	this->kind__ = PrintStmt_kind;
	this->expr = expr;
}

PrintStmt::~PrintStmt()
{
	// not used
}

void PrintStmt::exec()
#line 206 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{
    std::cout<<expr->eval();
}
#line 1544 "../src/ast.cpp"

int PrintStmt::isA(int kind) const
{
	if(kind == PrintStmt_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *PrintStmt::getKindName() const
{
	return "PrintStmt";
}

ReadStmt::ReadStmt(YYNODESTATE *state__)
	: Statement(state__)
{
	this->kind__ = ReadStmt_kind;
}

ReadStmt::~ReadStmt()
{
	// not used
}

void ReadStmt::exec()
#line 214 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{
    std::cerr << getFilename() << ":" << getLinenum() <<": warning: expression result unused" << endl;
}
#line 1575 "../src/ast.cpp"

int ReadStmt::isA(int kind) const
{
	if(kind == ReadStmt_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *ReadStmt::getKindName() const
{
	return "ReadStmt";
}

NextIntStmt::NextIntStmt(YYNODESTATE *state__, Expression * expr)
	: Statement(state__)
{
	this->kind__ = NextIntStmt_kind;
	this->expr = expr;
}

NextIntStmt::~NextIntStmt()
{
	// not used
}

void NextIntStmt::exec()
#line 225 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{
    std::cerr << getFilename() << ":" << getLinenum() <<": warning: expression result unused" << endl;
    rand();
}
#line 1608 "../src/ast.cpp"

int NextIntStmt::isA(int kind) const
{
	if(kind == NextIntStmt_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *NextIntStmt::getKindName() const
{
	return "NextIntStmt";
}

FunctionCallStmt::FunctionCallStmt(YYNODESTATE *state__, string_t id, Expression * expr)
	: Statement(state__)
{
	this->kind__ = FunctionCallStmt_kind;
	this->id = id;
	this->expr = expr;
}

FunctionCallStmt::~FunctionCallStmt()
{
	// not used
}

void FunctionCallStmt::exec()
#line 238 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{
    expr->eval();
}
#line 1641 "../src/ast.cpp"

int FunctionCallStmt::isA(int kind) const
{
	if(kind == FunctionCallStmt_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *FunctionCallStmt::getKindName() const
{
	return "FunctionCallStmt";
}

AssignStmt::AssignStmt(YYNODESTATE *state__, string_t id, Expression * expr)
	: Statement(state__)
{
	this->kind__ = AssignStmt_kind;
	this->id = id;
	this->expr = expr;
}

AssignStmt::~AssignStmt()
{
	// not used
}

void AssignStmt::exec()
#line 250 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{
    //vars[id] = expr->eval();
}
#line 1674 "../src/ast.cpp"

int AssignStmt::isA(int kind) const
{
	if(kind == AssignStmt_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *AssignStmt::getKindName() const
{
	return "AssignStmt";
}

ForStmt::ForStmt(YYNODESTATE *state__, Statement * for_dec, Expression * cond, Statement * for_assign, Statement * block)
	: Statement(state__)
{
	this->kind__ = ForStmt_kind;
	this->for_dec = for_dec;
	this->cond = cond;
	this->for_assign = for_assign;
	this->block = block;
}

ForStmt::~ForStmt()
{
	// not used
}

void ForStmt::exec()
#line 264 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ 
    for_dec->exec();
    while(cond->eval())
    {
        block->exec();
        for_assign->exec();
    }
}
#line 1714 "../src/ast.cpp"

int ForStmt::isA(int kind) const
{
	if(kind == ForStmt_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *ForStmt::getKindName() const
{
	return "ForStmt";
}

BlockStmt::BlockStmt(YYNODESTATE *state__, StmtList list)
	: Statement(state__)
{
	this->kind__ = BlockStmt_kind;
	this->list = list;
}

BlockStmt::~BlockStmt()
{
	// not used
}

void BlockStmt::exec()
#line 280 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{
    for(int x = 0;x<list.size();x++)
        list.at(x)->exec();
}
#line 1747 "../src/ast.cpp"

int BlockStmt::isA(int kind) const
{
	if(kind == BlockStmt_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *BlockStmt::getKindName() const
{
	return "BlockStmt";
}

IfStmt::IfStmt(YYNODESTATE *state__, Expression * cond, Statement * true_block, Statement * false_block)
	: Statement(state__)
{
	this->kind__ = IfStmt_kind;
	this->cond = cond;
	this->true_block = true_block;
	this->false_block = false_block;
}

IfStmt::~IfStmt()
{
	// not used
}

void IfStmt::exec()
#line 294 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{
    if(cond->eval())
        true_block->exec();
    else if(false_block != nullptr)
        false_block->exec();
}
#line 1784 "../src/ast.cpp"

int IfStmt::isA(int kind) const
{
	if(kind == IfStmt_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *IfStmt::getKindName() const
{
	return "IfStmt";
}

WhileStmt::WhileStmt(YYNODESTATE *state__, Expression * cond, Statement * block)
	: Statement(state__)
{
	this->kind__ = WhileStmt_kind;
	this->cond = cond;
	this->block = block;
}

WhileStmt::~WhileStmt()
{
	// not used
}

void WhileStmt::exec()
#line 309 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{ 
    while(cond->eval())
        block->exec();
}
#line 1818 "../src/ast.cpp"

int WhileStmt::isA(int kind) const
{
	if(kind == WhileStmt_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *WhileStmt::getKindName() const
{
	return "WhileStmt";
}

ReturnStmt::ReturnStmt(YYNODESTATE *state__, Expression * expr)
	: Statement(state__)
{
	this->kind__ = ReturnStmt_kind;
	this->expr = expr;
}

ReturnStmt::~ReturnStmt()
{
	// not used
}

void ReturnStmt::exec()
#line 321 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{

}
#line 1850 "../src/ast.cpp"

int ReturnStmt::isA(int kind) const
{
	if(kind == ReturnStmt_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *ReturnStmt::getKindName() const
{
	return "ReturnStmt";
}

BreakStmt::BreakStmt(YYNODESTATE *state__)
	: Statement(state__)
{
	this->kind__ = BreakStmt_kind;
}

BreakStmt::~BreakStmt()
{
	// not used
}

void BreakStmt::exec()
#line 329 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{

}
#line 1881 "../src/ast.cpp"

int BreakStmt::isA(int kind) const
{
	if(kind == BreakStmt_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *BreakStmt::getKindName() const
{
	return "BreakStmt";
}

ContinueStmt::ContinueStmt(YYNODESTATE *state__)
	: Statement(state__)
{
	this->kind__ = ContinueStmt_kind;
}

ContinueStmt::~ContinueStmt()
{
	// not used
}

void ContinueStmt::exec()
#line 337 "/home/boris/Desktop/CompiladoresII/Proyecto/src/expr_ast.tc"
{

}
#line 1912 "../src/ast.cpp"

int ContinueStmt::isA(int kind) const
{
	if(kind == ContinueStmt_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *ContinueStmt::getKindName() const
{
	return "ContinueStmt";
}

