#ifndef BRAIN_H
# define  BRAIN_H
#include <iostream>
#include <ctime>
#include <cstdlib>

class Brain
{
    public:
        Brain(void);
        ~Brain(void);
	    Brain(Brain const &r_obj);
        Brain & operator=(Brain const &r_obj);
        std::string ideas[100];
        std::string getIdea(void) const;
        // std::string getFirstIdea(void) const;
};

#endif