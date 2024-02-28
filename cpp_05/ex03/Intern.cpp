#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern constructor void called" << std::endl;
}

Intern::~Intern(void)
{
    std::cout << "Intern Deconstructor void called" << std::endl;
}

Intern & Intern::operator=(Intern &r_obj)
{
    (void)r_obj;
    return *this;
}

AForm * Intern::makeForm(std::string const &nameForm, std::string const &target)
{
    if("Shrubbery Form" == nameForm)
    {
        std::cout << "Intern creates " << nameForm << std::endl;
        return (new Shrubberycreationform(target));
    }    
    else if("PresidentialPardon Form" == nameForm)
    {
        std::cout << "Intern creates " << nameForm << std::endl;
        return (new PresidentialPardonForm(target));
    }    
    else if("RobotomyRequest Form" == nameForm)
    {
        std::cout << "Intern creates " << nameForm << std::endl;
        return (new RobotomyRequestform(target));
    }   
    else
        throw FailCreateForm();
}