#include "Fixed.hpp"

int main()
{

    FixedNumber a;
    FixedNumber b( a );
    FixedNumber c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    
    return 0;
}