#include "Fixed.hpp"

const int FixedNumber::FractionalBit = 8;

FixedNumber::FixedNumber() {
	this->number = 0;
}

FixedNumber::FixedNumber(int inumber) {
	setNumber(inumber * (1 << FractionalBit));
}

FixedNumber::FixedNumber(float fnumber) {
	setNumber((int)roundf(fnumber * (1 << this->FractionalBit)));
}

FixedNumber::FixedNumber(const FixedNumber &other) {
	*this = other;
}

FixedNumber &FixedNumber::operator=(const FixedNumber &other) {
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

}

FixedNumber FixedNumber::operator++(int) {
	FixedNumber tmp;
	tmp.setNumber(this->getNumber());
	this->setNumber(this->getNumber() + 1);
	return (tmp);
}

FixedNumber FixedNumber::operator++() {
	this->setNumber(this->getNumber() + 1);
	return (*this);
}

FixedNumber FixedNumber::operator--(int) {
	FixedNumber tmp;
	tmp.setNumber(this->getNumber());
	this->setNumber(this->getNumber() - 1);
	return (tmp);
}

FixedNumber FixedNumber::operator--() {
	this->setNumber(this->getNumber() - 1);
	return (*this);
}

FixedNumber &FixedNumber::min(FixedNumber &nbr1, FixedNumber &nbr2) {
	if(nbr1 > nbr2)
		return (nbr2);
	return (nbr1);
}

const FixedNumber &FixedNumber::min(const FixedNumber &nbr1, const FixedNumber &nbr2) {
	if(nbr1.getNumber() > nbr2.getNumber())
		return (nbr2);
	return (nbr1);
}

FixedNumber &FixedNumber::max(FixedNumber &nbr1, FixedNumber &nbr2) {
	if(nbr1 > nbr2)
		return (nbr1);
	return (nbr2);
}

const FixedNumber &FixedNumber::max(const FixedNumber &nbr1, const FixedNumber &nbr2) {
	if(nbr1.getNumber() > nbr2.getNumber())
		return (nbr1);
	return (nbr2);
}

bool FixedNumber::operator!=(const FixedNumber &nbr) {
	return (this->getNumber() != nbr.getNumber());
}

bool FixedNumber::operator==(const FixedNumber &nbr) {
	return (this->getNumber() ==  nbr.getNumber());
}

bool FixedNumber::operator>(const FixedNumber &nbr) {
	return (this->getNumber() >  nbr.getNumber());
}

bool FixedNumber::operator<(const FixedNumber &nbr) {
	return (this->getNumber() <  nbr.getNumber());
}

bool FixedNumber::operator>=(const FixedNumber &nbr) {
	return (this->getNumber() >=  nbr.getNumber());
}

bool FixedNumber::operator<=(const FixedNumber &nbr) {
	return (this->getNumber() <=  nbr.getNumber());
}

FixedNumber FixedNumber::operator+(const FixedNumber &nbr) {
	return (FixedNumber(this->toFloat() + nbr.toFloat()));
}

FixedNumber FixedNumber::operator-(const FixedNumber &nbr) {
	return (FixedNumber(this->toFloat() - nbr.toFloat()));
}

FixedNumber FixedNumber::operator*(const FixedNumber &nbr) {
	return (FixedNumber(this->toFloat() * nbr.toFloat()));
}

FixedNumber FixedNumber::operator/(const FixedNumber &nbr) {
	return (FixedNumber(this->toFloat() / nbr.toFloat()));
}