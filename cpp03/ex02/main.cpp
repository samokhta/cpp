#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap a("Clappy");
	a.attack("enemy1");
	a.takeDamage(12);

	std::cout << "----------------------" << std::endl;

	ScavTrap b("Scrappy");
	b.attack("enemy2");
	b.beRepaired(12);
	b.guardGate();

	std::cout << "----------------------" << std::endl;

	FragTrap c("Fraga");
	c.attack("Scrappy");
	c.takeDamage(15);
	c.highFivesGuys();

	
	return (0);
}