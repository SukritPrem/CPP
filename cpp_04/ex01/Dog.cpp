#include "Dog.hpp"

Dog::Dog(void)
{
    _type = "Dog";
    _Brain = new Brain();
    std::cout << "Create Dog construtor." << std::endl;
}

Dog::Dog(Dog const &r_obj)
{
    Animal::setType(r_obj.getType());
}   

Dog::~Dog(void)
{
    if(_Brain)
    {  
        delete _Brain;
        _Brain = NULL;
    }  
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

Brain Dog::getmyBrain(void) const
{
    Brain new_brain = *_Brain;
    return new_brain;
}

void Dog::whatIsFistThingInMyHead(void) const
{
    std::cout << _Brain->getFirstIdea() <<std::endl;
}