#include "Zombie.hpp"

int main()
{
    Zombie* myZombie;

    int nombreZ = 10;
    myZombie = zombieHorde(nombreZ, "Perroquet");
    for (int i = 0; i < nombreZ; i++)
        myZombie->announce();
    delete[] myZombie;
    return (0);
}