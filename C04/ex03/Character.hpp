#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <cstdlib>

class Character
{
    public :
        Character(void);
        Character(const Character &cop);
        Character &operator=(const Character &eg);
        virtual ~Character(void);
    private :
        std::string _name;
        AMateria    *bag[4];

};

#endif