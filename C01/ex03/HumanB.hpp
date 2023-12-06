#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    public :
        
        HumanB();
        HumanB(std::string name);
		~HumanB();
        void setWeapon(Weapon &arme);
        void attack();

    private :

        std::string name;
        Weapon *weapon;

};

#endif