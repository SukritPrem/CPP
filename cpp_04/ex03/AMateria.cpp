#include "AMateria.hpp"

AMateria::AMateria(void)
{
    _type = "Unknow";
    std::cout << "AMateria Construtor void called" << std::endl;
}

AMateria::AMateria(AMateria & r_obj)
{
    if(this != &r_obj)
    {
        _type = r_obj.getType();
    }
}

AMateria::AMateria(std::string const & type)
{
    _type = type;
    std::cout << "AMateria Construtor type called" << std::endl;
}

AMateria::~AMateria(void)
{
    std::cout << "AMateria Deconstrutor called" << std::endl;
}

AMateria & AMateria::operator=(AMateria & r_obj)
{
    if(this != &r_obj)
    {
        _type = r_obj.getType();
    }
    return (*this);
}

std::string const & AMateria::getType(void) const
{
    return _type;
}

// AMateria* clone(void) const
// {
//     return new AMateria(_type);
// }

// void AMateria::use(ICharacter & target)
// {
// }

void AMateria::use(std::string & target) // for Dev before use ICharacter class
{
    std::cout << "AMateria use called " << target <<std::endl;
}