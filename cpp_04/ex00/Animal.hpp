#ifndef ANIMAL_H
# define  ANIMAL_H

#include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal(void);
	    Animal(Animal const &r_obj);
	    Animal & operator=(Animal const &r_obj);
	   ~Animal(void);
        

        void setType(std::string type);
        std::string getType(void) const;

         void makeSound(void) const;
};

#endif