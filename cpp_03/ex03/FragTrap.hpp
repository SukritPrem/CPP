#ifndef FRAGTARP_H
# define FRAGTARP_H
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap(std::string const &name);
        ~FragTrap(void);

        void highFivesGuys(void);
};

#endif