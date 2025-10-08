# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <list>
#include <limits>

class	ContactObject
{
	public:
		std::string	FirstName;
		std::string	LastName;
		std::string	Nickname;
		std::string	Secret;
		std::string	PhoneNumber;
};

class BookObject
{
	public:
		BookObject(void);
		void	addCommand(void);
		void	searchCommand(void);
		
		private:
		int							_nbContacts;
		std::list<ContactObject>	_Contact;

		void	printLine(ContactObject Contact, int i);
		void	printContact(int index);
		void	searchPrompt(void);
		
};

# endif