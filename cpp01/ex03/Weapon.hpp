# ifndef WEAPON
# define WEAPON

#include <iostream>

class Weapon
{
	private:
		std::string	_type;
	public:
		std::string	getType( void ) const;
		void		setType( std::string newType );
		Weapon( std::string newType );
};

# endif