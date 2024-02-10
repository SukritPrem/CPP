#ifndef WRONGCAT_H
# define  WRONGCAT_H
#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongCat(void);
	    WrongCat(WrongCat const &r_obj);
	    WrongCat & operator=(WrongCat const &r_obj);
	    virtual ~WrongCat(void);
        

        void setType(std::string type);
        std::string getType(void) const;

         void makeSound(void) const;
};

#endif