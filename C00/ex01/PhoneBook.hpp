#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    public :

        // PhoneBook();
        // ~PhoneBook();
        Contact getContact(int index);
        int getIndex(void);
        void setContact(int index, Contact contact);
        void setIndex(int index);
        void addContact(void);
        void searchContact();

    private :
        
        Contact m_contact[8];
        int m_index;
};

#endif