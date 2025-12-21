/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:23:47 by vinda-si          #+#    #+#             */
/*   Updated: 2025/12/20 20:23:48 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	std::cout << "Adding new contact to index " << this->_index << "..." << std::endl;

	do
	{
		std::cout << "Enter First Name: ";
		if (!std::getline(std::cin, input))
			return;
		if (input.empty())
			std::cout << "Field cannot be empty! Please try again." << std::endl;
	}
	while (input.empty());
	contact.setFirstName(input);
	
	do
	{
		std::cout << "Enter Last Name: ";
		if (!std::getline(std::cin, input))
			return;
		if (input.empty())
			std::cout << "Field cannot be empty! Please try again." << std::endl;
	}
	while (input.empty());
	contact.setLastName(input);

	do
	{
		std::cout << "Enter Nickname: ";
		if (!std::getline(std::cin, input))
			return;
		if (input.empty())
			std::cout << "Field cannot be empty! Please try again." << std::endl;
	}
	while (input.empty());
	contact.setNickName(input);

	do
	{
		std::cout << "Enter Phone Number: ";
		if (!std::getline(std::cin, input))
			return;
		if (input.empty())
			std::cout << "Field cannot be empty! Please try again." << std::endl;
	}
	while (input.empty());
	contact.setPhoneNumber(input);

	do
	{
		std::cout << "Enter Darkest Secret: ";
		if (!std::getline(std::cin, input))
			return;
		if (input.empty())
			std::cout << "Field cannot be empty! Please try again." << std::endl;
	}
	while (input.empty());
	contact.setDarkestSecret(input);

	std::cout << "Contact saved at index " << this->_index << "!" << std::endl;
	
	this->_index++;
	if (this->_savedCount < 8)
		this->_savedCount++;
}

std::string PhoneBook::_truncate(std::string str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	PhoneBook::searchContact()
{
	if (this->_savedCount == 0)
	{
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < this->_savedCount; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(10) << _truncate(_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << _truncate(_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << _truncate(_contacts[i].getNickName()) << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;

	int	index = -1;
	std::cout << "Enter index to view details: ";

	if (!(std::cin >> index) || index < 0 || index >= this->_savedCount)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index!" << std::endl;
	}
	else
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
		std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
		std::cout << "Nickame: " << _contacts[index].getNickName() << std::endl;
		std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
	}
}
