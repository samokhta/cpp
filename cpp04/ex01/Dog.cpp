#include "Dog.hpp"

// Default constructor
Dog::Dog(void)
{
    std::cout << "Dog: Default constructor called" << std::endl;
	type = "Dog";
    dogBrain = new Brain();
    return ;
}

// Copy constructor
Dog::Dog(const Dog &other): Animal(other)
{
    std::cout << "Dog: Copy constructor called" << std::endl;
    this->dogBrain = new Brain(*(other.dogBrain));
    this->type = other.type;
    return ;
}

// Assignment operator overload
Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog: Assignment operator called" << std::endl;
    this->dogBrain = new Brain(*(other.dogBrain));
    this->type = other.type;
    return (*this);
}

// Destructor
Dog::~Dog(void)
{
    std::cout << "Dog: Destructor called" << std::endl;
    delete dogBrain;
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

void    Dog::setIdea(int index, const std::string newIdea)
{
    if (index >= 0 && index <= 100)
        dogBrain->setIdea(index, newIdea);
}

std::string Dog::getIdea(int index) const
{
    std::string idea;

    if (index >= 0 && index <= 100)
        idea = dogBrain->getIdea(index);
    else
        return NULL;
    return idea;
}