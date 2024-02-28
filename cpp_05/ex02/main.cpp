#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
        // sucess created
        // Bureaucrat B_grade_negative("john",-1) ;// create not success grade is to hight
        // Bureaucrat B_grade_zero("john",0) ;//create not success grade is to hight
        // Bureaucrat B_grade_greade_to_low("john",151);//create not success

        // B.increment(10); //grade is to hight;
        // B.decrement(141); //grade is to low;
        // B.increment(9); // OK;
        // B.decrement(140); // OK:

        //Test ShrubberyFrom
        //success sigin 145 execute 137

        //this expect john can execute File_one
        try
        {
            Bureaucrat B("john",10);
            Shrubberycreationform File_one("File_one");
            File_one.beSigned(B);
            File_one.execute(B);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        //this expect john can't execute because not signed
        try
        {
            Bureaucrat B("john",10);
            Shrubberycreationform File_one("File_one");
            // std::cout << File_one.getSigned() << std::endl;
            // std::cout << File_one.getTarget() << std::endl;
            File_one.execute(B);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        //Test RobotomyRequest
        //success sigin 72 execute 45
        
        //case not besigned
        try
        {
            Bureaucrat B("john",10);
            RobotomyRequestform File_one("File_one");
            File_one.execute(B);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        //case signed already
        try
        {
            Bureaucrat B("john",10);
            RobotomyRequestform File_one("File_one");
            File_one.beSigned(B);
            File_one.execute(B);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        //Test PresidentialPardonForm
        //success sigin 25 execute 5

        //case not besigned
        try
        {
            Bureaucrat B("john",10);
            PresidentialPardonForm File_one("File_one");
            File_one.execute(B);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        //case signed already
        try
        {
            Bureaucrat B("john",10);
            PresidentialPardonForm File_one("File_one");
            File_one.beSigned(B);
            File_one.execute(B);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }    
    
    return (0);
}