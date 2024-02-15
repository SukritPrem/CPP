#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    try
    {
        // AForm b("Student Doc", 1, 10);
        // AForm d("test",1,2);
        Shrubberycreationform test("Hello");
        std::cout << test ;
        // Form d(NULL, 150, 150);
        // std::cout << b << std::endl;   
        // std::cout << d << std::endl;
        // std::cout << d;
        Bureaucrat bob("bob", 150);
        // test.execute(bob);
        test.beSigned(bob);
        bob.executeForm(test);
        std::cout << test.getTarget() << std::endl;
        // b.beSigned(bob);
        // bob.signForm(b);
        // bob.increment(10);
        // std::cout << bob;
        // b.beSigned(bob);
        // bob.signForm(b);
        // b.beSigned(bob);
        // d.beSigned(bob);
        // std::cout << d ;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Bureaucrat Exception : " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Bureaucrat Exception : " << e.what() << std::endl;
    }
    catch (const Bureaucrat::StrNull& e)
    {
        std::cerr << "Bureaucrat Exception : " << e.what() << std::endl;
    }
    catch (const AForm::GradeTooHighException& e)
    {
        std::cerr << "Form Exception : " << e.what() << std::endl;
    }
    catch (const AForm::GradeTooLowException& e)
    {
        std::cerr << "Form Exception : " << e.what() << std::endl;
    }
    catch (const AForm::StrNull& e)
    {
        std::cerr << "Form Exception : " << e.what() << std::endl;
    }
    return (0);
}