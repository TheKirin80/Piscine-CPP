#include "PMergeMe.hpp"

void printe(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    std::vector<int>::iterator it = begin;
    std::cout << BLUE << "\t\tVECTOR" << RESET << std::endl;
    int i = 0;
    for (;it != end; ++it)
    {
        std::cout << *it << " ";
        i++;
        // if (i % 5 == 0)
        //     std::cout << std::endl;
    }
    std::cout << std::endl;
}

void printe(std::deque<int>::iterator begin, std::deque<int>::iterator end)
{
    std::deque<int>::iterator it = begin;
    int i = 0;
    std::cout << BLUE << "\t\tDEQUE" << RESET << std::endl;
    for (;it != end; ++it)
    {
        std::cout << *it << " ";
        i++;
        if (i % 5 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(int ac, char **av)
{
    if (ac < 3)
        return (std::cout << RED << "ERROR PARAMETERS" << RESET << std::endl, 0);
    std::vector<int> vect;
    std::deque<int> deq;
    for (int i = 1; i < ac ; i++)
    {
        std::string param = static_cast<std::string>(av[i]);
        size_t j = 0;
        if (param[0] == '+' || param[0] == '-')
            j++;
        for (; j < param.size() ; j++)
        {
            if(isdigit(param[j]) == 0)
                return (std::cout << RED << "ERROR PARAMETERS" << RESET << std::endl, 0);
        }
        double ret = strtod(param.c_str(), NULL);
        if (ret < 0  || ret > INT_MAX)
            return (std::cout << RED << "ERROR PARAMETERS" << RESET << std::endl, 0);
        t_vect::iterator it = find(vect.begin(), vect.end(), static_cast<int>(ret)); // Permet de verifier si la valeur est deja presente dans le vecteur auquel cas il ne l'insere pas de nouveau dans la liste
        if (it == vect.end()) 
        {
            vect.push_back(static_cast<int>(ret));
            deq.push_back(static_cast<int>(ret));
        }
        else
            return (std::cout << RED << "ERROR DOUBLON PARAMETERS" << RESET << std::endl, 0);
    }
    //t_vect::iterator it = vect.begin();
    // t_vect trou = vect;
    // vect.insert(it, 50);
    
    //std::cout << "vect[2] " << vect[2] << std::endl;
    printe(vect.begin(), vect.end());
    //printe(trou.begin(), trou.end());
    // printe(deq.begin(), deq.end());
    PMergeMe me;
    me.MergeInsertSort(vect);
    me.vprint();
    return (0);
    
}