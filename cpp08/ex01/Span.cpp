#include "Span.hpp"

Span::Span() : _size(0) {}
Span::~Span() {}
Span::Span(unsigned int size) : _size(size) {}
Span::Span(const Span& other) : _size(other._size), _vect(other._vect) {}
Span &Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_size = other._size;
		_vect = other._vect;
	}
	return *this;
}

void	Span::printSpan()
{
	for (size_t i = 0; i < _vect.size(); i++)
		std::cout << _vect[i] << " ";
	std::cout << std::endl;
}

void	Span::addNumber(int n)
{
	if (_vect.size() < _size)
		_vect.push_back(n);
	else
		throw ContainerFullException();
	
}

unsigned int	Span::shortestSpan()
{
	std::vector<int>	tmp = _vect;
	int	shortest = __INT_MAX__;
 
	if (_size < 2)
		throw NoSpanException();
	std::sort(tmp.begin(), tmp.end());
	for (size_t i = 1; i < _size; i++)
		shortest = std::min(shortest, tmp[i] - tmp[i - 1]);
	return shortest;
}

unsigned int	Span::longestSpan()
{
	if (_size < 2)
		throw NoSpanException();
	return *std::max_element(_vect.begin(), _vect.end()) - *std::min_element(_vect.begin(), _vect.end());
}

void Span::addNumberRange(std::vector<int>::iterator listBegin, std::vector<int>::iterator listEnd)
{}
