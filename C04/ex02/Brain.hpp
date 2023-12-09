#ifndef Brain_HPP
#define Brain_HPP

#include <iostream>
#include <cstdlib>

class Brain
{
    public :
        Brain(void);
        Brain(const Brain &cop);
        Brain &operator=(const Brain &eg);
        virtual ~Brain(void);
    private :
        std::string _ideas[100];
};

#endif