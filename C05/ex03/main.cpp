#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define BLUE		"\033[1;34m"
#define RESET		"\033[0m"

int	main(void)
{
	Bureaucrat	kevin("kevin", 150);
	Bureaucrat	jean("jean", 50);
	Bureaucrat	isildur("isildur", 1);
	Intern		slave;

	std::cout << BLUE << "make form test, test" << RESET << std::endl;
	{
		AForm		*form0 = slave.makeForm("test", "test");

		if (form0 != NULL)
		{
			std::cout << "new form:\t" << *form0 << std::endl;
			kevin.executeForm(*form0);
			kevin.signForm(*form0);
			jean.signForm(*form0);
			isildur.signForm(*form0);
			kevin.executeForm(*form0);
			jean.executeForm(*form0);
			isildur.executeForm(*form0);
			delete form0;
		}
	}
	std::cout << BLUE << "make form shrubbery creation, home" << RESET
		<< std::endl;
	{
		AForm		*form1 = slave.makeForm("ShrubberyCreationForm request", "home");

		if (form1 != NULL)
		{
			std::cout << "new form:\t" << *form1 << std::endl;
			kevin.executeForm(*form1);
			kevin.signForm(*form1);
			jean.signForm(*form1);
			isildur.signForm(*form1);
			kevin.executeForm(*form1);
			jean.executeForm(*form1);
			isildur.executeForm(*form1);
			delete form1;
		}
	}
	std::cout << BLUE << "make form robotomy request, akefeder" << RESET
		<< std::endl;
	{
		AForm		*form2 = slave.makeForm("RobotomyRequestForm request", "akefeder");

		if (form2 != NULL)
		{
			std::cout << "new form:\t" << *form2 << std::endl;
			kevin.executeForm(*form2);
			kevin.signForm(*form2);
			jean.signForm(*form2);
			isildur.signForm(*form2);
			kevin.executeForm(*form2);
			jean.executeForm(*form2);
			isildur.executeForm(*form2);
			delete form2;
		}
	}
	std::cout << BLUE << "make form presidential pardon, David" << RESET
		<< std::endl;
	{
		AForm		*form3 = slave.makeForm("PresidentialPardonForm request", "David");

		if (form3 != NULL)
		{
			std::cout << "new form:\t" << *form3 << std::endl;
			kevin.executeForm(*form3);
			kevin.signForm(*form3);
			jean.signForm(*form3);
			isildur.signForm(*form3);
			kevin.executeForm(*form3);
			jean.executeForm(*form3);
			isildur.executeForm(*form3);
			delete form3;
		}
	}
	return (0);
}