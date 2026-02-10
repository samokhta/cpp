#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <iostream>

class Span
{
	private:
		Span();
		unsigned int		_size;
		std::vector<int>	_vect;
	public:
		~Span();
		Span(unsigned int size);
		Span(const Span& other);
		Span	&operator=(const Span& other);

		void			printSpan();
		void			addNumber(int n);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		void addNumberRange(std::vector<int>::iterator listBegin, std::vector<int>::iterator listEnd);

		class ContainerFullException : public std::exception
		{
			public:
			virtual const char* what() const throw()
			{
				return ("Container is full");
			}
		};

		class NoSpanException : public std::exception
		{
			public:
			virtual const char* what() const throw()
			{
				return ("Not enough numbers in container to find a span");
			}
		};
		
};

#endif