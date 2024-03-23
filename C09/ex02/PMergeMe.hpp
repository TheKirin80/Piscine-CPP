#ifndef PMergeMe_HPP
#define PMergeMe_HPP

#include <stack>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <exception>
#include <deque>
#include <vector>
#include <climits>
#include <utility>
#include <algorithm>
#include <ctime>

#define BLUE		"\033[1;34m"
#define RED			"\033[1;31m"
#define RESET		"\033[0m"

typedef std::vector<int> t_vect;
typedef std::deque<int> t_deq;
typedef std::vector<std::pair<int, int> > t_vectp;
typedef std::deque<std::pair<int, int> > t_deqp;
class PMergeMe
{
    public :
        PMergeMe(void);
        PMergeMe(const PMergeMe &cop);
        PMergeMe &operator=(const PMergeMe &eg);
        virtual ~PMergeMe(void);
        //Fonction lier a vector
        void                MergeInsertSort(t_vect &vect);
        int                 SearchPair(t_vectp &vect_pair, int c);
        void                Dichotomie(t_vect &vect, int val);
        void                print(t_vect vect, std::string str);
        void                vprint();
        void                vprintp(t_vectp::iterator begin, t_vectp::iterator end);
        //Fonction lier a deque
        void                MergeInsertSort(t_deq &deq);
        int                 SearchPair(t_deqp &deq_pair, int c);
        void                Dichotomie(t_deq &deq, int val);
        void                print(t_deq vect, std::string str);
        void                dprint();
        void                dprintp(t_deqp::iterator begin, t_deqp::iterator end);

    private :
        t_vect  _vect_main;
        t_deq   _deq_main;

};

#endif