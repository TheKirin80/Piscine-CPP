#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <iostream>

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (0);
    }
    std::string param = static_cast<std::string>(av[1]);
    std::string bd = "data.csv";
    try
    {
        BitcoinExchange now(bd);
        now.traitement(param);
        //now.print();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return (0);
    
}