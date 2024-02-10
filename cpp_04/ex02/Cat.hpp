#ifndef CAT_H
# define CAT_H
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain   *_Brain;
    public:
        Cat(void);
	    Cat(Cat const &r_obj);
	    Cat & operator=(Cat const &r_obj);
	    ~Cat(void);

        // void whatIsFistThingInMyHead(void) const;
        void makeSound(void) const;
        Brain & getmyBrain(void) const;
};

#endif