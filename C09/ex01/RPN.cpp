#include "RPN.hpp"

RPN::RPN(void)
{
    return;
}

RPN::RPN(std::string const &line) : _polo(line)
{
    return;
}
RPN::RPN(const RPN &cop)
{
    this->_polo = cop._polo;
    *this = cop;
}
RPN &RPN::operator=(const RPN &eg)
{
    if (this != &eg)
    {
        this->_polo = eg._polo;
    }
    return (*this);
}
RPN::~RPN(void)
{
    return;
}
void    RPN::calc_polonais(void)
{
    for(size_t i = 0; i < this->_polo.size(); i++)
    {
        if (i % 2 == 0) //la chaine a deja ete verifie, ici on peut juste faire une case sur deux et regarder
        {
            if (isdigit(this->_polo[i]) != 0)
                this->_stack.push(_polo[i] - '0');
            else
            {
                if (this->_stack.size() < 2)
                {
                    std::cout << RED << "Error : too many operator" << RESET << std::endl;
                    return;
                }
                double val2 = this->_stack.top(); // represente la valeur tout au dessus
                this->_stack.pop();
                double val1 = this->_stack.top(); // represente le resultat
                this->_stack.pop();
                if (this->_polo[i] == '+')
                {
                    this->_stack.push(val1 + val2);
                }
                else if (this->_polo[i] == '-')
                {
                    this->_stack.push(val1 - val2);
                }
                else if (this->_polo[i] == '*')
                {
                    this->_stack.push(val1 * val2);
                    // std::cout << val1 << " et " << val2 << std::endl;
                }
                else if (this->_polo[i] == '/')
                {
                    if (val2 == 0)
                    {
                        std::cout << RED << "Error : try division with 0" << RESET << std::endl;    
                        return;
                    }
                    this->_stack.push(val1 / val2);
                }
                //std::cout << BLUE << this->_stack.top() << RESET << std::endl;
            }
        }
    }
    if (this->_stack.size() != 1)
        std::cout << RED << "Error : too many value" << RESET << std::endl;
    else
        std::cout << BLUE << this->_stack.top() << RESET << std::endl;    
}
