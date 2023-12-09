#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <cstdlib>

class Animal
{
    public :
        Animal(void);
        Animal(const Animal &cop);
        Animal &operator=(const Animal &eg);
        virtual ~Animal(void);
        virtual void makeSound(void) const = 0;
        std::string getType(void) const;
    protected :
        std::string _type;
};

#endif