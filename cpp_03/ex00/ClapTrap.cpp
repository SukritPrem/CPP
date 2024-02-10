#include "ClapTrap.hpp"


ClapTrap::ClapTrap(void)
{
    std::cout << "create Class ClapTrap" << std::endl;
    ClapTrap::setAttackDamage(0);
    ClapTrap::setEnergyPoint(10);
    ClapTrap::setHitpoint(10);
    ClapTrap::setName("UnknowName");
}

ClapTrap::ClapTrap(std::string const &name)
{
    std::cout << "create Class ClapTrap" << std::endl;
    ClapTrap::setAttackDamage(0);
    ClapTrap::setEnergyPoint(10);
    ClapTrap::setHitpoint(10);
    ClapTrap::setName(name);   
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Decostructer Class ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &r_obj)
{
    setAttackDamage(r_obj.getAttackDamage());
    setEnergyPoint(r_obj.getEnergyPoint());
    setHitpoint(r_obj.getHitpoint());
    setName(r_obj.getName());
}

ClapTrap & ClapTrap::operator=(ClapTrap const &r_obj)
{
    if (this != &r_obj) 
    {
        setAttackDamage(r_obj.getAttackDamage());
        setEnergyPoint(r_obj.getEnergyPoint());
        setHitpoint(r_obj.getHitpoint());
        setName(r_obj.getName());
    }
	return (*this);   
}

void    ClapTrap::attack(const std::string & target)
{
    if(ClapTrap::getHitpoint() == 0 || ClapTrap::getEnergyPoint() == 0)
    {
        std::cout << "Can't attack." << std::endl;
        return;
    }  
    else
    {
        std::cout << "ClapTrap "<< ClapTrap::getName() <<  " attacks "  << target << ", causing " <<  ClapTrap::getAttackDamage() <<" points of damage!" << std::endl;
        ClapTrap::setEnergyPoint(ClapTrap::getEnergyPoint() - 1);  
    }    
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if(ClapTrap::getHitpoint() == 0 || ClapTrap::getEnergyPoint() == 0)
    {
        std::cout << "Can't take damage anymore." << std::endl;
        return;
    }  
    else
    {
        int check = getHitpoint() - amount;
        if(check < 0)
            ClapTrap::setHitpoint(0);
        else
            ClapTrap::setHitpoint(ClapTrap::getHitpoint() - amount);
        ClapTrap::setEnergyPoint(ClapTrap::getEnergyPoint() - 1);  
    } 
}

void    ClapTrap::myinfo(void)
{
        std::cout << "My name : " << ClapTrap::getName() <<std::endl;
        std::cout << "My Hp : " << ClapTrap::getHitpoint() << std::endl;
        std::cout << "My Energypoint : " << ClapTrap::getEnergyPoint() << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if(ClapTrap::getHitpoint() == 0 || ClapTrap::getEnergyPoint() == 0)
    {
        std::cout << "Can't take Repaired." << std::endl;
        return;
    }  
    else
    {
        int check = ClapTrap::getHitpoint() + amount;
        if(check < 0)
            ClapTrap::setHitpoint(0);
        else    
            ClapTrap::setHitpoint(check);
    
        ClapTrap::setEnergyPoint(ClapTrap::getEnergyPoint() - 1);  
    }
}

void    ClapTrap::setHitpoint(int value){_Hit_point = value;}
int     ClapTrap::getHitpoint(void) const{return _Hit_point;}

void    ClapTrap::setAttackDamage(int value){_acttack_damage = value;}
int     ClapTrap::getAttackDamage(void) const{return _acttack_damage;}

void    ClapTrap::setEnergyPoint(int value){_energy_point = value;}
int     ClapTrap::getEnergyPoint(void) const{return _energy_point;}

void    ClapTrap::setName(std::string name){ClapTrap::name = name;}
std::string ClapTrap::getName(void) const{return ClapTrap::name;}

        // void        setName(std::string name);
        // std::string getName(void) const;