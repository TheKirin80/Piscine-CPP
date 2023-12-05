#include "header.hpp"

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
		std::cout << "\033[2J\033[1;1H";
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "|                    Available COMMAND :                 |" << std::endl;
		std::cout << "|                                                        |" << std::endl;
		std::cout << "|    ADD    : To add a new Contact                       |" << std::endl;
		std::cout << "|    SEARCH : If you want find your friends              |" << std::endl;
		std::cout << "|    EXIT   : A door to left this incredible phonebook   |" << std::endl;
		std::cout << "|                                                        |" << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl << std::endl << std::endl;

		if (secure_getline(&choice) == ERROR)
			return (ERROR);
		if (choice == "ADD")
		{
			if (myphonebook.addContact() == ERROR)
				return (ERROR);
		}
		else if (choice == "SEARCH")
		{
			if (myphonebook.searchContact() == ERROR)
				return (ERROR);		
		}
		else if (choice == "EXIT")
			exit = 1;
	}  
	return (0);
}