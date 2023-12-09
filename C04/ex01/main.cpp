#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    // std::cout << "Ex00 Test ---------------------------------------------------" << std::endl;
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* k = new Cat();
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << k->getType() << " " << std::endl;
    // k->makeSound(); //will output the cat sound!
    // j->makeSound();
    // meta->makeSound();

    // const   WrongAnimal* cat = new  WrongCat();
    // std::cout << cat->getType() << " " << std::endl;
    // cat->makeSound();

    // delete cat;
    // delete k;
    // delete j;
    // delete meta;

    // std::cout << "Premier Test ---------------------------------------------------" << std::endl;
    // const Animal *all[100];
    // int	i;

    // for(i = 0; i < 50; i++)
    //     all[i] = new Dog();
    // for(i = 50; i < 100;i++)
    //     all[i] = new Cat();
    // for(i = 0; i < 100; i++)
    // {
    //     std::cout << "Animal number: " << i << std::endl;
    //     all[i]->makeSound();
    //     delete	all[i];
    // }
    std::cout << "Second Test ---------------------------------------------------" << std::endl;
    const	Dog *vDog = new Dog();
    const	Cat *vCat = new Cat();
    const	Dog cDog(*vDog);
    const	Cat cCat(*vCat);
    Dog fcDog;
    Cat fcCat;
    std::cout << "///////////////////////////////////////" << std::endl;
    delete vCat;
    delete vDog;
    std::cout << "///////////////////////////////////////" << std::endl;
    fcDog = cDog;
    fcCat = cCat;
    std::cout << "///////////////////////////////////////" << std::endl;
    
    // std::cout << "Troisieme Test --------------------------------------------------" << std::endl;
    // Dog test;
    // {
    //     std::cout << "///////////////////////////////////////" << std::endl;
    //     Dog test2 = test;
        
    // }
    // std::cout << "///////////////////////////////////////" << std::endl;
    // Dog pardon;
    // pardon = test;
    // std::cout << "///////////////////////////////////////" << std::endl;
    return (0);
}