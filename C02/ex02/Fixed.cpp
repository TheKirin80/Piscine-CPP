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

Fixed   &Fixed::operator=(const Fixed &eg)
{
    std::cout << "Copy assignment operator called" << std::endl;
    value = eg.getRawBits();
    return(*this);
}

Fixed::Fixed(const int fix_int)
{
    std::cout << "Int constructor called" << std::endl;
    value = fix_int << bits; // on va bitshift afin de decaler du nombre de bit fractionnaire demande
}

Fixed::Fixed(const float fix_float)
{
    std::cout << "Float constructor called" << std::endl;
    value = (int)(roundf(fix_float * (1 << bits)));
    //1 << bits est equivalent a 2^bits a la difference que c'est moins lourd pour la machine le calcul
    //avec une valeur bitshifter plutot qu'un exponentiel sur une multiplication avec un float
    //roundf permet de faire un arrondi entier de la valeur passer en parametre, on perd la precision 
    //excedentaire mais on rentre dans le cadre de la virgule fixe
    
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

float Fixed::toFloat( void ) const // Operation inverse de la construction en float
{
    float ret;
    ret = (float)value / (float)(1 << bits);
    return (ret);
}

int Fixed::toInt( void ) const // Operation inverse de la construction en int
{
    int ret;
    ret = value >> bits;
    return (ret);
}

std::ostream& operator<<(std::ostream& os, const Fixed & fix)
{
    os << fix.toFloat(); 
    //ostream correspond au flux de sortie choisis. Ensuite la surcharge ne consiste qu'a
    //utiliser la fonction precedemment implemente de Fixed pour integrer le bon resultat au flux de
    //sortie.
    return os;
}

bool Fixed::operator>(const Fixed &eg) const
{
    return (value > eg.getRawBits());
}

bool Fixed::operator<(const Fixed &eg) const
{
    return (value < eg.getRawBits());
}

bool Fixed::operator>=(const Fixed &eg) const
{
    return (value >= eg.getRawBits());
}

bool Fixed::operator<=(const Fixed &eg) const
{
    return (value <= eg.getRawBits());
}

bool Fixed::operator==(const Fixed &eg) const
{
    return (value == eg.getRawBits());
}

bool Fixed::operator!=(const Fixed &eg) const
{
    return (value != eg.getRawBits());
}

Fixed Fixed::operator+(const Fixed &eg) const
{
    float ret;
    ret = this->toFloat() + eg.toFloat();
    return (Fixed(ret));
}

Fixed Fixed::operator-(const Fixed &eg) const
{
    float ret;
    ret = this->toFloat() - eg.toFloat();
    return (Fixed(ret));
}

Fixed Fixed::operator*(const Fixed &eg) const
{
    float ret;
    ret = this->toFloat() * eg.toFloat();
    return (Fixed(ret));
}

Fixed Fixed::operator/(const Fixed &eg) const
{
    float ret;
    if (eg.toFloat() == 0)
    {
        std::cout << "Division par 0" << std::endl;
        return (*this);
    }
    ret = this->toFloat() / eg.toFloat();
    return (Fixed(ret));
}

Fixed Fixed::operator++(int)   // Opérateur suffixe : i++
{                        // le int permet de faire la distinction entre i++ et ++i
    Fixed   tmp = *this;
    ++value;
    return tmp;
}

Fixed& Fixed::operator++(void) // Opérateur préfixe : ++i
{                              // Les versions préfixées des opérateurs doivent renvoyer une référence sur l'objet lui-même
    ++value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed   tmp = *this;
    --value;
    return tmp;
}

Fixed& Fixed::operator--(void)
{
    --value;
    return *this;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a > b)
        return (b);
    return (a);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (b);
    return (a);
}


const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}