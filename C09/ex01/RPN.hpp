#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <exception>

#define BLUE		"\033[1;34m"
#define RED			"\033[1;31m"
#define RESET		"\033[0m"

class RPN
{
    public :
        RPN(void);
        RPN(std::string const &line);
        RPN(const RPN &cop);
        RPN &operator=(const RPN &eg);
        virtual ~RPN(void);

        void    calc_polonais(void);
    private :
        std::stack<double>  _stack;
        std::string         _polo;
};

#endif