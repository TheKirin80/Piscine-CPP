#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public :
        Intern(void);
        Intern(const Intern &cop);
        Intern &operator=(const Intern &eg);
        virtual ~Intern(void);
        AForm *makeForm(const std::string name_form, const std::string target);
    private :
        std::string _name_form[3];
};

#endif