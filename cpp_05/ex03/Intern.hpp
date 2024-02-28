#ifndef INTERN_H
# define INTERN_H

#include "AForm.hpp"
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern(void);
        ~Intern(void);
        Intern(Intern &r_obj);
        Intern & operator=(Intern &r_obj);

        AForm *makeForm(std::string const &nameForm,std::string const &target);
};
#endif
