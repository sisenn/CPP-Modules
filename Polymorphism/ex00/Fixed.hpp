#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class FixedNumber {

    private:

        int number;
	    static const int FractionalBit;

    public:

        FixedNumber();
        ~FixedNumber();
    	FixedNumber(const FixedNumber &other);
	    FixedNumber &operator=(const FixedNumber &other);
	    int getRawBits( void ) const;
	    void setRawBits( int const raw );

};

#endif