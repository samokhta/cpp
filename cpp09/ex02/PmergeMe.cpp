#include "PmergeMe.hpp"

VectSort::VectSort() : _array(0), _order(0), _time(0) {}
VectSort::VectSort(const VectSort& other) : _array(other._array), _order(other._order), _time(other._time) {}
VectSort&	VectSort::operator=(const VectSort& other)
{
	_array = other._array;
	_order = other._order;
	_time = other._time;
	return *this;
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
	std::cout << "initSequences() call" << _order << std::endl;
	size_t	maxSize = _array.size() / _order;
	size_t	idx = _order * 2;
	bool	insert = true;

	for (size_t i = 0; i < _order * 2; i++) //push a1 et b1 dans le main
		main.push_back(_array[i]);
	while (idx < maxSize * _order)
	{
		std::cout << idx << maxSize << _order << std::endl;
		print();
		if (idx + _order > _array.size())
   			break;
		if (insert == true)
		{
			//push les b dans pend
			for (size_t i = 0; i < _order; i++)
				pend.push_back(_array[i + idx]);
			insert = false;
		}
		else
		{
			//push les a dans main
			for (size_t i = 0; i < _order; i++)
				main.push_back(_array[i + idx]);
			insert = true;
		}
		idx += _order;
	}
}

void		VectSort::binaryInsert(std::vector<int> &main, std::vector<int> &pend, int elemIdx, int min, int max)
{
	std::cout << "binaryInsert() call" << std::endl;
	int	mid = (min + max) / 2;				//milieu de la zone a binary search
	int	toInsert = pend[elemIdx * _order];	//valeur de l'element du pend a insert dans le main (b3, b2, b1)
	int	insertIdx;							//index auquel tu dois insert toInsert
	//std::vector<int>	smallMain;			//main mais seulement les valeurs a droite de chaque groupe

	//for (size_t i = _order; i < main.size(); i += _order)
	//	smallMain.push_back(main[i]);
	if (min == max)
		insertIdx = min;
	else
	{
		if (toInsert > main[mid * _order])
			binaryInsert(main, pend, elemIdx, mid + 1, max);
		else
			binaryInsert(main, pend, elemIdx, min, mid - 1);
	}
	std::vector<int>::iterator	viMain = main.begin();
	std::vector<int>::iterator	viPend = pend.begin();
	for (size_t i = 0; i < insertIdx * _order; i++)
		viMain++;
	for (size_t i = 0; i < elemIdx * _order; i++)
		viPend++;
	for (size_t i = 0; i < _order; i++)
	{
		main.insert(viMain, pend[elemIdx - _order]);
		elemIdx++;
	}
	pend.erase(viPend, viPend - _order);
	//trouve a quel index insert la i'eme paire avec binary search
	//comment eliminer les paires a ne pas search
	//insert la pair dans le main
	//erase la paire inseree du pend
}

unsigned long	VectSort::jacobsthal(long n) {return round((pow(2, n + 1) + pow(-1, n)) / 3);}

void	VectSort::insert()
{
	std::cout << "insert() call" << std::endl;
	std::vector<int>	main;
	std::vector<int>	pend;
	int	n = 2;

	initSequences(main, pend);

	while (pend.size() >= static_cast<size_t>(_order)) //itere jusqua qu'il n'y ait plus de paire dans le pend
	{
		if (pend.size() / static_cast<size_t>(_order) >= jacobsthal(n))
		{
			for (size_t i = jacobsthal(n); i > jacobsthal(n - 1); i--)
				binaryInsert(main, pend, i, 0, main.size() / _order);
		}
		else
		{
			for (size_t i = 1; i < (pend.size() / _order); i++)
				binaryInsert(main, pend, i, 0, main.size() / _order);
		}
		n++;
	}
	//implementer binary insertion
	//insert en suivant les nombres jacobsthal (js = 3: insert b3, b2, b1)
	/*si il y a pas assez d'elements a insert(exemple le nombre
	jacobsthal est 5 mais il reste que 4 elements a insert), 
	insert les elements dans l'ordre*/
	_array = main;
}

void	VectSort::merge()
{
	std::cout << "merge() call" << std::endl;
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