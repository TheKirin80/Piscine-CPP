#include "Dog.hpp"

Dog::Dog(void)
{
    _type = "Dog";
    _brain = new Brain();
    std::cout << "Dog Default Constructor" << std::endl;
    return;
}
Dog::Dog(const Dog &cop) : Animal(cop)
{
    _brain = new Brain(*cop._brain);
    std::cout << "Dog Recopy Constructor" << std::endl;
}
Dog &Dog::operator=(const Dog &eg)
{
    Animal::operator=(eg);
    delete _brain;
    _brain = new Brain(*eg._brain);
    std::cout << "Copy assignment operator Dog called" << std::endl;
    return (*this);
}
Dog::~Dog(void)
{
    delete _brain;
    std::cout << "Dog Default Destructor" << std::endl;
    return;
}

void    Dog::makeSound(void) const
{
    std::cout << "Je suis un Chien, j'aboie ouaf" << std::endl;
}