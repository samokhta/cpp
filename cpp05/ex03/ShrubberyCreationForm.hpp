#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# define TREE "       ,.,\n      MMMM_    ,..,\n        \"_ \"__\"MMMMM          ,...,,\n ,..., __.\" --\"    ,.,     _-\"MMMMMMM\nMMMMMM\"___ \"_._   MMM\"_.\"\" _ \"\"\"\"\"\"\n \"\"\"\"\"    \"\" , \\_.   \"_. .\"\n        ,., _\"__ \\__./ .\"\n       MMMMM_\"  \"_    ./\n        ''''      (    )\n ._______________.-'____\"---._.\n  \\                          /\n   \\________________________/\n   (_)                    (_)"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		std::string		getTarget() const;
		virtual void	execute(Bureaucrat const & executor) const;
	private:
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);
		ShrubberyCreationForm();
		std::string	_target;

};

#endif