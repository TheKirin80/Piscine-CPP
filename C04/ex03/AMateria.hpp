#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <cstdlib>
class AMateria;
#include "ICharacter.hpp"

class AMateria
{
    public:
        AMateria(void);
        AMateria(std::string const & type);
        AMateria(const AMateria &cop);
        AMateria &operator=(const AMateria &eg);
        virtual ~AMateria(void);

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

    protected:
    
        std::string _type;
};

#endif