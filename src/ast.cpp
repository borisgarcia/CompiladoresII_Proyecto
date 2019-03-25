/* ../src/ast.cpp.  Generated automatically by treecc */
#line 25 "/home/boris/Desktop/Proyecto/src/AST.tc"

    #include "ast.h"

    std::string getPlace(ASTNode * expr)
    {
        if(expr->getKind() == NumExpr_kind)
            return expr->place;
        else
            return "dword [" + expr->place + "]";
    }

    void addToNodeList(ASTNode * &lstn, ASTNode * node) 
    {
        if (lstn == nullptr) 
        {
            lstn = new nodeList(node, nullptr);
            static_cast<nodeList *>(lstn)->last = static_cast<nodeList *>(lstn);
        } 
        else 
        {
            nodeList *lst = static_cast<nodeList *>(lstn);
            nodeList *l = new nodeList(node, nullptr);
            lst->last->next = l;
            lst->last = l;
        }
    }

#line 31 "../src/ast.cpp"

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
#line 310 "../src/ast.cpp"
void *ASTNode::operator new(size_t size__)
{
	return YYNODESTATE::getState()->alloc(size__);
}

void ASTNode::operator delete(void *ptr__, size_t size__)
{
	YYNODESTATE::getState()->dealloc(ptr__, size__);
}

ASTNode::ASTNode()
{
	this->kind__ = ASTNode_kind;
	this->filename__ = YYNODESTATE::getState()->currFilename();
	this->linenum__ = YYNODESTATE::getState()->currLinenum();
	this->code = "";
	this->place = "";
}

ASTNode::~ASTNode()
{
	// not used
}

bool ASTNode::Func_Decl(IdentsHandler & identHandler)
#line 1 "/home/boris/Desktop/Proyecto/src/LoadFunc.tc"
{
    return true;
}
#line 340 "../src/ast.cpp"

bool ASTNode::gen_Code(IdentsHandler & identHandler)
#line 3 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    return true;
}
#line 347 "../src/ast.cpp"

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

Program::Program(ASTNode * dec_list)
	: ASTNode()
{
	this->kind__ = Program_kind;
	this->dec_list = dec_list;
}

Program::~Program()
{
	// not used
}

bool Program::Func_Decl(IdentsHandler & identHandler)
#line 5 "/home/boris/Desktop/Proyecto/src/LoadFunc.tc"
{
    nodeList *lst = static_cast<nodeList *>(dec_list);

    while (lst != nullptr) {
        ASTNode *fd = lst->node;

        if (!fd->Func_Decl(identHandler)) {
            return false;
        }
        lst = lst->next;
    }
    return true;
}
#line 389 "../src/ast.cpp"

int Program::isA(int kind) const
{
	if(kind == Program_kind)
		return 1;
	else
		return ASTNode::isA(kind);
}

const char *Program::getKindName() const
{
	return "Program";
}

FnDec::FnDec(string_t type, string_t name, ASTNode * params, Statement * block)
	: ASTNode()
{
	this->kind__ = FnDec_kind;
	this->type = type;
	this->name = name;
	this->params = params;
	this->block = block;
}

FnDec::~FnDec()
{
	// not used
}

bool FnDec::Func_Decl(IdentsHandler & identHandler)
#line 20 "/home/boris/Desktop/Proyecto/src/LoadFunc.tc"
{
    if (identHandler.findFunc(name)) {
        std::cerr << "Line: " << this->getLinenum() << ": Function '" << name << "' already declared\n";
        return false;
    }
    UPFuncDef funcDef = std::make_unique<FuncDef>(name,type);
    FnParamsDec * temp;

    nodeList *lst = static_cast<nodeList *>(params);
    while (lst != nullptr) {
        ASTNode *fd = lst->node;
        temp = static_cast<FnParamsDec *>(fd);
        funcDef->registerParam(temp->id);
        lst = lst->next;
    }
    identHandler.registerFuncDef(std::move(funcDef));
    identHandler.setCurrentFuncDef(name);
    if (!block->Func_Decl(identHandler))
        return false;
    identHandler.setCurrentFuncDef("");
    return true;
}
#line 443 "../src/ast.cpp"

bool FnDec::gen_Code(IdentsHandler & identHandler)
#line 39 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if(!block->gen_Code(identHandler))
        return false;
    std::ostringstream ss;
    identHandler.setCurrentFuncDef(name);
    FuncDef *fd = identHandler.getFuncDef(name);

    ss << name << ":\n"
       << "pusb ebp\n"
       << "mov ebp, esp\n"
       << "sub esp, " << fd->getVarSize() << "\n"
       << block->code
       << fd->getEpilogLabel() << ":\n"
       << "leave\n"
       << "ret";
    
    code = ss.str();
    identHandler.setCurrentFuncDef("");
    return true;
}
#line 467 "../src/ast.cpp"

int FnDec::isA(int kind) const
{
	if(kind == FnDec_kind)
		return 1;
	else
		return ASTNode::isA(kind);
}

const char *FnDec::getKindName() const
{
	return "FnDec";
}

stringNode::stringNode(string_t id)
	: ASTNode()
{
	this->kind__ = stringNode_kind;
	this->id = id;
}

stringNode::~stringNode()
{
	// not used
}

int stringNode::isA(int kind) const
{
	if(kind == stringNode_kind)
		return 1;
	else
		return ASTNode::isA(kind);
}

const char *stringNode::getKindName() const
{
	return "stringNode";
}

