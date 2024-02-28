#ifndef INTERN_H
# define INTERN_H

#include "AForm.hpp"
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    private:
        std::string _nameForm[3];
    public:
        Intern(void);
        ~Intern(void);
        Intern(Intern &r_obj);
        Intern & operator=(Intern &r_obj);

        AForm *makeForm(std::string const &nameForm,std::string const &target);
    class FailCreateForm : public std::exception
    {
        public:
            const char * what(void) const throw()
            {
                return "Fail create form.";
            }
    };
};
#endif
