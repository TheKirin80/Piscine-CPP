#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "header.hpp"

class Contact
{
	public :
	
		//Contact();
		//Contact(std::string first_name, std::string last_name, std::string phone_number[10], std::string darkest_secret);
		//~Contact();
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);
		void setFirstName(std::string str);
		void setLastName(std::string str);
		void setPhoneNumber(std::string str);
		void setDarkestSecret(std::string str);
	
	private :

		std::string	m_first_name;
		std::string	m_last_name;
		std::string	m_phone_number;
		std::string	m_darkest_secret;
};

#endif