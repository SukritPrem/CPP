#include "Ice.hpp"

Ice::Ice(void) : AMateria("Ice")
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

Ice::~Ice(void)
{
    std::cout << "Ice Deconstructor called" << std::endl;;
}

AMateria * Ice::clone (void) const
{
    return new Ice();
}