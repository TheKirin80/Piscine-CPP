#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    std::cout << "ScavTrap default constructor" << std::endl;
    _hit_point = 100;
    _energy_point = 50;
    _attack_damage = 20;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap name constructor" << std::endl;
    _hit_point = 100;
    _energy_point = 50;
    _attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &cop) : ClapTrap(cop)
{
    std::cout << "ScavTrap recopy constructor" << std::endl;
}
ScavTrap    &ScavTrap::operator=(const ScavTrap &eg)
{
    ClapTrap::operator=(eg);
    std::cout << "Copy assignment operator ScavTrap called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap default destructor" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_hit_point > 0)
    {
        if (_energy_point > 0)
        {
            std::cout << _name << " THE SCAVTRAP attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
            _energy_point = _energy_point - 1;
        }
        else
        {
            std::cout << _name <<  " THE SCAVTRAP don't have the energy for attacking" << std::endl;
        }
    }
    else
        std::cout << _name << " THE SCAVTRAP don't have the vitality for attacking" << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << _name << " are in gate keeper mode" << std::endl;
}