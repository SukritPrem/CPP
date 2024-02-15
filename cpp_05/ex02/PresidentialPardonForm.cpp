#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm Form", 25, 5) , target("Unknow")
{
    std::cout << "PresidentialPardonForm Constructor void Called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm Deconstructor void Called" << std::endl;   
}
PresidentialPardonForm::PresidentialPardonForm(const char *input) : AForm("PresidentialPardonForm Form", 25, 5)
{
    if(input == NULL)
    {
        target = "Unknow";
        std::cout << "PresidentialPardonForm Constructor input "" Called" << std::endl;
    }    
    else
    {
        target = input;
    }  
}

std::string PresidentialPardonForm::getTarget(void) const
{            // throw FailCreateForm();
    return target;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor)
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