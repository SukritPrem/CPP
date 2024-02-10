#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
int main(void)
{
    DiamondTrap My("test");
    // ScavTrap My("test");
    My.myinfo();
    My.whoAmi();
    My.attack("Some one.");
    My.myinfo();
    // My.attack("Some one");
    // My.myinfo();
    // My.beRepaired(1);
    // My.myinfo();
    // My.takeDamage(6);
    // My.myinfo();
    // My.guardGate();
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