#include "ShrubberyCreationForm.hpp"

//constructors/destructor-------------------------------------------------

ShrubberyCreationForm::ShrubberyCreationForm() :
AForm("SCF", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm("SCF", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
AForm("SCF", 145, 137), _target(other._target) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void)other;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

//member functions-------------------------------------------------

std::string	ShrubberyCreationForm::getTarget() const { return (_target); }

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > 137)
			throw AForm::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << "ShrubberyCreationForm: Couldnt sign form: " << e.what() << '\n';
		return ;
	}
	std::ofstream	file(_target.c_str());
	file << TREE;
	file.close();
	//std::cout << "Bureaucrat " << executor.getName() << " successfully executed " << this->getName() << std::endl;
}