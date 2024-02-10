#include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie clone(name);
    clone.announce();
}