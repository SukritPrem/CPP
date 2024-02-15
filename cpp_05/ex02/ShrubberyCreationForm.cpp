#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <string>
Shrubberycreationform::Shrubberycreationform(void) : AForm("Shrubbery Form", 145, 137) , target("Unknow")
{
    createFormTarget();
    std::cout << "Shrubbery Constructor void Called" << std::endl;
}

Shrubberycreationform::~Shrubberycreationform(void)
{
    std::cout << "Shrubbery Deconstructor void Called" << std::endl;   
}
Shrubberycreationform::Shrubberycreationform(const char *input) : AForm("Shrubbery Form", 145, 137)
{
    if(input == NULL)
    {
        target = "Unknow";
        std::cout << "Shrubbery Constructor input "" Called" << std::endl;
    }    
    else
    {
        target = input;
        createFormTarget();
    }  
}

void    Shrubberycreationform::createFormTarget(void)
{
    target = target + "_shrubbery";
    std::ofstream o(target.c_str(), std::ios::binary);

    if(!o.is_open())
    {
        std::cerr << "Error: Fail to open file for writing\n";
    }
    o << "      *" << std::endl;
    o << "     ***" << std::endl;
    o << "    *****" << std::endl;
    o << "   *******" << std::endl;
    o << "  *********" << std::endl;
    o << "     |||" << std::endl;
    o.close();
    std::cout << "Shrubbery Constructor input Called" << std::endl;
}

std::string Shrubberycreationform::getTarget(void) const
{
    return target;
}

void    Shrubberycreationform::execute(Bureaucrat const & executor)
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

}