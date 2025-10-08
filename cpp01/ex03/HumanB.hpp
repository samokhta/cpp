# ifndef HUMAN_B
# define HUMAN_B

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string _Name;
	Weapon *_Weapon;
public:
	HumanB( std::string newName );
	void	attack( void );
	void	setWeapon(Weapon &newWeapon);
};

# endif