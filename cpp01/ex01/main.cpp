#include "Zombie.hpp"

int main()
{
    Zombie  *newHorde = zombieHorde(5, "Zombi");
    delete []  newHorde;
    return (0);
}
