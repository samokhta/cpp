#include "PhoneBook.hpp"

BookObject::BookObject(void)
{
	this->_nbContacts = 0;
	return ;
}

void	BookObject::printContact(int index)
{
	int									i;
	std::list<ContactObject>::iterator	itr;
	ContactObject						Contact;

	i = 0;
	itr = this->_Contact.begin();
	while (i + 1 < index)
	{
		i++;
		itr++;
	}
	Contact = *itr;
	std::cout << std::endl << "First name: " << Contact.FirstName << std::endl;
	std::cout << "Last name: " << Contact.LastName << std::endl;
	std::cout << "Nickname: " << Contact.Nickname << std::endl;
	std::cout << "Darkest Secret: " << Contact.Secret << std::endl;
	std::cout << "Phone Number: " << Contact.PhoneNumber << std::endl << std::endl;
}

void	BookObject::printLine(ContactObject Contact, int i)
{
	if (Contact.FirstName.length() > 10)
	{
		Contact.FirstName.resize(9);
		Contact.FirstName.push_back('.');
	}
	if (Contact.LastName.length() > 10)
	{
		Contact.LastName.resize(9);
		Contact.LastName.push_back('.');
	}
	if (Contact.Nickname.length() > 10)
	{
		Contact.Nickname.resize(9);
		Contact.Nickname.push_back('.');
	}
	std::cout << std::setw(10) << i << '|';
	std::cout << std::setw(10) << Contact.FirstName << '|';
	std::cout << std::setw(10) << Contact.LastName << '|';
	std::cout << std::setw(10) << Contact.Nickname << std::endl;
}

void	BookObject::searchPrompt(void)
{
    int i;

   	while (1)
	{
		std::cout << "Enter index of desired contact: ";
		if (!(std::cin >> i))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input" << std::endl;
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (i < 1 || i > this->_nbContacts)
			std::cout << "Index out of range" << std::endl;
		else
			break;
	}
	printContact(i); 
}
