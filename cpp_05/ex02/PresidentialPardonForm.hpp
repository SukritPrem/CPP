#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string     target;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const char * input);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm & operator=(PresidentialPardonForm &r_obj);

        std::string getTarget(void) const;
        void    execute(Bureaucrat const & executor) const;
        class FailCreateForm : public std::exception
        {
            public:
                const char * what(void) const throw()
                {
                    return "Fail create form";
                }
        };
};

#endif