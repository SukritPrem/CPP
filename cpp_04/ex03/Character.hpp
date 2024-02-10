#ifndef CHARACTER_H
# define CHARACTER_H

#include "ICharacter.hpp"
#define LENGTH 4
class Character : virtual public ICharacter
{
    private:
        std::string name;
        AMateria * _myMateria[LENGTH];
    public:
        Character(void);
        ~Character(void);
        Character(Character & name);

        void    setName(std::string &name);
        std::string const & getName(void) const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target) ;

};

#endif