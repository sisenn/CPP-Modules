#include "Fixed.hpp"

int main( void )
{
  FixedNumber a;
  FixedNumber const b( FixedNumber( 5.05f ) * FixedNumber( 2 ) );

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;

  std::cout << b << std::endl;

  std::cout << FixedNumber::max( a, b ) << std::endl;
  
  return 0;
}