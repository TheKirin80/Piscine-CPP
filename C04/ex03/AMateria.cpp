#include "AMateria.hpp"

AMateria::AMateria(void) : _type("unknow")
{
    std::cout << "AMateria Default Constructor" << std::endl;
    return;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
    std::cout << "AMateria NameSet Constructor" << std::endl;
    return;
}

AMateria::AMateria(const AMateria &cop)
{
    *this = cop;
    std::cout << "AMateria Recopy Constructor" << std::endl;
}
AMateria &AMateria::operator=(const AMateria &eg)
{
    std::cout << "Copy assignment operator AMateria called" << std::endl;
    _type = eg._type;
    return (*this);
}
AMateria::~AMateria(void)
{
    std::cout << "AMateria Default Destructor" << std::endl;
    return;
}

std::string const & AMateria::getType(void) const
{
    return (this->_type);
}

void    AMateria::use(ICharacter& target)
{
    (void)target;
    return;
}
