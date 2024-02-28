#ifndef FORM_H
# define FORM_H

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>
class Bureaucrat;

class Form
{
    private:
        std::string   _nameStr;
        const char            *_name;
        bool                _signed;
        const int           _gradeSignein;
        const int           _gradeExecute;
    public:
        Form(void);
        ~Form(void);
        Form(Form &r_obj);

        Form(const char *ptr,
                int gradeSignein,
                int gradeExecute);
        void        beSigned(Bureaucrat &obj);
        std::string getName(void);
        bool        getSigned(void) const;
        int   getGradeSignein(void) const;
        int   getGradeExecute(void) const;
        
        class GradeTooHighException : public std::exception
        {
            public:
                const char * what(void) const throw()
                {
                    return "Grade is too high";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char * what(void) const throw()
                {
                    return "Grade is too low";
                }
        };
        class StrNull : public std::exception
        {
            public:
                const char * what(void) const throw()
                {
                    return "string is null";
                }
        };
};

std::ostream& operator<<(std::ostream &o, Form &r_obj);
// Form::GradeTooLowException::~GradeTooLowException() noexcept {};
#endif