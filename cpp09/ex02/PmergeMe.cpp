#include "PmergeMe.hpp"
//./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7
//si un element ne peut pas former de paire alors tu le mets dans pend, si il peut meme pas former de groupe alors tu l'ignore (il se fera sort quand _order == 1)
//TODO: indexer ax pour le binary search, handle les elements qui se font supprimer

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

size_t	VectSort::jacobsthal(long n) {return round((pow(2, n + 1) + pow(-1, n)) / 3);}

size_t	VectSort::group(vector& vec, size_t group) //retourne un index, pas la valeur a l'index
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

void	VectSort::updatePair(vector& pairIndex, size_t insertedPendIdx)
{
	//insertedPendIdx: l'index de l'element que je viens d'inserer 
	//exemple: je viens d'inserer b5 qui etait le 2eme groupe dans le pend aka pairIndex[2], insertedPendIdx sera alors 2
	//fonction obsolete mais je la garde au cas ou je me perds
	pairIndex.erase(pairIndex.begin() + insertedPendIdx);
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

//insere un element du pend dans le main en utilisant le binary search pour trouver ou le placer
void		VectSort::binaryInsert(vector &main, vector &pend, size_t itemIdx, vector::iterator max) //elemIdx: fin du groupe a insert
{
	//std::cout << "binaryInsert() call" << itemIdx << std::endl;
	size_t maxGroup  = (size_t)std::distance(main.begin(), max) / _order;
	size_t insertIdx = binarySearch(main, pend[itemIdx], 1, maxGroup);
	vector::iterator	position;	//insertIdx mais en iterateur aka la position dans le main ou tu vas inserer le groupe
	vector::iterator	first;		//premier element du groupe a inserer
	vector::iterator	last;		//dernier element du groupe a inserer

	position = main.begin();
	std::advance(position, insertIdx);
	first = pend.begin();
	if (itemIdx + 1 >= _order)
	    std::advance(first, itemIdx + 1 - _order);  // (7+1) - 4 = 4 → correct start
	last = first;
	std::advance(last, _order);  // first + 4 → correct end

	//std::cout << "debug\n";
	main.insert(position, first, last); //segfault ici
	pend.erase(first, last);

	//std::cout << std::endl << "main: "; printVec(main);
	//std::cout << "main.size(): " << main.size() << std::endl;
	//std::cout << "pend: "; printVec(pend);
	//std::cout << "pend.size(): " << pend.size()<< std::endl;
	//std::cout << "binaryInsert() return" << std::endl;
}

//push les elements necessaires dans le main et le pend (ax + b1 dans main, le reste des b dans pend)
//remplit pairIndex: pairIndex[0] = 0, pairIndex[1] = la valeur de l'element pair a pend (si b5 est le premier element du pend alors pairIndex[1] va donner la valeur de a5)
//ensuite tu peux utiliser std::find(main.begin(), main.end(), pairIndex[1]) pour trouver l'index de a5
//bug: supprime les elements qui ne peuvent pas former de paire, maybe fix en faisant un vec trash?
void	VectSort::initSequences(vector &main, vector &pend, vector& leftover, vector& pairIndex)
{
	//std::cout << std::endl << "initSequences() call " << std::endl;
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
		//std::cout << "odd element found in pend\n";
		for (size_t i = 0; i < (pend.size() / _order) - 1; i++)
			pairIndex.push_back(main[group(main, i + 3)]);
	}

	//for (size_t i = 0; i < pairIndex.size(); i++)
		//std::cout << "pairIndex[" << i << "] = " << pairIndex[i] << std::endl; 
	//std::cout << "_order: " << _order << std::endl;
	//std::cout << "maxSize * _order: " << maxSize * _order << std::endl;
	//std::cout << "_array: "; print();
	//std::cout << "_array.size(): " << _array.size() << std::endl;
	//std::cout << "main: "; printVec(main);
	//std::cout << "main.size(): " << main.size() << std::endl;
	//std::cout << "pend: "; printVec(pend);
	//std::cout << "pend.size(): " << pend.size() /_order << std::endl;
	//std::cout << "leftover: "; printVec(leftover);
	//std::cout << "leftover.size(): " << leftover.size() /_order << std::endl;
	//std::cout << "initSequences() return "<< std::endl << std::endl;
}



//risque de casser a cause des calculs d'index (est-ce que le premier groupe est index 0 ou index 1)
//dans certaines operations faut faire (x * index) - 1 pour compenser le fait que ton array commence a index 0
void	VectSort::insert()
{
	//std::cout << "insert() call" << std::endl;
	vector	main;
	vector	pend;
	vector	leftover;
	vector	pairIndex;
	//bool	isOdd = pend.size() % 2 == 0 ? true : false;//idk about that syntax
	size_t	n = 2;
	size_t	curr_jacobsthal = jacobsthal(n); //3
	size_t	prev_jacobsthal = jacobsthal(n - 1); //1

	initSequences(main, pend, leftover, pairIndex);
	while (pend.size() / _order > curr_jacobsthal - prev_jacobsthal)
	{
		curr_jacobsthal = jacobsthal(n);
		prev_jacobsthal = jacobsthal(n - 1);
		for (size_t i = curr_jacobsthal - prev_jacobsthal; i > 0; i--)
		{
			vector::iterator	bound = std::find(main.begin(), main.end(), pairIndex[i]); //si jai pas fuck up pairIndex ca retourne un iterator vers le dernier element du groupe
			binaryInsert(main, pend, group(pend, i), bound);
			pairIndex.erase(pairIndex.begin() + i);
		}
		n++;
	}
	while (!pend.empty())
		binaryInsert(main, pend, pend.size() - 1, main.end()); //claude propose binaryInsert(main, pend, group(pend, pend.size() / _order), main.end());
	_array = main;
	_array.insert(_array.end(), leftover.begin(), leftover.end());
	//std::cout << "insert() return" << std::endl;
}
//compare les paires et les swap de sorte a ce que ax > bx
void	VectSort::merge()
{
	//std::cout << "merge() call" << std::endl;
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
	//std::cout << "merge() return" << std::endl;
	//print();
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