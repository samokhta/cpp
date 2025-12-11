#include "Cat.hpp"

// Default constructor
Cat::Cat(void)
{
    std::cout << "Cat: Default constructor called" << std::endl;
	type = "Cat";
    return ;
}

// Copy constructor
Cat::Cat(const Cat &other): Animal(other)
{
    std::cout << "Cat: Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat: Assignment operator called" << std::endl;
    type = other.type;
    return (*this);
}

// Destructor
Cat::~Cat(void)
{
    std::cout << "Cat: Destructor called" << std::endl;
    return ;
}

void	Cat::makeSound() const
{
	std::cout << "Meooooowwwwwww" << std::endl;
}

std::string	Cat::getType() const
{
	return type;
}