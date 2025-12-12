#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	jim("jim", 50);
	Form		high("high", -1, -1);
	Form		low("low", 151, 151);

	jim.signForm(high);
	jim.signForm(low);

	return 0;
}