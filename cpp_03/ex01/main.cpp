#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap My("Prem");

    My.myinfo();
    My.attack("Some one");
    My.myinfo();
    My.beRepaired(1);
    My.myinfo();
    My.takeDamage(6);
    My.myinfo();
    My.guardGate();
    My.myinfo();
}

// A   A
// |   |
// B   C
// \   /
//   D

//   A
// /   \
// B   C
// \   /
//   D