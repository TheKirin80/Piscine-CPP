#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public :
        RobotomyRequestForm(void);
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &cop);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &eg);
        virtual ~RobotomyRequestForm(void);
        void    execute(Bureaucrat const & executor) const;
    private :

};

#endif