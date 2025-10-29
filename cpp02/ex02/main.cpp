#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ));

	std::cout << "a = " << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << "a = " << a << std::endl << std::endl;
	
	std::cout << "b = " << b << std::endl;
	std::cout << b + a + 5 << std::endl;
	std::cout << b - a << std::endl;
	std::cout << b / 2 << std::endl << std::endl;

	std::cout << "b = " << b << std::endl;
	std::cout << a * b << std::endl << std::endl;
	//std::cout << b / 0 << std::endl;

	std::cout << Fixed::max( a, b / 2 ) << std::endl;
	std::cout << Fixed::min(a * 1000, b) << std::endl;

	return 0;
}