#include "header.hpp"

std::string Contact::getFirstName(void)
{
    return this->m_first_name;
}

std::string Contact::getLastName(void)
{
    return this->m_last_name;
}

std::string Contact::getNickName(void)
{
    return this->m_nickname;
}

std::string Contact::getPhoneNumber(void)
{
    return this->m_phone_number;
}

std::string Contact::getDarkestSecret(void)
{
    return this->m_darkest_secret;
}

void Contact::setFirstName(std::string str)
{
    this->m_first_name = str;
}

void Contact::setLastName(std::string str)
{
    this->m_last_name = str;
}

void Contact::setNickName(std::string str)
{
    this->m_nickname = str;
}

void Contact::setPhoneNumber(std::string str)
{
    this->m_phone_number = str;
}

void Contact::setDarkestSecret(std::string str)
{
    this->m_darkest_secret = str;
}