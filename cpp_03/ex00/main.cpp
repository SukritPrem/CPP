#include "ClapTrap.hpp"


int main(void)
{
    ClapTrap My("Prem");

    My.myinfo();
    My.attack("Some one");
    My.myinfo();
    My.beRepaired(1);
    My.myinfo();
    My.takeDamage(200);
    My.myinfo();
    My.beRepaired(1);
}