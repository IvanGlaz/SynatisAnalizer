#ifndef PARSER_H
#define PARSER_H
#include <string>

#include "Operand.h"
#include "Expression.h"
#include "Factor.h"
#include "Primary.h"
#include "Exception.h"

class Parser
{
protected:
	std::string expression;
public:
	Parser() : expression("")
	{

	}
	Parser(std::string a) : expression(a)
	{

	}
	Expression* Evaluate()
	{
		return parseFactor();
	}

	Expression* parseFactor()
	{
		char operand = '\0';
		double rvalue = 0.0, lvalue = 0.0;

		//3.14 + 67
		std::string lvalues;
		int i = 0;
		while ((expression[i] != '+') && (expression[i] != '-'))
		{
			if (expression[i] < 48 || expression[i] > 57)
				throw new Exception("Value from left of the operator is wrong!\n");
			lvalues += expression[i++];
		}
		lvalue = atof(lvalues.c_str());
		while ((expression[i] != '+') && (expression[i] != '-')) { ++i; }
		operand = expression[i++];
		while (expression[i] == ' ') { ++i; }
		std::string rvalues;
		while ((expression[i] != '+') && (expression[i] != '-') && i < expression.size())
		{
			if (expression[i] < 48 || expression[i] > 57)
				throw new Exception("Value from right of the operator is wrong!\n");
			rvalues += expression[i++];
		}
		rvalue = atof(rvalues.c_str());
		
		Factor* ret = new Factor();

		Factor::OpCode op;
		if (operand == '+')
			op = Factor::OpCode::PLUS;
		else if (operand == '-')
			op = Factor::OpCode::MINUS;
		ret->op = op;

		Expression* left = new Operand(lvalue);
		ret->left = left;
	//	5+6+677-
		if (i + 1 == expression.size())
		{
			Expression* right = new Operand(rvalue);
			ret->right = right;

			return ret;
		}
		//Expression* right = new 
		operand = expression[i++];
		Factor::OpCode op1;
		if (operand == '+')
			op1 = Factor::OpCode::PLUS;
		else if (operand == '-')
			op1 = Factor::OpCode::MINUS;
		Factor* factor2 = new Factor();
		ret->right = factor2;
		factor2->left = new Operand(rvalue);
		factor2->op = op1;
		rvalues.clear();
		while ((expression[i] != '+') && (expression[i] != '-') && (i != expression.size()))
		{
			if (expression[i] < 48 || expression[i] > 57)
			{
				throw new Exception("Value from right of the operator is wrong!\n");
			}
			rvalues += expression[i];
			++i;
		}
		rvalue = 0.0;
		rvalue = atof(rvalues.c_str());
		factor2->right = new Operand(rvalue);
		return ret;

	}
	Primary* parsePrimary()
	{
		Primary* ret = NULL;
		//if () // if digit 
		//ret = parseOperand();
		return ret;
	}

	Operand* parseOperand()
	{
		return new Operand();
	}
};

#endif