#include "HumanB.hpp"

HumanB::HumanB( std::string newName ) : _Name(newName), _Weapon(NULL) {}

void	HumanB::attack( void )
{
	if (this->_Weapon)
		std::cout << this->_Name << " attacks with their " << this->_Weapon->getType() << std::endl;
	else
		std::cout << this->_Name << " attacks with their bare hands" << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	this->_Weapon = &newWeapon;
	return ;
}
