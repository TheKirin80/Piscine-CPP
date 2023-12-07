#include <iostream>
#include "Fixed.hpp"

// int main( void ) 
// {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;
//     return 0;
// }

int main(void)
{
    
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << "Deuxieme partie du main" << std::endl;
    Fixed   c(15.5f);
    Fixed   d(14.09f);
    std::cout << (c > d) << std::endl;
    std::cout << (c < d) << std::endl;
    std::cout << (c >= d) << std::endl;
    std::cout << (c <= d) << std::endl;
    std::cout << (c == d) << std::endl;
    std::cout << (c != d) << std::endl;
    std::cout << (c + d) << std::endl;
    std::cout << (c - d) << std::endl;
    std::cout << (c * d) << std::endl;
    std::cout << (c / d) << std::endl;
    std::cout << (c++) << std::endl;
    std::cout << (c) << std::endl;
    std::cout << (++c) << std::endl;
    std::cout << (c--) << std::endl;
    std::cout << (--c) << std::endl;
    std::cout << Fixed::max(c, d) << std::endl;
    std::cout << Fixed::min(c, d) << std::endl;
    return (0);
}