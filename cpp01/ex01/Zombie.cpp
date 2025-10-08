#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie()
{
    std::cout << this->_name << ": Destructor called" << std::endl;
    return ;
}

void	Zombie::setName(std::string newName)
{
    this->_name = newName;
}

void	Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}
