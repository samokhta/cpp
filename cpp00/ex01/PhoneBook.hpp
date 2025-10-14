# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		void	addCommand(void);
		void	searchCommand(void);
		void	fillCommand(void);
		
	private:
		int							_nbContacts;
		Contact						_bookArray[8];

		void		printLine(Contact toPrint, int i);
		void		printContact(int index);
		void		searchPrompt(void);
		std::string	addPrompt(std::string prompt);
		void		popBack(void);
		
};

# endif