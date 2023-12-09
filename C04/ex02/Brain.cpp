#include "Brain.hpp"

Brain::Brain(void)
{
    for (int i = 0; i < 100 ; i++)
    {
        _ideas[i] = "A strange idea";
    }
    std::cout << "Brain Default Constructor" << std::endl;
    return;
}
Brain::Brain(const Brain &cop)
{
    for (int i = 0; i < 100 ; i++)
    {
        _ideas[i] = cop._ideas[i];
    }
    std::cout << "Brain Recopy Constructor" << std::endl;
}
Brain &Brain::operator=(const Brain &eg)
{
    for (int i = 0; i < 100 ; i++)
    {
        _ideas[i] = eg._ideas[i];
    }
    std::cout << "Copy assignment operator Brain called" << std::endl;
    return(*this);
}
Brain::~Brain(void)
{
    std::cout << "Brain Default Destructor" << std::endl;
    return;
}
