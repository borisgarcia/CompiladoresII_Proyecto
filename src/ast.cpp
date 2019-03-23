/* ../src/ast.cpp.  Generated automatically by treecc */
#line 29 "/home/boris/Desktop/Proyecto/src/AST.tc"

    #include "ast.h"
    
    std::string getPlace(ASTNode * expr)
    {
        if(expr->getKind() == NumExpr_kind)
            return expr->place;
        else
            return "dword [" + expr->place + "]";
    }
#line 14 "../src/ast.cpp"

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
#line 293 "../src/ast.cpp"
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

bool NumExpr::genCode(IdentsHandler identHandler)
#line 348 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    place = std::to_string(value);
    return true;    
}
#line 398 "../src/ast.cpp"

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

StringConstant::StringConstant(string_t value)
	: Expression()
{
	this->kind__ = StringConstant_kind;
	this->value = value;
}

StringConstant::~StringConstant()
{
	// not used
}

bool StringConstant::genCode(IdentsHandler identHandler)
#line 342 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    place = identHandler.registerStrLiteral(value);
    return true;
}
#line 431 "../src/ast.cpp"

int StringConstant::isA(int kind) const
{
	if(kind == StringConstant_kind)
		return 1;
	else
		return Expression::isA(kind);
}

const char *StringConstant::getKindName() const
{
	return "StringConstant";
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

bool CharExpr::genCode(IdentsHandler identHandler)
#line 354 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    place = std::to_string(value);
    return true;    
}
#line 464 "../src/ast.cpp"

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

NotExpr::NotExpr(Expression * expr)
	: OneExpr(expr)
{
	this->kind__ = NotExpr_kind;
}

NotExpr::~NotExpr()
{
	// not used
}

bool NotExpr::genCode(IdentsHandler identHandler)
#line 740 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{

}
#line 521 "../src/ast.cpp"

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

bool NegExpr::genCode(IdentsHandler identHandler)
#line 718 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr->genCode(identHandler)) {
        return false;
    }
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
#line 569 "../src/ast.cpp"

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

bool AddExpr::genCode(IdentsHandler identHandler)
#line 361 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->genCode(identHandler))
        return false;
    if (!expr2->genCode(identHandler))
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
#line 613 "../src/ast.cpp"

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

bool SubExpr::genCode(IdentsHandler identHandler)
#line 457 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->genCode(identHandler))
        return false;
    if (!expr2->genCode(identHandler))
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
#line 657 "../src/ast.cpp"

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

bool MulExpr::genCode(IdentsHandler identHandler)
#line 475 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->genCode(identHandler))
        return false;
    if (!expr2->genCode(identHandler))
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
#line 702 "../src/ast.cpp"

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

bool DivExpr::genCode(IdentsHandler identHandler)
#line 494 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->genCode(identHandler)) {
        return false;
    }
    if (!expr2->genCode(identHandler)) {
        return false;
    }
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
#line 750 "../src/ast.cpp"

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

bool SRLExpr::genCode(IdentsHandler identHandler)
#line 417 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->genCode(identHandler)) {
        return false;
    }
    if (!expr2->genCode(identHandler)) {
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
#line 796 "../src/ast.cpp"

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

bool SLLExpr::genCode(IdentsHandler identHandler)
#line 437 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->genCode(identHandler)) {
        return false;
    }
    if (!expr2->genCode(identHandler)) {
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
#line 842 "../src/ast.cpp"

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

bool ModExpr::genCode(IdentsHandler identHandler)
#line 516 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->genCode(identHandler)) {
        return false;
    }
    if (!expr2->genCode(identHandler)) {
        return false;
    }
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
#line 890 "../src/ast.cpp"

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

bool LesExpr::genCode(IdentsHandler identHandler)
#line 538 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->genCode(identHandler))
        return false;
    
    if (!expr2->genCode(identHandler)) 
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
#line 946 "../src/ast.cpp"

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

bool GreExpr::genCode(IdentsHandler identHandler)
#line 568 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
     if (!expr1->genCode(identHandler))
        return false;
    
    if (!expr2->genCode(identHandler)) 
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
#line 1002 "../src/ast.cpp"

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

bool LeEExpr::genCode(IdentsHandler identHandler)
#line 598 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->genCode(identHandler))
        return false;
    
    if (!expr2->genCode(identHandler)) 
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
#line 1058 "../src/ast.cpp"

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

bool GrEExpr::genCode(IdentsHandler identHandler)
#line 628 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
     if (!expr1->genCode(identHandler))
        return false;
    
    if (!expr2->genCode(identHandler)) 
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
#line 1114 "../src/ast.cpp"

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

bool EquExpr::genCode(IdentsHandler identHandler)
#line 658 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->genCode(identHandler))
        return false;
    
    if (!expr2->genCode(identHandler)) 
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
#line 1170 "../src/ast.cpp"

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

bool NEqExpr::genCode(IdentsHandler identHandler)
#line 688 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
   if (!expr1->genCode(identHandler))
        return false;
    
    if (!expr2->genCode(identHandler)) 
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
#line 1226 "../src/ast.cpp"

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

bool AndExpr::genCode(IdentsHandler identHandler)
#line 379 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->genCode(identHandler)) 
        return false;
    if (!expr2->genCode(identHandler)) 
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
#line 1270 "../src/ast.cpp"

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

bool Or_Expr::genCode(IdentsHandler identHandler)
#line 397 "/home/boris/Desktop/Proyecto/src/genCode.tc"
{
    if (!expr1->genCode(identHandler)) {
        return false;
    }
    if (!expr2->genCode(identHandler)) {
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
#line 1316 "../src/ast.cpp"

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

