#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(std::string name);
        ~FragTrap(void);
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap& other);
		void	attack(const std::string &target);
		void	highFivesGuys(void);
};

#endif