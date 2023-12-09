#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <cstdlib>

class WrongAnimal
{
    public :
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &cop);
        WrongAnimal &operator=(const WrongAnimal &eg);
        virtual ~WrongAnimal(void);
        void makeSound(void) const;
        std::string getType(void) const;
    protected :
        std::string _type;
};

#endif