#ifndef AFORM_H
# define AFORM_H

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>
class Bureaucrat;

class AForm
{
    private:
        std::string   _nameStr;
        const char            *_name;
        bool                _signed;
        const int           _gradeSignein;
        const int           _gradeExecute;
    public:
        AForm(void);
        virtual ~AForm(void);
        AForm(AForm &r_obj);
        AForm(const char *ptr,
                int gradeSignein,
                int gradeExecute);
        void        beSigned(Bureaucrat &obj);

        // void        setGradeSignIn(int gradSignin);
        // void        setGradeExecute(int gradExecute);
        void        setSigned(bool sign);
        std::string getName(void) const;
        bool        getSigned(void) const;
        int   getGradeSignein(void) const;
        int   getGradeExecute(void) const;
        bool       checkGradeExecutor(Bureaucrat const & executor) const;


        virtual void   execute(Bureaucrat const & executor) const = 0;

        // virtual void    fixRangeSignExecute(int sign,int execute) = 0;
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
        class NotBeSigned : public std::exception
        {
            public:
                const char * what(void) const throw()
                {
                    return "Not Be signed";
                }
        };
};

std::ostream& operator<<(std::ostream &o, AForm &r_obj);
// AForm::GradeTooLowException::~GradeTooLowException() noexcept {};
#endif