#ifndef RoBOTOMYREQUESTFORM_HPP
# define RoBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		std::string		getTarget() const;
		virtual void	execute(Bureaucrat const & executor) const;
	private:
		RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm& other);
		std::string	_target;
};

#endif