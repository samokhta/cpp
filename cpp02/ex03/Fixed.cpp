#include "Fixed.hpp"


//Constructors

const int Fixed::_fractionnalBits = 8;

Fixed::Fixed( void ): _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& copy )
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed( const int n )
{
	//std::cout << "Int constructor called" << std::endl;
	_value = n << _fractionnalBits;
}

Fixed::Fixed( const float n )
{
	//std::cout << "Float constructor called" << std::endl;
	_value  = roundf(n * (1 << _fractionnalBits));
	//std::cout << "_value = " << _value << std::endl;
}

Fixed::~Fixed( void )
{
	//std::cout << "Destructor called" << std::endl;
}


//arithmetic operators

Fixed &Fixed::operator=( const Fixed& rhs )
{
	//std::cout << "Copy assign operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed	result;

	result._value = this->_value + rhs.getRawBits();
	return (result);
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed	result;

	result._value = this->_value - rhs.getRawBits();
	return (result);
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	Fixed	result;

	result._value = this->_value * rhs.getRawBits();
	return (result);
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	Fixed	result;

	result._value = this->_value / rhs.getRawBits();
	return (result);
}


//comparaison operators

bool Fixed::operator==( const Fixed &rhs ) const
{
	if (_value == rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator!=( const Fixed &rhs ) const
{
	if (_value != rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator>=( const Fixed &rhs ) const
{
	if (_value >= rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<=( const Fixed &rhs ) const
{
	if (_value <= rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator>( const Fixed &rhs ) const
{
	if (_value > rhs.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<( const Fixed &rhs ) const
{
	if (_value < rhs.getRawBits())
		return (true);
	else
		return (false);
}


//increment operators
Fixed	&Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	temp;
	this->_value++;
	return (temp);	
}

Fixed	Fixed::operator--( int )
{
	Fixed	temp;
	this->_value--;
	return (temp);
}

//member functions

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

Fixed	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed	Fixed::max(const Fixed&a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed	Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed	Fixed::min(const Fixed&a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}


//i forgot what this one is called

std::ostream 	&operator<<( std::ostream &o,const Fixed &rhs )
{
	return (o << rhs.toFloat());
}
