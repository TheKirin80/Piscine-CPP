#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
    std::cout << "WrongAnimal Default Constructor" << std::endl;
    return;
}
WrongAnimal::WrongAnimal(const WrongAnimal &cop)
{
    std::cout << "WrongAnimal Recopy Constructor" << std::endl;
    *this = cop;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &eg)
{
    std::cout << "Copy assignment operator WrongAnimal called" << std::endl;
    _type = eg._type;
    return (*this);
}
WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal Default Destructor" << std::endl;
    return;
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "Je suis un WrongAnimal indefini je n'ai pas de cri" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}