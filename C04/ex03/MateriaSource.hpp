#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <cstdlib>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public :
        MateriaSource(void);
        MateriaSource(const MateriaSource &cop);
        MateriaSource &operator=(const MateriaSource &eg);
        virtual ~MateriaSource(void);
    private :

};

#endif