#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <algorithm>

class OccurenceNotFoundException : public std::exception
{
	public:
	virtual const char* what() const throw()
	{
		return ("Occurence not found in container");
	}
};

template <typename T>
void	easyfind(T& container, int n)
{
	if (std::find(container.begin(), container.end(), n) != container.end())
		std::cout << "Occurence of " << n << " found in container" << std::endl;
	else
		throw OccurenceNotFoundException();
}

#endif