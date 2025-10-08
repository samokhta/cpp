#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(std::string newName): name(newName), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << this->name << " ClapTrap: Default constructor called" << std::endl;
    return ;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << this->name << " ClapTrap: Copy constructor called" << std::endl;
	name = other.getName();
	hitPoints = other.getHitPoints();
	energyPoints = other.getEnergyPoints();
	attackDamage = other.getAttackDamage();
    return ;
}

// Assignment operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << this->name << " ClapTrap: Assignment operator called" << std::endl;
	if (this != &other)
	{
		name = other.getName();
		hitPoints = other.getHitPoints();
		energyPoints = other.getEnergyPoints();
		attackDamage = other.getAttackDamage();
	}
	return *this;
}

// Destructor
ClapTrap::~ClapTrap(void)
{
    std::cout << this->name << " ClapTrap: Destructor called" << std::endl;
    return ;
}

// Member functions
void	ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		energyPoints -= 1;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " tried to attack " << target << ", but it failed !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > 0)
	{
		if (amount > hitPoints)
			hitPoints = 0;
		else
			this->hitPoints -= amount;
		std::cout << "ClapTrap " << name << " took " << amount << " damage !" << std::endl;
	}
	else
		std::cout << "ClapTrap took " << amount << " damage, but is already KO !" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		hitPoints += amount;
		energyPoints -= 1;
		std::cout << "ClapTrap " << name << " repaired itself for " << amount << " Hitpoints !" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " tried to repair itself, but it failed !" << std::endl;
}

void	ClapTrap::printStatus(void) const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Hitpoints: " << hitPoints << std::endl;
	std::cout << "Energy Points: " << energyPoints << std::endl;
	std::cout << "Attack damage: " << attackDamage << std::endl;
}

std::string		ClapTrap::getName(void) const
{
	return (this->name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->attackDamage);
}
