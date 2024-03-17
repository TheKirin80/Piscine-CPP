#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm :public AForm
{
    public :
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &cop);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &eg);
        virtual ~ShrubberyCreationForm(void);
        void    execute(Bureaucrat const & executor) const;

    private :

};

#endif