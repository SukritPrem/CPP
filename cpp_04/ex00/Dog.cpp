#include "Dog.hpp"

Dog::Dog(void)
{
    _type = "Dog";
    std::cout << "Create Dog construtor." << std::endl;
}

Dog::Dog(Dog const &r_obj)
{
    Animal::setType(r_obj.getType());
}   

Dog::~Dog(void)
{
    std::cout << "Deconstrutor Dog." << std::endl;
}

Dog & Dog::operator=(Dog const &r_obj)
{
    if(this != &r_obj)
        Animal::setType(r_obj.getType());
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Dog sounds." <<std::endl;
}