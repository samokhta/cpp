#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat(void);
        Cat(const Cat& other);
        Cat &operator=(const Cat &other);
        virtual ~Cat();
		virtual void	makeSound() const;
		virtual std::string	getType() const;
        void    setIdea(int index, const std::string newIdea);
        std::string getIdea(int index) const;
	private:
		Brain*	catBrain;
};

#endif

