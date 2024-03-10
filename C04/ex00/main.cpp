#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    j->makeSound();
    i->makeSound();
    meta->makeSound();

    const   WrongAnimal* cat = new  WrongCat();
    std::cout << cat->getType() << " " << std::endl;
    cat->makeSound();
    delete cat;
    delete i;
    delete j;
    delete meta;
    return (0);
}