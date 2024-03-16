#include "Bureaucrat.hpp"
#include "Form.hpp"

# define BLACK		"\033[1;30m"
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define WHITE		"\033[1;37m"
# define RESET		"\033[0m" // remet la couleur par defaut

int	main(void)
{
	Bureaucrat	jean("jean", 50);

	std::cout << "new bureaucrat:\t\t" << jean << std::endl;
	std::cout
		<< MAGENTA
		<< "--------------------------------------------------form-lv-1-1------"
		<< RESET
		<< std::endl;
	try
	{
		Form		form("form_lv_1", 1, 1);

		std::cout << "new form:\t\t" << form << std::endl;
		jean.signForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "test interrupted because " << e.what() << std::endl;
	}
	std::cout
		<< MAGENTA
		<< "--------------------------------------------------form-lv-100-100--"
		<< RESET
		<< std::endl;
	try
	{
		Form		form("form_lv_100", 100, 100);

		std::cout << "new form:\t\t" << form << std::endl;
		jean.signForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "test interrupted because " << e.what() << std::endl;
	}
	std::cout
		<< MAGENTA
		<< "--------------------------------------------------form-lv-(-1)-(-1)"
		<< RESET
		<< std::endl;
	try
	{
		Form		form("form_lv_-1", -1, -1);

		std::cout << "new form:\t\t" << form << std::endl;
		jean.signForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "test interrupted because " << e.what() << std::endl;
	}
	std::cout
		<< MAGENTA
		<< "--------------------------------------------------form-lv-151-151--"
		<< RESET
		<< std::endl;
	try
	{
		Form		form("form_lv_151", 151, 151);

		std::cout << "new form:\t\t" << form << std::endl;
		jean.signForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "test interrupted because " << e.what() << std::endl;
	}
	return (0);
}