FieldDecStmt::FieldDecStmt(string_t type, string_t id, Expression * value)
	: ASTNode()
{
	this->kind__ = FieldDecStmt_kind;
	this->type = type;
	this->id = id;
	this->value = value;
}

FieldDecStmt::~FieldDecStmt()
{
	// not used
}

bool FieldDecStmt::Func_Decl(IdentsHandler & identHandler)
#line 44 "/home/boris/Desktop/Proyecto/src/LoadFunc.tc"
{
    int val;
    if(value == nullptr)
        identHandler.registerVar(id, -1);
    else
    {
        if(type == "int")
            val = static_cast<NumExpr*>(value)->value;
        else if(type == "int")
            val = static_cast<CharExpr*>(value)->value;
        else if(type == "int")
            val = static_cast<BoolExpr*>(value)->value;
        identHandler.registerVar(id, val);
    }
}
#line 538 "../src/ast.cpp"

int FieldDecStmt::isA(int kind) const
{
	if(kind == FieldDecStmt_kind)
		return 1;
	else
		return ASTNode::isA(kind);
}

const char *FieldDecStmt::getKindName() const
{
	return "FieldDecStmt";
}

FieldDecStmt_2::FieldDecStmt_2(string_t type, ASTNode * list)
	: ASTNode()
{
	this->kind__ = FieldDecStmt_2_kind;
	this->type = type;
	this->list = list;
}

FieldDecStmt_2::~FieldDecStmt_2()
{
	// not used
}

bool FieldDecStmt_2::Func_Decl(IdentsHandler & identHandler)
#line 61 "/home/boris/Desktop/Proyecto/src/LoadFunc.tc"
{
    stringNode * temp;
    ArrayDec * temp_2;
    nodeList *lst = static_cast<nodeList *>(list);
    while (lst != nullptr) {
        ASTNode *curr = lst->node;
        if(isA(stringNode_kind))
        {
            temp = static_cast<stringNode *>(curr);
            identHandler.registerVar(temp->id, -1);
        }
        else if(isA(ArrayDec_kind))
        {
            temp_2 = static_cast<ArrayDec *>(curr);

        }
        lst = lst->next;
    }
}
#line 587 "../src/ast.cpp"

int FieldDecStmt_2::isA(int kind) const
{
	if(kind == FieldDecStmt_2_kind)
		return 1;
	else
		return ASTNode::isA(kind);
}

const char *FieldDecStmt_2::getKindName() const
{
	return "FieldDecStmt_2";
}

nodeList::nodeList(ASTNode * node, nodeList * next)
	: ASTNode()
{
	this->kind__ = nodeList_kind;
	this->node = node;
	this->next = next;
	this->last = nullptr;
}

nodeList::~nodeList()
{
	// not used
}

int nodeList::isA(int kind) const
{
	if(kind == nodeList_kind)
		return 1;
	else
		return ASTNode::isA(kind);
}

const char *nodeList::getKindName() const
{
	return "nodeList";
}

FnParamsDec::FnParamsDec(string_t type, string_t id)
	: ASTNode()
{
	this->kind__ = FnParamsDec_kind;
	this->type = type;
	this->id = id;
}

FnParamsDec::~FnParamsDec()
{
	// not used
}

int FnParamsDec::isA(int kind) const
{
	if(kind == FnParamsDec_kind)
		return 1;
	else
		return ASTNode::isA(kind);
}

const char *FnParamsDec::getKindName() const
{
	return "FnParamsDec";
}

Expression::Expression()
	: ASTNode()
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

Statement::Statement()
	: ASTNode()
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

NumExpr::NumExpr(int value)
	: Expression()
{
	this->kind__ = NumExpr_kind;
	this->value = value;
}

NumExpr::~NumExpr()
{
	// not used
}

bool NumExpr::gen_Code(IdentsHandler & identHandler)
#line 283 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    place = std::to_string(value);
    return true;    
}
#line 721 "../src/ast.cpp"

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

StringConstantExpr::StringConstantExpr(string_t value)
	: Expression()
{
	this->kind__ = StringConstantExpr_kind;
	this->value = value;
}

StringConstantExpr::~StringConstantExpr()
{
	// not used
}

bool StringConstantExpr::gen_Code(IdentsHandler & identHandler)
#line 277 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    place = identHandler.registerStrLiteral(value);
    return true;
}
#line 754 "../src/ast.cpp"

