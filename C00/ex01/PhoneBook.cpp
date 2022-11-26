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
	if (instancy("Phone number (need to be in this form : 0612345678): ", &str, 1) == ERROR)
		return (ERROR);
	contact.setPhoneNumber(str);
	if (instancy("Darkest secret : ",&str, 0) == ERROR)
		return (ERROR);
	contact.setDarkestSecret(str);
	m_contact[m_index % 8] = contact;
	m_index++;
	if (m_fill < 8)
		m_fill++;
    std::cout << std::endl << std::endl << "              Contact add in your phonebook" << std::endl;
    sleep(2);
	return (OK);
}

void    PhoneBook::searchContact(void)
{
    for (int i = 0; i < m_fill; i++)
    {
        std::cout << "- ---------- - ---------- - ---------- - ---------- -" << std::endl ;
        std::cout << 
        std::cout << "- ---------- - ---------- - ---------- - ---------- -" << std::endl ;
    }
}

PhoneBook::~PhoneBook(void){}