#include "PMergeMe.hpp"

PMergeMe::PMergeMe(void)
{
    return;
}
PMergeMe::PMergeMe(t_vect &vect_copy)
{
    _vect_copy = vect_copy;
    return;
}
PMergeMe::PMergeMe(const PMergeMe &cop)
{
    *this = cop;
}
PMergeMe &PMergeMe::operator=(const PMergeMe &eg)
{
    if (this != &eg)
    {

    }
    return (*this);
}
PMergeMe::~PMergeMe(void)
{
    return;
}

void PMergeMe::MergeInsertSort(t_vect &vect)
{
    int solo = -1;
    t_vectp vect_pair;
    t_vect::iterator it = vect.begin();
    while(it != vect.end())
    {
        if ((it + 1) != vect.end()) // ici on va creer les pairs et mettre en premiere position la plus grande des deux valeurs
        {
            std::pair<int,int> p = std::make_pair(*it, *(it + 1));
            if (p.first < p.second)
                std::swap(p.first, p.second);
            vect_pair.push_back(p);
            it++;
        }
        else
            solo = *it; // cas dans lequel le nombre d'element est impair
        it++;
    }
    t_vect envoy;
    printp(vect_pair.begin(), vect_pair.end());
    for (t_vectp::iterator itp = vect_pair.begin(); itp != vect_pair.end(); ++itp) //On recupere ici les valeurs des plus grands
    {
        envoy.push_back(itp->first);
    }
    PMergeMe::print(envoy.begin(), envoy.end());
    std::cout << "solo : " << solo << std::endl;
    // On va lancer ici la recursivite
    if (envoy.size() > 1)
        MergeInsertSort(envoy);
    //On va chercher maintenant a trier via les pairs en remontant
    // save = this->_vect_main;
    // for (t_vect::iterator ite = envoy.begin(); ite != envoy.end(); ite++);
    // {
        
    // }
    
}

void PMergeMe::print(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    std::vector<int>::iterator it = begin;
    std::cout << BLUE << "\t\tVECTOR" << RESET << std::endl;
    int i = 0;
    for (;it != end; ++it)
    {
        std::cout << *it << " ";
        i++;
        if (i % 5 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

void PMergeMe::printp(t_vectp::iterator begin, t_vectp::iterator end)
{
    t_vectp::iterator it = begin;
    std::cout << BLUE << "\t\tVECTOR PAIR" << RESET << std::endl;
    int i = 0;
    for (;it != end; ++it)
    {
        std::cout << "pair " << i << ": " << it->first << " | " << it->second << std::endl;
        i++;
    }
    std::cout << std::endl;
}

void PMergeMe::print(std::deque<int>::iterator begin, std::deque<int>::iterator end)
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

