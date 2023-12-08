#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
    // ClapTrap    Furieux("Furieux");
    // ClapTrap    Furieux2(Furieux);
    // ClapTrap    Calm("Calm");
    // //ClapTrap    Grinch(Calm);
    // Furieux2.attack("dans le vide");
    // Furieux2 = Calm;
    // Furieux2.attack("dans le vide");
    // Furieux.attack("Calm");
    // Calm.takeDamage(9);
    // Calm.attack("Furieux");
    // Furieux.takeDamage(9);
    // Furieux.beRepaired(1);
    // Furieux.beRepaired(1);
    // Furieux.beRepaired(1);
    // Furieux.beRepaired(1);
    // Furieux.beRepaired(1);
    // Furieux.beRepaired(1);
    // Furieux.beRepaired(1);
    // Furieux.beRepaired(1);
    // Furieux.beRepaired(1);
    // Furieux.beRepaired(1);
    // Furieux.attack("Calm");
    // Calm.attack("Furieux");
    // Furieux.takeDamage(10);
    // Furieux.attack("Calm");
    // Furieux.beRepaired(1);



    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "--SCAVTRAP--" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    
    ScavTrap    Furieux3("Furieux3");
    ScavTrap    Furieux4(Furieux3);
    Furieux4.attack("Calm");
    Furieux4.guardGate();
    return (0);
}