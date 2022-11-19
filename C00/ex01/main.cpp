#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

int main ()
{
    std::string  choice;
    std::string	first_name;
    std::string	last_name;
    std::string	phone_number;
    std::string	darkest_secret;
    PhoneBook myphonebook;
    int exit = 0;
    while (exit == 0)
    {
        std::cout << "----------------------------------------------------------" << std::endl;
        std::cout << "|                    Available COMMAND :                 |" << std::endl;
        std::cout << "|                                                        |" << std::endl;
        std::cout << "|    ADD    : To add a new Contact                       |" << std::endl;
        std::cout << "|    SEARCH : If you want find your friends              |" << std::endl;
        std::cout << "|    EXIT   : A door to left this incredible phonebook   |" << std::endl;
        std::cout << "|                                                        |" << std::endl;
        std::cout << "----------------------------------------------------------" << std::endl << std::endl << std::endl;

        std::getline(std::cin, choice);
        if (choice == "ADD")
            myphonebook.addContact();
        else if (choice == "SEARCH")
            myphonebook.searchContact();
        else if (choice == "EXIT")
            exit = 1;
    }  
    return (0);
}