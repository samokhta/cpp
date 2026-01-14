#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat				garice("garice", 150);
	Bureaucrat				noe("noé", 75);
	Bureaucrat				jim("jim", 1);
	ShrubberyCreationForm	scf("home");
	PresidentialPardonForm	ppf("maria");
	RobotomyRequestForm		rrf("maria");

	std::cout << std::endl << "Garice, grade 150-----------------------------------" << std::endl << std::endl;
	garice.signForm(scf);
	garice.executeForm(scf);
	garice.signForm(ppf);
	garice.executeForm(ppf);
	garice.signForm(rrf);
	garice.executeForm(rrf);

	//std::cout << std::endl << "Noé, grade 75-----------------------------------" << std::endl << std::endl;
	//noe.signForm(scf);
	//noe.executeForm(scf);
	//noe.signForm(ppf);
	//noe.executeForm(ppf);
	//noe.signForm(rrf);
	//noe.executeForm(rrf);

	//std::cout << std::endl << "Jim, grade 1-----------------------------------" << std::endl << std::endl;
	//jim.signForm(scf);
	//jim.executeForm(scf);
	//jim.signForm(ppf);
	//jim.executeForm(ppf);
	//jim.signForm(rrf);
	//jim.executeForm(rrf);

	return 0;
}