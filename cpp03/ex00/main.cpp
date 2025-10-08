#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	test("test");
	//ClapTrap	test2("test2");
	//ClapTrap	test3("test3");

	//test3 = test2;
	//test.printStatus();
	//test2.printStatus();
	//test3.printStatus();
	test.attack("target");
	test.beRepaired(50);
	test.takeDamage(200);
	test.printStatus();
	test.attack("target");
	test.beRepaired(999);
	test.takeDamage(1);
	return (0);
}