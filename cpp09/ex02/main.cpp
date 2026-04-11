#include "PmergeMe.hpp"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc < 3 || checkArgv(argc, argv) == false)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	VectSort	vec(argc, argv);
	vec.print();
	vec.sort();
	vec.print();
	return 0;
}