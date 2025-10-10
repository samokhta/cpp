#include "BookObject.hpp"
#include "ContactObject.hpp"

int main()
{
    std::string	command;
	BookObject	PhoneBook;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (!std::cin)
			break;
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
