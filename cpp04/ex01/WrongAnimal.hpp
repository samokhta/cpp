#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal &operator=(const WrongAnimal &other);
        virtual ~WrongAnimal();
		void	makeSound() const;
		virtual std::string	getType() const;
	protected:
		std::string	type;
};

#endif

