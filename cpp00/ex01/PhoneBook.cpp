#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_nbContacts = 0;
	return ;
}

void	PhoneBook::printContact(int i)
{
	std::cout << std::endl << "First name: " << _bookArray[i].getFirstName() << std::endl;
	std::cout << "Last name: " << _bookArray[i].getLastName() << std::endl;
	std::cout << "Nickname: " << _bookArray[i].getNickname() << std::endl;
	std::cout << "Darkest Secret: " << _bookArray[i].getSecret() << std::endl;
	std::cout << "Phone Number: " << _bookArray[i].getPhoneNumber() << std::endl << std::endl;
}

void	PhoneBook::printLine(Contact Contact, int i)
{
	std::string first = Contact.getFirstName();
	std::string last = Contact.getLastName();
	std::string nick = Contact.getNickname();
	if (first.length() > 10)
	{
		first.resize(9);
		first.push_back('.');
	}
	if (last.length() > 10)
	{
		last.resize(9);
		last.push_back('.');
	}
	if (nick.length() > 10)
	{
		nick.resize(9);
		nick.push_back('.');
	}
	std::cout << std::setw(10) << i << '|';
	std::cout << std::setw(10) << first << '|';
	std::cout << std::setw(10) << last << '|';
	std::cout << std::setw(10) << nick << '|' << std::endl;
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
		if (i < 1 || i > this->_nbContacts)
			std::cout << "Invalid input" << std::endl;
		else
			break;
	}
	printContact(i - 1); 
}

std::string	PhoneBook::addPrompt(std::string prompt)
{
	std::string	input;
	int			isNull = 1;
    while (1)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!input.empty() || !std::cin || isNull == 0)
            break ;
        else
            continue ;
    }
	return input;
}

void	PhoneBook::addCommand()
{
	Contact			newContact;

    newContact.setFirstName(addPrompt("Enter first name: "));
    newContact.setLastName(addPrompt("Enter last name: "));
	newContact.setNickname(addPrompt("Enter nickname: "));
    newContact.setSecret(addPrompt("Enter your darkest secret....: "));
    newContact.setPhoneNumber(addPrompt("Enter phone number: "));
	if (this->_nbContacts < 8)
	{
		this->_bookArray[_nbContacts] = newContact;
		this->_nbContacts++;
	}
	else
	{
		this->popBack();
		this->_bookArray[7] = newContact;
	}
}

void	PhoneBook::searchCommand(void)
{
	int	i;

	if (this->_nbContacts == 0)
	{
		std::cout << "No contacts found !" << std::endl;
		return ;
	}
	i = 0;
	std::cout << std::endl << "     index|First name| Last name|  Nickname" << std::endl;
	std::cout << "__________|__________|__________|__________" << std::endl;
	while (i <= 7)
	{
		printLine(_bookArray[i], i + 1);
		i++;
	}
	std::cout << "__________|__________|__________|__________|" << std::endl << std::endl;
	searchPrompt();
	return ;
}

void	PhoneBook::popBack(void)
{
	for (int i = 0; i < 7; i++)
		_bookArray[i] = _bookArray[i + 1];
}

void	PhoneBook::fillCommand(void)
{
	int i = 0;
	std::stringstream 	stream;
	std::string			iString;

	_nbContacts = 8;
	while (i <= 7)
	{
		stream.str("");
		stream << (i + 1);
		iString = stream.str();
		_bookArray[i].setFirstName("First" + iString);
		_bookArray[i].setLastName("Last" + iString);
		_bookArray[i].setNickname("Nick" + iString);
		_bookArray[i].setSecret("Secret" + iString);
		_bookArray[i].setPhoneNumber("Number" + iString);
		i++;
	}
	std::cout << "Successfully filled the phonebook" << std::endl;
}