#include "phonebook.hpp"
#include <limits>

PhoneBook::PhoneBook()
{
	this->_index = 0;
	this->_savedCount = 0;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact()
{
	std::string	input;

	if (this->_index > 7)
		this->_index = 0;

	Contact	&contact = this->_contacts[this->_index];

	std::cout << "Enter First Name: ";
	std::getline(std::cin, input);

}
