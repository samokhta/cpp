#include <iostream>

template<typename T>
void	swap(T& a, T& b)
{
	T	cpy = a;
	a = b;
	b = cpy;
}

template<typename T>
T	min(T& a, T& b) { return (a < b ? a : b); }
template<typename T>
T	max(T& a, T& b) { return (a > b ? a : b); }