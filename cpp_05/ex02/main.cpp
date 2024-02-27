#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat B("john",10);// sucess created
        // Bureaucrat B_grade_negative("john",-1) ;// create not success grade is to hight
        // Bureaucrat B_grade_zero("john",0) ;//create not success grade is to hight
        // Bureaucrat B_grade_greade_to_low("john",151);//create not success

        // B.increment(10); //grade is to hight;
        // B.decrement(141); //grade is to low;
        // B.increment(9); // OK;
        // B.decrement(140); // OK:

        //Test ShrubberyFrom
        //success sigin 145 execute 137
        AForm *test = new Shrubberycreationform ("tree_file"); 
        // File_one.beSigned(B); //B can signed. B is 10.
        // File_one.execute(B); //B can execute. B is 10.
        // B.signForm(File_one);
        // B.executeForm(*test);
        test->beSigned(B);
        B.executeForm(*test);
        // B.decrement(136); // B 
        // File_one.beSigned(B); //B can't signed. B is 146.
        // File_one.execute(B); //B can execute. B is 146.

        //Test RobotomyRequestFrom

        // std::cout << File_one <<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}