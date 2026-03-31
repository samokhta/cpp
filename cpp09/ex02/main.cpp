#include "PmergeMe.hpp"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc < 3 || checkArgv(argc, argv) == false)
	{
		std::cerr << "Error" << argc << std::endl;
		return 1;
	}
	VectSort	vec(argc, argv);
	vec.sort();
	return 0;
}