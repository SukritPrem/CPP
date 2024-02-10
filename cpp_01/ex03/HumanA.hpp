#ifndef HUMANA_H
# define HUMANA_H
#include "Weapon.hpp"
#include <iostream>

class HumanA{
    private:
        std::string  _name;
        Weapon      &_weapone;
    public:
        ~HumanA(void);
        HumanA(std::string name, Weapon &club);
        void    attack(void) const;
};

#endif