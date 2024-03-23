#include "PMergeMe.hpp"

PMergeMe::PMergeMe(void)
{
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

// FONCTION POUR VECTOR

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
    // On va lancer ici la recursivite
    if (envoy.size() > 1)
        MergeInsertSort(envoy);
    //On va chercher maintenant a trier via les pairs en remontant
    t_vect vect_save = this->_vect_main;
    if (vect_save.size() != 0)
    {
        for (t_vect::iterator ite = vect_save.begin(); ite != vect_save.end(); ++ite)
        {
            if (ite != vect_save.begin())
            {
                Dichotomie(this->_vect_main, SearchPair(vect_pair, *ite));
            }
            else
                this->_vect_main.insert(this->_vect_main.begin(), SearchPair(vect_pair, *ite)); // si la liste est au premier element on peut de maniere logique que la pair est plus petite donc on l'insert
        }
    }
    else
    {
        this->_vect_main.push_back(*(envoy.begin()));
        this->_vect_main.insert(this->_vect_main.begin(), SearchPair(vect_pair, *envoy.begin()));
    }
    if (solo != -1)
    { 
        Dichotomie(this->_vect_main, solo);
    }
    
}

int PMergeMe::SearchPair(t_vectp &vect_pair, int c)
{
    for (t_vectp::iterator it = vect_pair.begin(); it != vect_pair.end(); it++)
    {
        if (it->first == c)
            return (it->second);
    }
    return(vect_pair.begin()->second);
}

void PMergeMe::Dichotomie(t_vect &vect, int val)
{
    size_t gauche = 0;
    size_t droite = vect.size() - 1;
    size_t mid = (gauche + droite) / 2;
    while (mid != gauche && mid != droite) // Je verifie que je n'ai pas reduit mon ecart a deux valeurs
    {
        if (vect[mid] > val)
            droite = mid;
        else
            gauche = mid; 
        mid = (gauche + droite) / 2;
    }
    if (vect[gauche] > val) // si valeur de gauche superieur a val alors la valeur doit aller avant gauche
    {
        vect.insert(std::find(vect.begin(), vect.end(), vect[gauche]), val);
    }   
        
    else if (vect[droite] < val) 
    {
        if ((droite + 1) < vect.size()) // On verifier si on est pas sur le dernier maillon
            vect.insert(std::find(vect.begin(), vect.end(), vect[droite]), val);
        else
            vect.push_back(val);
    }
    else
    // on insert via droite car l'insertion se fait a gauche de l'iterator passe 
    {
        vect.insert(std::find(vect.begin(), vect.end(), vect[droite]), val);
    } 
}

