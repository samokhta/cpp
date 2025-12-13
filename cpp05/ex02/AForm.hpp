#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>
# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm& other);
		virtual ~AForm();
		
		std::string		getName() const;
		bool			getSigned() const;
		int				getSignGrade() const;
		int				getExecGrade() const;
		void			beSigned(Bureaucrat& b);
		virtual void	execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade too low");
				}
		};

		class AlreadySignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Already signed");
				}
		};

	private:
		const std::string	_name;	
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

		AForm();
		AForm	&operator=(const AForm& other);
		int					checkGrade(int grade);
};

std::ostream	&operator<<(std::ostream& stream, AForm& rhs);

#endif
