#include "HumanA.hpp"

HumanA::HumanA( std::string newName, Weapon &newWeapon ) : _Name(newName), _Weapon(newWeapon) {}

void	HumanA::attack( void )
{
	std::cout << this->_Name << " attacks with their " << this->_Weapon.getType() << std::endl;
	return ;
}
