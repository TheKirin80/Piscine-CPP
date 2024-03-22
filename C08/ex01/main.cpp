#include "Span.hpp"

#define BLUE		"\033[1;34m"
#define RED			"\033[1;31m"
#define RESET		"\033[0m"

int	main(void)
{
	srand(time(NULL));
    std::cout<< BLUE<< "\t\t\tSpan(1) 42"<< RESET << std::endl;
	{
        
		Span sp = Span(5);
        std::cout<< BLUE<< "\t\t\tTest sur 1 valeur dans la liste"<< RESET << std::endl;
		try
		{
			sp.addNumber(42);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
        try
		{
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
        try
		{

            std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
			
        
        sp.print();

	}
	std::cout<< BLUE<< "\t\t\tSpan(5) {5, 3, 17, 9, 11}"<< RESET << std::endl;
	{
        
		Span sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		try
		{
			sp.addNumber(42);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		std::cout
			<< "shortest span: " << sp.shortestSpan() << std::endl
			<< "longest span: " << sp.longestSpan() << std::endl;
        
        sp.print();

	}
    std::cout<< BLUE<< "\t\t\tSpan(n) avec une list de n random"<< RESET << std::endl;
    {
        int n = 10000;
        int nbr_imp = 10000;
        Span sp = Span(n);

        std::list<int> list;
        for (int i = 0; i < nbr_imp; i++)
        {
            int r = rand() % 30000;
            list.push_back(r);
        }
        try
        {
            sp.addrange(list.begin(), list.end());
        }
        catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
		std::cout
			<< "shortest span: " << sp.shortestSpan() << std::endl
			<< "longest span: " << sp.longestSpan() << std::endl;
        
        sp.print();
    }

    return (0);
}