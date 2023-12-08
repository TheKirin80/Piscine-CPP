#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>

class ClapTrap
{
    public :
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &cop);
        ClapTrap &operator=(const ClapTrap &eg);
        ~ClapTrap(void);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    private :
        std::string _name;
        int         _hit_point;
        int         _energy_point;
        int         _attack_damage;
};

#endif