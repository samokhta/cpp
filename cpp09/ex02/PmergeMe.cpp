#include "PmergeMe.hpp"
//./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

VectSort::VectSort() : _array(0), _order(0), _start(0) {}
VectSort::VectSort(const VectSort& other) : _array(other._array), _order(other._order), _start(other._start) {}
VectSort&	VectSort::operator=(const VectSort& other)
{
	_array = other._array;
	_order = other._order;
	_start = other._start;
	return *this;
}
VectSort::VectSort(int argc, char **argv) : _order(1)
{
	for (int i = 1; i < argc; i++)
		_array.push_back(atoi(argv[i]));
}
VectSort::~VectSort() {}

/************************************************************/

size_t	VectSort::jacobsthal(long n) {return round((pow(2, n + 1) + pow(-1, n)) / 3);}

size_t	VectSort::group(vector& vec, size_t group)
{
	if (group == 0)
		return(std::cerr << "Error: group == 0\n", 0);
	if ((group * _order) - 1 > vec.size())
		return(std::cerr << "Error: group " << group << " doesn't exist (out of bounds)\n", 0);
	return ((group * _order) - 1);
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
void	VectSort::printVec(vector &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

/************************************************************/

size_t VectSort::binarySearch(vector &main, int item, size_t minGroup, size_t maxGroup)
{
    if (minGroup > maxGroup)
        return (minGroup - 1) * _order;

    size_t midGroup = (minGroup + maxGroup) / 2;
    int    midVal   = main[midGroup * _order - 1];

    if (item == midVal)
        return midGroup * _order;
    if (item > midVal)
    {
        if (midGroup == maxGroup)
            return maxGroup * _order;
        return binarySearch(main, item, midGroup + 1, maxGroup);
    }
    if (midGroup == minGroup)
        return (minGroup - 1) * _order;
    return binarySearch(main, item, minGroup, midGroup - 1);
}

void		VectSort::binaryInsert(vector &main, vector &pend, size_t itemIdx, vector::iterator max)
{
	size_t maxGroup  = (size_t)std::distance(main.begin(), max) / _order;
	size_t insertIdx = binarySearch(main, pend[itemIdx], 1, maxGroup);
	vector::iterator	position;	//insertIdx mais en iterateur aka la position dans le main ou tu vas inserer le groupe
	vector::iterator	first;		//premier element du groupe a inserer
	vector::iterator	last;		//dernier element du groupe a inserer

	position = main.begin();
	std::advance(position, insertIdx);
	first = pend.begin();
	if (itemIdx + 1 >= _order)
	    std::advance(first, itemIdx + 1 - _order);
	last = first;
	std::advance(last, _order);
	main.insert(position, first, last);
	pend.erase(first, last);
}

void	VectSort::initSequences(vector &main, vector &pend, vector& leftover, vector& pairIndex)
{
	size_t	maxSize = _array.size() / _order;
	size_t	idx = _order * 2;
	bool	insert = true;

	for (size_t i = 0; i < _order * 2; i++) //push a1 et b1 dans le main
		main.push_back(_array[i]);
	while (idx < maxSize * _order)
	{
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
	if (_array.size() - maxSize > 0) //fill le leftover vector
	{
		for (size_t i = maxSize * _order; i < _array.size(); i++)
			leftover.push_back(_array[i]);
	}
	pairIndex.push_back(0);
	if (maxSize % 2 == 0)
	{
		for (size_t i = 0; i < pend.size() / _order; i++)
			pairIndex.push_back(main[group(main, i + 3)]);
	}
	else
	{
		for (size_t i = 0; i < (pend.size() / _order) - 1; i++)
			pairIndex.push_back(main[group(main, i + 3)]);
	}
}

void	VectSort::insert()
{
	vector	main;
	vector	pend;
	vector	leftover;
	vector	pairIndex;
	size_t	n = 2;
	size_t	curr_jacobsthal = jacobsthal(n);
	size_t	prev_jacobsthal = jacobsthal(n - 1);

	initSequences(main, pend, leftover, pairIndex);
	while (pend.size() / _order > curr_jacobsthal - prev_jacobsthal)
	{
		curr_jacobsthal = jacobsthal(n);
		prev_jacobsthal = jacobsthal(n - 1);
		for (size_t i = curr_jacobsthal - prev_jacobsthal; i > 0; i--)
		{
			vector::iterator	bound = std::find(main.begin(), main.end(), pairIndex[i]);
			binaryInsert(main, pend, group(pend, i), bound);
			pairIndex.erase(pairIndex.begin() + i);
		}
		n++;
	}
	while (!pend.empty())
		binaryInsert(main, pend, pend.size() - 1, main.end());
	_array = main;
	_array.insert(_array.end(), leftover.begin(), leftover.end());
}
//compare les paires et les swap de sorte a ce que ax > bx
void	VectSort::merge()
{
	if ((size_t)_order * 2 > _array.size())
		return ;

	size_t i = _order - 1;
	size_t j = _order * 2 - 1;
	size_t size = _array.size();
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

clock_t	VectSort::getTime() { return _time; }

template <class ForwardIterator>
  bool isSorted (ForwardIterator first, ForwardIterator last)
{
  if (first==last) return true;
  ForwardIterator next = first;
  while (++next!=last) {
    if (*next<*first)     // or, if (comp(*next,*first)) for version (2)
      return false;
    ++first;
  }
  return true;
}

void	VectSort::sort()
{
	_start = clock();
	merge();
	_time = clock() - _start;
	//std::cout << std::boolalpha << std::endl << std::endl << "is_sorted(_array.begin(), _array.end()): " << isSorted(_array.begin(), _array.end()) << std::endl;
}

void	VectSort::print()
{
	for (size_t i = 0; i < _array.size(); i++)
		std::cout << _array[i] << ' ';
	std::cout << std::endl;
}

/*********************************************************************************************************************************************/

DequeSort::DequeSort() : _array(0), _order(0), _start(0) {}
DequeSort::DequeSort(const DequeSort& other) : _array(other._array), _order(other._order), _start(other._start) {}
DequeSort&	DequeSort::operator=(const DequeSort& other)
{
	_array = other._array;
	_order = other._order;
	_start = other._start;
	return *this;
}

DequeSort::DequeSort(int argc, char **argv) : _order(1)
{
	_start = clock();
	for (int i = 1; i < argc; i++)
		_array.push_back(atoi(argv[i]));
}

DequeSort::~DequeSort() {}

size_t	DequeSort::jacobsthal(long n) {return round((pow(2, n + 1) + pow(-1, n)) / 3);}

size_t	DequeSort::group(deque& vec, size_t group)
{
	if (group == 0)
		return(std::cerr << "Error: group == 0\n", 0);
	if ((group * _order) - 1 > vec.size())
		return(std::cerr << "Error: group " << group << " doesn't exist (out of bounds)\n", 0);
	return ((group * _order) - 1);
}

void	DequeSort::swapPair(int i, int j)
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

void	DequeSort::printVec(deque &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

size_t DequeSort::binarySearch(deque &main, int item, size_t minGroup, size_t maxGroup)
{
    if (minGroup > maxGroup)
        return (minGroup - 1) * _order;

    size_t midGroup = (minGroup + maxGroup) / 2;
    int    midVal   = main[midGroup * _order - 1];

    if (item == midVal)
        return midGroup * _order;
    if (item > midVal)
    {
        if (midGroup == maxGroup)
            return maxGroup * _order;
        return binarySearch(main, item, midGroup + 1, maxGroup);
    }
    if (midGroup == minGroup)
        return (minGroup - 1) * _order;
    return binarySearch(main, item, minGroup, midGroup - 1);
}

//insere un element du pend dans le main en utilisant le binary search pour trouver ou le placer
void		DequeSort::binaryInsert(deque &main, deque &pend, size_t itemIdx, deque::iterator max)
{
	size_t maxGroup  = (size_t)std::distance(main.begin(), max) / _order;
	size_t insertIdx = binarySearch(main, pend[itemIdx], 1, maxGroup);
	deque::iterator	position;	//insertIdx mais en iterateur aka la position dans le main ou tu vas inserer le groupe
	deque::iterator	first;		//premier element du groupe a inserer
	deque::iterator	last;		//dernier element du groupe a inserer

	position = main.begin();
	std::advance(position, insertIdx);
	first = pend.begin();
	if (itemIdx + 1 >= _order)
	    std::advance(first, itemIdx + 1 - _order);
	last = first;
	std::advance(last, _order);

	main.insert(position, first, last);
	pend.erase(first, last);
}

void	DequeSort::initSequences(deque &main, deque &pend, deque& leftover, deque& pairIndex)
{
	size_t	maxSize = _array.size() / _order;
	size_t	idx = _order * 2;
	bool	insert = true;

	for (size_t i = 0; i < _order * 2; i++) //push a1 et b1 dans le main
		main.push_back(_array[i]);
	while (idx < maxSize * _order)
	{
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
	if (_array.size() - maxSize > 0) //fill le leftover deque
	{
		for (size_t i = maxSize * _order; i < _array.size(); i++)
			leftover.push_back(_array[i]);
	}
	pairIndex.push_back(0);
	if (maxSize % 2 == 0)
	{
		for (size_t i = 0; i < pend.size() / _order; i++)
			pairIndex.push_back(main[group(main, i + 3)]);
	}
	else
	{
		for (size_t i = 0; i < (pend.size() / _order) - 1; i++)
			pairIndex.push_back(main[group(main, i + 3)]);
	}
}

void	DequeSort::insert()
{
	deque	main;
	deque	pend;
	deque	leftover;
	deque	pairIndex;
	size_t	n = 2;
	size_t	curr_jacobsthal = jacobsthal(n);
	size_t	prev_jacobsthal = jacobsthal(n - 1);

	initSequences(main, pend, leftover, pairIndex);
	while (pend.size() / _order > curr_jacobsthal - prev_jacobsthal)
	{
		curr_jacobsthal = jacobsthal(n);
		prev_jacobsthal = jacobsthal(n - 1);
		for (size_t i = curr_jacobsthal - prev_jacobsthal; i > 0; i--)
		{
			deque::iterator	bound = std::find(main.begin(), main.end(), pairIndex[i]);
			binaryInsert(main, pend, group(pend, i), bound);
			pairIndex.erase(pairIndex.begin() + i);
		}
		n++;
	}
	while (!pend.empty())
		binaryInsert(main, pend, pend.size() - 1, main.end());
	_array = main;
	_array.insert(_array.end(), leftover.begin(), leftover.end());
}

void	DequeSort::merge()
{
	if ((size_t)_order * 2 > _array.size())
		return ;

	size_t i = _order - 1;
	size_t j = _order * 2 - 1;
	size_t size = _array.size();
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

clock_t	DequeSort::getTime() { return _time; }

void	DequeSort::sort()
{
	_start = clock();
	merge();
	_time = clock() - _start;
	//std::cout << std::boolalpha << std::endl << std::endl  << "is_sorted(_array.begin(), _array.end()): " << isSorted(_array.begin(), _array.end()) << std::endl;
}

void	DequeSort::print()
{
	for (size_t i = 0; i < _array.size(); i++)
		std::cout << _array[i] << ' ';
	std::cout << std::endl;
}



