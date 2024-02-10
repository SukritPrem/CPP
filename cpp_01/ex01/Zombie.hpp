
#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie{
    private:
        std::string _name;
    public:
        Zombie(void);
        Zombie(std:: string name);
        ~Zombie(void);
        void announce( void );
        void    set_name(std:: string name);
        std::string get_name(void) const;
};

Zombie* zombieHorde(int N, std::string name);

#endif