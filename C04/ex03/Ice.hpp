#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <cstdlib>
#include "AMateria.hpp"

class Ice : public AMateria
{
    public :
        Ice(void);
        Ice(const Ice &cop);
        Ice &operator=(const Ice &eg);
        virtual ~Ice(void);
        std::string const & getType(void) const;
        AMateria*   clone(void) const;
        void        use(ICharacter& target);
    private :

};

#endif