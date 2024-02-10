#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string const &name) : ClapTrap()
{
    std::cout << "create Class ScavTrap" << std::endl;
    // ClapTrap::setHitpoint(100);
    // ClapTrap::setName(name);
    // ClapTrap::setEnergyPoint(50);
    // ClapTrap::setAttackDamage(20);
    _Hit_point = 100;
    _name = name;
    _energy_point = 50;
    _acttack_damage = 20;
}

ScavTrap::~ScavTrap(void){
    std::cout << "Decostructer Class ScavTarp" << std::endl;
}

void    ScavTrap::guardGate(void)
{
    if(ClapTrap::getHitpoint() == 0 || ClapTrap::getEnergyPoint() == 0)
    {
        std::cout << "Can't GuardGate." << std::endl;
        return;
    }  
    else
    {
        std::cout << ClapTrap::getName() << " open GuardGate." << std::endl;
        ClapTrap::setEnergyPoint(ClapTrap::getEnergyPoint() - 1);  
    } 
}

void    ScavTrap::attack(const std::string & target)
{
    if(ClapTrap::getHitpoint() == 0 || ClapTrap::getEnergyPoint() == 0)
    {
        std::cout << "Can't attack." << std::endl;
        return;
    }  
    else
    {
        std::cout << "ScavTrap "<< ScavTrap::getName() <<  " attacks "  << target << ", causing " <<  ClapTrap::getAttackDamage() <<" points of damage!" << std::endl;
        ClapTrap::setEnergyPoint(ClapTrap::getEnergyPoint() - 1);  
    }    
}