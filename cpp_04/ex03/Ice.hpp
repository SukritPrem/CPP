#ifndef ICE_H
# define ICE_H

#include "AMateria.hpp"



class Ice: virtual public AMateria
{
    public:
        Ice(void);
        ~Ice(void);
        Ice(Ice & r_obj);
        Ice & operator=(Ice & r_obj);
    //    virtual AMateria* clone() const = 0;
        AMateria* clone(void) const;
        void use(ICharacter & target);  
};

#endif