#ifndef CLAPTARP_H
# define CLAPTARP_H
#include <iostream>

class ClapTrap{
    protected:
        int _Hit_point;
        int _energy_point;
        int _acttack_damage;
        std::string _name;
    public:
    	ClapTrap(void);
	    ClapTrap(std::string const &name);
	    ClapTrap(ClapTrap const &r_obj);
	    ClapTrap & operator=(ClapTrap const &r_obj);
	    ~ClapTrap();

        void    attack(const std::string & target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

        void    setHitpoint(int value);
        int     getHitpoint(void) const;

        void    setEnergyPoint(int value);
        int     getEnergyPoint(void) const;

        void    setAttackDamage(int value);
        int     getAttackDamage(void) const;

        void        setName(std::string name);
        std::string getName(void) const;

        void    myinfo(void);
};

#endif