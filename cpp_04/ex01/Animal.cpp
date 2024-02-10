#include "Animal.hpp"


Animal::Animal(void): _type("Animal")
{
    std::cout << "Create Animal construtor." << std::endl;
}

Animal::Animal(Animal const &r_obj)
{
    setType(r_obj.getType());
}   

Animal::~Animal(void)
{
    std::cout << "Deconstrutor Animal." << std::endl;
}

Animal & Animal::operator=(Animal const &r_obj)
{
    //     std::cout << "this" << std::endl;
    // std::cout << this << std::endl;
    // std::cout << &r_obj << std::endl;
    if(this != &r_obj)
        setType(r_obj.getType());
    return (*this);
}

void        Animal::setType(std::string type){_type = type;}
std::string Animal::getType(void) const{return _type;}

void Animal::makeSound(void) const
{
    std::cout << "Animal sounds." <<std::endl;
}

void Animal::whatIsFistThingInMyHead(void) const{
    std::cout << "Brain...." <<std::endl;  
}
    // protected:
    //     std::string type;
    // public:
    //     Animal(void);
	//     Animal(Animal const &r_obj);
	//     Animal & operator=(Animal const &r_obj);
	//     ~Animal();        std::string get_type(void) const;