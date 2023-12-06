#include "HumanB.hpp"

HumanB::HumanB(){return ;}

HumanB::HumanB(std::string str) : name(str){
}

HumanB::~HumanB()
{
    //std::cout << name << " HumanB dead " << std::endl;
    return;
}

void HumanB::setWeapon(Weapon &arme)
{
    weapon = &arme;
}
void HumanB::attack()
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

