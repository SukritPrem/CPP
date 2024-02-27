#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

RobotomyRequestform::RobotomyRequestform(void) : AForm("RobotomyRequestform Form", 72, 45) , target("Unknow")
{
    std::cout << "RobotomyRequestform Constructor void Called" << std::endl;
}

RobotomyRequestform::~RobotomyRequestform(void)
{
    std::cout << "RobotomyRequestform Deconstructor void Called" << std::endl;   
}
RobotomyRequestform::RobotomyRequestform(const char *input) : AForm("RobotomyRequestform Form", 72, 45)
{
    if(input == NULL)
    {
        target = "Unknow";
        std::cout << "RobotomyRequestform Constructor input "" Called" << std::endl;
    }    
    else
    {
        target = input;
    }  
}

RobotomyRequestform & RobotomyRequestform::operator=(RobotomyRequestform &r_obj)
{
    return *this;
}

std::string RobotomyRequestform::getTarget(void) const
{          
    return target;
}

void    RobotomyRequestform::execute(Bureaucrat const & executor) const
{
    std::srand(std::time(NULL));
    if(std::rand() % 2 == 0)
    {
        if(!AForm::getSigned())
            throw AForm::NotBeSigned();
        std::cout << target << " has been robotomized successfully." << std::endl;
    }    
    else
    {
        std::cout << target << " has been robotomized fail." << std::endl;
    }

}