#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <cstdlib>
#include <iostream>

class Bureaucrat
{
    public :
        Bureaucrat(void);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &cop);
        Bureaucrat &operator=(const Bureaucrat &eg);
        virtual ~Bureaucrat(void);
        std::string getName(void) const;
        int getGrade(void) const;
        class GradeTooHighException : public std::exception{
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            const char* what() const throw();
        };
        void increment(void);
        void decrement(void);
    private :
        const std::string   _name;
        int                 _grade;

};

std::ostream& operator<<(std::ostream& os, Bureaucrat const & bureau);

#endif