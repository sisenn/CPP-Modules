#include "Fixed.hpp"

const int FixedNumber::FractionalBit = 8;

FixedNumber::FixedNumber() {
	std::cout << "Default construtor called" << std::endl;
	this->number = 0;
}

FixedNumber::FixedNumber(int integerPart) {
	std::cout << "Int constructor called" << std::endl;
	setNumber(integerPart * (1 << FractionalBit));
}

FixedNumber::FixedNumber(float floatPart) {
	std::cout << "Float constructor called" << std::endl;
	setNumber((int)roundf(floatPart * (1 << this->FractionalBit)));
}

FixedNumber::FixedNumber(const FixedNumber &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

FixedNumber &FixedNumber::operator=(const FixedNumber &other) {
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &other)
		setNumber(other.getNumber());
	return *this;
}

int FixedNumber::toInt( void ) const {
	return  getNumber() / (1 << FractionalBit);
}

float FixedNumber::toFloat( void ) const {
	return  (float)getNumber() / (1 << FractionalBit);
}

std::ostream &operator<<(std::ostream &os, const FixedNumber &FixedNumber) {
	os << FixedNumber.toFloat();
	return os;
}


int FixedNumber::getNumber( void ) const {
	return (number);
}

void FixedNumber::setNumber( int const raw) {
	this->number = raw;
}


FixedNumber::~FixedNumber() {
	std::cout << "Destructor called" << std::endl;

}