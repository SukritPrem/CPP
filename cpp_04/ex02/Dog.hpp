
#ifndef DOG_H
# define DOG_H
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain   *_Brain;
    public:
        Dog(void);
	    Dog(Dog const &r_obj);
	    Dog & operator=(Dog const &r_obj);
	    ~Dog(void);
        void makeSound(void) const;
        Brain & getmyBrain(void) const;
        // virtual void whatIsFistThingInMyHead(void) const;
};

#endif