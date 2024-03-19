#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <exception>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <climits>
#include <iomanip>

#define BLUE		"\033[1;34m"
#define RESET		"\033[0m"


class ScalarConverter
{
    public :
        static void convert(std::string str);
        virtual ~ScalarConverter(void);
    private :
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &cop);
        ScalarConverter &operator=(const ScalarConverter &eg);
        static int verifTypeString (std::string str);
};

#endif