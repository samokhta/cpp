#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
    public:
        Animal(void);
        Animal(const Animal& other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();
		virtual void	makeSound() const;
		virtual std::string	getType() const;
	protected:
		std::string	type;
};

#endif

