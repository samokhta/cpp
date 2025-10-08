#include "Brain.hpp"

// Default constructor
Brain::Brain(void)
{
    std::cout << "Brain: Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Brain::Brain(const Brain &other)
{
    std::cout << "Brain: Copy constructor called" << std::endl;
    *this = other;
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
