#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", "unknown", 25, 5)
{
    return;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", target, 25, 5)
{
    return;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cop) : AForm(cop)
{
    return;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &eg)
{
    if (this != &eg)
    {
        this->setSign(eg.getSign());
    }
    return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm(void)
{
    return;
}
void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getSign() == false)
        throw AForm::SignFalseException();
    else if (executor.getGrade() > this->getGradExec())
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
}

