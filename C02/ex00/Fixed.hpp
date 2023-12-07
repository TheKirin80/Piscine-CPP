#ifndef FIXED_HPP
#define FIXED_HPP

#include <cstdlib>
#include <iostream>

class Fixed
{
    public :
        Fixed(void);
        Fixed(const Fixed &cop);
        Fixed   &operator=(const Fixed&eg);
        ~Fixed(void);
        int getRawBits(void) const;
        void setRawBits(int val);
    private :
        int value;
        static const int bits = 8;
};

#endif