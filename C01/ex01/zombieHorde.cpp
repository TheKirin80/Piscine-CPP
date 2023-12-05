#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* hordeZ = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        hordeZ[i].setName(name);
    }
    return (hordeZ);
}