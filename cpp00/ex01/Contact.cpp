#include "Contact.hpp"

Contact::Contact()
{
    this->_firstName = "";
    this->_lastName = "";
    this->_nickname = "";
    this->_secret = "";
}

Contact::Contact(Contact &other)
{
    this->_firstName = other._firstName;
    this->_lastName = other._lastName;
    this->_nickname = other._nickname;
    this->_secret = other._secret;
    this->_phoneNumber = other._phoneNumber;
}

std::string	Contact::getFirstName() { return this->_firstName; }
std::string	Contact::getLastName() { return this->_lastName; }
std::string	Contact::getNickname() { return this->_nickname; }
std::string	Contact::getSecret() { return this->_secret; }
std::string	Contact::getPhoneNumber() { return this->_phoneNumber; }

void	Contact::setFirstName(std::string input) { this->_firstName = input; } 
void	Contact::setLastName(std::string input) { this->_lastName = input; }
void	Contact::setNickname(std::string input) { this->_nickname = input; }
void	Contact::setSecret(std::string input) { this->_secret = input; }
void	Contact::setPhoneNumber(std::string input) { this->_phoneNumber = input; }
