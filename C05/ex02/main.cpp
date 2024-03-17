#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define BLUE		"\033[1;34m"
#define RESET		"\033[0m"

int	main(void)
{
	Bureaucrat	kevin("kevin", 150);
	Bureaucrat	jean("jean", 50);
	Bureaucrat	isildur("isildur", 1);

	std::cout << BLUE << "ShrubberyCreationForm home" << RESET << std::endl;
	{
		AForm		*form1 = new ShrubberyCreationForm("home");

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
	std::cout << BLUE << "RobotomyRequestForm akefeder" << RESET << std::endl;
	{
		AForm		*form2 = new RobotomyRequestForm("akefeder");

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
	std::cout << BLUE << "PresidentialPardonForm David" << RESET << std::endl;
	{
		AForm		*form3 = new PresidentialPardonForm("David");

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
	return (0);
}