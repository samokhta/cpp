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
	//constructors
	Fixed( void );
	Fixed( const Fixed& copy );
	Fixed( const int n );
	Fixed( const float n );
	~Fixed( void );

	//arithmetic operators
	Fixed &operator=( const Fixed &rhs );
	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;

	//comparaison operators
	bool operator==( const Fixed &rhs ) const;
	bool operator!=( const Fixed &rhs ) const;
	bool operator>=( const Fixed &rhs ) const;
	bool operator<=( const Fixed &rhs ) const;
	bool operator>( const Fixed &rhs ) const;
	bool operator<( const Fixed &rhs ) const;

	//increment operators
	Fixed	&operator++();
	Fixed	&operator--();
	Fixed	operator++( int );
	Fixed	operator--( int );

	//member functions
	float	toFloat( void ) const;
	int		toInt( void ) const;
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	static Fixed max(Fixed& a, Fixed& b);
	static Fixed max(const Fixed&a, const Fixed& b);
	static Fixed min(Fixed& a, Fixed& b);
	static Fixed min(const Fixed&a, const Fixed& b);
};

//i forgot what this one is called
std::ostream 	&operator<<( std::ostream &o,const Fixed &rhs );

#endif