#ifndef ANIMAL_H
# define  ANIMAL_H

#include <iostream>
#include "Brain.hpp"
class Animal
{
    protected:
        std::string _type;
    public:
        Animal(void);
        // ~Animal(void);
	    Animal(Animal const &r_obj);
	    Animal & operator=(Animal const &r_obj);
	    virtual ~Animal(void);
        

        void setType(std::string type);
        std::string getType(void) const;
        virtual void makeSound(void) const;
        // Brain getmyBrain(void) const;
        // virtual void whatIsFistThingInMyHead(void) const;
};

#endif