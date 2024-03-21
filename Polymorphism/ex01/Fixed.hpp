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
		FixedNumber(const FixedNumber &other);
		FixedNumber &operator=(const FixedNumber &other);

		int toInt( void ) const;
		float toFloat( void ) const;
		int getNumber( void ) const;
		void setNumber( int const raw );

};
std::ostream &operator<<(std::ostream &os, const FixedNumber &FixedNumber);

#endif