#include "PmergeMe.hpp"

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

VectSort::VectSort(int argc, char **argv) : _order(0)
{
	for (int i = 1; i < argc; i++)
		_array.push_back(atoi(argv[i]));
}

VectSort::~VectSort() {}

void	VectSort::print()
{
	for (size_t i = 0; i < _array.size(); i++)
		std::cout << _array[i] << ' ';
	std::cout << std::endl;
}

void	VectSort::sort()
{
	
}