#include "Form.hpp"
#include "Bureaucrat.hpp"


//constructors/destructor-------------------------------------------------

Form::Form() : _name(NULL), _signed(false), _signGrade(-1), _execGrade(-1) {}

Form::Form(std::string name, int signGrade, int execGrade) : 
_name(name), _signed(false),
_signGrade(checkGrade(signGrade)), _execGrade(checkGrade(execGrade)) {}

Form::Form(const Form& other) :
_name(other._name), _signed(other._signed),
_signGrade(other._signGrade), _execGrade(other._execGrade) {}

Form &Form::operator=(const Form& other)
{
	/*everything except _signed is const
	and copying _signed by itself makes no sense*/
	(void)other;
	return (*this);
}

Form::~Form() {}

int	Form::checkGrade(int grade)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
		
	}
	catch (const GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	catch (const GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
		return (150);
	}
	return (grade);
}

//member functions-------------------------------------------------

std::string	Form::getName()			{ return (_name); }
bool		Form::getSigned()		{ return (_signed); }
int			Form::getSignGrade()	{ return (_signGrade); }
int			Form::getExecGrade()	{ return (_execGrade); }

void		Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= _signGrade)
		_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream& stream, Form& rhs)
{
	stream << "Name: " << rhs.getName() << std::endl;
	stream << "Signed: " << rhs.getSigned() << std::endl;
	stream << "Sign Grade: " << rhs.getSignGrade() << std::endl;
	stream << "Execution Grade: " << rhs.getExecGrade();
	return (stream);
}
