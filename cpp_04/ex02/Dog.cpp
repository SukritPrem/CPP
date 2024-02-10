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
    {
        Animal::setType(r_obj.getType());
        if(_Brain)
        {
            delete _Brain;
            _Brain = NULL;
            _Brain = new Brain(r_obj.getmyBrain());
        }
    }
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Dog sounds." <<std::endl;
}

Brain & Dog::getmyBrain(void) const
{
    return (*_Brain);
}

// void Dog::whatIsFistThingInMyHead(void) const
// {
//     std::cout << _Brain->getFirstIdea() <<std::endl;
// }