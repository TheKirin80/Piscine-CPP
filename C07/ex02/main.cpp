#include "Array.hpp"

#define BLUE		"\033[1;34m"
#define RESET		"\033[0m"

class	A
{
	public:
		A() :
			_i(42)
		{
			return ;
		}
		A(int i) :
			_i(i)
		{
			return ;
		}
		int	getI(void) const
		{
			return (this->_i);
		}
	private:
		int	_i;
};

std::ostream	&operator<<(std::ostream &o, A const &i)
{
	o << i.getI();
	return (o);
}

int main(void)
{
	std::cout<< BLUE << "-------------------Array<int>-------------------" << RESET << std::endl;
	{
		Array<int>	array(2);

		array[1] = 21;
		try
		{
			std::cout
				<< "size: " << array.size() << std::endl
				<< "array[0]: "<< array[0] << std::endl
				<< "array[1]: " << array[1] << std::endl
				<< "array[2]: " << array[2] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
    std::cout<< BLUE << "-------------------const Array<int>-------------------" << RESET << std::endl;
	{
		const Array<int>	array(2);

		try
		{
			std::cout
				<< "size: " << array.size() << std::endl
				<< "array[0]: "<< array[0] << std::endl
				<< "array[1]: " << array[1] << std::endl
				<< "array[2]: " << array[2] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
    std::cout<< BLUE << "-------------------Array<int const>-------------------" << RESET << std::endl;
	{
		Array<int const>	array(2);

		try
		{
			std::cout
				<< "size: " << array.size() << std::endl
				<< "array[0]: "<< array[0] << std::endl
				<< "array[1]: " << array[1] << std::endl
				<< "array[2]: " << array[2] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
    std::cout<< BLUE << "-------------------const Array<int const>-------------------" << RESET << std::endl;
	{
		const Array<int const>	array(2);

		try
		{
			std::cout
				<< "size: " << array.size() << std::endl
				<< "array[0]: "<< array[0] << std::endl
				<< "array[1]: " << array[1] << std::endl
				<< "array[2]: " << array[2] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
    std::cout<< BLUE << "-------------------Array<A>-------------------" << RESET << std::endl; 
	{
		Array<A>	array(2);

		array[1] = A(21);
		try
		{
			std::cout
				<< "size: " << array.size() << std::endl
				<< "array[0]: "<< array[0] << std::endl
				<< "array[1]: " << array[1] << std::endl
				<< "array[2]: " << array[2] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
    std::cout<< BLUE << "-------------------const Array<A>-------------------" << RESET << std::endl; 
	{
		const Array<A>	array(2);

		try
		{
			std::cout
				<< "size: " << array.size() << std::endl
				<< "array[0]: "<< array[0] << std::endl
				<< "array[1]: " << array[1] << std::endl
				<< "array[2]: " << array[2] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
    std::cout<< BLUE << "-------------------Array<A const>-------------------" << RESET << std::endl; 
	{
		Array<A const>	array(2);

		try
		{
			std::cout
				<< "size: " << array.size() << std::endl
				<< "array[0]: "<< array[0] << std::endl
				<< "array[1]: " << array[1] << std::endl
				<< "array[2]: " << array[2] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
    std::cout<< BLUE << "-------------------const Array<A const>-------------------" << RESET << std::endl; 
	{
		Array<A const>	array(2);

		try
		{
			std::cout
				<< "size: " << array.size() << std::endl
				<< "array[0]: "<< array[0] << std::endl
				<< "array[1]: " << array[1] << std::endl
				<< "array[2]: " << array[2] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
