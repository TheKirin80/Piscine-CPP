#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <list>
#include <vector>
#include <iostream>
#include <cstdlib>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void)
		{
			return ;
		}
		MutantStack(const MutantStack<T>& cop)
		{
			*this = cop;
		}
		MutantStack<T>& operator=(const MutantStack<T>& eg) 
		{
			this->c = eg.c;
			return (*this);
		}
		~MutantStack()
		{
			return ;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator	begin(void)
		{
			return (this->c.begin());
		}
		iterator	end(void)
		{
			return (this->c.end());
		}
		const_iterator	begin(void) const
		{
			return (this->c.begin());
		}
		const_iterator	end(void) const
		{
			return (this->c.end());
		}
};

#endif