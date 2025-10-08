#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat(void)
{
    std::cout << "WrongCat: Default constructor called" << std::endl;
	type = "WrongCat";
    return ;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other)
{
    std::cout << "WrongCat: Copy constructor called" << std::endl;
    *this = other;
    return ;
}

// Assignment operator overload
WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat: Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat: Destructor called" << std::endl;
    return ;
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Meooooowwwwwww" << std::endl;
}

std::string	WrongCat::getType() const
{
	return type;
}