#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <map>
#include <iostream>
#include <fstream>
#include <exception>
#include <cctype>
#include <string>

#define BLUE		"\033[1;34m"
#define RED			"\033[1;31m"
#define RESET		"\033[0m"

class BitcoinExchange
{
    public :
        BitcoinExchange(void);
        BitcoinExchange(std::string const &file);
        BitcoinExchange(const BitcoinExchange &cop);
        BitcoinExchange &operator=(const BitcoinExchange &eg);
        virtual ~BitcoinExchange(void);
        void        print(void);
        void        traitement(std::string const &file);
        bool        check_date(std::string const date);
        void        charg_data_map(std::string const &file);
        bool        check_val(std::string const val);
        float       calc_bit(std::string const date, std::string const val);
        //Exception
        class DataProblemException : public std::exception
        {
            const char* what() const throw(){
                return ("Problem with CSV configuration");
            }
        };
        class InputProblemException : public std::exception
        {
            const char* what() const throw(){
                return ("Problem with user file");
            }
        };
    private :
        std::map<std::string, float> _map;
};

#endif