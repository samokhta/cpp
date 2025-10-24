#include "Zombie.hpp"

int main()
{
    Zombie  *Zombie1 = newZombie("Zombie1");

    Zombie1->announce();
    delete Zombie1;
    randomChump("Zombie2");
    return (0);
}
