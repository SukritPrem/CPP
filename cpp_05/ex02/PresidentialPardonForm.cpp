#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm Form", 25, 5) , target("Unknow")
{
    // std::cout << "PresidentialPardonForm Constructor void Called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    // std::cout << "PresidentialPardonForm Deconstructor void Called" << std::endl;   
}
PresidentialPardonForm::PresidentialPardonForm(const char *input) : AForm("PresidentialPardonForm Form", 25, 5)
{
    if(input == NULL)
    {
        target = "Unknow";
        // std::cout << "PresidentialPardonForm Constructor input "" Called" << std::endl;
    }    
    else
    {
        target = input;
    }  
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm &r_obj)
{
    (void)r_obj;
    return *this;
}

std::string PresidentialPardonForm::getTarget(void) const
{
    return target;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSigned())
        throw(std::runtime_error(executor.getName() + " couldn't executed " + this->getName()));
    std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}



// A -> print A
// B = A;
// A 
// B