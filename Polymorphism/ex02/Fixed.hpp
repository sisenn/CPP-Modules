#ifndef Fixed_HPP
#define Fixed_HPP

#include <iostream>
#include <cmath>

class FixedNumber
{
	private:

		int number;
		static const int FractionalBit;

	public:

		FixedNumber();
        ~FixedNumber();
		FixedNumber(int integerPart);
		FixedNumber(float floatPart);
		FixedNumber(const FixedNumber &FixedNumber);
		FixedNumber &operator=(const FixedNumber &number);

		int toInt( void ) const;
		float toFloat( void ) const;

		int getNumber( void ) const;
		void setNumber( int const raw );

		FixedNumber operator++(int);
		FixedNumber operator++();
		FixedNumber operator--(int);
		FixedNumber operator--();

		FixedNumber operator+(const FixedNumber &number);
		FixedNumber operator-(const FixedNumber &number);
		FixedNumber operator*(const FixedNumber &number);
		FixedNumber operator/(const FixedNumber &number);

		bool operator!=(const FixedNumber &number);
		bool operator==(const FixedNumber &number);
		bool operator>(const FixedNumber &number);
		bool operator<(const FixedNumber &number);
		bool operator>=(const FixedNumber &number);
		bool operator<=(const FixedNumber &number);

		static FixedNumber &min(FixedNumber &number1, FixedNumber &number2);
		static FixedNumber &max(FixedNumber &number1, FixedNumber &number2);
		
		static const FixedNumber &min(const FixedNumber &number1, const FixedNumber &number2);
		static const FixedNumber &max(const FixedNumber &number1, const FixedNumber &number2);

};

std::ostream &operator<<(std::ostream &os, const FixedNumber &FixedNumber);


#endif