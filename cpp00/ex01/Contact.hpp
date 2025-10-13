#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>

class	Contact
{
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	Nickname;
		std::string	Secret;
		std::string	PhoneNumber;
	public:
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getSecret();
		std::string	getPhoneNumber();

		void	setFirstName(std::string input);
		void	setLastName(std::string input);
		void	setNickname(std::string input);
		void	setSecret(std::string input);
		void	setPhoneNumber(std::string input);
};

#endif