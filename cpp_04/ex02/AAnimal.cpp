#include "AAnimal.hpp"


AAnimal::AAnimal(void): _type("AAnimal")
{
    std::cout << "Create AAnimal construtor." << std::endl;
}

AAnimal::AAnimal(AAnimal const &r_obj)
{
    setType(r_obj.getType());
}   

AAnimal::~AAnimal(void)
{
    std::cout << "Deconstrutor AAnimal." << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const &r_obj)
{
    //     std::cout << "this" << std::endl;
    // std::cout << this << std::endl;
    // std::cout << &r_obj << std::endl;
    if(this != &r_obj)
        setType(r_obj.getType());
    return (*this);
}

void        AAnimal::setType(std::string type){_type = type;}
std::string AAnimal::getType(void) const{return _type;}

void AAnimal::makeSound(void) const
{
    std::cout << "AAnimal sounds." <<std::endl;
}

// void AAnimal::whatIsFistThingInMyHead(void) const{
//     std::cout << "Brain...." <<std::endl;  
// }
    // protected:
    //     std::string type;
    // public:
    //     AAnimal(void);
	//     AAnimal(AAnimal const &r_obj);
	//     AAnimal & operator=(AAnimal const &r_obj);
	//     ~AAnimal();        std::string get_type(void) const;