#include "header.hpp"

PhoneBook::PhoneBook(void): m_fill(0), m_index(0) {}

Contact PhoneBook::getContact(int index)
{
	return this->m_contact[index];
}

int	PhoneBook::getIndex(void)
{
	return this->m_index;
}

void	PhoneBook::setContact(int index, Contact contact)
{
	this->m_contact[index] = contact;
}

void	PhoneBook::setIndex(int index)
{
	this->m_index = index;
}

int	PhoneBook::addContact(void)
{
	std::string str;
	Contact contact;

	if (instancy("First name : ", &str, 0) == ERROR)
		return (ERROR);
	contact.setFirstName(str);
	if (instancy("Last name : ", &str, 0) == ERROR)
		return (ERROR);
	contact.setLastName(str);
	if (instancy("Nickname : ", &str, 0) == ERROR)
		return (ERROR);
	contact.setNickName(str);
	if (instancy("Phone number (need to be in this form : 0612345678): ", &str, 1) == ERROR)
		return (ERROR);
	contact.setPhoneNumber(str);
	if (instancy("Darkest secret : ",&str, 0) == ERROR)
		return (ERROR);
	contact.setDarkestSecret(str);
	//std::cout << contact.getFirstName() << "|  |" << contact.getLastName() << "|  |" << contact.getPhoneNumber() << "|  |" << contact.getDarkestSecret() << std::endl;
	m_contact[m_index % 8] = contact;
	m_index++;
	if (m_fill < 8)
		m_fill++;
    std::cout << std::endl << std::endl << "              Contact add in your phonebook" << std::endl;
    sleep(1);
	return (OK);
}

int    PhoneBook::searchContact(void)
{
	std::string str;
	int valid = 0;

	std::cout << "\033[2J\033[1;1H";
	if (m_fill == 0)
	{
		std::cout << std::endl << std::endl << std::endl << std::endl << "       You don't have for the moment. Please register some before retry SEARCH!" << std::endl;
		sleep(3);
		return (OK);
	}
	std::cout << "- --- - ---------- - ---------- - ---------- - ---------- - ---------- -" << std::endl ;
    for (int i = 0; i < m_fill; i++)
    {
		//std::cout << "je suis la" << i << std::endl;
        std::cout << "| " << " " << i << " " << " | " << affichage(m_contact[i].getFirstName()) << " | " << affichage(m_contact[i].getLastName()) << " | " << affichage(m_contact[i].getNickName()) << " | " << affichage(m_contact[i].getPhoneNumber()) << " | " << affichage(m_contact[i].getDarkestSecret()) << " |" << std::endl;
    }
	std::cout << "- --- - ---------- - ---------- - ---------- - ---------- - ---------- -" << std::endl ;
	while (valid == 0)
	{
		std::cout << std::endl << std::endl << "What contact do you want ? (index 0-7)(8 to quit)" << std::endl;
		if (secure_getline(&str) == ERROR)
				return (ERROR);
		if (str.length() == 1 && isnum(&str) == OK && ((int)str[0] < m_fill + '0' || (int)str[0] == 8 + '0'))
		{
			if ((int)str[0] == 8 + '0')
				return (OK);
			std::cout << "\033[2J\033[1;1H";
			std::cout << "First name     : " << m_contact[(int)str[0] - '0'].getFirstName() << std::endl;
			std::cout << "Last name      : " << m_contact[(int)str[0] - '0'].getLastName() << std::endl;
			std::cout << "Nickname       : " << m_contact[(int)str[0] - '0'].getNickName() << std::endl;
			std::cout << "Phone number   : " << m_contact[(int)str[0] - '0'].getPhoneNumber() << std::endl;
			std::cout << "Darkest secret : " << m_contact[(int)str[0] - '0'].getDarkestSecret() << std::endl;
			valid = 1;
			sleep(5);
		}
	}
	return (OK);
}

PhoneBook::~PhoneBook(void){}