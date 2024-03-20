#include "Span.hpp"

Span::Span(void) : _n(0){}
Span::Span(unsigned int const n) : _n(n){}
Span::Span(const Span &cop) : _n(cop._n)
{
    *this = cop;
}
Span &Span::operator=(const Span &eg)
{
    if (this != &eg)
        *this = eg;
    return (*this);
}
Span::~Span(void)
{
    return;
}

void    Span::addNumber(int const &add)
{
    if (this->_list.size() + 1 > this->_n)
        throw (TooManyObjectException());
    this->_list.push_back(add);
}

unsigned int     Span::shortestSpan(void)
{
    if (this->_list.size() < 2)
        throw (NotEnoughMemberException());
    this->_list.sort();
    unsigned int ret = UINT_MAX;
    std::list<int>::iterator i = this->_list.begin();
    std::list<int>::iterator save = i;
    i++;
    for (; i != this->_list.end(); ++i)
    {
        unsigned int dist = abs(*i - *save);
        if (ret > dist)
            ret = dist;
        save = i;
    }
    return (ret);
}

unsigned int     Span::longestSpan(void)
{
    if (this->_list.size() < 2)
        throw (NotEnoughMemberException());
    this->_list.sort();
    return (this->_list.back() - this->_list.front());
}

void    Span::print() const
{
    std::list<int>::const_iterator i = this->_list.begin();
    for (; i != this->_list.end(); ++i)
    {
        std::cout << *i << "; ";
    }
    std::cout << std ::endl;
}