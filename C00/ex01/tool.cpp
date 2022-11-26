#include "header.hpp"

int wspace(std::string *str)
{
	int len = str->length();
	//std::cout << len << *str;
	for(int i = 0; i < len; i++)
	{
		char c = (*str)[i];
		if (isspace(c) == 0)
		{
			//std::cout << "wspace" << std::endl;
			return (FOUND);
		}
	}
	//std::cout << "wspace get" << std::endl;
	return (N_FOUND);
}

int	isnum(std::string *str)
{
	int len = str->length();
	for (int i  = 0 ; i < len ; i++)
	{
		if (isdigit((*str)[i]) == 0)
		{
			std::cout << "ici";
			return (ERROR); 
		}	
	}
	return (OK);
}

int secure_getline(std::string *str)
{
	std::getline(std::cin, *str);
	//std::cout << *str;
	if(std::cin.eof() == ERROR)
	{
			//std::cout << "secure err get" << std::endl;
			return (ERROR);
	}
	else
	{
			//std::cout << "secure ok get" << std::endl;
			return (OK);
	}
}

int instancy(std::string post, std::string *str, int phone)
{
	int     pass;

	pass = 0;
	while (pass == 0)
	{
		std::cout << post;
		if (secure_getline(str) == ERROR)
		{
			//std::cout << "instancy get" << std::endl;
			return (ERROR);
		}
		//std::cout << str;
		if (wspace(str) == FOUND)
		{
			//std::cout << "instancy wsp" << std::endl;
			int len = str->length();
			if ((phone == 1 && len == 10 && isnum(str) == OK) || (phone == 0))
				pass = 1;
			else
				pass = 0;
		}
	}
	return (OK);
}