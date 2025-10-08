#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie  *newHorde = new Zombie[N];
    int i = 0;
    while (i < N)
    {
        newHorde[i].setName(name);
        newHorde[i].announce();
        i++;
    }
    return (newHorde);
}
