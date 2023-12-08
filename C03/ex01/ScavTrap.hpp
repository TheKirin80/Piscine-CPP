#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public :
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &cop);
        ScavTrap &operator=(const ScavTrap &eg);
        ~ScavTrap(void);
        void attack(const std::string& target);
        void guardGate(void);
    private :

};

#endif 
