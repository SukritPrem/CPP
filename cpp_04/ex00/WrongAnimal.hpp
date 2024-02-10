#ifndef WRONGANIMAL_H
# define  WRONGANIMAL_H

#include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal(void);
	    WrongAnimal(WrongAnimal const &r_obj);
	    WrongAnimal & operator=(WrongAnimal const &r_obj);
	    virtual ~WrongAnimal(void);
        

        void setType(std::string type);
        std::string getType(void) const;

        void makeSound(void) const;
};

#endif