#ifndef HUMANB_H
# define HUMANB_H
#include "Weapon.hpp"
#include <iostream>

class HumanB{
    private:
        std::string  _name;
        Weapon      *_weapone;
    public:
        ~HumanB(void);
        HumanB(std::string name);
        void    attack(void) const;
        void    setWeapon(Weapon &club);
        // std::string setType(std::string type);
};

#endif