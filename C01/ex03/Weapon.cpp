#include "Weapon.hpp"

Weapon::Weapon(){return ;}

Weapon::Weapon(std::string str)
{
    type = str;
}

Weapon::~Weapon(void)
{
    //std::cout << type << " weapon destructed " << std::endl;
    return;
}

const std::string& Weapon::getType(void)
{
    const std::string &ref = type;
    return ref;
}

void Weapon::setType(std::string str)
{
    type = str;
}