int StringConstantExpr::isA(int kind) const
{
	if(kind == StringConstantExpr_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *StringConstantExpr::getKindName() const
{
	return "StringConstantExpr";
}

CharExpr::CharExpr(int value)
	: Expression()
{
	this->kind__ = CharExpr_kind;
	this->value = value;
}

CharExpr::~CharExpr()
{
	// not used
}

bool CharExpr::gen_Code(IdentsHandler & identHandler)
#line 289 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    place = std::to_string(value);
    return true;    
}
#line 787 "../src/ast.cpp"

int CharExpr::isA(int kind) const
{
	if(kind == CharExpr_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *CharExpr::getKindName() const
{
	return "CharExpr";
}

BoolExpr::BoolExpr(bool value)
	: Expression()
{
	this->kind__ = BoolExpr_kind;
	this->value = value;
}

BoolExpr::~BoolExpr()
{
	// not used
}

bool BoolExpr::gen_Code(IdentsHandler & identHandler)
#line 265 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    place = std::to_string(value);
    return true;
}
#line 820 "../src/ast.cpp"

int BoolExpr::isA(int kind) const
{
	if(kind == BoolExpr_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *BoolExpr::getKindName() const
{
	return "BoolExpr";
}

OneExpr::OneExpr(Expression * expr)
	: Expression()
{
	this->kind__ = OneExpr_kind;
	this->expr = expr;
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

BinExpr::BinExpr(Expression * expr1, Expression * expr2)
	: Expression()
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

IdExpr::IdExpr(string_t id)
	: Expression()
{
	this->kind__ = IdExpr_kind;
	this->id = id;
}

IdExpr::~IdExpr()
{
	// not used
}

bool IdExpr::gen_Code(IdentsHandler & identHandler)
#line 249 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    int Offset = identHandler.getVarOffset(id);
    if (Offset == -1) {
        std::cerr << "Line: " << this->getLinenum() << ":Error:Var '" << this->place << "' not found\n";
        return false;
    }
    if(Offset == 0)
        place = id;
    else if(Offset > 0)
        place = "ebp + " + std::to_string(Offset);
    else
        place = "ebp - " + std::to_string(-Offset);
    return true;
}
#line 914 "../src/ast.cpp"

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

IdArrayExpr::IdArrayExpr(string_t id, Expression * pos)
	: Expression()
{
	this->kind__ = IdArrayExpr_kind;
	this->id = id;
	this->pos = pos;
}

IdArrayExpr::~IdArrayExpr()
{
	// not used
}

bool IdArrayExpr::gen_Code(IdentsHandler & identHandler)
#line 271 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{

    return true;
}
#line 948 "../src/ast.cpp"

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

ArrayDec::ArrayDec(string_t id, int size)
	: Expression()
{
	this->kind__ = ArrayDec_kind;
	this->id = id;
	this->size = size;
}

ArrayDec::~ArrayDec()
{
	// not used
}

int ArrayDec::isA(int kind) const
{
	if(kind == ArrayDec_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *ArrayDec::getKindName() const
{
	return "ArrayDec";
}

NextIntExpr::NextIntExpr(Expression * expr)
	: Expression()
{
	this->kind__ = NextIntExpr_kind;
	this->expr = expr;
}

NextIntExpr::~NextIntExpr()
{
	// not used
}

bool NextIntExpr::gen_Code(IdentsHandler & identHandler)
#line 312 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr->gen_Code(identHandler))
        return false;
    
    std::ostringstream ss;
     ss << "mov eax, 0\n"
        << "push eax\n"
        << "call time\n"
        << "add esp, 4\n"
        << "push eax\n"
        << "call srand\n"
        << "add esp, 4\n"
        << "call rand\n"
        << "mov ecx, " << getPlace(expr) << "\n"
        << "cdq\n"
        << "add ecx, 1\n"
        << "idiv ecx\n"
        << "mov eax, edx\n";
    
    code = ss.str();
    return true;
}
#line 1025 "../src/ast.cpp"

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

ReadExpr::ReadExpr()
	: Expression()
{
	this->kind__ = ReadExpr_kind;
}

ReadExpr::~ReadExpr()
{
	// not used
}

bool ReadExpr::gen_Code(IdentsHandler & identHandler)
#line 302 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    std::ostringstream ss;  
    ss << "push %d\n"
       << "call scanf\n"
       << "add esp, 8\n";
    code = ss.str();
    return true;
}
#line 1061 "../src/ast.cpp"

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

PrintExpr::PrintExpr(Expression * expr)
	: Expression()
{
	this->kind__ = PrintExpr_kind;
	this->expr = expr;
}

PrintExpr::~PrintExpr()
{
	// not used
}

bool PrintExpr::gen_Code(IdentsHandler & identHandler)
#line 295 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    std::cerr << "error: can't assign void to expr" << std::endl;
    exit(0);
    return false;
}
#line 1095 "../src/ast.cpp"

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

FunctionCallExpr::FunctionCallExpr(string_t id, ASTNode * param_list)
	: Expression()
{
	this->kind__ = FunctionCallExpr_kind;
	this->id = id;
	this->param_list = param_list;
}

FunctionCallExpr::~FunctionCallExpr()
{
	// not used
}

bool FunctionCallExpr::gen_Code(IdentsHandler & identHandler)
#line 244 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    return true;
}
#line 1128 "../src/ast.cpp"

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

NotExpr::NotExpr(Expression * expr)
	: OneExpr(expr)
{
	this->kind__ = NotExpr_kind;
}

NotExpr::~NotExpr()
{
	// not used
}

bool NotExpr::gen_Code(IdentsHandler & identHandler)
#line 704 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if(!expr->gen_Code(identHandler))
        return false;
    
    std::string lbl = identHandler.genNewLabel();
    std::string lbl_end = identHandler.genNewLabel();

    std::ostringstream ss;
    place = identHandler.newTemp();

    ss << expr->code << "\n"
       << "mov eax, " << getPlace(expr) << "\n"
       << "cmp eax, 0 \n"
       << "je " << lbl << "\n"
       << "mov eax , 0 \n"
       << "jmp " << lbl_end << "\n"
       << lbl <<":\n"
       << "mov eax , 1 \n"
       << lbl_end << ":\n"
       << "mov dword [" << place << "], eax\n";
    code = ss.str();
    return true;

}
#line 1180 "../src/ast.cpp"

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

NegExpr::NegExpr(Expression * expr)
	: OneExpr(expr)
{
	this->kind__ = NegExpr_kind;
}

NegExpr::~NegExpr()
{
	// not used
}

