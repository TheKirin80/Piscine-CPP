#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	public :
	
		Zombie();
		Zombie(std::string str);
		~Zombie();
		void announce(void);
		std::string getName(void);
		void setName(std::string str);

	private :

		std::string	name;
};

Zombie* zombieHorde( int N, std::string name );

#endif