#ifndef OPERAND_H
#define OPERAND_H
#include "Primary.h"
class Operand : public Expression
{
	double value;
public:
	Operand() : value(0.0) {}
	Operand(double v) : value(v){}

	double Calculate()
	{
		return value;
	}
};

#endif