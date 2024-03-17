#ifndef AForm_HPP
#define AForm_HPP

#include <exception>
#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"

class AForm;
class Bureaucrat;

class AForm
{
    public :
        AForm(void);
        AForm(const std::string name, const std::string target, const int grad_sign, const int grad_exec);
        AForm(const AForm &cop);
        AForm &operator=(const AForm &eg);
        virtual ~AForm(void);
        std::string getName(void) const;
        std::string getTarget(void) const;
        bool        getSign(void) const;
        void        setSign(bool sign);
        int         getGradSign(void) const;
        int         getGradExec(void) const;
        class GradeTooHighException : public std::exception{
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            const char* what() const throw();
        };
        class SignFalseException : public std::exception{
            const char* what() const throw();
        };
        class OpenFalseException : public std::exception{
            const char* what() const throw();
        };
        void    beSigned(const Bureaucrat &bureau);
        virtual void execute(Bureaucrat const & executor) const = 0;
    private :
        const std::string   _name;
        const std::string   _target;
        bool                _sign;
        const int           _grad_sign;
        const int           _grad_exec;
};

std::ostream& operator<<(std::ostream& os, AForm const & AForm);

#endif