#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
class Form;
class Bureaucrat;
class Form
{
    public :
        Form(void);
        Form(const std::string name, const int grad_sign, const int grad_exec);
        Form(const Form &cop);
        Form &operator=(const Form &eg);
        virtual ~Form(void);
        std::string getName(void) const;
        bool        getSign(void) const;
        int         getGradSign(void) const;
        int         getGradExec(void) const;
        class GradeTooHighException : public std::exception{
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            const char* what() const throw();
        };
        void    beSigned(const Bureaucrat &bureau);
    private :
        const std::string   _name;
        bool                _sign;
        const int           _grad_sign;
        const int           _grad_exec;
};

std::ostream& operator<<(std::ostream& os, Form const & form);

#endif