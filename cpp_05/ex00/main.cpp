#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        // std::string test1 = NULL;
        Bureaucrat b("john", 19);

        // Bureaucrat d(NULL,0);
        std::cout << b << std::endl;
        b.increment(8);
        std::cout << b ;
        b.increment(11);
        std::cout << b;
        b.decrement(11);
        std::cout << b;
        b.decrement(1234);
        std::cout << b;
        std::cout << b.getName() << std::endl;
        // std::cout << b << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
    catch (const Bureaucrat::StrNull& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
    return (0);
}