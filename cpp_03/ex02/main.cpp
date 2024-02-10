#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ScavTrap My("Prem");
    FragTrap My1("eiei");
    // My1.myinfo();
    // My.myinfo();
    // My.attack("Some one");
    // My.myinfo();
    // My.beRepaired(1);
    // My.myinfo();
    // My.takeDamage(6);My.takeDamage(1116);My.takeDamage(6);
    // My.myinfo();
    // My.guardGate();
    My1.myinfo();
    My1.attack("Some one");
    My1.myinfo();
    My1.beRepaired(1);
    My1.myinfo();
    My1.takeDamage(6);My.takeDamage(1116);My.takeDamage(6);
    My1.myinfo();
    My1.highFivesGuys();
    My1.myinfo();
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