bool NegExpr::gen_Code(IdentsHandler & identHandler)
#line 683 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr->gen_Code(identHandler))
        return false;
    place = identHandler.newTemp();
    std::ostringstream ss;

    ss << expr->code << "\n";
    if(expr->getKind() == NumExpr_kind)
        expr->place = "-" + expr->place;
    else
    {
        ss << "mov eax, dword [" << expr->place << "]\n";
        ss << "neg eax\n";
        ss << "mov dword [" << place << "], eax";
    }

    code = ss.str();
    return true;
}
#line 1227 "../src/ast.cpp"

int NegExpr::isA(int kind) const
{
	if(kind == NegExpr_kind)
		return 1;
	else
		return OneExpr::isA(kind);
}

const char *NegExpr::getKindName() const
{
	return "NegExpr";
}

AddExpr::AddExpr(Expression * expr1, Expression * expr2)
	: BinExpr(expr1, expr2)
{
	this->kind__ = AddExpr_kind;
}

AddExpr::~AddExpr()
{
	// not used
}

bool AddExpr::gen_Code(IdentsHandler & identHandler)
#line 336 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->gen_Code(identHandler))
        return false;
    if (!expr2->gen_Code(identHandler))
        return false;
    std::ostringstream ss;

    place = identHandler.newTemp();
    ss << expr1->code << "\n"
       << expr2->code << "\n"
       << "mov eax, " << getPlace(expr1) << "\n"
       << "add eax, " << getPlace(expr2) << "\n"
       << "mov dword [" << place << "], eax";
    code = ss.str();
    return true;
}
#line 1271 "../src/ast.cpp"

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

SubExpr::SubExpr(Expression * expr1, Expression * expr2)
	: BinExpr(expr1, expr2)
{
	this->kind__ = SubExpr_kind;
}

SubExpr::~SubExpr()
{
	// not used
}

bool SubExpr::gen_Code(IdentsHandler & identHandler)
#line 432 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->gen_Code(identHandler))
        return false;
    if (!expr2->gen_Code(identHandler))
        return false;
    std::ostringstream ss;

    place = identHandler.newTemp();
    ss << expr1->code << "\n"
       << expr2->code << "\n"
       << "mov eax, " << getPlace(expr1) << "\n"
       << "sub eax, " << getPlace(expr2) << "\n"
       << "mov dword [" << place << "], eax";
    code = ss.str();
    return true;
}
#line 1315 "../src/ast.cpp"

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

MulExpr::MulExpr(Expression * expr1, Expression * expr2)
	: BinExpr(expr1, expr2)
{
	this->kind__ = MulExpr_kind;
}

MulExpr::~MulExpr()
{
	// not used
}

bool MulExpr::gen_Code(IdentsHandler & identHandler)
#line 450 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->gen_Code(identHandler))
        return false;
    if (!expr2->gen_Code(identHandler))
        return false;

    std::ostringstream ss;

    place = identHandler.newTemp();
    ss << expr1->code << "\n"
       << expr2->code << "\n"
       << "mov eax, " << getPlace(expr1) << "\n"
       << "imul eax, " << getPlace(expr2) << "\n"
       << "mov dword [" << place << "], eax" << "\n";
    code = ss.str();
    return true;
}
#line 1360 "../src/ast.cpp"

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

DivExpr::DivExpr(Expression * expr1, Expression * expr2)
	: BinExpr(expr1, expr2)
{
	this->kind__ = DivExpr_kind;
}

DivExpr::~DivExpr()
{
	// not used
}

bool DivExpr::gen_Code(IdentsHandler & identHandler)
#line 469 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->gen_Code(identHandler))
        return false;
    if (!expr2->gen_Code(identHandler)) 
        return false;
    std::ostringstream ss;

    place = identHandler.newTemp();
    ss << expr1->code << "\n"
       << expr2->code << "\n"
       << "mov eax, " << getPlace(expr1) << "\n"
       << "mov ebx, " << getPlace(expr1) << "\n"
       << "cdq\n"
       << "idiv ebx\n"
       << "mov dword [" << place << "], eax";
    code = ss.str();
    return true;
}
#line 1406 "../src/ast.cpp"

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

SRLExpr::SRLExpr(Expression * expr1, Expression * expr2)
	: BinExpr(expr1, expr2)
{
	this->kind__ = SRLExpr_kind;
}

SRLExpr::~SRLExpr()
{
	// not used
}

bool SRLExpr::gen_Code(IdentsHandler & identHandler)
#line 392 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->gen_Code(identHandler)) {
        return false;
    }
    if (!expr2->gen_Code(identHandler)) {
        return false;
    }
    std::ostringstream ss;

    place = identHandler.newTemp();
    ss << expr1->code << "\n"
       << expr2->code << "\n"
       << "mov eax, " << getPlace(expr1) << "\n"
       << "sar eax, " << getPlace(expr2) << "\n"
       << "mov dword [" << place << "], eax";
    code = ss.str();
    return true;
}
#line 1452 "../src/ast.cpp"

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

SLLExpr::SLLExpr(Expression * expr1, Expression * expr2)
	: BinExpr(expr1, expr2)
{
	this->kind__ = SLLExpr_kind;
}

SLLExpr::~SLLExpr()
{
	// not used
}

bool SLLExpr::gen_Code(IdentsHandler & identHandler)
#line 412 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->gen_Code(identHandler)) {
        return false;
    }
    if (!expr2->gen_Code(identHandler)) {
        return false;
    }
    std::ostringstream ss;

    place = identHandler.newTemp();
    ss << expr1->code << "\n"
       << expr2->code << "\n"
       << "mov eax, " << getPlace(expr1) << "\n"
       << "sal eax, " << getPlace(expr2) << "\n"
       << "mov dword [" << place << "], eax";
    code = ss.str();
    return true;
}
#line 1498 "../src/ast.cpp"

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

