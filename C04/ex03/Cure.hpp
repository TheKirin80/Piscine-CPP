#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <cstdlib>
#include "AMateria.hpp"

class Cure : Public AMateria
{
    public :
        Cure(void);
        Cure(const Cure &cop);
        Cure &operator=(const Cure &eg);
        virtual ~Cure(void);
        AMateria*   clone(void) const;
        void        use(ICharacter& target);
    private :

};

#endif