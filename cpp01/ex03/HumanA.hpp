# ifndef HUMAN_A
# define HUMAN_A

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_Name;
		Weapon	&_Weapon;
	public:
		HumanA( std::string newName, Weapon &newWeapon );
		void	attack( void );
};

# endif