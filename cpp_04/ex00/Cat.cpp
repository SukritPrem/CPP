#include "Cat.hpp"

Cat::Cat(void)
{
    _type = "Cat";
    std::cout << "Create Cat construtor." << std::endl;
}

Cat::Cat(Cat const &r_obj)
{
    std::cout << "Copy constructor Cat called." << std::endl;
    Animal::setType(r_obj.getType());
}   

Cat::~Cat(void)
{
    std::cout << "Deconstrutor Cat." << std::endl;
}

Cat & Cat::operator=(Cat const &r_obj)
{
    std::cout << "Cat assignment opertor called." << std::endl;
    if(this != &r_obj)
        Animal::setType(r_obj.getType());
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Cat sounds." <<std::endl;
}
// class Cat
// {
//     public:
//         Cat(void);
// 	    Cat(Cat const &r_obj);
// 	    Cat & operator=(Cat const &r_obj);
// 	    ~Cat(void);
// };