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
#include <ios>

# define vector	std::vector<int>

class VectSort
{
	private:
		vector	_array;
		size_t	_order;
		clock_t	_start;
		clock_t	_time;

		VectSort();
		VectSort(const VectSort& other);
		VectSort	&operator=(const VectSort& other);


		//helpers
		size_t	jacobsthal(long n);
		size_t	group(vector& vec, size_t group);
		void	swapPair(int i, int j);
		void	printVec(vector &vec);

		size_t	binarySearch(vector &main, int item, size_t min, size_t max);
		void	binaryInsert(vector &main, vector &pend, size_t itemIdx, vector::iterator max);
		void	initSequences(vector &main, vector &pend, vector& leftover, vector& pairIndex);
		void	insert();
		void	merge();

	public:
		VectSort(int argc, char **argv);
		~VectSort();
		clock_t	getTime();
		void	sort();
		void	print();
};

# define deque	std::deque<int>

class DequeSort
{
	private:
		deque	_array;
		size_t	_order;
		clock_t	_start;
		clock_t	_time;

		DequeSort();
		DequeSort(const DequeSort& other);
		DequeSort	&operator=(const DequeSort& other);


		//helpers
		size_t	jacobsthal(long n);
		size_t	group(deque& vec, size_t group);
		void	swapPair(int i, int j);
		void	printVec(deque &vec);

		size_t	binarySearch(deque &main, int item, size_t min, size_t max);
		void	binaryInsert(deque &main, deque &pend, size_t itemIdx, deque::iterator max);
		void	initSequences(deque &main, deque &pend, deque& leftover, deque& pairIndex);
		void	insert();
		void	merge();

	public:
		DequeSort(int argc, char **argv);
		~DequeSort();
		clock_t	getTime();
		void	sort();
		void	print();
};

bool	checkArgv(int argc, char **argv);

#endif