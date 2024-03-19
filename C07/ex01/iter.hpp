#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>
#include <iostream>

#define BLUE		"\033[1;34m"
#define RESET		"\033[0m"

template <typename T>
void iter(T * array, size_t const array_size, void (*func)(T &))
{
    for (size_t i = 0; i < array_size; i++)
    {
        func(array[i]);
    }
}
template <typename T> void print(T &fprint)
{
	std::cout << "La variable vaut : "<< BLUE << fprint << RESET << std::endl;
}

template<typename T>
void inc(T &x)
{
	x++;
	return;
}

#endif