#include "Weapon.hpp"

Weapon::Weapon( std::string newType )
{
	setType(newType);
	return ;
}

const std::string&	Weapon::getType( void ) const
{
	return (this->_type);
}

void	Weapon::setType( std::string newType )
{
	this->_type = newType;
	return ;
}
