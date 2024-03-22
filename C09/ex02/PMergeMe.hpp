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

#define BLUE		"\033[1;34m"
#define RED			"\033[1;31m"
#define RESET		"\033[0m"

typedef std::vector<int> t_vect;
typedef std::deque<int> t_deq;
typedef std::vector<std::pair<int, int> > t_vectp;
typedef std::vector<std::pair<int, int> > t_deqp;
class PMergeMe
{
    public :
        PMergeMe(void);
        PMergeMe(t_vect &vect_copy);
        PMergeMe(const PMergeMe &cop);
        PMergeMe &operator=(const PMergeMe &eg);
        virtual ~PMergeMe(void);
        void MergeInsertSort(t_vect &vect);
        void print(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void print(std::deque<int>::iterator begin, std::deque<int>::iterator end);
    private :
        t_vect  _vect_main;
        t_vect  _vect_copy;
        t_deq   _deq_main;

};

#endif