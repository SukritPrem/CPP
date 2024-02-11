#ifndef AMATERIA_H
# define AMATERIA_H

#include <iostream>
#include "ICharacter.hpp"
class ICharacter;

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria(void);
        virtual ~AMateria(void);
        AMateria & operator=(AMateria & r_obj);
        AMateria(AMateria & r_obj);
        AMateria(std::string const & type);

        // size_t lenght(void)
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter & target);  
        // virtual void use(std::string & target);
};

#endif