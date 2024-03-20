#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <cstdlib>
#include <iterator>
#include <exception>
#include <algorithm>

class NotFoundException : public std::exception
{
    const char* what() const throw(){
        return ("Your value wasn't in the container");
    }
};

template <typename T>
typename T::iterator easyfind (T &contain, int const  &search) //Pour les besoin d'un retour modifiable
{
    typename T::iterator iterat;
    iterat = find(contain.begin(), contain.end(), search); 
    if (iterat == contain.end())
        throw NotFoundException();
    return (iterat);
}

template <typename T>
typename T::const_iterator easyfind (T const &contain, int const &search)//Pour les besoin d'un retour non modifiable
{
    typename T::const_iterator iterat;
    iterat = find(contain.begin(), contain.end(), search);
    if (iterat == contain.end())
        throw NotFoundException();
    return (iterat);
}



#endif