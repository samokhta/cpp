#include "Zombie.hpp"

int main()
{
    Zombie  *Zombie1 = newZombie("Zombie1");

    randomChump("Zombie2");
    Zombie1->announce();
    delete Zombie1;
    return (0);
}
