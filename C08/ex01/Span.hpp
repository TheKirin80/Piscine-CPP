#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <list>
#include <climits>


class Span
{
    public :
        Span(void);
        Span(unsigned int const n);
        Span(const Span &cop);
        Span &operator=(const Span &eg);
        virtual ~Span(void);
        class TooManyObjectException : public std::exception
        {
            const char* what() const throw(){
                return ("List have too many items in it");
            }
        };
        class NotEnoughMemberException : public std::exception
        {
            const char* what() const throw(){
                return ("List haven't enough items in it");
            }
        };
        void            addNumber(int const &add);
        unsigned int    shortestSpan(void);
        unsigned int    longestSpan(void);
        template <typename InputIterator>
        void    addrange(InputIterator it_begin, InputIterator it_end)
        {
            InputIterator it_i = it_begin;
            for (; it_i != it_end; ++it_i)
            {
                if (this->_list.size() + 1 > this->_n)
                    throw (TooManyObjectException());
                this->_list.push_back(*it_i);
            }
        };
        //void            addrange(std::list<int>::iterator it_begin, std::list<int>::iterator it_end);
        void            print() const;
    private :
        unsigned int const _n;
        std::list<int> _list;

};

#endif