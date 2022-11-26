#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "header.hpp"

class PhoneBook
{
	public :

		PhoneBook();
		~PhoneBook();
		Contact getContact(int index);
		int		getIndex(void);
		void	setContact(int index, Contact contact);
		void	setIndex(int index);
		int		addContact(void);
		//void    searchContact();

	private :
		
		Contact m_contact[8];
		int		m_fill;
		int		m_index;
};

#endif