#include "Fixed.hpp"

const int FixedNumber::FractionalBit = 8;

FixedNumber::FixedNumber() {
    std::cout << "Default constructor called" << std::endl;
    this->number = 0;
}


FixedNumber::~FixedNumber() {
    std::cout << "Destructor called" << std::endl;
}

FixedNumber::FixedNumber(const FixedNumber &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

FixedNumber &FixedNumber::operator=(const FixedNumber &other) {
    std::cout << "Copy assigment operator called" << std::endl;
    if(this != &other)
        setRawBits(other.getRawBits());
	return (*this);
}

int FixedNumber::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
	return number;
}

void FixedNumber::setRawBits( int const raw ) {
	number = raw;
}