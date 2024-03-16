#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Gertrude"), _grade(150)
{
    return;
}
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &cop)
{
    *this = cop;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &eg)
{
    if (this != &eg)
    {
        this->_grade = eg.getGrade();
    }
    return(*this);
}
Bureaucrat::~Bureaucrat(void)
{
    return;
}

std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Too High exception triggered");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Too Low exception triggered");
}
void    Bureaucrat::increment()
{
    if (this->_grade > 1)
        this->_grade--;
    else
        throw Bureaucrat::GradeTooHighException();
}
void    Bureaucrat::decrement()
{
    if (this->_grade < 150)
        this->_grade++;
    else
        throw Bureaucrat::GradeTooLowException();
}
std::ostream& operator<<(std::ostream& os, Bureaucrat const & bureau)
{
    os << bureau.getName() << ", bureaucrat grade " << bureau.getGrade();
    return os;
}