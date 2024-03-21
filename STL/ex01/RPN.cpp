#include "RPN.hpp"

RPN::RPN()
{
	return;
}

RPN::~RPN()
{
	return;
}

RPN::RPN(std::stack<double> number)
{
	this->numStack = number;
}

RPN::RPN(const RPN &var)
{
	*this = var;
}

RPN &RPN::operator=(const RPN &var)
{
	this->numStack = var.numStack;
	return (*this);
}

void RPN::calculate(std::string input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		char c = input[i];

		if (c == ' ')
		{
			continue;
		}
		else if (isdigit(c))
		{
			int number = c - '0';
			numStack.push(number);
		}
		else if (c == '+' && numStack.size() >= 2)
		{
			double b = numStack.top();
			numStack.pop();
			double a = numStack.top();
			numStack.pop();
			numStack.push(a + b);
		}
		else if (c == '-' && numStack.size() >= 2)
		{
			double b = numStack.top();
			numStack.pop();
			double a = numStack.top();
			numStack.pop();
			numStack.push(a - b);
		}
		else if (c == '*' && numStack.size() >= 2)
		{
			double b = numStack.top();
			numStack.pop();
			double a = numStack.top();
			numStack.pop();
			numStack.push(a * b);
		}
		else if (c == '/' && numStack.size() >= 2)
		{
			double b = numStack.top();
			numStack.pop();
			double a = numStack.top();
			numStack.pop();
			numStack.push(a / b);
		}
		else
		{
			std::cout << "Invalid input." << std::endl;
			return;
		}
	}

	if (numStack.size() == 1)
	{
		double result = numStack.top();
		numStack.pop();
		std::cout << "Result: " << result << std::endl;
	}
	else
	{
		std::cout << "Invalid input." << std::endl;
	}
}
