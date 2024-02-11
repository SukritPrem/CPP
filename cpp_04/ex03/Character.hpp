#ifndef CHARACTER_H
# define CHARACTER_H

#include "ICharacter.hpp"
#include "Floor.hpp"
#include <iostream>
#include "AMateria.hpp"
#ifndef LENGTH 
# define LENGTH 4
#endif
class Character :  public ICharacter
{
    private:
        std::string _name;
        AMateria    *_myMateria[LENGTH];
        Floor       floor;
        size_t      _idx;
    public:
        Character(void);
        ~Character(void);
        Character(std::string name);

        void    setName(std::string &name);
        std::string const & getName(void) const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target) ;

};

#endif