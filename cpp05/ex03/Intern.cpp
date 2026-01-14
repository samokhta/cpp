#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern &Intern::operator=(const Intern& other) { (void)other; return *this; }
Intern::~Intern() {}

AForm*	Intern::makePPF(std::string target) const { return new PresidentialPardonForm(target); }
AForm*	Intern::makeRRF(std::string target) const { return new RobotomyRequestForm(target); }
AForm*	Intern::makeSCF(std::string target) const { return new ShrubberyCreationForm(target); }

AForm*	Intern::makeForm(std::string type, std::string target)
{
	typedef AForm* (Intern::*FormFunctions)(std::string target) const;

	std::string forms[] = { "ppf", "rrf", "scf" };
	FormFunctions functions[] = { &Intern::makePPF, &Intern::makeRRF, &Intern::makeSCF };

	for (int i = 0; i < 3; ++i) {
		if (type == forms[i])
		{
			std::cout << "Intern creates " << forms[i] << std::endl;
			return ((this->*functions[i])(target));
		}
	}
	std::cout << "Error: form type \"" << type << "\" does not exist" << std::endl;
	return NULL;
}
