#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
    public:
        Brain(void);
        Brain(const Brain& other);
        Brain &operator=(const Brain &other);
        ~Brain();
        void    setIdea(int index, const std::string newIdea);
        std::string getIdea(int index) const;
	private:
		std::string	ideas[100];
};

#endif

