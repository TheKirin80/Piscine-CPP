#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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
    ScavTrap    FurieuxX = ScavTrap();
    Furieux4.takeDamage(0);
    FurieuxX.attack("Calm");
    Furieux4.attack("Calm");
    Furieux4.guardGate();

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "--FRAGTRAP--" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    
    FragTrap    Furieux5("Furieux5");
    FragTrap    Furieux6(Furieux5);
    FragTrap    FurieuxY = FragTrap();
    Furieux5.takeDamage(0);
    FurieuxY.highFivesGuys();
    Furieux6.highFivesGuys();
    return (0);
}