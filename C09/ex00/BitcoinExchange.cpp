#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    return;
}

BitcoinExchange::BitcoinExchange(std::string const &file)
{
    charg_data_map(file);
    return;
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &cop)
{
    this->_map = cop._map;
    *this = cop;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &eg)
{
    if (this != &eg)
    {
        this->_map = eg._map;
    }
    return (*this);
}
BitcoinExchange::~BitcoinExchange(void)
{
    return;
}

void BitcoinExchange::charg_data_map(std::string const &file)
{
    std::ifstream open_data;
    open_data.open(file.c_str());
    if (open_data.is_open() == false)
        throw (DataProblemException());  
    std::string line;
    if (open_data.peek() == EOF) //Protege le fichier vide
        throw (DataProblemException()); 
    //bool first = true; // permet de passer la premiere ligne du fichier CSV indiquant les infos des colonnes
    while (std::getline(open_data, line))
    {
        size_t virg =  line.find(',');
        if (virg != std::string::npos && virg != 0 && line[virg + 1] != '\0')
        {
            // if (first == true)
            //     first = false;
            //else
                this->_map[line.substr(0, virg)] = std::strtof(line.substr(virg + 1).c_str(), NULL);
        }
        else
        {
            open_data.close();
            throw (DataProblemException());
        }
    }
    open_data.close();
}


void BitcoinExchange::traitement(std::string const &file)
{
    std::ifstream open_file;
    open_file.open(file.c_str());
    if (open_file.is_open() == false)
        throw (InputProblemException());
    std::string line;
    if (open_file.peek() == EOF) 
        throw (InputProblemException()); 
    std::getline(open_file, line);
    if(line.compare("date | value") != 0)
    {
        open_file.close();
        throw (InputProblemException());
    }
    while(std::getline(open_file, line))
    {
        size_t pip = line.find('|');
        //La verification de npos sert a determiner si le caractere recherche est present
        //pip = 11 permet de verifier si la date fais bien 10 caractere (de pos 0 a 9)
        //  et si il y a bien un caractere entre le pipe et la date
        //line[pip - 1] == ' ' permet de verifier si le caractere intermediaire est bien un space
        //(pip + 2) < line.size() permet de verifier qu'il y a bien une valeur a droite du pipe
        if (pip != std::string::npos && pip == 11 && line[pip - 1] == ' ' 
                && (pip + 2) < line.size() && line[pip + 1] == ' ')
        {
            std::string date = line.substr(0, pip - 1);
            // On va check si la date correspond a nos attentes
            bool v_date = BitcoinExchange::check_date(date);
            if (v_date != true)
                std::cout << RED << "Error: bad input => " << date << RESET << std::endl;
            else
            {
                //on va check si la valeur correspond a nos attentes
                std::string val = line.substr(pip + 2);
                bool v_val = BitcoinExchange::check_val(val);
                if (v_val == true)
                {
                    float ret = BitcoinExchange::calc_bit(date, val);
                    if (ret != -1) 
                        std::cout << date << " => " << val << " = " << ret << std::endl;
                }
            }
        }
        else 
        {
            std::cout << RED << "Error: bad input => " << line << RESET << std::endl;
        }
    }

}
bool BitcoinExchange::check_date(std::string const date)
{
    if (date.size() != 10)
        return (false);
    for (size_t i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                return (false);
        }
        else if (isdigit(date[i]) == 0)
            return (false);
    }
    int year = atoi(date.substr(0,4).c_str());
    int month = atoi(date.substr(5, 7).c_str());
    int day = atoi(date.substr(8).c_str());
    if (year < 2000 || year > 2025)
       return (false);
    if (month > 12)
        return (false);
    if (month == 2 && day > 29) //fevrier
        return (false);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) // mois a 30j
        return (false);
    if (day > 31) // mois a 31j
        return (false);
    return (true);
}
bool BitcoinExchange::check_val(std::string const val)
{
    if (val.size() > 20)
    {
        std::cout << RED << "Error: too large a number." << RESET << std::endl;
        return (false);
    }
    if (val[0] == '.' || (isdigit(val[0]) == 0 && val[1] == '.'))
    {
        std::cout << RED << "Error: bad input => " << val << RESET << std::endl;
        return (false);
    }
    bool point = false;

    for (size_t i = 1; i < val.size(); i++)
    {
        if (val[i] == '.')
        {
            if (point == false)
                point = true;
            else
            {
                std::cout << RED << "Error: bad input => " << val << RESET << std::endl;
                return (false);
            }
        }
        else if (isdigit(val[i]) == 0)
        {
            std::cout << RED << "Error: bad input => " << val << RESET << std::endl;
            return (false);
        }
    }
    if (val[0] == '-')
    {
        std::cout << RED << "Error: not a positive number." << RESET << std::endl;
        return(false);
    }
    else if (isdigit(val[0]) == 0 && val[0] != '+')
    {
            std::cout << RED << "Error: bad input => " << val << RESET << std::endl;
            return (false);
    }
    double value = strtod(val.c_str(), NULL);
    if (value < 0 || value > 1000)
    {
        std::cout << RED << "Error: too large a number." << RESET << std::endl;
        return (false);
    }
    return (true);
    

}

float  BitcoinExchange::calc_bit(std::string const date, std::string const val)
{
    std::map<std::string, float>::const_iterator it_save;
    if (this->_map.begin()->first > date)
        return (std::cout << RED << "La date est trop vieille par rapport au set de donnee desole" << RESET << std::endl, -1);
    for (std::map<std::string, float>::const_iterator it = this->_map.begin(); it != this->_map.end(); ++it)
    {   
        if (it->first == date)
            return (strtof(val.c_str(), NULL) * it->second);
        if (it->first > date)
            return (strtof(val.c_str(), NULL) * it_save->second);
        it_save = it;
    }
    return (strtof(val.c_str(), NULL) * it_save->second);
}
void BitcoinExchange::print(void)
{
    int i = 0;
    for (std::map<std::string, float>::const_iterator it = this->_map.begin(); it != this->_map.end(); ++it)
    {   
        std::cout << it->first << " = " << it->second << ";\t" ;
        if ((i % 4) == 3)
            std::cout << std::endl;
        i++;
    }
 
    std::cout << '\n';
}