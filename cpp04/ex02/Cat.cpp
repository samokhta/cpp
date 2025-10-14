#include "Cat.hpp"

// Default constructor
Cat::Cat(void)
{
    std::cout << "Cat: Default constructor called" << std::endl;
	type = "Cat";
    catBrain = new Brain();
    return ;
}

// Copy constructor
Cat::Cat(const Cat &other): Animal(other)
{
    std::cout << "Cat: Copy constructor called" << std::endl;
    this->catBrain = new Brain(*(other.catBrain));
    this->type = other.type;
    return ;
}

// Assignment operator overload
Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat: Assignment operator called" << std::endl;
    if (this != &other)
    {
        delete this->catBrain;
        this->catBrain = new Brain(*(other.catBrain));
        this->type = other.type;
    }
	return *this;
}

// Destructor
Cat::~Cat(void)
{
    std::cout << "Cat: Destructor called" << std::endl;
    delete catBrain;
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

void    Cat::setIdea(int index, const std::string newIdea)
{
    catBrain->setIdea(index, newIdea);
}

std::string Cat::getIdea(int index) const
{
    std::string idea;

    idea = catBrain->getIdea(index);
    return (idea);
}