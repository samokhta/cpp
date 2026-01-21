#include "BaseABC.hpp"

Base * generate(void)
{
	srand(time(0));
	int	random = rand() % 3;

	std::cout << random << std::endl;
	if (random == 0)
		return new A;
	else if (random == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "p is an A object" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "p is a B object" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "p is a C object" << std::endl;
}

void identify(Base& p)
{
	try
	{
		/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
