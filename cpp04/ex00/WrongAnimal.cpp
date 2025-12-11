#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal: Default constructor called" << std::endl;
	type = "WrongAnimal";
    return ;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
    std::cout << "WrongAnimal: Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal: Assignment operator called" << std::endl;
    type = other.type;
    return (*this);
}

// Destructor
WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal: Destructor called" << std::endl;
    return ;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal noises" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return type;
}