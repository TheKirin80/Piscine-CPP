#include "Cat.hpp"

Cat::Cat(void)
{
    _type = "Cat";
    _brain = new Brain();
    std::cout << "Cat Default Constructor" << std::endl;
    return;
}
Cat::Cat(const Cat &cop) : Animal(cop)
{
    _brain = new Brain(*cop._brain);
    std::cout << "Cat Recopy Constructor" << std::endl;
}
Cat &Cat::operator=(const Cat &eg)
{
    Animal::operator=(eg);
    delete _brain;
    _brain = new Brain (*eg._brain);
    std::cout << "Copy assignment operator Cat called" << std::endl;
    return (*this);
}
Cat::~Cat(void)
{
    delete _brain;
    std::cout << "Cat Default Destructor" << std::endl;
    return;
}

void    Cat::makeSound(void) const
{
    std::cout << "Je suis un Chat, je miaule miaou" << std::endl;
}