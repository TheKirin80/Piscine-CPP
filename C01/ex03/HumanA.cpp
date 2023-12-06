#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon& weapon_) : name(str), weapon(weapon_) {
   }

HumanA::~HumanA()
{
    //std::cout << name << " HumanA dead " << std::endl;
    return;
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}