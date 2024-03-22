#include "RPN.hpp"

bool check_polo(std::string const &polo)
{
    if (polo.size() < 5)
        return (false);
    if (polo.size() % 2 == 0)
        return (false);
    bool carac = true; //Va permettre de verifier l'alternance caractere / espace d'un calcul
    for (size_t i = 0; i < polo.size(); i++)
    {
        if (carac == true)
        {
            carac = false;
            if (isdigit(polo[i]) == 0 && polo[i] != '-' && polo[i] != '+' && polo[i] != '*'
                    && polo[i] != '/')
                return (false);
        }
        else
        {
            carac = true;
            if (polo[i] != ' ')
                return (false);
        }
    }
    return (true);
}  

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cout << "Bad number of argument" << std::endl, 0);
    std::string polo = static_cast<std::string>(av[1]);
    bool v_polo = check_polo(polo);
    if (v_polo == false)
        return (std::cout << RED << "Error" << RESET << std::endl, 0);
    else
        std::cout << "Bien joue gogole" << std::endl;
    RPN rpn(polo);
    rpn.calc_polonais();
    return (0);
}