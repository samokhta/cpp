#include "RobotomyRequestForm.hpp"

//constructors/destructor-------------------------------------------------

RobotomyRequestForm::RobotomyRequestForm() : AForm("RRF", 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm("RRF", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
AForm("RRF", 72, 45), _target(other._target) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	(void)other;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

//member functions-------------------------------------------------

std::string	RobotomyRequestForm::getTarget() const { return (_target); }

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > 45)
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << "RobotomyRequestForm: Couldnt sign form: " << e.what() << '\n';
		return ;
	}
	std::cout << "***BZZZZZZZZZ..... WHIZZZZZ....***" << std::endl;
	srand(time(0));
	if (rand() % 2)
		std::cout << _target << " was robotomized successfully." << std::endl;
	else
		std::cout << _target << " couldn't be robotomized." << std::endl;
}