ModExpr::ModExpr(Expression * expr1, Expression * expr2)
	: BinExpr(expr1, expr2)
{
	this->kind__ = ModExpr_kind;
}

ModExpr::~ModExpr()
{
	// not used
}

bool ModExpr::gen_Code(IdentsHandler & identHandler)
#line 489 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->gen_Code(identHandler))
        return false;
    if (!expr2->gen_Code(identHandler)) 
        return false;
    std::ostringstream ss;

    place = identHandler.newTemp();
    ss << expr1->code << "\n"
       << expr2->code << "\n"
       << "mov eax, " << getPlace(expr1) << "\n"
       << "mov ebx, " << getPlace(expr1) << "\n"
       << "cdq\n"
       << "idiv ebx\n"
       << "mov dword [" << place << "], edx";
    code = ss.str();
    return true;
}
#line 1544 "../src/ast.cpp"

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

LesExpr::LesExpr(Expression * expr1, Expression * expr2)
	: BinExpr(expr1, expr2)
{
	this->kind__ = LesExpr_kind;
}

LesExpr::~LesExpr()
{
	// not used
}

bool LesExpr::gen_Code(IdentsHandler & identHandler)
#line 509 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->gen_Code(identHandler))
        return false;
    if (!expr2->gen_Code(identHandler)) 
        return false;
    place = identHandler.newTemp();

    std::ostringstream ss;

    place = identHandler.newTemp();
    std::string label = identHandler.genNewLabel();
    std::string fin = identHandler.genNewLabel();

    ss << expr1->code << "\n"
        << expr2->code << "\n"
        << "mov eax, " << getPlace(expr1) << "\n"
        << "cmp eax, " << getPlace(expr2) << "\n"
        << "jl" << label <<"\n"
        << "mov eax, 0\n"
        << "jmp " << fin <<"\n"
        << label << ":\n"
        << "mov eax, 1\n"
        << fin << ":\n"
        << "mov dword [" << place << "], eax";
    code = ss.str();
    return true;
}
#line 1599 "../src/ast.cpp"

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

GreExpr::GreExpr(Expression * expr1, Expression * expr2)
	: BinExpr(expr1, expr2)
{
	this->kind__ = GreExpr_kind;
}

GreExpr::~GreExpr()
{
	// not used
}

bool GreExpr::gen_Code(IdentsHandler & identHandler)
#line 538 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
     if (!expr1->gen_Code(identHandler))
        return false;
    if (!expr2->gen_Code(identHandler)) 
        return false;
    place = identHandler.newTemp();

    std::ostringstream ss;

    place = identHandler.newTemp();
    std::string label = identHandler.genNewLabel();
    std::string fin = identHandler.genNewLabel();

    ss << expr1->code << "\n"
        << expr2->code << "\n"
        << "mov eax, " << getPlace(expr1) << "\n"
        << "cmp eax, " << getPlace(expr2) << "\n"
        << "jg" << label <<"\n"
        << "mov eax, 0\n"
        << "jmp " << fin <<"\n"
        << label << ":\n"
        << "mov eax, 1\n"
        << fin << ":\n"
        << "mov dword [" << place << "], eax";
    code = ss.str();
    return true;
}
#line 1654 "../src/ast.cpp"

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

LeEExpr::LeEExpr(Expression * expr1, Expression * expr2)
	: BinExpr(expr1, expr2)
{
	this->kind__ = LeEExpr_kind;
}

LeEExpr::~LeEExpr()
{
	// not used
}

bool LeEExpr::gen_Code(IdentsHandler & identHandler)
#line 567 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->gen_Code(identHandler))
        return false;
    if (!expr2->gen_Code(identHandler)) 
        return false;
    place = identHandler.newTemp();

    std::ostringstream ss;

    place = identHandler.newTemp();
    std::string label = identHandler.genNewLabel();
    std::string fin = identHandler.genNewLabel();

    ss << expr1->code << "\n"
        << expr2->code << "\n"
        << "mov eax, " << getPlace(expr1) << "\n"
        << "cmp eax, " << getPlace(expr2) << "\n"
        << "jle" << label <<"\n"
        << "mov eax, 0\n"
        << "jmp " << fin <<"\n"
        << label << ":\n"
        << "mov eax, 1\n"
        << fin << ":\n"
        << "mov dword [" << place << "], eax";
    code = ss.str();
    return true;
}
#line 1709 "../src/ast.cpp"

int LeEExpr::isA(int kind) const
{
	if(kind == LeEExpr_kind)
		return 1;
	else
		return BinExpr::isA(kind);
}

const char *LeEExpr::getKindName() const
{
	return "LeEExpr";
}

GrEExpr::GrEExpr(Expression * expr1, Expression * expr2)
	: BinExpr(expr1, expr2)
{
	this->kind__ = GrEExpr_kind;
}

GrEExpr::~GrEExpr()
{
	// not used
}

bool GrEExpr::gen_Code(IdentsHandler & identHandler)
#line 596 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
     if (!expr1->gen_Code(identHandler))
        return false;
    if (!expr2->gen_Code(identHandler)) 
        return false;
    place = identHandler.newTemp();

    std::ostringstream ss;

    place = identHandler.newTemp();
    std::string label = identHandler.genNewLabel();
    std::string fin = identHandler.genNewLabel();

    ss << expr1->code << "\n"
        << expr2->code << "\n"
        << "mov eax, " << getPlace(expr1) << "\n"
        << "cmp eax, " << getPlace(expr2) << "\n"
        << "jge" << label <<"\n"
        << "mov eax, 0\n"
        << "jmp " << fin <<"\n"
        << label << ":\n"
        << "mov eax, 1\n"
        << fin << ":\n"
        << "mov dword [" << place << "], eax";
    code = ss.str();
    return true;
}
#line 1764 "../src/ast.cpp"

