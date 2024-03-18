#ifndef Serializer_HPP
#define Serializer_HPP

#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include "Data.hpp"

class Serializer
{
    public :
        virtual ~Serializer(void);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private :
        Serializer(void);
        Serializer(const Serializer &cop);
        Serializer &operator=(const Serializer &eg);

};

#endif