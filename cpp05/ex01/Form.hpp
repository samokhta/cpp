#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form& other);
		Form &operator=(const Form& other);
		~Form();
		
		std::string	getName();
		bool		getSigned();
		int			getSignGrade();
		int			getExecGrade();
		void		beSigned(Bureaucrat& b);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form: Grade too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form: Grade too low");
				}
		};

	private:
		const std::string	_name;	
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

		int					checkGrade(int grade);
};

std::ostream	&operator<<(std::ostream& stream, Form& rhs);

#endif