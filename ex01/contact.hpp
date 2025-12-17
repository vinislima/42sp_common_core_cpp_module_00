#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		Contact();
		~Contact();

		void	setFirstName(std::string str);
		void	setLastName(std::string srt);
		void	setNickName(std::string str);
		void	setPhoneNumber(std::string str);
		void	setDarkestSecret(std::string str);

		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
};

#endif