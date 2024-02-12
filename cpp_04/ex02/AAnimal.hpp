#ifndef AANIMAL_H
# define  AANIMAL_H

#include <iostream>
#include "Brain.hpp"
class AAnimal
{
    protected:
        std::string _type;
    public:
        AAnimal(void);
	    AAnimal(AAnimal const &r_obj);
	    AAnimal & operator=(AAnimal const &r_obj);
	    virtual ~AAnimal(void);
        

        void setType(std::string type);
        std::string getType(void) const;
        virtual void makeSound(void) const;
        // Brain getmyBrain(void) const;
        // virtual void whatIsFistThingInMyHead(void) const;
};

#endif