#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <cstdlib>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public :
        WrongCat(void);
        WrongCat(const WrongCat &cop);
        WrongCat &operator=(const WrongCat &eg);
        virtual ~WrongCat(void);
        void makeSound(void) const;
};

#endif