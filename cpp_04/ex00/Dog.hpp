
#ifndef DOG_H
# define DOG_H
#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog(void);
	    Dog(Dog const &r_obj);
	    Dog & operator=(Dog const &r_obj);
	    ~Dog(void);
        void makeSound(void) const;
};

#endif