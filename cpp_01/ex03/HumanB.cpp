#include "HumanB.hpp"

HumanB::~HumanB(void){}

HumanB::HumanB(std::string name)
{
    _weapone = NULL;
    _name = name;
}

void    HumanB::attack(void) const{
    if(_weapone)
        std::cout << _name << " attacks with their " << _weapone->getType() <<std::endl;
    else
        std::cout << _name << " I can't attack. " << std::endl;
}

void    HumanB::setWeapon(Weapon &club)
{
    _weapone = &club;
}