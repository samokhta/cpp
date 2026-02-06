#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private:
		T*				_array;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array& other);
		
		Array	&operator=(const Array& other);
		T		&operator[](const unsigned int index) const;

		unsigned int	size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
			virtual const char* what() const throw()
			{
				return ("Out of bounds");
			}
		};
};

# include "Array.tpp"
#endif