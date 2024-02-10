#include "HumanA.hpp"

HumanA::~HumanA(void){}

HumanA::HumanA(std::string name,Weapon &club): _name(name), _weapone(club){}

void    HumanA::attack(void) const{
    std::cout << _name << " attacks with their " << _weapone.getType() <<std::endl;

}