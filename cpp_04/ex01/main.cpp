#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

int main(void)
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    Animal a;
    Animal b;
    a = b;
    a.makeSound();
    // std::cout << j << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound();
    std::cout << i << std::endl;
    std::cout << j <<std::endl;
    delete j;//should not create a leak
    delete i;
    return 0;
}