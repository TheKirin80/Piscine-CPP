#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <cstdlib>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public :
        Dog(void);
        Dog(const Dog &cop);
        Dog &operator=(const Dog &eg);
        virtual ~Dog(void);
        void makeSound(void) const;
    private:
        Brain   *_brain;
};

#endif