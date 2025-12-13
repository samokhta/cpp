#include "PresidentialPardonForm.hpp"

//constructors/destructor-------------------------------------------------

PresidentialPardonForm::PresidentialPardonForm() : AForm("PPF", 25, 5), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm("PPF", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
AForm("PPF", 25, 5), _target(other._target) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	(void)other;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

//member functions-------------------------------------------------

std::string	PresidentialPardonForm::getTarget() const { return (_target); }

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > 5)
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << "PresidentialPardonForm: Couldnt sign form: " << e.what() << '\n';
		return ;
	}
	
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}