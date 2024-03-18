#include "Serializer.hpp"

Serializer::Serializer(void)
{
    return;
}
Serializer::Serializer(const Serializer &cop)
{
    *this = cop;
}
Serializer &Serializer::operator=(const Serializer &eg)
{
    if (this != &eg)
    {

    }
    return (*this);
}
Serializer::~Serializer(void)
{
    return;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}