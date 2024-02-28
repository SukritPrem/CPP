#include "Bureaucrat.hpp"
#include "Form.hpp"
int main(void)
{
    try
    {
        Form b("Student Doc", 1, 10);
        Form d("test",1,2);
        // Form d(NULL, 150, 150);
        std::cout << b << std::endl;   
        std::cout << d << std::endl;
        std::cout << d;
        Bureaucrat bob("bob", 19);
        b.beSigned(bob);
        bob.signForm(b);
        bob.increment(10);
        std::cout << bob;
        b.beSigned(bob);
        bob.signForm(b);
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
    catch (const Form::GradeTooHighException& e)
    {
        std::cerr << "Form Exception : " << e.what() << std::endl;
    }
    catch (const Form::GradeTooLowException& e)
    {
        std::cerr << "Form Exception : " << e.what() << std::endl;
    }
    catch (const Form::StrNull& e)
    {
        std::cerr << "Form Exception : " << e.what() << std::endl;
    }
    return (0);
}