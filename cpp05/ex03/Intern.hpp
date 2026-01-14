#ifndef INTERN_H
# define INTERN_H
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern &operator=(const Intern& other);
		~Intern();
		AForm *makeForm(std::string type, std::string target);
	private:
		AForm *makePPF(std::string target) const;
		AForm *makeRRF(std::string target) const;
		AForm *makeSCF(std::string target) const;
};

#endif