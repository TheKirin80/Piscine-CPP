#include "ClapTrap.hpp"
ClapTrap::ClapTrap(void) : _name("random"), _hit_point(10), _energy_point(10), _attack_damage(0)
{
    // std::cout << "Je suis " << _name << " j'ai " << _hit_point << " point(s) de vie, " << _energy_point << " point(s) d'energie et je tape du "
    // << _attack_damage << std::endl;
    // std::cout << "Mon createur le constructeur par defaut de ClapTrap" << std::endl; 
    std::cout << "ClapTrap default constructor" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hit_point(10), _energy_point(10), _attack_damage(0)
{
    std::cout << "ClapTrap name constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cop)
{
    std::cout << "ClapTrap recopy constructor" << std::endl;
    *this = cop;
}
ClapTrap    &ClapTrap::operator=(const ClapTrap &eg)
{
    _name = eg._name;
    _hit_point = eg._hit_point;
    _energy_point = eg._energy_point;
    _attack_damage = eg._attack_damage;
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap default destructor" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hit_point > 0)
    {
        if (_energy_point > 0)
        {
            std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage!" << std::endl;
            _energy_point = _energy_point - 1;
        }
        else
        {
            std::cout << "ClapTrap " << _name <<  " don't have the energy for attacking" << std::endl;
        }
    }
    else
        std::cout << "ClapTrap " << _name << " don't have the vitality for attacking" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hit_point == 0)
    {
        std::cout << "ClapTrap " << _name << "already have 0 hp" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " take " << amount << " damage" << std::endl;
        _hit_point = _hit_point - amount;
        if (_hit_point <= 0)
            _hit_point = 0;
        std::cout << "ClapTrap " << _name << " have " << _hit_point << " HP left" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hit_point > 0)
    {
        if (_energy_point > 0)
        {
            _hit_point = _hit_point + amount;
            std::cout << "ClapTrap " << _name << " repaired " << amount << " HP and now he have " << _hit_point << " HP" << std::endl;
            _energy_point = _energy_point - 1;
        }
        else
        {
            std::cout << "ClapTrap " << _name <<  " don't have the energy for repaired" << std::endl;
        }
    }
    else
        std::cout << "ClapTrap " << _name << " don't have the vitality for repaired" << std::endl;
}