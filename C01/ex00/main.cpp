#include "Zombie.hpp"

int main()
{
    Zombie* myZombie;

    randomChump("Casimir");
    myZombie = newZombie("Perroquet");
    myZombie->announce();
    delete myZombie;
    return (0);
}