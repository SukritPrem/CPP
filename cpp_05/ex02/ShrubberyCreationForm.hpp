#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"
//shrubberycreationform test;
//test(target).creatForm;
//CreateFile();
//
class Shrubberycreationform : public AForm
{
    private:
        std::string     target;
    public:
        Shrubberycreationform(void);
        Shrubberycreationform(const char * input);
        ~Shrubberycreationform(void);
        // Shrubberycreationform & operator=(Shrubberycreationform &r_obj);

        void    createFormTarget(void);
        // void    fixRangeSignExecute(int sign,int execute);
        std::string getTarget(void) const;
        void     execute(Bureaucrat const & executor);
};











#endif