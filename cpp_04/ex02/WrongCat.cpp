#include "WrongCat.hpp"

WrongCat::WrongCat(void): _type("WrongCat")
{
    std::cout << "Create WrongCat construtor." << std::endl;
}

WrongCat::WrongCat(WrongCat const &r_obj)
{
    setType(r_obj.getType());
}   

WrongCat::~WrongCat(void)
{
    std::cout << "Deconstrutor WrongCat." << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const &r_obj)
{
    if(this != &r_obj)
        setType(r_obj.getType());
    return (*this);
}

void        WrongCat::setType(std::string type){_type = type;}
std::string WrongCat::getType(void) const{return _type;}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat sounds." <<std::endl;
}
