#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
class AForm;
#include "AForm.hpp"
#define GRADE_MAX 1
#define GRADE_MIN 150

class Bureaucrat
{
    private:
        const char * _name;
        std::string  _nameStr;
        int     _grade;
        void checkStrNameIsNull(const char *name);
        int  checkGrade(int grade);
        void    setGrade(int grade);
    public:
        Bureaucrat(void);
        ~Bureaucrat(void);
        Bureaucrat(const char * name,int grade);
        Bureaucrat(Bureaucrat &r_obj);
        Bureaucrat & operator=(Bureaucrat &r_obj);


        std::string const getName(void) const;
        int getGrade(void) const;

        void    increment(int number);
        void    decrement(int number);
        void    executeForm(AForm const & form);
        void    signForm(AForm &obj);
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

std::ostream& operator<<(std::ostream &o, Bureaucrat &r_obj);
#endif