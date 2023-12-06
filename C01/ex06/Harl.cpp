#include "Harl.hpp"

Harl::Harl(){return;}

Harl::~Harl(){return;}

void Harl::debug (void)
{
    std::cout << "Ceci est un message de DEBUG" << std::endl;
}

void Harl::info (void)
{
    std::cout << "Ceci est un message d'INFO" << std::endl;
}

void Harl::warning (void)
{
    std::cout << "Ceci est un message WARNING " << std::endl;
}

void Harl::error (void)
{
    std::cout << "Ceci est un message d'ERROR" << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*func[4])();
    func[0] = &Harl::debug;
    func[1] = &Harl::info;
    func[2] = &Harl::warning;
    func[3] = &Harl::error;
    int start = 4;
    std::string choice[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (level == choice[i])
        {
            start = i;
        }
    }
    switch (start)
    {
        case 0:
            (this->*func[0])();
        case 1:
            (this->*func[1])();
        case 2:
            (this->*func[2])();
        case 3:
            (this->*func[3])();
            break;
        default:
            std::cout << "Certainement une plainte inutile" << std::endl;
            break;
    }
}