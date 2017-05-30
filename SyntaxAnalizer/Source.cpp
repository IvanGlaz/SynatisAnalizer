#include <iostream>
#include <string>

#include "Expression.h"
#include "Primary.h"
#include "Tests.h"
#include "Factor.h"
#include "Operand.h"
#include "Parser.h"

using namespace std;

int main() 
{
	TEST("Test 1", "6+7", 13, false);
	TEST("Test 2", "9-5", 4, false);
	TEST("Test 3", "25+17", 42, false);
	TEST("Test 4", "25-17", 8, false);
	TEST("Test 5", "255 - 17", 238, false);
	TEST("Test 6", "r-17", 8, true);

	TEST("Test 7", "6+7+5", 18, false);
	TEST("Test 8", "9-5-1", 3, false);
	TEST("Test 9", "6+7-5", 8, false);
	return 0;
}


