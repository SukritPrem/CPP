#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const &name)
{
    std::cout << "create Class FragTrap" << std::endl;
    // setHitpoint(100);
    // setName(name);
    // setEnergyPoint(100);
    // setAttackDamage(30);
    _Hit_point = 100;
    _name = name;
    _energy_point = 100;
    _acttack_damage = 30;
}

FragTrap::~FragTrap(void){
    std::cout << "Decostructer Class FragTarp" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTarp highfivesguys" << std::endl;   
}
