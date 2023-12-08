#include "ClapTrap.hpp"
int main()
{
    ClapTrap    Furieux("Furieux");
    ClapTrap    Furieux2(Furieux);
    ClapTrap    Calm("Calm");
    //ClapTrap    Grinch(Calm);
    Furieux2.attack("dans le vide");
    Furieux2 = Calm;
    Furieux2.attack("dans le vide");
    Furieux.attack("Calm");
    Calm.takeDamage(9);
    Calm.attack("Furieux");
    Furieux.takeDamage(9);
    Furieux.beRepaired(1);
    Furieux.beRepaired(1);
    Furieux.beRepaired(1);
    Furieux.beRepaired(1);
    Furieux.beRepaired(1);
    Furieux.beRepaired(1);
    Furieux.beRepaired(1);
    Furieux.beRepaired(1);
    Furieux.beRepaired(1);
    Furieux.beRepaired(1);
    Furieux.attack("Calm");
    Calm.attack("Furieux");
    Furieux.takeDamage(10);
    Furieux.attack("Calm");
    Furieux.beRepaired(1);
    return (0);
}