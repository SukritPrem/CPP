#include "Bureaucrat.hpp"



Bureaucrat::Bureaucrat(void) : _name("Unknow"),_nameStr("Unknow"),_grade(150)
{
    // std::cout << "Bureaucrat constructor void called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat &r_obj)
{
    if(this != &r_obj)
    {
        _grade = r_obj.getGrade();
    }
    return (*this);   
}



Bureaucrat::Bureaucrat(const char * name, int grade) : _name(name)
{

    checkStrNameIsNull(name);
    setGrade(checkGrade(grade));
    // std::cout << "Bureaucrat constructor name grade called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
    // std::cout << "Bureaucrat Deconstructor void called" << std::endl;
}


Bureaucrat::Bureaucrat(Bureaucrat &r_obj)
{
    if(this != &r_obj)
    {
        _grade = r_obj.getGrade();
    }
}

int  Bureaucrat::checkGrade(int grade)
{
    if(grade > GRADE_MIN)
        throw GradeTooLowException();
    else if(grade < GRADE_MAX)
        throw GradeTooHighException();
    else
        return grade;
}

void    Bureaucrat::checkStrNameIsNull(const char * name)
{
    if(_name == NULL)
        throw StrNull();
    else
        _nameStr = name; 
}

void    Bureaucrat::increment(int number)
{
    int checkGrade = _grade - number;
    if(checkGrade < GRADE_MAX)
        throw GradeTooHighException();
    else if(checkGrade > GRADE_MIN)
        throw GradeTooLowException();
    else
        setGrade(checkGrade);
}

void    Bureaucrat::decrement(int number)
{
    int checkGrade = _grade + number;
        if(checkGrade < GRADE_MAX)
            throw GradeTooHighException();
        else if(checkGrade > GRADE_MIN)
            throw GradeTooLowException();
        else
            _grade = checkGrade;
}

void Bureaucrat::setGrade(int grade){ _grade = grade;}
int Bureaucrat::getGrade(void) const {return _grade;}
std::string const Bureaucrat::getName(void) const {return _nameStr;}

std::ostream& operator<<(std::ostream &o, Bureaucrat &r_obj)
{
    o << r_obj.getName() << ", bureaucrat grade " << r_obj.getGrade() << std::endl;
    return o;
}

void Bureaucrat::signForm(Form &obj)
{
    if(obj.getSigned())
        std::cout << _name << " signed " << obj.getName() << std::endl;
    else if(obj.getSigned() == 0)
    {
        std::string meassage = " couldn't sign " + obj.getName();
        throw (std::runtime_error(_name + meassage));
    }
}