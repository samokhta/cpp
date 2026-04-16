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

void	VectSort::printVec(vector &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}
//size_t		VectSort::binarySearch(vector &main, int item, size_t min, size_t max) //ici elemIdx passe a la fin du groupe pour pouvoir le comparer aux autres groupes, risque de casser dans le cas de _order == 1
//{
//	//pour retourner un size_t de l'index tu peux faire std::distance(main.begin(), min)
//	//ou bien tu peux lui faire retourner un iterator
//	size_t	ret = 0;
//    if (max <= min) //condition qui casse la recursion une fois que t'as trouve le bon index
//        return (item > main[min]) ? (min + _order) : min;
//
//    int mid = (min + max) /2;//trouve un moyen d'arrondir a l'ordre le plus proche
//
//    if (item == main[mid])
//        return mid + 1;
//
//    if (item > main[mid])
//        return binarySearch(main, item, mid + _order, max);
//    return binarySearch(main, item, min, mid - _order);
//}

size_t VectSort::binarySearch(vector& main,
                              int item,
                              size_t min,
                              size_t max)
{
	std::cout << "binarySearch() call" << std::endl;
    size_t order = _order;

    while (min <= max)
    {
        // Compute midpoint and snap to nearest multiple of order
        size_t raw = (min + max) / 2;
        size_t mid = (raw / order) * order;

        // Safety: ensure mid stays in range
        if (mid < min)
            mid = min;
        if (mid > max)
            mid = max - (max % order);

        if (main[mid] == item)
		{
			std::cout << "binarySearch() return1" << std::endl;
            return mid + order;  // insert after
		}

        if (main[mid] < item)
        {
            if (mid + order > max)
			{
				std::cout << "binarySearch() return" << mid + order << std::endl;
                return mid + order;
			}
            min = mid + order;
        }
        else
        {
            if (mid < order || mid - order < min)
			{
				std::cout << "binarySearch() return3" << std::endl;
                return mid;
			}
            max = mid - order;
        }
    }
	std::cout << "binarySearch() return4" << std::endl;
    return min;
}



//insere un element du pend dans le main en utilisant le binary search pour trouver ou le placer
void		VectSort::binaryInsert(vector &main, vector &pend, size_t elemIdx, vector::iterator min, vector::iterator max) //elemIdx: debut du groupe a insert (ex: si je passe b2 aka le premier groupe du pend elemIdx sera 0)
{
	std::cout << "binaryInsert() call" << std::endl;
	(void)min;
	size_t	insertIdx = binarySearch(main, pend[elemIdx * _order], 0, std::distance(main.begin(), max));	//index auquel tu dois insert toInsert, si tu dois inserer entre le 1er et le 2eme groupe a order 4 alors insertIdx sera 5(vector::insert insert avant l'index specifie)
	vector::iterator	position;
	vector::iterator	first;
	vector::iterator	last;

	position = main.begin();
	for (size_t i = 0; i < insertIdx; i++)
		position++;
	first = pend.begin();
	for (size_t i = 0; i < elemIdx; i++)
		first++;
	last = first;
	for (size_t i = 0; i < _order; i++)
		last++;
	main.insert(position, first, last);
	pend.erase(first, last);
	std::cout << "binaryInsert() return" << std::endl;
}

//push les elements necessaires dans le main et le pend (ax + b1 dans main, le reste des b dans pend)
//remplit pairIndex: pairIndex[0] = 0, pairIndex[1] = la valeur de l'element pair a pend (si b5 est le premier element du pend alors pairIndex[1] va donner la valeur de a5)
//ensuite tu peux utiliser std::find(main.begin(), main.end(), pairIndex[1]) pour trouver l'index de a5
//bug: supprime les elements qui ne peuvent pas former de paire, maybe fix en faisant un vec trash?
void	VectSort::initSequences(vector &main, vector &pend, vector& pairIndex)
{
	std::cout << std::endl << "initSequences() call " << std::endl;
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
	pairIndex.push_back(0);
	for (size_t i = 1; i < pend.size() / _order; i++)	//je crois ca assigne correctement???
		pairIndex.push_back(main[i * _order]);			
	std::cout << "_order: " << _order << std::endl;
	std::cout << "maxSize * _order: " << maxSize * _order << std::endl;
	std::cout << "_array: "; print();
	std::cout << "_array.size(): " << _array.size() << std::endl;
	std::cout << "main: "; printVec(main);
	std::cout << "main.size(): " << main.size() << std::endl;
	std::cout << "pend: "; printVec(pend);
	std::cout << "pend.size(): " << pend.size() << std::endl;
	std::cout << "initSequences() return "<< std::endl << std::endl;
}

void	VectSort::updatePair(vector& pairIndex, size_t insertedPendIdx)
{
	//insertedPendIdx: l'index de l'element que je viens d'inserer 
	//exemple: je viens d'inserer b5 qui etait le 2eme groupe dans le pend aka pairIndex[2], insertedPendIdx sera alors 2
	//fonction obsolete mais je la garde au cas ou je me perds
	pairIndex.erase(pairIndex.begin() + insertedPendIdx);
}

//risque de casser a cause des calculs d'index (est-ce que le premier groupe est index 0 ou index 1)
//dans certaines operations faut faire (x * index) - 1 pour compenser le fait que ton array commence a index 0
void	VectSort::insert()
{
	std::cout << "insert() call" << std::endl;
	vector	main;
	vector	pend;
	vector	pairIndex;
	//bool	isOdd = pend.size() % 2 == 0 ? true : false;//idk about that syntax
	size_t	n = 2;
	size_t	curr_jacobsthal = jacobsthal(n); //3
	size_t	prev_jacobsthal = jacobsthal(n - 1); //1

	initSequences(main, pend, pairIndex);
	while (pend.size() / _order > curr_jacobsthal - prev_jacobsthal)
	{
		curr_jacobsthal = jacobsthal(n);
		prev_jacobsthal = jacobsthal(n - 1);
		for (size_t i = curr_jacobsthal - prev_jacobsthal; i > 0; i--)
		{
			vector::iterator	bound = std::find(main.begin(), main.end(), pairIndex[i]);
			binaryInsert(main, pend, i, main.begin() + _order, bound);//dans la premiere iteration, i == 2
			pairIndex.erase(pairIndex.begin() + i);
		}
		n++;
	}
	while (!pend.empty())
		binaryInsert(main, pend, pend.size() - _order, main.begin(), main.end());
	_array = main;
	std::cout << "insert() return" << std::endl;
}
//compare les paires et les swap de sorte a ce que ax > bx
void	VectSort::merge()
{
	std::cout << "merge() call" << std::endl;
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
	std::cout << "merge() return" << std::endl;
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