void PMergeMe::print(t_vect vect, std::string str)
{
    std::vector<int>::iterator it = vect.begin();
    std::cout << BLUE << "\t\tVECTOR "<< str << RESET << std::endl;
    int i = 0;
    for (;it != vect.end(); ++it)
    {
        std::cout << *it << " ";
        i++;
        if (i % 5 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

void PMergeMe::vprint()
{
    std::vector<int>::iterator it = this->_vect_main.begin();
    std::cout << BLUE << "After  : " << RESET;
    int i = 0;
    for (;it != this->_vect_main.end(); ++it)
    {
        std::cout << *it << " ";
        i++;
        // if (i % 5 == 0)
        //     std::cout << std::endl;
    }
    std::cout << std::endl;
}

void PMergeMe::vprintp(t_vectp::iterator begin, t_vectp::iterator end)
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

// FONCTION POUR DEQUE

void PMergeMe::MergeInsertSort(t_deq &deq)
{
    int solo = -1;
    t_deqp deq_pair;
    t_deq::iterator it = deq.begin();
    while(it != deq.end())
    {
        if ((it + 1) != deq.end()) // ici on va creer les pairs et mettre en premiere position la plus grande des deux valeurs
        {
            std::pair<int,int> p = std::make_pair(*it, *(it + 1));
            if (p.first < p.second)
                std::swap(p.first, p.second);
            deq_pair.push_back(p);
            it++;
        }
        else
            solo = *it; // cas dans lequel le nombre d'element est impair
        it++;
    }
    t_deq envoy;
    for (t_deqp::iterator itp = deq_pair.begin(); itp != deq_pair.end(); ++itp) //On recupere ici les valeurs des plus grands
    {
        envoy.push_back(itp->first);
    }
    // On va lancer ici la recursivite
    if (envoy.size() > 1)
        MergeInsertSort(envoy);
    //On va chercher maintenant a trier via les pairs en remontant
    t_deq deq_save = this->_deq_main;
    if (deq_save.size() != 0)
    {
        for (t_deq::iterator ite = deq_save.begin(); ite != deq_save.end(); ++ite)
        {
            if (ite != deq_save.begin())
            {
                Dichotomie(this->_deq_main, SearchPair(deq_pair, *ite));
            }
            else
                this->_deq_main.insert(this->_deq_main.begin(), SearchPair(deq_pair, *ite)); // si la liste est au premier element on peut de maniere logique que la pair est plus petite donc on l'insert
        }
    }
    else
    {
        this->_deq_main.push_back(*(envoy.begin()));
        this->_deq_main.insert(this->_deq_main.begin(), SearchPair(deq_pair, *envoy.begin()));
    }
    if (solo != -1)
    { 
        Dichotomie(this->_deq_main, solo);
    }
    
}

int PMergeMe::SearchPair(t_deqp &deq_pair, int c)
{
    for (t_deqp::iterator it = deq_pair.begin(); it != deq_pair.end(); it++)
    {
        if (it->first == c)
            return (it->second);
    }
    return(deq_pair.begin()->second);
}

void PMergeMe::Dichotomie(t_deq &deq, int val)
{
    size_t gauche = 0;
    size_t droite = deq.size() - 1;
    size_t mid = (gauche + droite) / 2;
    while (mid != gauche && mid != droite) // Je verifie que je n'ai pas reduit mon ecart a deux valeurs
    {
        if (deq[mid] > val)
            droite = mid;
        else
            gauche = mid; 
        mid = (gauche + droite) / 2;
    }
    if (deq[gauche] > val) // si valeur de gauche superieur a val alors la valeur doit aller avant gauche
    {
        deq.insert(std::find(deq.begin(), deq.end(), deq[gauche]), val);
    }   
        
    else if (deq[droite] < val) 
    {
        if ((droite + 1) < deq.size()) // On verifier si on est pas sur le dernier maillon
            deq.insert(std::find(deq.begin(), deq.end(), deq[droite]), val);
        else
            deq.push_back(val);
    }
    else
    // on insert via droite car l'insertion se fait a gauche de l'iterator passe 
    {
        deq.insert(std::find(deq.begin(), deq.end(), deq[droite]), val);
    } 
}

void PMergeMe::print(t_deq deq, std::string str)
{
    std::deque<int>::iterator it = deq.begin();
    std::cout << BLUE << "\t\tdeque "<< str << RESET << std::endl;
    int i = 0;
    for (;it != deq.end(); ++it)
    {
        std::cout << *it << " ";
        i++;
        if (i % 5 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

void PMergeMe::dprint()
{
    std::deque<int>::iterator it = this->_deq_main.begin();
    std::cout << BLUE << "\t\tDEQUE IN" << RESET << std::endl;
    int i = 0;
    for (;it != this->_deq_main.end(); ++it)
    {
        std::cout << *it << " ";
        i++;
        if (i % 5 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

void PMergeMe::dprintp(t_deqp::iterator begin, t_deqp::iterator end)
{
    t_deqp::iterator it = begin;
    std::cout << BLUE << "\t\tDEQUE PAIR" << RESET << std::endl;
    int i = 0;
    for (;it != end; ++it)
    {
        std::cout << "pair " << i << ": " << it->first << " | " << it->second << std::endl;
        i++;
    }
    std::cout << std::endl;
}

// FAIT AVANT


