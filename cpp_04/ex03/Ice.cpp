#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
    std::cout << "Ice Construtor void called" << std::endl; 
}

Ice::Ice(Ice & r_obj)
{
    _type = r_obj.getType();
}

Ice & Ice::operator=(Ice &r_obj)
{
    if(this != &r_obj)
    {
        _type = r_obj.getType();
    }
    return (*this);
}

void Ice::use(ICharacter & target)
{
    std::cout << "* shoots an " <<  _type  <<"bolt at bob *" << target.getName() << std::endl;
}

Ice::~Ice(void)
{
    std::cout << "Ice Deconstructor called" << std::endl;;
}

AMateria * Ice::clone (void) const
{
    return new Ice();
}