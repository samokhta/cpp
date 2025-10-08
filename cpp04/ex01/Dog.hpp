#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog(void);
        Dog(const Dog& other);
        Dog &operator=(const Dog &other);
        virtual ~Dog();
		virtual void	makeSound() const;
		virtual std::string	getType() const;
	private:
		Brain*	dogBrain;
};

#endif

