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
    for (t_vectp::iterator itp = vect_pair.begin(); itp != vect_pair.end(); ++itp) //On recupere ici les valeurs des plus grands
    {
        envoy.push_back(itp->first);
    }
    PMergeMe::print(envoy.begin(), envoy.end());
    std::cout << "solo : " << solo << std::endl;
    // On va lancer ici la recursivite
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

