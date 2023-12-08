#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public :
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap &cop);
        FragTrap &operator=(const FragTrap &eg);
        ~FragTrap(void);
        void highFivesGuys(void);
    private :

};

#endif 