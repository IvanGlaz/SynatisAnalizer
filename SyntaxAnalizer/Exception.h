#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Exception
{
	std::string message;

public:

	Exception() : message("") {

	}

	Exception(const std::string msg) : message(msg) {

	}

	std::string GetMessage() const
	{
		return message;
	}
};

#endif