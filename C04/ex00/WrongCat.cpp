#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    _type = "WrongCat";
    std::cout << "WrongCat Default Constructor" << std::endl;
    return;
}
WrongCat::WrongCat(const WrongCat &cop) : WrongAnimal(cop)
{
    std::cout << "WrongCat Recopy Constructor" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &eg)
{
    WrongAnimal::operator=(eg);
    std::cout << "Copy assignment operator WrongCat called" << std::endl;
    return (*this);
}
WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat Default Destructor" << std::endl;
    return;
}

void    WrongCat::makeSound(void) const
{
    std::cout << "Je suis un WrongChat, je miaule wrong_miaou" << std::endl;
}