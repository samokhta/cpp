#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	_value;
	static const int	_fractionnalBits;
public:
	Fixed( void );
	Fixed( const Fixed& copy );
	Fixed &operator=( const Fixed &rhs );
	~Fixed( void );
	int	getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif