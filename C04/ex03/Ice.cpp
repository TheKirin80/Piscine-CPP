#include "Ice.hpp"

Ice::Ice(void)
{
    this->_type = "ice";
    std::cout << "Ice Default Constructor" << std::endl;
    return;
}
Ice::Ice(const Ice &cop) : AMateria("ice")
{
    *this = cop;
    std::cout << "Ice Recopy Constructor" << std::endl;
}
Ice &Ice::operator=(const Ice &eg)
{
    std::cout << "Copy assignment operator Ice called" << std::endl;
    _type = eg._type;
    return (*this);
}
Ice::~Ice(void)
{
    std::cout << "Ice Default Destructor" << std::endl;
    return;
}

std::string const & Ice::getType(void) const
{
    return (this->_type);
}

AMateria* Ice::clone(void) const
{
    return (new Ice());
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    return;
}