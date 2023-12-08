#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    std::cout << "FragTrap default constructor" << std::endl;
    _hit_point = 100;
    _energy_point = 100;
    _attack_damage = 30;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap name constructor" << std::endl;
    _hit_point = 100;
    _energy_point = 100;
    _attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &cop) : ClapTrap(cop)
{
    std::cout << "FragTrap recopy constructor" << std::endl;
}
FragTrap    &FragTrap::operator=(const FragTrap &eg)
{
    ClapTrap::operator=(eg);
    std::cout << "Copy assignment operator FragTrap called" << std::endl;
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap default destructor" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << _name << " want to High Five with you guys" << std::endl;
}