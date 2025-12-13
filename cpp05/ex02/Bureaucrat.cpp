#include "Bureaucrat.hpp"
#include "AForm.hpp"

//constructors/destructor-------------------------------------------------

Bureaucrat::Bureaucrat() : _name(NULL), _grade(-1) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
		else
			_grade = grade;
	}
	catch(const GradeTooHighException& e)
	{
		std::cout << "Out of bounds" << e.what() << std::endl;
		_grade = 1;
	}
	catch(const GradeTooLowException& e)
	{
		std::cout << "Out of bounds" << e.what() << std::endl;
		_grade = 150;
	}
    return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
_name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	//_name = other._name; pas possible puisque _name est const
	if (this != &other)
		_grade = other._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

//member functions-------------------------------------------------

std::string Bureaucrat::getName()	const { return _name; }
int 		Bureaucrat::getGrade()	const { return _grade; }

void	Bureaucrat::gradeUp(int amount)
{
	try
	{
		if (_grade - amount < 1)
			throw GradeTooHighException();
		else
			_grade -= amount;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		_grade = 1;
	}
}

void	Bureaucrat::gradeDown(int amount)
{
	try
	{
		if (_grade + amount > 150)
			throw GradeTooLowException();
		else
			_grade += amount;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		_grade = 150;
	}
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		if (form.getSigned())
			throw AForm::AlreadySignedException();
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Bureaucrat " << _name << " couldn't sign form " << form.getName() <<": " << e.what() << std::endl;
		return ;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		if (_grade > form.getExecGrade())
			throw AForm::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Bureaucrat " << _name << " couldn't execute form " << form.getName() <<": " << e.what() << std::endl;
		return ;
	}
	form.execute(*this);
	std::cout << "Bureaucrat " << _name << " successfully executed " << form.getName() << std::endl;
}

//redirection overload------------------

std::ostream &operator<<(std::ostream& stream, const Bureaucrat& rhs)
{
	return (stream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade());
}