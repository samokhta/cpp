#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <sstream>

class	Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_secret;
		std::string	_phoneNumber;
	public:
		Contact();
		Contact &operator=(Contact &other);
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