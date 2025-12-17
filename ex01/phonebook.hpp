#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iomanip>

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_index;
		int		_savedCount;

		std::string	_truncate(std::string str) const;

	public:
		PhoneBook();
		~PhoneBook();

		void	addContact();
		void	searchContact();
};

#endif