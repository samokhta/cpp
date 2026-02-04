#include <iostream>

template<typename T>
void	print(const T &n) { std::cout << n << std::endl; }
template<typename T>
void	incr(T &n) { n++; }

template<typename T>
void	iter(const T* array, const int length, void (*f)(const T &n))
{
	if (!array || !f || length <= 0)
		return ;
	for (int i = 0; i < length; i++)
		f(array[i]);
}

template<typename T>
void	iter(T* array, const int length, void (*f)(T &n))
{
	if (!array || !f || length <= 0)
		return ;
	for (int i = 0; i < length; i++)
		f(array[i]);
}
