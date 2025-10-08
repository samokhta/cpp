#include "Fixed.hpp"

const int Fixed::_fractionnalBits = 8;

Fixed::Fixed( void ): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& copy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed( const int n )
{
	std::cout << "Int constructor called" << std::endl;
	_value = n << _fractionnalBits;
}

Fixed::Fixed( const float n )
{
	std::cout << "Float constructor called" << std::endl;
	_value  = roundf(n * (1 << _fractionnalBits));
	//std::cout << "_value = " << _value << std::endl;
}

Fixed &Fixed::operator=( const Fixed& rhs )
{
	std::cout << "Copy assign operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat( void ) const
{
	return ((float)_value / (1 << _fractionnalBits));
}

int		Fixed::toInt( void ) const
{
	//shifts a _fractionnalBits amount of digits into the fractionnal part, effectively removing them
	return (_value >> _fractionnalBits); 
}

int	Fixed::getRawBits( void ) const
{
	return (this->_value);
}
void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

std::ostream 	&operator<<( std::ostream &o,const Fixed &rhs )
{
	return (o << rhs.toFloat());
}