int GrEExpr::isA(int kind) const
{
	if(kind == GrEExpr_kind)
		return 1;
	else
		return BinExpr::isA(kind);
}

const char *GrEExpr::getKindName() const
{
	return "GrEExpr";
}

EquExpr::EquExpr(Expression * expr1, Expression * expr2)
	: BinExpr(expr1, expr2)
{
	this->kind__ = EquExpr_kind;
}

EquExpr::~EquExpr()
{
	// not used
}

bool EquExpr::gen_Code(IdentsHandler & identHandler)
#line 625 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->gen_Code(identHandler))
        return false;
    if (!expr2->gen_Code(identHandler)) 
        return false;
    place = identHandler.newTemp();

    std::ostringstream ss;

    place = identHandler.newTemp();
    std::string label = identHandler.genNewLabel();
    std::string fin = identHandler.genNewLabel();

    ss << expr1->code << "\n"
        << expr2->code << "\n"
        << "mov eax, " << getPlace(expr1) << "\n"
        << "cmp eax, " << getPlace(expr2) << "\n"
        << "je" << label <<"\n"
        << "mov eax, 0\n"
        << "jmp " << fin <<"\n"
        << label << ":\n"
        << "mov eax, 1\n"
        << fin << ":\n"
        << "mov dword [" << place << "], eax";
    code = ss.str();
    return true;
}
#line 1819 "../src/ast.cpp"

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

NEqExpr::NEqExpr(Expression * expr1, Expression * expr2)
	: BinExpr(expr1, expr2)
{
	this->kind__ = NEqExpr_kind;
}

NEqExpr::~NEqExpr()
{
	// not used
}

bool NEqExpr::gen_Code(IdentsHandler & identHandler)
#line 654 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
   if (!expr1->gen_Code(identHandler))
        return false;
    if (!expr2->gen_Code(identHandler)) 
        return false;
    place = identHandler.newTemp();

    std::ostringstream ss;

    place = identHandler.newTemp();
    std::string label = identHandler.genNewLabel();
    std::string fin = identHandler.genNewLabel();

    ss << expr1->code << "\n"
        << expr2->code << "\n"
        << "mov eax, " << getPlace(expr1) << "\n"
        << "cmp eax, " << getPlace(expr2) << "\n"
        << "jne" << label <<"\n"
        << "mov eax, 0\n"
        << "jmp " << fin <<"\n"
        << label << ":\n"
        << "mov eax, 1\n"
        << fin << ":\n"
        << "mov dword [" << place << "], eax";
    code = ss.str();
    return true;
}
#line 1874 "../src/ast.cpp"

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

AndExpr::AndExpr(Expression * expr1, Expression * expr2)
	: BinExpr(expr1, expr2)
{
	this->kind__ = AndExpr_kind;
}

AndExpr::~AndExpr()
{
	// not used
}

bool AndExpr::gen_Code(IdentsHandler & identHandler)
#line 354 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->gen_Code(identHandler)) 
        return false;
    if (!expr2->gen_Code(identHandler)) 
        return false;
    std::ostringstream ss;

    place = identHandler.newTemp();
    ss << expr1->code << "\n"
       << expr2->code << "\n"
       << "mov eax, " << getPlace(expr1) << "\n"
       << "and eax, " << getPlace(expr2) << "\n"
       << "mov dword [" << place << "], eax";
    code = ss.str();
    return true;
}
#line 1918 "../src/ast.cpp"

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

Or_Expr::Or_Expr(Expression * expr1, Expression * expr2)
	: BinExpr(expr1, expr2)
{
	this->kind__ = Or_Expr_kind;
}

Or_Expr::~Or_Expr()
{
	// not used
}

bool Or_Expr::gen_Code(IdentsHandler & identHandler)
#line 372 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->gen_Code(identHandler)) {
        return false;
    }
    if (!expr2->gen_Code(identHandler)) {
        return false;
    }
    std::ostringstream ss;

    place = identHandler.newTemp();
    ss << expr1->code << "\n"
       << expr2->code << "\n"
       << "mov eax, " << getPlace(expr1) << "\n"
       << "or eax, " << getPlace(expr2) << "\n"
       << "mov dword [" << place << "], eax";
    code = ss.str();
    return true;
}
#line 1964 "../src/ast.cpp"

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

WhileStmt::WhileStmt(Expression * cond, Statement * block)
	: Statement()
{
	this->kind__ = WhileStmt_kind;
	this->cond = cond;
	this->block = block;
}

WhileStmt::~WhileStmt()
{
	// not used
}

bool WhileStmt::Func_Decl(IdentsHandler & identHandler)
#line 108 "/home/boris/Desktop/Proyecto/src/LoadFunc.tc"
{
    if(!block->Func_Decl(identHandler))
        return false;
    return true;
}
#line 1999 "../src/ast.cpp"

