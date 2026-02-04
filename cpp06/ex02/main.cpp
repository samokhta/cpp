#include "BaseABC.hpp"

int	main()
{
	srand(time(0));
	Base	*test1 = generate();
	Base	*test2 = generate();
	Base	*test3 = generate();
	std::cout << std::endl;
	identify(test1);
	identify(test2);
	identify(test3);
	std::cout << std::endl;
	identify(*test1);
	identify(*test2);
	identify(*test3);
	return (0);
}