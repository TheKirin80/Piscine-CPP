#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <cstdlib>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    public :
        MateriaSource(void);
        MateriaSource(const MateriaSource &cop);
        MateriaSource &operator=(const MateriaSource &eg);
        virtual ~MateriaSource(void);
        void        learnMateria(AMateria*);
        AMateria*   createMateria(std::string const & type);
    private :
        AMateria    *_inventory[4];
};

#endif