#include <iostream>
#include "Zombie.hpp"

int main(void)
{
    Zombie *test = zombieHorde(2, "HElllo");
    for(int i = 0; i < 2; i++)
    {
        test[i].announce();
    }
    delete[] test;
}