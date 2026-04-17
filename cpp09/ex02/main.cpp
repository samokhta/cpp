#include "PmergeMe.hpp"
#include <stdio.h>

bool	checkArgv(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string	str(argv[i]);
		for (size_t j = 0; j < str.size(); j++)
		{
			if (!isdigit(str[j])) 
				return false;
		}
	}
	return true;
}

int	main(int argc, char **argv)
{
	if (argc < 3 || checkArgv(argc, argv) == false)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	VectSort	vec(argc, argv);
	std::cout << "starting sequence: ";
	vec.print();
	vec.sort();
	std::cout << "sorted sequence: ";
	vec.print();
	return 0;
}