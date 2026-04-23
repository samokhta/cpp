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
	DequeSort	deq(argc, argv);
	std::cout << "Before:	";
	vec.print();

	vec.sort();
	deq.sort();

	std::cout << "After:	";
	vec.print();

	std::cout << std::fixed << "time to process a range of " << argc - 1 << " elements with std::vector:	" << (double)vec.getTime() / CLOCKS_PER_SEC << "sec" << std::endl;
	std::cout << std::fixed << "time to process a range of " << argc - 1 << " elements with std::deque:		" << (double)deq.getTime() / CLOCKS_PER_SEC << "sec" << std::endl;
	return 0;
}