#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include "easyfind.hpp"

#define BLUE		"\033[1;34m"
#define RESET		"\033[0m"

int	main(void)
{
    std::cout << BLUE << "----------------vector<int>----------------" << RESET << std::endl;
	{
		std::vector<int>	array;

		array.push_back(21);
		array.push_back(42);
		try
		{
			std::cout
				<< "size: " << array.size() << std::endl
				<< "easyfind 21: " << *easyfind(array, 21) << std::endl
				<< "easyfind 42: " << *easyfind(array, 42) << std::endl
				<< "easyfind 0: " << *easyfind(array, 0) << std::endl
				<< "easyfind 404: " << *easyfind(array, 404) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
    std::cout << BLUE << "----------------deque<int>----------------" << RESET << std::endl;
	{
		std::deque<int>	array;

		array.push_back(21);
		array.push_back(42);
		try
		{
			std::cout
				<< "size: " << array.size() << std::endl
				<< "easyfind 21: " << *easyfind(array, 21) << std::endl
				<< "easyfind 42: " << *easyfind(array, 42) << std::endl
				<< "easyfind 0: " << *easyfind(array, 0) << std::endl
				<< "easyfind 404: " << *easyfind(array, 404) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
    std::cout << BLUE << "----------------list<int>----------------" << RESET << std::endl;
	{
		std::list<int>	array;

		array.push_back(21);
		array.push_back(42);
		try
		{
			std::cout
				<< "size: " << array.size() << std::endl
				<< "easyfind 21: " << *easyfind(array, 21) << std::endl
				<< "easyfind 42: " << *easyfind(array, 42) << std::endl
				<< "easyfind 0: " << *easyfind(array, 0) << std::endl
				<< "easyfind 404: " << *easyfind(array, 404) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}