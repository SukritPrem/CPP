#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : ScavTrap(name), FragTrap(name){

    _name = name;
    ClapTrap::setName(name + "_clap_name");
    ClapTrap::setHitpoint(FragTrap::getHitpoint());
    ClapTrap::setEnergyPoint(50);
    ClapTrap::setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "Decostructer Class Diamond" << std::endl;
}

void    DiamondTrap::whoAmi(void)
{
    std::cout << "My name : " << _name << std::endl;
    std::cout << "I have anther name is : " << ClapTrap::_name << std::endl;
}
