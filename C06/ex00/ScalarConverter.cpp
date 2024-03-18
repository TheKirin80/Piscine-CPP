#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
    return;
}
ScalarConverter::ScalarConverter(const ScalarConverter &cop)
{
    *this = cop;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &eg)
{
    if (this != &eg)
    {
        (void)eg;
    }
    return (*this);
}
ScalarConverter::~ScalarConverter(void)
{
    return;
}

void ScalarConverter::convert (std::string str)
{
    //double stack;

    //stack = strtod(str.c_str(), NULL); // transforme la chaine en une valeur numerique
    //std::cout << "stack : " << stack << "    " << (sqrt(-1)) << std::endl;
    //------CHAR-----
    if ((str.size() == 1 && isdigit(str[0]) == 0) || (str[0] == '\0'))
    {
        char c = str[0];
        if (isprint(c))
            std::cout << "char : '" << c << "'" << std::endl;
        else
            std::cout << "char : Non displayable" << std::endl;
        std::cout << "int : " << static_cast<int>(c) << std::endl;
        std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
    }
    //------NAN ET INF-----
    else if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
    {
        double stack = strtod(str.c_str(), NULL);
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        std::cout << "float : " << static_cast<float>(stack) << "f" << std::endl;
        std::cout << "double : " << stack << std::endl;
    }
    else if (str == "+inff" || str == "-inff" || str == "inff")
    {
        float stack = strtof(str.c_str(), NULL);
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        std::cout << "float : " << stack << "f" << std::endl;
        std::cout << "double : " << static_cast<double>(stack) << std::endl;
    }
    //-------Verification de la str-------
    else
    {
        int ret = ScalarConverter::verifTypeString(str);
        //Valeur de retour : 0 si Float , 1 si Double , 2 si Int et -1 si Error
        //------INT-------
        if (ret == 2) 
        {
            int stack = atoi(str.c_str());
            std::cout << "char : ";
            if (stack < -128 || stack > 127)
                std::cout << "impossible" << std::endl;
            else if (isprint(static_cast<char>(stack)))
                std::cout << "'" << static_cast<char>(stack) << "'" << std::endl;
            else
                std::cout << "Non displayable" << std::endl;
            std::cout << "int : " << stack << std::endl;
            std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(stack) << "f" << std::endl;
            std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(stack) << std::endl;
        }
        //------DOUBLE----
        else if (ret == 1)
        {
            double stack = strtod(str.c_str(), NULL);
            std::cout << "char : ";
            if (stack < -128 || stack > 127)
                std::cout << "impossible" << std::endl;
            else if (isprint(static_cast<char>(stack)))
                std::cout << "'" << static_cast<char>(stack) << "'" << std::endl;
            else
                std::cout << "Non displayable" << std::endl;
            std::cout << "int : ";
            if (stack < INT_MIN || stack > 214743647)
                std::cout << "impossible" << std::endl;
            else
                std::cout << static_cast<int>(stack) << std::endl;
            std::cout << "float : " << static_cast<float>(stack) << "f" << std::endl;
            std::cout << "double : " << stack << std::endl;
        }
        //------FLOAT-----
        else if (ret == 0)
        {
            float stack = strtof(str.c_str(), NULL);
            std::cout << "char : ";
            if (stack < -128 || stack > 127)
                std::cout << "impossible" << std::endl;
            else if (isprint(static_cast<char>(stack)))
                std::cout << "'" << static_cast<char>(stack) << "'" << std::endl;
            else
                std::cout << "Non displayable" << std::endl;
            std::cout << "int : ";
            if (static_cast<double>(stack) < INT_MIN || static_cast<double>(stack) > INT_MAX)
                std::cout << "impossible" << std::endl;
            else
                std::cout << static_cast<int>(stack) << std::endl;
            std::cout << "float : " << stack << "f" << std::endl;
            std::cout << "double : " << static_cast<double>(stack) << std::endl;
        }
        else
            std::cout << "Bad expression" << std::endl;
    }
}

int ScalarConverter::verifTypeString (std::string str)
{
    //Valeur de retour : 0 si Float , 1 si Double , 2 si Float et -1 si Error
    bool point = false;
    int i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;
    for (; i < static_cast<int>(str.size()); i++)
    {
        if (str[i] == 'f' && point == true && str[i + 1] == '\0' && isdigit(str[i -1]))
            return (0);
        else if (str[i] == '.')
        {
            if (point == true)
                return (-1);
            else
                point = true;
        }
        else if (isdigit(str[i]) == 0)
            return (-1);    
    }
    double stack =  strtod(str.c_str(), NULL);
    if (point == true || stack < INT_MIN || stack > INT_MAX)
        return (1);
    else
        return (2);
}