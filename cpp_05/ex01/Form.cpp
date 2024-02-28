#include "Form.hpp"

Form::Form(void):  _nameStr("UnknowName"),
                    _name("UnknowName"),
                    _signed(false),
                    _gradeSignein(0),
                    _gradeExecute(0)
{
    std::cout << "Form Constructor void Called " << std::endl;
}

Form::~Form(void)
{
    std::cout << "Form Deconstructor Called " << std::endl;
}

Form::Form(Form &r_obj) : _nameStr(r_obj.getName()),
                            _signed(r_obj.getSigned()),
                            _gradeSignein(r_obj.getGradeSignein()),
                            _gradeExecute(r_obj.getGradeExecute())
{
    std::cout << "Form Copy Constructor Called " << std::endl; 
}

void    Form::beSigned(Bureaucrat &obj)
{
    try
    {
        if(obj.getGrade() > _gradeSignein && obj.getGrade() > _gradeExecute){
            throw GradeTooLowException();
        }
        else 
            _signed = true;
    }
    catch (const Form::GradeTooLowException& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream &o, Form &r_obj)
{
    o << "Form Name : " << r_obj.getName() << std::endl
    <<  "Sign : " << r_obj.getSigned() << std::endl
    <<  "Grade Signin : " << r_obj.getGradeSignein() << std::endl
    <<  "Grade Execute : " << r_obj.getGradeExecute() << std::endl;
    return o;
}
// Form & operator=(Form &r_obj);
// Form(Form &r_obj);

Form::Form(const char *ptr,
        int gradeSignein,
        int gradeExecute) :
        _name(ptr),
        _gradeSignein(gradeSignein),
        _gradeExecute(gradeExecute)
{
    if(_name == NULL)
        throw StrNull();
    else
        _nameStr = _name;

    if(gradeExecute < Bureaucrat::gradeMax || gradeSignein < Bureaucrat::gradeMax)
    {
        throw GradeTooHighException();
    }
    else if(gradeExecute > Bureaucrat::gradeMin || gradeSignein > Bureaucrat::gradeMin)
    {
        throw GradeTooLowException();
    }
    std::cout << "Form Constructor name signed gradesignein gradeexecute Called " << std::endl;
}

std::string    Form::getName(void){return _nameStr;}
bool    Form::getSigned(void) const{return _signed;}
int Form::getGradeSignein(void) const{return _gradeSignein;}
int Form::getGradeExecute(void) const{return _gradeExecute;}


