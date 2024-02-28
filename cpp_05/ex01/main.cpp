#include "Bureaucrat.hpp"
#include "Form.hpp"
int main(void)
{
    try
    {
        Bureaucrat  b1("Bureaucrat1", 1); 
        Form        f1("Form1", 1, 1);
        
        f1.beSigned(b1);
        std::cout << f1;
        b1.signForm(f1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    };

    try
    {
        Bureaucrat  b1("Bureaucrat1", 1); 
        Form        f1("Form1", 1, 1);

        b1.signForm(f1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    };
    return (0);
}