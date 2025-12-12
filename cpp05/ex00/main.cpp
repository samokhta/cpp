#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	low("low", 151);
	Bureaucrat	high("high", 0);
	Bureaucrat	correct("correct", 75);
	Bureaucrat	copy(correct);

	std::cout << std::endl << low << std::endl;
	std::cout << high << std::endl;
	std::cout << correct << std::endl << std::endl;
	std::cout << copy << std::endl << std::endl;

	correct.gradeDown(76);
	std::cout << correct << std::endl;
	correct.gradeUp(151);
	std::cout << correct << std::endl;

	return 0;
}