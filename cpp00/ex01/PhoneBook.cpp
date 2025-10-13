#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_nbContacts = 0;
	return ;
}

void	PhoneBook::printContact(int index)
{
	int									i;
	std::list<Contact>::iterator	itr;
	Contact						Contact;

	i = 0;
	itr = this->_Contact.begin();
	while (i + 1 < index)
	{
		i++;
		itr++;
	}
	Contact = *itr;
	std::cout << std::endl << "First name: " << Contact.getFirstName() << std::endl;
	std::cout << "Last name: " << Contact.getLastName() << std::endl;
	std::cout << "Nickname: " << Contact.getNickname() << std::endl;
	std::cout << "Darkest Secret: " << Contact.getSecret() << std::endl;
	std::cout << "Phone Number: " << Contact.getPhoneNumber() << std::endl << std::endl;
}

void	PhoneBook::printLine(Contact Contact, int i)
{
	if (Contact.getFirstName().length() > 10)
	{
		Contact.getFirstName().resize(9);
		Contact.getFirstName().push_back('.');
	}
	if (Contact.getLastName().length() > 10)
	{
		Contact.getLastName().resize(9);
		Contact.getLastName().push_back('.');
	}
	if (Contact.getNickname().length() > 10)
	{
		Contact.getNickname().resize(9);
		Contact.getNickname().push_back('.');
	}
	std::cout << std::setw(10) << i << '|';
	std::cout << std::setw(10) << Contact.getFirstName() << '|';
	std::cout << std::setw(10) << Contact.getLastName() << '|';
	std::cout << std::setw(10) << Contact.getNickname() << std::endl;
}

void	PhoneBook::searchPrompt(void)
{
	int i;
	std::string	input;

	while (1)
	{
		std::cout << "Enter index of desired contact: ";
		if (!std::getline(std::cin, input))
			return ;
		if (input.empty())
			continue;
		std::stringstream stream(input);
		stream >> i;
		//std::cout << i << " " << input << std::endl;
		if (i < 1 || i > this->_nbContacts)
			std::cout << "Invalid input" << std::endl;
		else
			break;
	}
	printContact(i); 
}

void	PhoneBook::addCommand()
{
	Contact	newContact;
    std::string		input;

    while (1)
    {
        std::cout << "Enter first name: ";
        std::getline(std::cin, input);
        if (!input.empty() || !std::cin)
        {
            newContact.setFirstName(input);
            break ;
        }
        else
            continue ;
    }
    while (1)
    {
        std::cout << "Enter last name: ";
        std::getline(std::cin, input);
        if (!input.empty() || !std::cin)
        {
            newContact.setLastName(input);
            break ;
        }
        else
            continue ;
    }

    while (1)
    {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, input);
        if (!input.empty() || !std::cin)
        {
            newContact.setNickname(input);
            break ;
        }
        else
            continue ;
    }

    while (1)
    {
        std::cout << "Enter your darkest secret....: ";
        std::getline(std::cin, input);
        if (!input.empty() || !std::cin)
        {
            newContact.setSecret(input);
            break ;
        }
        else
            continue ;
    }

    while (1)
    {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, input);
        if (!input.empty() || !std::cin)
        {
            newContact.setPhoneNumber(input);
            break ;
        }
        else
            continue ;
    }

	this->_Contact.push_front(newContact);
	if (this->_nbContacts < 8)
		this->_nbContacts++;
	else
		this->_Contact.pop_back();
}

void	PhoneBook::searchCommand(void)
{
	std::list<Contact>			contactList;
	std::list<Contact>::iterator	itr;
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