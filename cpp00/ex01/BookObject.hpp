# ifndef BOOKOBJECT_HPP
# define BOOKOBJECT_HPP

#include "ContactObject.hpp"

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