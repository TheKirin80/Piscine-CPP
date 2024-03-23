#include "PMergeMe.hpp"

void printe(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    std::vector<int>::iterator it = begin;
    std::cout << BLUE << "Before : " << RESET;
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
        // if (i % 5 == 0)
        //     std::cout << std::endl;
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
    PMergeMe me;
    //Traitement dans Vecteur
    clock_t c_vect;
    printe(vect.begin(), vect.end());
    c_vect = clock();
    me.MergeInsertSort(vect);
    c_vect = clock() - c_vect;
    me.vprint();
    //Traitement dans Deque
    clock_t c_deq;
    //printe(deq.begin(), deq.end());
    c_deq = clock();
    me.MergeInsertSort(deq);
    c_deq = clock() - c_deq;
    //me.dprint();
    std::cout << "Time to process a range of "<< vect.size() <<" elements with std::vector " << (static_cast<float>(c_vect)/CLOCKS_PER_SEC) * 1000000 << "us" << std::endl;
    std::cout << "Time to process a range of "<< deq.size()<<" elements with std::deque " << (static_cast<float>(c_deq)/CLOCKS_PER_SEC) * 1000000 << "us" << std::endl;
    return (0);
    
}