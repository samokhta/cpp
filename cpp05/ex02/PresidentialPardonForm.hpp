#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		std::string		getTarget() const ;
		virtual void	execute(Bureaucrat const & executor) const;
	private:
		PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
		std::string	_target;
};

#endif