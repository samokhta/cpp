#include "FragTrap.hpp"

// Constructors/Destructor
FragTrap::FragTrap(std::string newName): ClapTrap(newName)
{
    std::cout << this->name << " FragTrap: Default constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
    return ;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
    std::cout << this->name << " FragTrap: Copy constructor called" << std::endl;
    return ;
}

FragTrap &FragTrap::operator=(const FragTrap& other)
{
	ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << this->name << " FragTrap Destructor called" << std::endl;
    return ;
}

void	FragTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		energyPoints -= 1;
		std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "FragTrap " << name << " tried to attack " << target << ", but it failed !" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " wants to do a high five !" << std::endl;
}