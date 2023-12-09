#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
    std::cout << "Animal Default Constructor" << std::endl;
    return;
}
Animal::Animal(const Animal &cop)
{
    std::cout << "Animal Recopy Constructor" << std::endl;
    *this = cop;
}
Animal &Animal::operator=(const Animal &eg)
{
    std::cout << "Copy assignment operator Animal called" << std::endl;
    _type = eg._type;
    return (*this);
}
Animal::~Animal(void)
{
    std::cout << "Animal Default Destructor" << std::endl;
    return;
}

void    Animal::makeSound(void) const
{
    std::cout << "Je suis un animal indefini je n'ai pas de cri" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->_type);
}
