#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public :
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &cop);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &eg);
        virtual ~PresidentialPardonForm(void);
        void    execute(Bureaucrat const & executor) const;
    private :
};

#endif