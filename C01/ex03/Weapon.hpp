#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
    public :

        Weapon();
        Weapon(std::string name);
        ~Weapon();
        const std::string& getType(void);
		void setType(std::string str);

    private :

        std::string type;
};

#endif