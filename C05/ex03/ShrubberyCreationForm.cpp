#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", "unknown", 145, 137)
{
    return;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", target, 145, 137)
{
    return;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cop) : AForm(cop)
{
    return;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &eg)
{
    if (this != &eg)
    {
        this->setSign(eg.getSign());
    }
    return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    return;
}
void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getSign() == false)
        throw AForm::SignFalseException();
    else if (executor.getGrade() > this->getGradExec())
        throw AForm::GradeTooLowException();
    else
    {
        std::ofstream output_file;
        std::string name_file;
        name_file = this->getTarget() + "_shrubbery";
        output_file.open(name_file.c_str());
        if (output_file.is_open())
        {
         output_file << "    0    " << "       " << "    0    " << std::endl <<
         "   000   " << "       " << "   000   " << std::endl <<
         "  00000  " << "       " << "  00000  " << std::endl <<
         "   000   " << "       " << "   000   " << std::endl <<
         "  00000  " << "       " << "  00000  " << std::endl <<
         " 0000000 " << "       " << " 0000000 " << std::endl <<
         "  00000  " << "       " << "  00000  " << std::endl <<
         " 0000000 " << "       " << " 0000000 " << std::endl <<
         "000000000" << "       " << "000000000" << std::endl <<
         "   |||   " << "       " << "   |||   " << std::endl <<
         "   |||   " << "       " << "   |||   " << std::endl <<
         "   |||   " << "       " << "   |||   " << std::endl <<
         "   |||   " << "       " << "   |||   " << std::endl <<
         "   |||   " << "       " << "   |||   " << std::endl <<
         "█████████████████████████████████████" << std::endl <<
         "█████████████████████████████████████" << std::endl;
        }
        else
            throw AForm::OpenFalseException();
    }
}