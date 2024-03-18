#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <exception>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <climits>
#include <iomanip>

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