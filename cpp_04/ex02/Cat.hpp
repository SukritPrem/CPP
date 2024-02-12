#ifndef CAT_H
# define CAT_H
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    private:
        Brain   *_Brain;
    public:
        Cat(void);
	    Cat(Cat const &r_obj);
	    Cat & operator=(Cat const &r_obj);
	    ~Cat(void);

        void makeSound(void) const;
        Brain & getmyBrain(void) const;
        void getIdea(int idx) const;
        void setIdea(int idx,std::string newIdea) const;
};

#endif