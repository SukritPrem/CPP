
#ifndef DOG_H
# define DOG_H
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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
        void getIdea(int idx) const;
        void setIdea(int idx,std::string newIdea) const;
        // virtual void whatIsFistThingInMyHead(void) const;
};

#endif