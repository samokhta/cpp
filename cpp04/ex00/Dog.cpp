#include "Dog.hpp"

// Default constructor
Dog::Dog(void)
{
    std::cout << "Dog: Default constructor called" << std::endl;
	type = "Dog";
    return ;
}

// Copy constructor
Dog::Dog(const Dog &other): Animal(other)
{
    std::cout << "Dog: Copy constructor called" << std::endl;
    *this = other;
    return ;
}

// Assignment operator overload
Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog: Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Dog::~Dog(void)
{
    std::cout << "Dog: Destructor called" << std::endl;
    return ;
}

void	Dog::makeSound() const
{
	std::cout << "Bark Bark Grrrrrrr....." << std::endl;
}

std::string	Dog::getType() const
{
	return type;
}