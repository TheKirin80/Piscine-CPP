#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstdlib>
#include <iostream>

template<typename T>
class Array
{
    public :
        Array<T>(void) : _n(0), _tab(new T()){}
        Array<T>(unsigned int n) : _n(n), _tab(new T[n]()) {}
        Array<T>(const Array<T> &cop) : _n(cop._n), _tab(new T[cop._n])
        {
            for (unsigned int i = 0; i < cop._n; i++)
                this->_tab[i] = cop._tab[i];
        }
        Array<T> &operator=(const Array<T> &eg)
        {
            if (this != &eg)
            {
                this->_n = eg._n;
                if (this->_tab != NULL)
                    delete [] this->_tab;
                this->_tab = new T[this->_n];
                for (unsigned int i = 0; i < eg._n; i++)
                this->_tab[i] = eg._tab[i];
            }
            return (*this);
        }
        ~Array<T>(void){delete [] this->_tab;}
        class OutOfBoundException : public std::exception
        {
            const char* what() const throw(){
                return ("Position is Out Of Bound");
            }
        };
        T &operator[](unsigned int pos)
        {
            if (pos >= this->_n)
                throw OutOfBoundException();
            return (this->_tab[pos]); 
        }
        T const &operator[](unsigned int pos) const
        {
            if (pos >= this->_n)
                throw OutOfBoundException();
            return (this->_tab[pos]); 
        }
        unsigned int size() const {return (this->_n);};

    private :
        unsigned int const _n;
        T *_tab;
};

#endif