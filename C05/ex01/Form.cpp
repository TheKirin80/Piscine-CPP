#include "Form.hpp"

Form::Form(void) : _name("unspoiled"), _sign(false), _grad_sign(1), _grad_exec(1)
{
    return;
}

Form::Form(const std::string name, const int grad_sign, const int grad_exec) : _name(name), _sign(false), _grad_sign(grad_sign), _grad_exec(grad_exec)
{
    if (this->_grad_sign < 1 || this->_grad_exec < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->_grad_sign > 150 || this->_grad_exec > 150) 
        throw Bureaucrat::GradeTooLowException();
}
Form::Form(const Form &cop) : _name(cop.getName()), _sign(cop.getSign()),
         _grad_sign(cop.getGradSign()), _grad_exec(cop.getGradExec())
{
    return;
}
Form &Form::operator=(const Form &eg)
{
    if (this != &eg)
    {
        this->_sign = eg.getSign();
    }
    return (*this);
}
Form::~Form(void)
{
    return;
}
std::string Form::getName(void) const
{
    return (this->_name);
}
bool Form::getSign(void) const
{
    return (this->_sign);
}
int Form::getGradSign(void) const
{
    return (this->_grad_sign);
}
int Form::getGradExec(void) const
{
    return (this->_grad_exec);
}
const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form Too High exception triggered");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form Too Low exception triggered");
}

void    Form::beSigned(const Bureaucrat &bureau)
{
    if (this->_sign != true)
    {
        if (this->_grad_sign >= bureau.getGrade())
            this->_sign = true;
        else
            throw Form::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, Form const & form)
{
    os << form.getName() << ",  is signed : " << form.getSign() << std::endl << "grade required to sign : "
        << form.getGradSign() << std::endl << "grade required to exec : " << form.getGradExec() << std::endl;
    return os;
}