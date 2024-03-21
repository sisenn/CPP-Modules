#include "Fixed.hpp"

int main( void )
{
	FixedNumber a;
	FixedNumber const b( 10 );
	FixedNumber const c( 42.42f );
	FixedNumber const d( b );

	a = FixedNumber( 1234.4321f );
    
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}