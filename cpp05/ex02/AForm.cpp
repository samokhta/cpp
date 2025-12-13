#include "AForm.hpp"
#include "Bureaucrat.hpp"


//constructors/destructor-------------------------------------------------

AForm::AForm() : _name(NULL), _signed(false), _signGrade(-1), _execGrade(-1) {}

AForm::AForm(std::string name, int signGrade, int execGrade) : 
_name(name), _signed(false),
_signGrade(checkGrade(signGrade)), _execGrade(checkGrade(execGrade)) {}

AForm::AForm(const AForm& other) :
_name(other._name), _signed(other._signed),
_signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm &AForm::operator=(const AForm& other)
{
	/*everything except _signed is const
	and copying _signed by itself makes no sense*/
	(void)other;
	return (*this);
}

AForm::~AForm() {}

int	AForm::checkGrade(int grade)
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

std::string	AForm::getName() const		{ return (_name); }
bool		AForm::getSigned() const	{ return (_signed); }
int			AForm::getSignGrade() const	{ return (_signGrade); }
int			AForm::getExecGrade() const	{ return (_execGrade); }

void		AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() <= _signGrade)
	{
		_signed = true;
		std::cout << "Bureaucrat " << _name << " successfully signed form " << _name << std::endl;
	}
	else
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream& stream, AForm& rhs)
{
	stream << "Name: " << rhs.getName() << std::endl;
	stream << "Signed: " << rhs.getSigned() << std::endl;
	stream << "Sign Grade: " << rhs.getSignGrade() << std::endl;
	stream << "Execution Grade: " << rhs.getExecGrade();
	return (stream);
}
