#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	jim("jim", 50);
	Form		high("high", -1, -1);
	Form		low("low", 151, 151);

	std::cout << std::endl << high << std::endl << std::endl;
	std::cout << low << std::endl << std::endl;

	jim.signForm(high);
	jim.signForm(low);

	return 0;
}