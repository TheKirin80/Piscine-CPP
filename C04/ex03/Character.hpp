#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <cstdlib>
#include "ICharacter.hpp"

class Character : public ICharacter
{
    public :
        Character(void);
        Character(std::string const & name);
        Character(const Character &cop);
        Character &operator=(const Character &eg);
        virtual ~Character(void);
        std::string const & getName(void) const ;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        void add_floor(AMateria *m);
    private :
        std::string _name;
        AMateria    *_bag[4];
        AMateria    *_floor;
};

#endif