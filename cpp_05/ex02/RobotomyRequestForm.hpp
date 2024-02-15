#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"

class RobotomyRequestform : public AForm
{
    private:
        std::string     target;
    public:
        RobotomyRequestform(void);
        RobotomyRequestform(const char * input);
        ~RobotomyRequestform(void);
        // RobotomyRequestform & operator=(RobotomyRequestform &r_obj);

        std::string getTarget(void) const;
        void     execute(Bureaucrat const & executor);
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