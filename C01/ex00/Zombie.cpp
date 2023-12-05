#include "Zombie.hpp"

Zombie::Zombie (void)
{
    name = "random";
}

Zombie::Zombie(std::string str)
{
    name = str;
}

Zombie::~Zombie(void)
{
    std::cout << "De mon vivant je m'appelais " << name << " et maintenant je meurs" << std::endl;
    return;
}

std::string Zombie::getName(void)
{
    return name;
}

// void Zombie::setName(std::string str)
// {
//     name = str;
// }

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

