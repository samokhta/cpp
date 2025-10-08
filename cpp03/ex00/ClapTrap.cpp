#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(std::string newName): _name(newName), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << this->_name << " ClapTrap: Default constructor called" << std::endl;
    return ;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << this->_name << " ClapTrap: Copy constructor called" << std::endl;
	_name = other.getName();
	_hitPoints = other.getHitPoints();
	_energyPoints = other.getEnergyPoints();
	_attackDamage = other.getAttackDamage();
    return ;
}

// Assignment operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << this->_name << " ClapTrap: Assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other.getName();
		_hitPoints = other.getHitPoints();
		_energyPoints = other.getEnergyPoints();
		_attackDamage = other.getAttackDamage();
	}
	return *this;
}

// Destructor
ClapTrap::~ClapTrap(void)
{
    std::cout << this->_name << " ClapTrap: Destructor called" << std::endl;
    return ;
}

// Member functions
void	ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		_energyPoints -= 1;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " tried to attack " << target << ", but it failed !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		if (amount > _hitPoints)
			_hitPoints = 0;
		else
			this->_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " took " << amount << " damage !" << std::endl;
	}
	else
		std::cout << "ClapTrap took " << amount << " damage, but is already KO !" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints -= 1;
		std::cout << "ClapTrap " << _name << " repaired itself for " << amount << " Hitpoints !" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " tried to repair itself, but it failed !" << std::endl;
}

void	ClapTrap::printStatus(void) const
{
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Hitpoints: " << _hitPoints << std::endl;
	std::cout << "Energy Points: " << _energyPoints << std::endl;
	std::cout << "Attack damage: " << _attackDamage << std::endl;
}

std::string		ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}