bool WhileStmt::gen_Code(IdentsHandler & identHandler)
#line 219 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if(!cond->gen_Code(identHandler))
        return false;
    if(!block->gen_Code(identHandler))
        return false;
    
    std::ostringstream ss;
    std::string beg = identHandler.genNewLabel();
    std::string end = identHandler.genNewLabel();
    
    ss<<beg<<":\n"
      <<cond->code<<"\n" 
      <<"mov eax, "<<getPlace(cond)<<"\n"
      <<"cmp eax, 0\n"
      <<"je "<<end<<"\n"
      <<block->code<<"\n"
      <<"jmp "<<beg<<"\n"
      <<end<<":\n";
  
    code = ss.str();
}
#line 2024 "../src/ast.cpp"

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

ForStmt::ForStmt(ASTNode * for_dec, Expression * cond, ASTNode * for_assign, Statement * block)
	: Statement()
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

bool ForStmt::Func_Decl(IdentsHandler & identHandler)
#line 102 "/home/boris/Desktop/Proyecto/src/LoadFunc.tc"
{
    if(!block->Func_Decl(identHandler))
        return false;
    return true;
}
#line 2061 "../src/ast.cpp"

bool ForStmt::gen_Code(IdentsHandler & identHandler)
#line 188 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
  if(!for_dec->gen_Code(identHandler))
    return false;
  if(!cond->gen_Code(identHandler))
    return false;
  if(!for_assign->gen_Code(identHandler))
    return false;
  if(!block->gen_Code(identHandler))
    return false;

  std::ostringstream ss;
  std::string beg = identHandler.genNewLabel();
  std::string end = identHandler.genNewLabel();

  ss<<for_dec->code<<"\n" 
    <<beg<<":\n"
    <<cond->code<<"\n" 
    <<"mov eax, "<<getPlace(cond)<<"\n"
    <<"cmp eax, 0\n"
    <<"je "<<end<<"\n"
    <<block->code<<"\n"
    <<for_assign->code<<"\n"
    <<"jmp "<<beg<<"\n"
    <<end<<":\n";
  
  code = ss.str();
  return true;
  
}
#line 2094 "../src/ast.cpp"

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

IfStmt::IfStmt(Expression * cond, Statement * true_block, Statement * false_block)
	: Statement()
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

bool IfStmt::Func_Decl(IdentsHandler & identHandler)
#line 94 "/home/boris/Desktop/Proyecto/src/LoadFunc.tc"
{
    if(!true_block->Func_Decl(identHandler))
        return false;
    if(false_block != nullptr && !false_block->Func_Decl(identHandler))
        return false;
    return true;
}
#line 2132 "../src/ast.cpp"

bool IfStmt::gen_Code(IdentsHandler & identHandler)
#line 157 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!cond->gen_Code(identHandler)) {
        return false;
    }
    if (!true_block->gen_Code(identHandler)) {
        return false;
    }
    if (false_block != nullptr) {
        if (!false_block->gen_Code(identHandler)) {
            return false;
        }
    }
    std::ostringstream ss;
    std::string lblelse = identHandler.genNewLabel();
    std::string lblendif = identHandler.genNewLabel();
    ss << cond->code << '\n'
        << "cmp " << getPlace(cond) << ", 0\n"
        << "je " << lblelse << '\n'
        << true_block->code << '\n'
        << "jmp " << lblendif << '\n'
        << lblelse << ":\n";

    if (true_block != nullptr)
        ss << false_block->code << '\n';
    ss << lblendif << ':';

    code = ss.str();
    return true;
}
#line 2165 "../src/ast.cpp"

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

AssignStmt::AssignStmt(Expression * lhs, Expression * rhs)
	: Statement()
{
	this->kind__ = AssignStmt_kind;
	this->lhs = lhs;
	this->rhs = rhs;
}

AssignStmt::~AssignStmt()
{
	// not used
}

bool AssignStmt::gen_Code(IdentsHandler & identHandler)
#line 34 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{   
    return true;
}
#line 2198 "../src/ast.cpp"

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

PrintlnStmt::PrintlnStmt(Expression * expr)
	: Statement()
{
	this->kind__ = PrintlnStmt_kind;
	this->expr = expr;
}

PrintlnStmt::~PrintlnStmt()
{
	// not used
}

bool PrintlnStmt::gen_Code(IdentsHandler & identHandler)
#line 84 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr->gen_Code(identHandler))
        return false;
    
    int argsize = 4;
    std::ostringstream ss;

    if (expr->isA(StringConstantExpr_kind)) {
        ss << "%s"
           << "push " << expr->place << "\n";
    } else if (expr->isA(CharExpr_kind)) {
        ss << "%c"
           << "push " << expr->place << "\n";
    } else {
        ss << "%d"
           << "push " << getPlace(expr) << "\n";
    }
    ss << expr->code << '\n';
    std::string strfmtplace = identHandler.registerStrLiteral(ss.str());
    ss << "push " << strfmtplace << '\n'
       << "call printf \n"
       << "add esp, " << (argsize + 4) << "\n";
    
    code = ss.str();
    return true;
}
#line 2253 "../src/ast.cpp"

