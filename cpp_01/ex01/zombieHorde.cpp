#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if(N <= 0)
    {
        std::cout << "ERROR N" << std::endl;
        return (NULL);
    }
    Zombie *clone = new Zombie[N];
    for(int i = 0; i < N ; i++)
    {
        clone[i].set_name(name);
    }
    return clone;
}