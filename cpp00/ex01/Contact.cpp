#include "Contact.hpp"

std::string	Contact::getFirstName() { return this->FirstName; }
std::string	Contact::getLastName() { return this->LastName; }
std::string	Contact::getNickname() { return this->Nickname; }
std::string	Contact::getSecret() { return this->Secret; }
std::string	Contact::getPhoneNumber() { return this->PhoneNumber; }

void	Contact::setFirstName(std::string input) { this->FirstName = input; } 
void	Contact::setLastName(std::string input) { this->LastName = input; }
void	Contact::setNickname(std::string input) { this->Nickname = input; }
void	Contact::setSecret(std::string input) { this->Secret = input; }
void	Contact::setPhoneNumber(std::string input) { this->PhoneNumber = input; }