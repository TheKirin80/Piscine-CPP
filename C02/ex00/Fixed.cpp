#include "Fixed.hpp"

Fixed::Fixed(void): value(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}
Fixed::Fixed(const Fixed &cop)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = cop;
}
Fixed   &Fixed::operator=(const Fixed&eg)
{
    std::cout << "Copy assignment operator called" << std::endl;
    value = eg.getRawBits();
    return(*this);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}