#include "Cat.hpp"


Cat::Cat(void)
{
    _type = "Cat";
    _Brain = new Brain();
    std::cout << "Create Cat construtor." << std::endl;
}

Cat::Cat(Cat const &r_obj)
{
    Animal::setType(r_obj.getType());
}   

Cat::~Cat(void)
{
    if(_Brain)
    {  
        delete _Brain;
        _Brain = NULL;
    }    
    std::cout << "Deconstrutor Cat." << std::endl;
}

Cat & Cat::operator=(Cat const &r_obj)
{
    if(this != &r_obj)
    {
        Animal::setType(r_obj.getType());
        if(_Brain)
        {
            delete _Brain;
            _Brain = NULL;

            // *_Brain = r_obj.getmyBrain();
            // r_obj.getmyBrain() ;
            _Brain = r_obj.getmyBrain();
            std::cout << _Brain << std::endl;
        }
    }

    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Cat sounds." <<std::endl;
}

Brain * Cat::getmyBrain(void) const
{
    std::cout << _Brain << std::endl;
    Brain *test = new Brain(*_Brain);
    return test;
}

void Cat::whatIsFistThingInMyHead(void) const
{
    std::cout << _Brain->getFirstIdea() <<std::endl;
}
// class Cat
// {
//     public:
//         Cat(void);
// 	    Cat(Cat const &r_obj);
// 	    Cat & operator=(Cat const &r_obj);
// 	    ~Cat(void);
// };