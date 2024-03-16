#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	gerard("gerard", 42);
	std::cout << gerard << std::endl;
	try
	{
		gerard = Bureaucrat("gerard", 0);
		std::cout << gerard << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << gerard << std::endl;
	try
	{
		gerard = Bureaucrat("gerard", 151);
		std::cout << gerard << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << gerard << std::endl;
	try
	{
		gerard = Bureaucrat("gerard", 10);
		std::cout << "after construction:\t" << gerard << std::endl;
        gerard.increment();
		std::cout << "return of gerard increment:\t" << gerard << std::endl;
		gerard.decrement(); 
        std::cout << "return of gerard decrement:\t" << gerard << std::endl;

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << gerard << std::endl;
	try
	{
		gerard = Bureaucrat("gerard", 3);
	    std::cout << gerard << std::endl;
		gerard.increment();
        std::cout << gerard << std::endl;
        gerard.increment();
        std::cout << gerard << std::endl;
        gerard.increment();
        std::cout << gerard << std::endl;
    }
	catch (std::exception& e)
	{
		std::cout
			<< e.what()
			<< std::endl;
	}
	std::cout << gerard << std::endl;
	try
	{
		gerard = Bureaucrat("gerard", 148);
	    std::cout << gerard << std::endl;
		gerard.decrement();
        std::cout << gerard << std::endl;
        gerard.decrement();
        std::cout << gerard << std::endl;
        gerard.decrement();
        std::cout << gerard << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << gerard << std::endl;
	return (0);
}