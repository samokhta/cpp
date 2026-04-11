#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cmath>
#include <cstdlib>

class VectSort
{
	private:
		std::vector<int>	_array;
		size_t				_order;
		clock_t				_time;

		VectSort();
		VectSort(const VectSort& other);
		VectSort	&operator=(const VectSort& other);

		void	merge();
		void	swapPair(int i, int j);
		void	initSequences(std::vector<int> &main, std::vector<int> &pend);
		void	insert();
		void	binaryInsert(std::vector<int> &main, std::vector<int> &pend, size_t elemIdx, int min, int max);
		void	printVec(std::vector<int> &vec);
		unsigned long	jacobsthal(long n);

	public:
		VectSort(int argc, char **argv);
		~VectSort();
		void	sort();
		void	print();
};

class DequeSort
{
	private:
		std::vector<int>	_array;
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