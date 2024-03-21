#include <unistd.h>
#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{

	if ((argc != 2) || (argc == 2 && argv[1] && strlen(argv[1]) == 0))
	{
		std::cout << "error: 1 argument input needed for conversion" << std::endl;
		return 1;
	}

	try
	{
		ScalarConverter cvt(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
