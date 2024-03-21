#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

# include <iomanip>

class ScalarConverter
{
private:
	const std::string	input;
	bool				charError;
	bool				intError;
	bool				floatError;
	bool				doubleError;

public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &);
	ScalarConverter(std::string input);
	~ScalarConverter();

	ScalarConverter &operator=(const ScalarConverter &);
	std::string getInput() const;

	void	searchType();

	bool	checkNanInf();
	bool	checkChar();
	bool	checkInt();
	bool	checkFloat();
	bool	checkDouble();

	void	printNanInf();
	void	convertToChar();
	void	convertToInt();
	void	convertToFloat();
	void	convertToDouble();

	void	printImpossible();
};

#endif
