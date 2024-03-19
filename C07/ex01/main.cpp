#include "iter.hpp"

class Test
{
	public:
		Test(void) :
			_val(42)
		{
			return;
		}
		int get(void) const
		{
			return (this->_val);
		}
	private:
		int _val;
};

std::ostream & operator<<(std::ostream &o, Test const &rhs)
{
	o << rhs.get();
	return (o);
}

int main(void)
{
	int		tab[] = {0, 1, 2, 3, 4};
	Test	tab2[5];
	char	tab3[] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << BLUE << "-----Test tab fixe print-----" << RESET << std::endl;
	iter(tab, 5, print);
	std::cout << BLUE << "-----Test tab fixe increment-----" << RESET << std::endl;
	iter(tab, 5, increment);
	std::cout << BLUE << "-----Test tab fixe print-----" << RESET << std::endl;
	iter(tab, 5, print);
	std::cout << BLUE << "-----Test tab2 class print-----" << RESET << std::endl;
	iter(tab2, 5, print);
	std::cout << BLUE << "-----Test tab3 fixe print-----" << RESET << std::endl;
	iter(tab3, 5, print);
	std::cout << BLUE << "-----Test tab3 fixe increment-----" << RESET << std::endl;
	iter(tab3, 5, increment);
	std::cout << BLUE << "-----Test tab3 fixe print-----" << RESET << std::endl;
	iter(tab3, 5, print);
	return (0);
}