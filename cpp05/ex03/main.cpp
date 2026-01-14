#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
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

	Intern someRandomIntern;
	AForm*	rrfIntern;
	AForm*	ppfIntern;
	AForm*	scfIntern;
	rrfIntern = someRandomIntern.makeForm("error test", "Bender");
	rrfIntern = someRandomIntern.makeForm("rrf", "Bender");
	ppfIntern = someRandomIntern.makeForm("ppf", "Bender");
	scfIntern = someRandomIntern.makeForm("scf", "Bender");
	if (rrfIntern)
	{
		jim.signForm(*rrfIntern);
		jim.executeForm(*rrfIntern);
		delete rrfIntern;
	}
	if (ppfIntern)
	{
		jim.signForm(*ppfIntern);
		jim.executeForm(*ppfIntern);
		delete ppfIntern;
	}
	if (scfIntern)
	{
		jim.signForm(*scfIntern);
		jim.executeForm(*scfIntern);
		delete scfIntern;
	}

	//std::cout << std::endl << "Garice, grade 150-----------------------------------" << std::endl << std::endl;
	//garice.signForm(scf);
	//garice.executeForm(scf);
	//garice.signForm(ppf);
	//garice.executeForm(ppf);
	//garice.signForm(rrf);
	//garice.executeForm(rrf);

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