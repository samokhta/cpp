#include "Bureaucrat.hpp"
#include "Form.hpp"

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
		std::cout << e.what() << std::endl;
		_grade = 1;
	}
	catch(const GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
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

void	Bureaucrat::signForm(Form& f)
{
	if (f.getSigned())
	{
		std::cout 
		<< "Bureaucrat " 
		<< _name 
		<< " couldn't sign form " 
		<< f.getName() 
		<< " because it's already signed" 
		<< std::endl;
		return ;
	}
	try
	{
		f.beSigned(*this);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if (f.getSigned() == true)
	{
		std::cout 
		<< "Bureaucrat " 
		<< _name 
		<< " signed form " 
		<< f.getName()
		<< std::endl;
	}
	else
	{
		std::cout 
		<< "Bureaucrat " 
		<< _name 
		<< " couldn't sign form " 
		<< f.getName() 
		<< " because its grade was too low" 
		<< std::endl;
	}
}

std::ostream &operator<<(std::ostream& stream, const Bureaucrat& rhs)
{
	return (stream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade());
}