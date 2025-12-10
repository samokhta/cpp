#include "Brain.hpp"

// Default constructor
Brain::Brain(void)
{
    std::cout << "Brain: Default constructor called" << std::endl;
    for (int i = 0; i < 100; ++i)
        ideas[i] = "Empty"; 
    return ;
}

// Copy constructor
Brain::Brain(const Brain &other)
{
    std::cout << "Brain: Copy constructor called" << std::endl;
    for (int i = 0; i < 100; ++i)
        this->ideas[i] = other.ideas[i];
    return ;
}

// Assignment operator overload
Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain: Assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
            this->ideas[i] = other.ideas[i];
    }
    return (*this);
}

// Destructor
Brain::~Brain(void)
{
    std::cout << "Brain: Destructor called" << std::endl;
    return ;
}

void    Brain::setIdea(int index, const std::string newIdea)
{
    if (index >= 0 && index <= 100)
        ideas[index] = newIdea;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index <= 100)
        return ideas[index];
    else
        return NULL;
}
