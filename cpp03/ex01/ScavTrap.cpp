#include "ScavTrap.hpp"

// Constructors/Destructor
ScavTrap::ScavTrap(std::string newName): ClapTrap(newName)
{
    std::cout << this->name << " ScavTrap: Default constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
    return ;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
    std::cout << this->name << " ScavTrap: Copy constructor called" << std::endl;
    return ;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other)
{
	ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << this->name << " ScavTrap Destructor called" << std::endl;
    return ;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		energyPoints -= 1;
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << name << " tried to attack " << target << ", but it failed !" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is now in Gate Keeper mode !" << std::endl;
}
