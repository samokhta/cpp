#include "PmergeMe.hpp"

VectSort::VectSort() : _array(NULL), _order(0), _time(0) {}
VectSort::VectSort(const VectSort& other) : _array(other._array), _order(other._order), _time(other._time) {}
VectSort&	VectSort::operator=(const VectSort& other)
{
	_array = other._array;
	_order = other._order;
	_time = other._time;
}
VectSort::VectSort(int argc, char **argv) : _order(1)
{
	for (int i = 1; i < argc; i++)
		_array.push_back(atoi(argv[i]));
}
VectSort::~VectSort() {}

/************************************************************/

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

void	VectSort::swapPair(int i, int j)
{
	int len = _order - 1;
	int tmp = 0;

	while (len >= 0)
	{
		tmp = _array[i];
		_array[i] = _array[j];
		_array[j] = tmp;
		i--;
		j--;
		len--;
	}	
}

void	VectSort::initSequences(std::vector<int> &main, std::vector<int> &pend)
{
	size_t	maxSize = _array.size() / _order;
	size_t	idx = _order * 2;
	bool	insert = true;

	for (size_t i = 0; i < _order * 2; i++) //push a1 et b1 dans le main
		main.push_back(_array[i]);
	while (idx < maxSize * _order)
	{
		if (insert == true)
		{
			//push dans pend
			for (size_t i = 0; i < _order; i++)
				pend.push_back(_array[i + idx]);
			insert = false;
		}
		else
		{
			//push dans main
			for (size_t i = 0; i < _order; i++)
				main.push_back(_array[i + idx]);
			insert = true;
		}
		idx += _order;
	}
}

void	VectSort::insert()
{
	std::vector<int>	main;
	std::vector<int>	pend;

	initSequences(main, pend);
	//find out comment implementer la fonction jacobsthal (est-ce que je call a chaque fois que jai besoin dun nombre ou je fais un vector avec tous les nombres necessaires)
	//find out comment exclure les paires que t'as pas besoin de comparer
}

void	VectSort::merge()
{
	if ((size_t)_order * 2 > _array.size())
		return ;

	int i = _order - 1;
	int j = _order * 2 - 1;
	int size = _array.size();
	while (i < size && j < size)
	{
		if (_array[j] < _array[i])
			swapPair(i, j);
		i = j + _order;
		j = i + _order;
	}
	_order *= 2;
	merge();
	_order /= 2;
	insert();
}

/************************************************************/

void	VectSort::sort()
{
	//start timer
	merge();
	//end timer
}

void	VectSort::print()
{
	for (size_t i = 0; i < _array.size(); i++)
		std::cout << _array[i] << ' ';
	std::cout << std::endl;
}