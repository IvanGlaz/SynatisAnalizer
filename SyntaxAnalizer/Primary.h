#ifndef PRIMARY_H
#define PRIMARY_H

class Primary : public Expression
{
public:
	enum OpCode { MULTI, DIVISION, NONE };
private:
	OpCode op;
	Expression* right;
	Expression* left;
public:
	double Calculate()
	{
		return 0.0;
	}
};

#endif

