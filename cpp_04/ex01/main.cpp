#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

int main(void)
{
    // const Animal* meta = new Animal();
    // Animal* j = new Animal();

    // *j = *meta;
    // std::cout << j->getType() << " " << std::endl;
    // j->whatIsFistThingInMyHead();
    // j->makeSound();
    // meta->makeSound();
    // // std::cout << j << std::endl;
    // // std::cout << meta << std::endl;
    // delete meta;
    // delete j;

    const Cat * meta_1 = new Cat ();
    Cat * j_1 = new Cat ();

    *j_1 = *meta_1;
    std::cout << j_1->getType() << " " << std::endl;
    j_1->whatIsFistThingInMyHead();
    meta_1->whatIsFistThingInMyHead();
    j_1->makeSound();
    meta_1->makeSound();
    delete meta_1;
    delete j_1;
}