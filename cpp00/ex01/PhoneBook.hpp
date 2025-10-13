# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		void	addCommand(void);
		void	searchCommand(void);
		
	private:
		int							_nbContacts;
		Contact						_bookArray[8];

		void	printLine(Contact toPrint, int i);
		void	printContact(int index);
		void	searchPrompt(void);
		void	popBack(void);
		
};

# endif