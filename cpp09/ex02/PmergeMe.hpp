#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cmath>
#include <cstdlib>

# define vector	std::vector<int>

class VectSort
{
	private:
		vector				_array;
		size_t				_order;
		clock_t				_time;

		VectSort();
		VectSort(const VectSort& other);
		VectSort	&operator=(const VectSort& other);


		//helpers
		size_t	jacobsthal(long n);
		size_t	group(vector& vec, size_t group);
		void	swapPair(int i, int j);
		void	updatePair(vector& pairIndex, size_t insertedPendIdx);
		void	printVec(vector &vec);

		size_t	binarySearch(vector &main, int item, size_t min, size_t max);
		void	binaryInsert(vector &main, vector &pend, size_t itemIdx, vector::iterator max);
		void	initSequences(vector &main, vector &pend, vector& leftover, vector& pairIndex);
		void	insert();
		void	merge();

	public:
		VectSort(int argc, char **argv);
		~VectSort();
		void	sort();
		void	print();
};

class DequeSort
{
	private:
		vector	_array;
		int					_order;
		clock_t				_time;

		DequeSort();
		DequeSort(const DequeSort& other);
		DequeSort	&operator=(const DequeSort& other);

		void	merge();
		void	insert();
		int		jacobsthal();

	public:
		DequeSort(char *av);
		~DequeSort();
};

bool	checkArgv(int argc, char **argv);

#endif