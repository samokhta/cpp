#include "PhoneBook.hpp"

void	BookObject::addCommand()
{
	ContactObject	newContact;

	std::cout << "Enter first name: ";
	std::getline(std::cin, newContact.FirstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, newContact.LastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, newContact.Nickname);
	std::cout << "Enter your darkest secret....: ";
	std::getline(std::cin, newContact.Secret);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, newContact.PhoneNumber);

	this->_Contact.push_front(newContact);
	if (this->_nbContacts < 8)
		this->_nbContacts++;
	else
		this->_Contact.pop_back();
}

void	BookObject::searchCommand(void)
{
	std::list<ContactObject>			contactList;
	std::list<ContactObject>::iterator	itr;
	int									i;

	if (this->_nbContacts == 0)
	{
		std::cout << "No contacts found !" << std::endl;
		return ;
	}
	contactList = this->_Contact;
	itr = contactList.begin();
	i = 1;
	std::cout << std::endl << "     index|First name| Last name|  Nickname" << std::endl;
	std::cout << "__________|__________|__________|__________" << std::endl;
	while (itr != contactList.end())
	{
		printLine(*itr, i);
		itr++;
		i++;
	}
	std::cout << "__________|__________|__________|__________|" << std::endl << std::endl;
	searchPrompt();
	return ;
}

int main()
{
    std::string	command;
	BookObject	PhoneBook;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break ;
		if (command == "ADD")
			PhoneBook.addCommand();
		if (command == "SEARCH")
			PhoneBook.searchCommand();
	}
	std::cout << "Exiting..." << std::endl;
	return (0);
}
