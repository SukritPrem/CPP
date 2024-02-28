#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
class Bureaucrat
{
    private:
        const char * _name;
        std::string  _nameStr;
        int     _grade;
    public:
        static int gradeMax;
        static int gradeMin;
        Bureaucrat(void);
        ~Bureaucrat(void);
        Bureaucrat(std::string hi);
        Bureaucrat(const char * name,int grade);
        Bureaucrat(Bureaucrat &r_obj);
        Bureaucrat & operator=(Bureaucrat &r_obj);


        std::string const getName(void) const;
        int getGrade(void) const;

        // void setName(std::string name);
        // void    setGrade(int grade);
        void    increment(int number);
        void    decrement(int number);
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