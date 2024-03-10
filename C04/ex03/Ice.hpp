#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <cstdlib>

class Ice
{
    public :
        Ice(void);
        Ice(const Ice &cop);
        Ice &operator=(const Ice &eg);
        virtual ~Ice(void);
    private :

};

#endif