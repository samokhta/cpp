#include "easyfind.hpp"
#include <list>
#include <vector>


int	main()
{
	std::list<int>	lst;
	lst.push_back(44);
	lst.push_back(67);
	lst.push_back(21);
	std::cout << "list container:" << std::endl;
	try
	{
		easyfind(lst, 67);
		easyfind(lst, 2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::vector<int>	vect;
	vect.push_back(44);
	vect.push_back(67);
	vect.push_back(21);
	std::cout << "vector container:" << std::endl;
	try
	{
		easyfind(vect, 21);
		easyfind(vect, 2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}