#ifndef FIXED_HPP
#define FIXED_HPP

#include <cstdlib>
#include <iostream>
#include <cmath>

class Fixed
{
    public :
        Fixed(void);
        Fixed(const Fixed &cop);
        Fixed(const int fix_int);
        Fixed(const float fix_float);
        ~Fixed(void);
        Fixed   &operator=(const Fixed&eg);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat( void ) const;
        int     toInt( void ) const;

    private :

        int value;
        static const int bits = 8;
};

std::ostream& operator<<(std::ostream& os, Fixed const & fix);

#endif