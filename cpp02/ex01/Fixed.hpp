#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	_value;
	static const int	_fractionnalBits;
public:
	Fixed( void );
	Fixed( const Fixed& copy );
	Fixed( const int n );
	Fixed( const float n );
	Fixed &operator=( const Fixed &rhs );
	~Fixed( void );
	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

std::ostream 	&operator<<( std::ostream &o,const Fixed &rhs );

#endif