#ifndef CAT_H
# define CAT_H
#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat(void);
	    Cat(Cat const &r_obj);
	    Cat & operator=(Cat const &r_obj);
	    ~Cat(void);

        void makeSound(void) const;
};

#endif