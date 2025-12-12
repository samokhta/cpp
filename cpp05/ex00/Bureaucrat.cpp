#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    //std::cout << "Bureaucrat: Default constructor called" << std::endl;
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

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
    //std::cout << "Bureaucrat: Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    //std::cout << "Bureaucrat: Assignment operator called" << std::endl;
	//_name = other._name; pas possible puisque _name est const
	_grade = other._grade;
    return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat(void)
{
   // std::cout << "Bureaucrat: Destructor called" << std::endl;
    return ;
}

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

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
std::ostream &operator<<(std::ostream& stream, const Bureaucrat& rhs)
{
	return (stream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade());
}