#include "Bureaucrat.hpp"

int Bureaucrat::gradeMax = 1;
int Bureaucrat::gradeMin = 150;

Bureaucrat::Bureaucrat(void) : _name("Unknow"),_nameStr("Unknow"),_grade(150)
{
    std::cout << "Bureaucrat constructor void called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat &r_obj)
{
    if(this != &r_obj)
    {
        _grade = r_obj.getGrade();
    }
    return (*this);   
}

void    Bureaucrat::executeForm(AForm const & form)
{
    if(form.getSigned())
    {
        std::cout << getName() << " executed " << form.getName() << std::endl;
    }
    else
        std::cout << getName() << " Can't executed " << form.getName() << std::endl;
    
}

Bureaucrat::Bureaucrat(const char * name, int grade) : _name(name)
{
    // std::cout << "Hello" <<std::endl;
    if(_name == NULL)
        throw StrNull();
    else
    {
        _nameStr = name;
    }
    
    if(grade > gradeMin)
        throw GradeTooLowException();
    else if(grade < gradeMax)
        throw GradeTooHighException();
    else
        _grade = grade;
    std::cout << "Bureaucrat constructor name grade called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat Deconstructor void called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &r_obj)
{
    if(this != &r_obj)
    {
        _grade = r_obj.getGrade();
    }
}

void    Bureaucrat::increment(int number)
{
    int checkGrade = _grade - number;
    try
    {
        if(checkGrade < gradeMax)
            throw GradeTooHighException();
        else if(checkGrade > gradeMin)
            throw GradeTooLowException();
        else
            _grade = checkGrade;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
}

void Bureaucrat::signForm(AForm &obj)
{
    if(obj.getSigned())
        std::cout << _name << " signed " << obj.getName() << std::endl;
    else if(obj.getSigned() == 0)
    {
        std::cout << _name << " couldn't sign " << obj.getName() << " because ";
        std::cout << "the signature isn't true?" << std::endl;
    }
}

void    Bureaucrat::decrement(int number)
{
    int checkGrade = _grade + number;
    try
    {
        if(checkGrade < gradeMax)
            throw GradeTooHighException();
        else if(checkGrade > gradeMin)
            throw GradeTooLowException();
        else
            _grade = checkGrade;
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
}

int Bureaucrat::getGrade(void) const {return _grade;}
std::string const Bureaucrat::getName(void) const {return _nameStr;}

std::ostream& operator<<(std::ostream &o, Bureaucrat &r_obj)
{
    o << r_obj.getName() << ", bureaucrat grade " << r_obj.getGrade() << std::endl;
    return o;
}