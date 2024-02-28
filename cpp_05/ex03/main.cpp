#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
int main(void)
{
    Bureaucrat  b1("Bureaucrat1", 1); 
    
    Intern      intern;
    //success execute shrubbery
    try
    {
        AForm *form = intern.makeForm("Shrubbery Form", "home");
        form->beSigned(b1); 
        b1.signForm(*form);
        b1.executeForm(*form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    //fail execute form shrubbery
    try
    {
        AForm *form = intern.makeForm("Shrubbery Form", "home");
        b1.signForm(*form);
        b1.executeForm(*form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    //sucess execute presidential
    try
    {
        AForm *form = intern.makeForm("PresidentialPardon Form", "home");
        form->beSigned(b1); 
        b1.signForm(*form);
        b1.executeForm(*form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    //fail execute presidential
    try
    {
        AForm *form = intern.makeForm("PresidentialPardon Form", "home"); 
        b1.signForm(*form);
        b1.executeForm(*form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    //success execute RobotomyRequest
    try
    {
        AForm *form = intern.makeForm("RobotomyRequest Form", "home"); 
        form->beSigned(b1); 
        b1.signForm(*form);
        b1.executeForm(*form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    //fail execute RobotomyRequest
    try
    {
        AForm *form = intern.makeForm("RobotomyRequest Form", "home"); 
        b1.signForm(*form);
        b1.executeForm(*form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return (0);
}