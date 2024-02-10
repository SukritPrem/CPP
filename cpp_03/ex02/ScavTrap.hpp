#ifndef SCAVTARP_H
# define SCAVTARP_H
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(std::string const &name);
        ~ScavTrap(void);
        void guardGate(void);

        void    attack(const std::string & target);
};

#endif