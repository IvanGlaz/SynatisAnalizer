#ifndef TEST_H
#define TEST_H
#include <string>
#include <iostream>
#include "Expression.h"
#include "Parser.h"

const bool DEBUG_VIEW = false;

bool Test(std::string input, double expected, const bool isExceptionCheck = false)
{
	if (DEBUG_VIEW)
	{
		std::cout << "\n---------\n";
		std::cout << "input: " << input
			<< "\nexpected: " << expected;
	}

	try
	{
		Parser parser(input);
		Expression* treeExpression = parser.Evaluate();
		const double ret = treeExpression->Calculate();
		if (DEBUG_VIEW)
		{
			std::cout << "\nresult: " << ret << "\n";
		}
		return expected == ret;
	}
	catch (Exception* e)
	{
		if (isExceptionCheck)
			return true;
	}
}

#define TEST(TestName, Input, Expected, ExceptionCheck) std::cout << TestName << " " << (Test(Input, Expected, ExceptionCheck) ? "SUCCESS\n" : "FAILED\n")

#endif