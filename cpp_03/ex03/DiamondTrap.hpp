#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;
    public:
        DiamondTrap(const std::string& name);
        ~DiamondTrap(void);

        using ScavTrap::attack;
        void whoAmi(void);      
};

#endif