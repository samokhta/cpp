#include "PhoneBook.hpp"

int main()
{
    std::string	command;
	PhoneBook	book;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (!std::cin)
			break;
		if (command == "EXIT")
			break ;
		if (command == "ADD")
			book.addCommand();
		if (command == "SEARCH")
			book.searchCommand();
	}
	std::cout << "Exiting..." << std::endl;
	return (0);
}
