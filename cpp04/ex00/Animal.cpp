#include "Animal.hpp"

// Default constructor
Animal::Animal(void)
{
    std::cout << "Animal: Default constructor called" << std::endl;
	type = "Animal";
    return ;
}

// Copy constructor
Animal::Animal(const Animal &other)
{
    std::cout << "Animal: Copy constructor called" << std::endl;
    *this = other;
    return ;
}

// Assignment operator overload
Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal: Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Animal::~Animal(void)
{
    std::cout << "Animal: Destructor called" << std::endl;
    return ;
}

void	Animal::makeSound() const
{
	std::cout << "Animal noises" << std::endl;
}

std::string	Animal::getType() const
{
	return type;
}