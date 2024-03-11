#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <cstdlib>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public :
        Cure(void);
        Cure(const Cure &cop);
        Cure &operator=(const Cure &eg);
        virtual ~Cure(void);
        std::string const & getType(void) const;
        AMateria*   clone(void) const;
        void        use(ICharacter& target);
    private :

};

#endif