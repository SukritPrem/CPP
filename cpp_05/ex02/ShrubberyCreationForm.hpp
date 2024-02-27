#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"

class Shrubberycreationform : public AForm
{
    private:
        std::string     target;
        void    createFormTarget(void) const;
    public:
        Shrubberycreationform(void);
        Shrubberycreationform(const char * input);
        ~Shrubberycreationform(void);
        Shrubberycreationform & operator=(Shrubberycreationform &r_obj);

        std::string getTarget(void) const;
        void    execute(Bureaucrat const & executor) const;
};











#endif