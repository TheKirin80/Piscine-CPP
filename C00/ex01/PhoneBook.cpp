#include "PhoneBook.hpp"

Contact PhoneBook::getContact(int index)
{
    return this->m_contact[index];
}

int PhoneBook::getIndex(void)
{
    return this->m_index;
}

void PhoneBook::setContact(int index, Contact contact)
{
    this->m_contact[index] = contact;
}

void PhoneBook::setIndex(int index)
{
    this->m_index = index;
}

