#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>

class Sed
{
    public :
        Sed(std::string p, std::string s, std::string r);
        ~Sed();
        void like_replace();

    private : 

        std::string file_path;
        std::string str_search;
        std::string str_replace;
        Sed();
};

#endif