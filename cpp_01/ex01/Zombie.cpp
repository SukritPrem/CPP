#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name)
{
    std::cout << "create constructer" << std::endl;
}
Zombie::Zombie(void)
{
    _name = "NULL";
}

void    Zombie::set_name(std::string name){_name = name;}

Zombie::~Zombie(void)
{
    std::cout << "Deconstructer" << std::endl;
}

std::string    Zombie::get_name(void) const{return _name;}

void    Zombie::announce(void)
{
    std::cout << Zombie::get_name() << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}