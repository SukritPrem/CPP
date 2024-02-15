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
        std::srand(std::time(NULL));
        if(std::rand() % 2 == 0)
            std::cout << target << " has been robotomized successfully." << std::endl;
        else
        {
            std::cout << target << " has been robotomized fail." << std::endl;
            // throw FailCreateForm();
        }
    }  
}

std::string RobotomyRequestform::getTarget(void) const
{            // throw FailCreateForm();
    return target;
}

void    RobotomyRequestform::execute(Bureaucrat const & executor)
{
    try
    {
        if(executor.getGrade() > AForm::getGradeExecute())
            throw AForm::GradeTooLowException();
        else if(executor.getGrade() < 0)
            throw AForm::GradeTooHighException();
        else
        {
            AForm::setSigned(1);
        }
    }
    catch (const AForm::GradeTooLowException& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
    catch (const AForm::GradeTooHighException& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
}