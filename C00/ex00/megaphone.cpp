#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	int i = 1;
	int j;
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < ac)
		{
			j = 0;
			while (av[i][j] != '\0')
			{
				char res = toupper(av[i][j]);
				std::cout << res;
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}