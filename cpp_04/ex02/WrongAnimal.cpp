#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("WrongAnimal")
{
    std::cout << "Create WrongAnimal construtor." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &r_obj)
{
    setType(r_obj.getType());
}   

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "Deconstrutor WrongAnimal." << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const &r_obj)
{
    if(this != &r_obj)
        setType(r_obj.getType());
    return (*this);
}

void        WrongAnimal::setType(std::string type){_type = type;}
std::string WrongAnimal::getType(void) const{return _type;}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal sounds." <<std::endl;
}
