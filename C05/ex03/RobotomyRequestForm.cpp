#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", "unknown", 72, 45)
{
    return;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", target, 72, 45)
{
    return;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cop) : AForm(cop)
{
    return;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &eg)
{
    if (this != &eg)
    {
        this->setSign(eg.getSign());
    }
    return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm(void)
{
    return;
}
void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getSign() == false)
        throw AForm::SignFalseException();
    else if (executor.getGrade() > this->getGradExec())
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << "Drrrrrrzzz, Drzzzzzz.... ";
        srand(time(NULL)); //setup le rand avec le temps actuel car random n'est pas reeelement random
        if ((rand() % 2) == 0)
            std::cout << this->getTarget() <<  " has been robotomized" << std::endl;
        else
            std::cout << this->getTarget() <<  " has not been robotomized" << std::endl;
    }
}