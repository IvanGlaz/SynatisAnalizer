#ifndef FACTOR_H
#define FACTOR_H
#include "Expression.h"
class Factor : public Expression
{
public:
	enum OpCode { PLUS, MINUS, NONE };
public:
	OpCode op;
	Expression* right;
	Expression* left;

	double Calculate()
	{
		if (op == PLUS)
			return left->Calculate() + right->Calculate();
		return left->Calculate() - right->Calculate();
		/*
		if (op == PLUS)
			return ((Operand*)left)->GetValue() + ((Operand*)right)->GetValue();
		return ((Operand*)left)->GetValue() - ((Operand*)right)->GetValue();
*/	}
};

#endif