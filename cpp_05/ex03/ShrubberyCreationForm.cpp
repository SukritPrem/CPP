#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <string>
Shrubberycreationform::Shrubberycreationform(void) : AForm("Shrubbery Form", 145, 137) , target("Unknow")
{
    createFormTarget();
    // std::cout << "Shrubbery Constructor void Called" << std::endl;
}

Shrubberycreationform::~Shrubberycreationform(void)
{
    // std::cout << "Shrubbery Deconstructor void Called" << std::endl;   
}
Shrubberycreationform::Shrubberycreationform(const char *input) : AForm("Shrubbery Form", 145, 137)
{
    if(input == NULL)
    {
        target = "Unknow";
        // std::cout << "Shrubbery Constructor input "" Called" << std::endl;
    }    
    else
    {
        target = input;
    }  
}

Shrubberycreationform::Shrubberycreationform(std::string input) : AForm("Shrubbery Form", 145, 137)
{
    target = input;
}

Shrubberycreationform & Shrubberycreationform::operator=(Shrubberycreationform &r_obj)
{
    (void)r_obj;
    return *this;
}


void    Shrubberycreationform::createFormTarget(void) const
{
    std::string newtarget = target + "_shrubbery";
    std::ofstream o(newtarget.c_str(), std::ios::binary);

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

void    Shrubberycreationform::execute(Bureaucrat const & executor) const
{
    if(!this->getSigned())
    {
        std::string meassage = " couldn't executed " + AForm::getName();
        throw (std::runtime_error(executor.getName() + meassage));
    }
    // std::cout << executor.getGrade() << " " << this->getGradeExecute() << std::cout;
    if(executor.getGrade() > this->getGradeExecute())
        throw AForm::GradeTooLowException();
    std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    createFormTarget();
}