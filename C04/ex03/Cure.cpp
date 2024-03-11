#include "Cure.hpp"

Cure::Cure(void)
{
    this->_type = "cure";
    std::cout << "Cure Default Constructor" << std::endl;
    return;
}
Cure::Cure(const Cure &cop) : AMateria("cure")
{
    *this = cop;
    std::cout << "Cure Recopy Constructor" << std::endl;
}
Cure &Cure::operator=(const Cure &eg)
{
    std::cout << "Copy assignment operator Cure called" << std::endl;
    _type = eg._type;
    return (*this);
}
Cure::~Cure(void)
{
    std::cout << "Cure Default Destructor" << std::endl;
    return;
}

std::string const & Cure::getType(void) const
{
    return (this->_type);
}

AMateria* Cure::clone(void) const
{
    return (new Cure());
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
    return;
}
