/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinda-si <vinda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:23:31 by vinda-si          #+#    #+#             */
/*   Updated: 2025/12/20 20:23:32 by vinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

int main()
{
	PhoneBook	pb;
	std::string	command;

	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	std::cout << "Available command: ADD, SEARCH, EXIT" << std::endl;

	while (true)
	{
		std::cout << "> ";
		
		if (!std::getline(std::cin, command))
			break;

		if (command == "ADD")
			pb.addContact();
		else if (command == "SEARCH")
			pb.searchContact();
		else if (command == "EXIT")
			break;
		else
			if (!command.empty())
				std::cout << "Unknown command." << std::endl;
	}
	return (0);
}
