#include "C.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Base* generate()
{
	srand(time(NULL));
	int some = rand() % 3;
	if (some == 2)
	{
		std::cout << "A created" << std::endl;
		return new A;
	}
	else if (some == 1)
	{
		std::cout << "B created" << std::endl;
		return new B;
	}	
	std::cout << "C created" << std::endl;
	return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "pointer is A" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "pointer is B" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "pointer is C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		Base &na = dynamic_cast<A&>(p);
		(void)na;
		std::cout << "pointer is A" << std::endl;
	}
	catch(const std::bad_cast &bad) {}
	try
	{
		Base &nb = dynamic_cast<B&>(p);
		(void)nb;
		std::cout << "pointer is B" << std::endl;
	}
	catch(const std::bad_cast &bad) {}
	try
	{
		Base &nc = dynamic_cast<C&>(p);
		(void)nc;
		std::cout << "pointer is C" << std::endl;
	}
	catch(const std::bad_cast &bad) {}
}

int main ()
{
	Base *ptr = generate();
	Base * &some = ptr;
	identify(ptr);
	identify(some);
	delete ptr;
}