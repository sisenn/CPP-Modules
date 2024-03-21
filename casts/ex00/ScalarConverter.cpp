#include "ScalarConverter.hpp"
#include <stdlib.h>

ScalarConverter::ScalarConverter() : input("null") {}
ScalarConverter::ScalarConverter(const ScalarConverter &) : input("null") {}
ScalarConverter::ScalarConverter(const std::string input) : input(input)
{
	this->searchType();
}
ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (this == &copy)
		return (*this);

	return (*this);
}

std::string ScalarConverter::getInput() const
{
	return (this->input);
}

void ScalarConverter::searchType()
{
	if (this->checkNanInf())
		printNanInf();
	else if (this->checkChar())
		convertToChar();
	else if (this->checkInt())
		convertToInt();
	else if (this->checkFloat())
		convertToFloat();
	else if (this->checkDouble())
		convertToDouble();
	else
		printImpossible();
}

bool ScalarConverter::checkNanInf()
{
	if ((this->input == "+inff") || (this->input == "-inff") || (this->input == "nanf") ||
		(this->input == "+inf") || (this->input == "-inf") || (this->input == "nan"))
		return true;
	return false;
}
bool ScalarConverter::checkChar()
{
	if (this->input.length() == 1 && !isdigit(this->input[0]) && isprint(this->input[0]))
		return true;
	return false;
}
bool ScalarConverter::checkInt()
{
	int i = 0;
	int sign = 1;
	int len = static_cast<int>(this->input.length());

	if (input[i] == '-')
	{
		i++;
		sign = -1;
	}
	for (; i < len; i++)
	{
		if (!isdigit(this->input[i]))
			return false;
	}

	unsigned int i_dec;
	if (sign == -1)
	{
		const char *i_ptr = &this->input[1];
		i_dec = atoi(i_ptr);
	}
	else
	{
		const char *i_ptr = &this->input[0];
		i_dec = atoi(i_ptr);
	}
	if ((sign == -1 && i_dec > 2147483648) || (sign == 1 && i_dec > 2147483647))
	{
		return false;
	}
	return true;
}

bool ScalarConverter::checkFloat()
{
	int i = 0;
	int sign = 1;
	int len = static_cast<int>(this->input.length());

	if (input[i] == '-')
	{
		i++;
		sign = -1;
	}
	for (; i < len; i++)
	{
		if (!(isdigit(this->input[i]) || this->input[i] == '.' || this->input[i] == 'f'))
		{
			return false;
		}
	}

	if (this->input.find_first_of("f") != this->input.find_last_of("f") ||
		this->input.find_first_of(".") != this->input.find_last_of(".") ||
		this->input.find_first_of("f") - this->input.find_first_of(".") == 1 ||
		this->input.find_first_of(".") == 0 ||
		this->input[this->input.find_first_of("f") + 1] != '\0')
		return false;
	return true;
}

bool ScalarConverter::checkDouble()
{
	int i = 0;
	int sign = 1;
	int len = static_cast<int>(this->input.length());

	if (input[i] == '-')
	{
		i++;
		sign = -1;
	}
	for (; i < len; i++)
	{
		if (!(isdigit(this->input[i]) || this->input[i] == '.'))
		{
			return false;
		}
	}

	if (this->input.find_first_of(".") != this->input.find_last_of(".") ||
		(this->input.find_last_of(".") - (std::strlen(this->input.c_str()) - 1) == 0))
		return false;

	char *end;
	std::strtod(this->input.c_str(), &end);
	if (errno == ERANGE)
	{
		return false;
	}
	return true;
}

void ScalarConverter::printNanInf()
{
	if (this->input == "-inf" || this->input == "-inff")
	{
		std::cout << "char: impossible " << std::endl;
		std::cout << "int: impossible " << std::endl;
		std::cout << "float: -inff " << std::endl;
		std::cout << "double: -inf " << std::endl;
	}
	if (this->input == "+inf" || this->input == "+inff")
	{
		std::cout << "char: impossible " << std::endl;
		std::cout << "int: impossible " << std::endl;
		std::cout << "float: +inff " << std::endl;
		std::cout << "double: +inf " << std::endl;
	}
	if (this->input == "nan")
	{
		std::cout << "char: impossible " << std::endl;
		std::cout << "int: impossible " << std::endl;
		std::cout << "float: nanf " << std::endl;
		std::cout << "double: nan " << std::endl;
	}
	if (this->input == "nanf")
	{
		std::cout << "error: impossible convertion" << std::endl;
	}
}
void ScalarConverter::convertToChar()
{
	char c = this->input[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}
void ScalarConverter::convertToInt()
{
	const char *i_ptr = &this->input[0];
	int i_dec = atoi(i_ptr);

	std::cout << std::fixed << std::setprecision(1);
	char c = static_cast<char>(i_dec);
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i_dec << std::endl;
	std::cout << "float: " << static_cast<float>(i_dec) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i_dec) << std::endl;
}
void ScalarConverter::convertToFloat()
{
	charError = false;
	intError = false;
	floatError = false;
	doubleError = false;
	char c;
	int i;


	char *end;
	float f = static_cast<float>(std::strtod(this->input.c_str(), &end));
	if (errno == ERANGE)
	{
		intError = true;
		floatError = true;
		charError = true;
	}


	long intCheckL = static_cast<long>(f);
	if (intCheckL > std::numeric_limits<char>::max() || intCheckL < std::numeric_limits<char>::min())
	{
		charError = true;
	}
	else
		c = static_cast<char>(f);


	if (intCheckL > std::numeric_limits<int>::max() || intCheckL < std::numeric_limits<int>::min())
	{
		intError = true;
	}
	else
		i = static_cast<int>(f);


	std::cout << std::fixed << std::setprecision(1);

	if (charError == true)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(c) == false || isnumber(c) == true)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;

	if (intError == true)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	if (floatError == true)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << this->input << std::endl;

	if (floatError)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(f) << std::endl;
}
void ScalarConverter::convertToDouble()
{
	charError = false;
	intError = false;
	floatError = false;
	doubleError = false;
	char c;
	int i;
	float f;

	char *end;
	double d = std::strtod(this->input.c_str(), &end);
	if (errno == ERANGE)
	{
		charError = true;
		intError = true;
		floatError = true;
		doubleError = true;
	}

	long intCheckL = static_cast<long>(d);
	if (intCheckL > std::numeric_limits<char>::max() || intCheckL < std::numeric_limits<char>::min())
		charError = true;
	else
		c = static_cast<char>(d);

	if (intCheckL > std::numeric_limits<int>::max() || intCheckL < std::numeric_limits<int>::min())
		intError = true;
	else
		i = static_cast<int>(d);

	if ( d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		floatError = true;
	else
		f = static_cast<float>(d);

	std::cout << std::fixed << std::setprecision(1);
	if (charError == true)
		std::cout << "char: impossible" << std::endl;
	else if (isprint(c) == false || isnumber(c) == true)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;

	if (intError == true)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	if (floatError == true)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;

	if (floatError)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << this->input << std::endl;
}

void ScalarConverter::printImpossible()
{
	std::cout << "char: invalid type" << std::endl;
	std::cout << "int: invalid type " << std::endl;
	std::cout << "float: invalid type " << std::endl;
	std::cout << "double: invalid type " << std::endl;
}
