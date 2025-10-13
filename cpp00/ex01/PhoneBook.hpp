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
		std::list<Contact>	_Contact;

		void	printLine(Contact Contact, int i);
		void	printContact(int index);
		void	searchPrompt(void);
		
};

# endif