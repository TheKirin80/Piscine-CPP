#include "AForm.hpp"

AForm::AForm(void) : _name("unspoiled"), _target("unknow"), _sign(false), _grad_sign(1), _grad_exec(1)
{
    return;
}

AForm::AForm(const std::string name, const std::string target, const int grad_sign, const int grad_exec) : _name(name), _target(target), _sign(false), _grad_sign(grad_sign), _grad_exec(grad_exec)
{
    if (this->_grad_sign < 1 || this->_grad_exec < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->_grad_sign > 150 || this->_grad_exec > 150) 
        throw Bureaucrat::GradeTooLowException();
}
AForm::AForm(const AForm &cop) : _name(cop.getName()), _target(cop.getTarget()), _sign(cop.getSign()),
         _grad_sign(cop.getGradSign()), _grad_exec(cop.getGradExec())
{
    return;
}
AForm &AForm::operator=(const AForm &eg)
{
    if (this != &eg)
    {
        this->_sign = eg.getSign();
    }
    return (*this);
}
AForm::~AForm(void)
{
    return;
}
std::string AForm::getName(void) const
{
    return (this->_name);
}
std::string AForm::getTarget(void) const
{
    return (this->_target);
}
bool AForm::getSign(void) const
{
    return (this->_sign);
}
void AForm::setSign(bool sign)
{
    this->_sign = sign;
}
int AForm::getGradSign(void) const
{
    return (this->_grad_sign);
}
int AForm::getGradExec(void) const
{
    return (this->_grad_exec);
}
const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Form Too High exception triggered");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Form Too Low exception triggered");
}
const char* AForm::SignFalseException::what() const throw()
{
    return ("Form is not signed exception triggered");
}
const char* AForm::OpenFalseException::what() const throw()
{
    return ("File is not opened exception triggered");
}

void    AForm::beSigned(const Bureaucrat &bureau)
{
    if (this->_sign != true)
    {
        if (this->_grad_sign >= bureau.getGrade())
            this->_sign = true;
        else
            throw AForm::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, AForm const & AForm)
{
    os << AForm.getName() << ",  is signed : " << AForm.getSign() << std::endl << "grade required to sign : "
        << AForm.getGradSign() << std::endl << "grade required to exec : " << AForm.getGradExec() << std::endl;
    return os;
}