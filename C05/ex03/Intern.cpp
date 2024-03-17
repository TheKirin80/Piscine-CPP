#include "Intern.hpp"

Intern::Intern(void)
{
    this->_name_form[0] = ShrubberyCreationForm().getName() + " request";
	this->_name_form[1] = RobotomyRequestForm().getName() + " request";
	this->_name_form[2] = PresidentialPardonForm().getName() + " request";
    return;
}
Intern::Intern(const Intern &cop)
{
    this->_name_form[0] = cop._name_form[0];
	this->_name_form[1] = cop._name_form[1];
	this->_name_form[2] = cop._name_form[2];
    return;
}
Intern &Intern::operator=(const Intern &eg)
{
    (void)eg;
    return (*this);
}
Intern::~Intern(void)
{
    return;
}
AForm   *Intern::makeForm(const std::string name_form, const std::string target)
{
    for (int i = 0 ; i < 3 ; i++)
    {
        if (this->_name_form[i] == name_form)
        {
            switch (i)
            {
                case 0 :
                    return (new ShrubberyCreationForm(target));
                case 1 :
                    return (new RobotomyRequestForm(target));
                case 2 :
                    return (new PresidentialPardonForm(target));
                default :
                    std::cout << "Oups a little problem" << std::endl;
            }
        }
    }
    std::cout << "Sorry but your request is incorrect !" << std::endl;
    return (NULL);
}