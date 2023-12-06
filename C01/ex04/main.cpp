#include "Sed.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Bad numbers of arguments" << std::endl;
        return (1);
    }
    Sed mySed = Sed(argv[1], argv[2], argv[3]);
    mySed.like_replace();
    return(0);
}