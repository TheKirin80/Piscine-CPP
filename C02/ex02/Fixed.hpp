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
        Fixed   &operator=(const Fixed &eg);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat( void ) const;
        int     toInt( void ) const;
        bool    operator>(const Fixed &eg) const;
        bool    operator<(const Fixed &eg) const;
        bool    operator>=(const Fixed &eg) const;
        bool    operator<=(const Fixed &eg) const;
        bool    operator==(const Fixed &eg) const;
        bool    operator!=(const Fixed &eg) const;
        Fixed   operator+(const Fixed &eg) const;
        Fixed   operator-(const Fixed &eg) const;
        Fixed   operator*(const Fixed &eg) const;
        Fixed   operator/(const Fixed &eg) const;
        Fixed   operator++(int);
        Fixed   &operator++(void);
        Fixed   operator--(int);
        Fixed   &operator--(void);
        static Fixed   &min(Fixed &a, Fixed &b);
        static Fixed   &max(Fixed &a, Fixed &b);
        static const Fixed   &min(const Fixed &a, const Fixed &b);
        static const Fixed   &max(const Fixed &a, const Fixed &b);

    private :

        int value;
        static const int bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed & fix);

#endif