#include "ScavTrap.hpp"

int	main()
{
	ClapTrap a("Clappy");
	a.attack("enemy1");

	std::cout << "----------------------" << std::endl;

	ScavTrap b("Scrappy");
	b.attack("enemy2");
	b.guardGate();

	return (0);
}