#include "ContactObject.hpp"

std::string	ContactObject::getFirstName() { return this->FirstName; }
std::string	ContactObject::getLastName() { return this->LastName; }
std::string	ContactObject::getNickname() { return this->Nickname; }
std::string	ContactObject::getSecret() { return this->Secret; }
std::string	ContactObject::getPhoneNumber() { return this->PhoneNumber; }

void	ContactObject::setFirstName(std::string input) { this->FirstName = input; } 
void	ContactObject::setLastName(std::string input) { this->LastName = input; }
void	ContactObject::setNickname(std::string input) { this->Nickname = input; }
void	ContactObject::setSecret(std::string input) { this->Secret = input; }
void	ContactObject::setPhoneNumber(std::string input) { this->PhoneNumber = input; }