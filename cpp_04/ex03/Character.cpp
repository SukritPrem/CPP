
#include "Character.hpp"

Character::Character(void)
{
    _name = "UnknowName";
    _idx = 0;
    for(int i = 0; i < LENGTH; i++)
        _myMateria[i] = NULL;
    std::cout << "Character constructor void called" <<std::endl;
}

Character::~Character(void)
{
    std::cout << "Hi" <<std::endl;
    for(int i = 0; i < LENGTH; i++)
    {
        if(_myMateria[i] != NULL)
        {
            delete _myMateria[i];
            _myMateria[i] = NULL;
        }    
    }
    std::cout << "Character Deconstructor void called" <<std::endl;
}

Character::Character(std::string name)
{
    _name = name;
    _idx = 0;
    for(int i = 0; i < LENGTH; i++)
        _myMateria[i] = NULL;
}

void    Character::setName(std::string &name)
{
    _name = name;
}

std::string const & Character::getName(void) const
{
    return (_name);
}


void    Character::use(int idx, ICharacter & target)
{
        std::cout << _myMateria[idx] << std::endl;    
    if(idx < LENGTH && idx >= 0 && _myMateria[idx] != NULL)
        _myMateria[idx]->use(target);
}

void Character::equip(AMateria* m)
{
    if(m == NULL)
        return ;
    for(int i = 0;i < LENGTH; i++)
    {
        if(m == floor.getFromFloor(m) && _myMateria[i] == NULL)
        {
            std::cout << "pick up floor from idx " << floor.getFromFloor(m) << std::endl;
            _myMateria[i] = m;
            return;
        }
    }
    for(int i = 0;i < LENGTH; i++)
    {
        std::cout << i << std::endl;
        // std::cout << m->getType() << std::endl;
        if(_myMateria[i] && _myMateria[i] == m)
        {
                std::cout << "myMateria address " << _myMateria[i] \
                        << " m " << m <<" already exist" << std::endl;
                return;
        }
        if(_myMateria[i] == NULL && m != NULL)
        {
            _myMateria[i] = m;
            // floor.setFloor(*m);
            return;
        } 
    }

    // delete m;
    if(m != NULL)
        floor.setFloor(*m);
    // (void)m;
}

void Character::unequip(int idx)
{
    if(idx >= 0 && idx < LENGTH)
    {
        for(int i = 0; i < LENGTH; i++)
        {
            if(i == idx && _myMateria[i] != NULL)
            {
                floor.setFloor(*_myMateria[i]);
                _myMateria[i] = NULL;
                std::cout << std::endl;
                std::cout << "myMateria " << _myMateria[i] <<std::endl;
            }
        }
    }
    else
        std::cout << "Is outside index " << std::endl;
}