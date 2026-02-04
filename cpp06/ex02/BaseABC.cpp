#include "BaseABC.hpp"

Base * generate(void)
{
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
	else if (dynamic_cast<B*>(p))
		std::cout << "p is a B object" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "p is a C object" << std::endl;
	else
		std::cout << "Invalid type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "p is an A object" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << "p is a B object" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				dynamic_cast<C&>(p);
				std::cout << "p is a C object" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << "Invalid type" << std::endl;
			};
		}	
	}	
}
