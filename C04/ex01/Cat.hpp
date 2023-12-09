#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <cstdlib>
#include "Animal.hpp"

class Cat : public Animal
{
    public :
        Cat(void);
        Cat(const Cat &cop);
        Cat &operator=(const Cat &eg);
        virtual ~Cat(void);
        void makeSound(void) const;
};

#endif