int PrintlnStmt::isA(int kind) const
{
	if(kind == PrintlnStmt_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *PrintlnStmt::getKindName() const
{
	return "PrintlnStmt";
}

PrintStmt::PrintStmt(Expression * expr)
	: Statement()
{
	this->kind__ = PrintStmt_kind;
	this->expr = expr;
}

PrintStmt::~PrintStmt()
{
	// not used
}

bool PrintStmt::gen_Code(IdentsHandler & identHandler)
#line 112 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr->gen_Code(identHandler))
        return false;
    
    std::ostringstream ss;

    if (expr->isA(StringConstantExpr_kind)) {
        ss << "%s"
           << "push " << expr->place << "\n";
    } else if (expr->isA(CharExpr_kind)) {
        ss << "%c"
           << "push " << expr->place << "\n";
    } else {
        ss << "%d"
           << "push " << getPlace(expr) << "\n";
    }
    ss << expr->code << '\n';
    std::string strfmtplace = identHandler.registerStrLiteral(ss.str());
    
    ss << "push " << strfmtplace << '\n'
       << "call printf"
       << "add esp, 8 \n";
    
    code = ss.str();
    return true;
}
#line 2308 "../src/ast.cpp"

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

ReadStmt::ReadStmt()
	: Statement()
{
	this->kind__ = ReadStmt_kind;
}

ReadStmt::~ReadStmt()
{
	// not used
}

bool ReadStmt::gen_Code(IdentsHandler & identHandler)
#line 13 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    std::cerr << "Line: "<< this->getLinenum() << ": error: expression result unused!" << std::endl;
    exit(0);
}
#line 2340 "../src/ast.cpp"

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

NextIntStmt::NextIntStmt(Expression * expr)
	: Statement()
{
	this->kind__ = NextIntStmt_kind;
	this->expr = expr;
}

NextIntStmt::~NextIntStmt()
{
	// not used
}

bool NextIntStmt::gen_Code(IdentsHandler & identHandler)
#line 8 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    std::cerr << "Line: "<< expr->getLinenum() << ": error: expression result unused!" << std::endl;
    return false;
}
#line 2373 "../src/ast.cpp"

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

ReturnStmt::ReturnStmt(Expression * expr)
	: Statement()
{
	this->kind__ = ReturnStmt_kind;
	this->expr = expr;
	this->label = "";
}

ReturnStmt::~ReturnStmt()
{
	// not used
}

bool ReturnStmt::gen_Code(IdentsHandler & identHandler)
#line 140 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr->gen_Code(identHandler) && expr == nullptr)
        return false;
    
    std::ostringstream ss;

    FuncDef *fd = identHandler.getCurrentFuncDef();
    
    ss << expr->code << '\n';
    //if()
    ss << "mov eax, " << getPlace(expr) << "\n";
    ss << "jmp " << fd->getEpilogLabel();
    code = ss.str();
    return true;
}
#line 2418 "../src/ast.cpp"

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

ContinueStmt::ContinueStmt()
	: Statement()
{
	this->kind__ = ContinueStmt_kind;
	this->label = "";
}

ContinueStmt::~ContinueStmt()
{
	// not used
}

bool ContinueStmt::gen_Code(IdentsHandler & identHandler)
#line 24 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    
}
#line 2450 "../src/ast.cpp"

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

BreakStmt::BreakStmt()
	: Statement()
{
	this->kind__ = BreakStmt_kind;
	this->label = "";
}

BreakStmt::~BreakStmt()
{
	// not used
}

bool BreakStmt::gen_Code(IdentsHandler & identHandler)
#line 29 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    
}
#line 2482 "../src/ast.cpp"

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

FunctionCallStmt::FunctionCallStmt(string_t id, ASTNode * param_list)
	: Statement()
{
	this->kind__ = FunctionCallStmt_kind;
	this->id = id;
	this->param_list = param_list;
}

FunctionCallStmt::~FunctionCallStmt()
{
	// not used
}

bool FunctionCallStmt::gen_Code(IdentsHandler & identHandler)
#line 19 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    

}
#line 2516 "../src/ast.cpp"

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

VarDecStmt::VarDecStmt(string_t type, ASTNode * list)
	: Statement()
{
	this->kind__ = VarDecStmt_kind;
	this->type = type;
	this->list = list;
}

VarDecStmt::~VarDecStmt()
{
	// not used
}

int VarDecStmt::isA(int kind) const
{
	if(kind == VarDecStmt_kind)
		return 1;
	else
		return Statement::isA(kind);
}

const char *VarDecStmt::getKindName() const
{
	return "VarDecStmt";
}

BlockStmt::BlockStmt(ASTNode * stmt_list)
	: Statement()
{
	this->kind__ = BlockStmt_kind;
	this->stmt_list = stmt_list;
}

BlockStmt::~BlockStmt()
{
	// not used
}

bool BlockStmt::Func_Decl(IdentsHandler & identHandler)
#line 81 "/home/boris/Desktop/Proyecto/src/LoadFunc.tc"
{
    nodeList *lst = static_cast<nodeList *>(stmt_list);
    
    while (lst != nullptr) 
    {
        ASTNode *curr = lst->node;
        if(!lst->Func_Decl(identHandler))
            return false;
        lst = lst->next;
    }
    return true;
}
#line 2583 "../src/ast.cpp"

bool BlockStmt::gen_Code(IdentsHandler & identHandler)
#line 61 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    std::ostringstream ss;
    nodeList *lista = static_cast<nodeList *>(stmt_list);
    while(lista != nullptr)
    {
        if(!lista->node->gen_Code(identHandler))
            return false;
        if(lista->node->isA(NextIntStmt_kind))
            std::cerr<<"Line: "<<lista->node->getLinenum()<<" -> warning: expression result unused\n";
        if(lista->node->isA(ReadStmt_kind))
        {
            std::cerr<<"Line: "<<lista->node->getLinenum()<<" -> Error: System.in.read value result unused\n";
            exit(1);
        }
        ss << lista->node->code <<"\n";
        lista = lista->next;
        
    }
    code = ss.str();
    return true;
}
#line 2608 "../src/ast.cpp"

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

