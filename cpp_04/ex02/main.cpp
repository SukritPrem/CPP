#include "Cat.hpp"
#include "Dog.hpp"
#include "AAnimal.hpp"
#include "unistd.h"
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

    // const Cat * meta_1 = new Cat ();
    // Cat * j_1 = new Cat ();
    // Cat * j_2 = new Cat();
    // *j_1 = *meta_1;
    // std::cout << j_1->getType() << " " << std::endl;
    // j_1->getIdea(0);
    // j_2->getIdea(0);
    // j_1->setIdea(-1,"Ha Ha Ha");
    // j_1->getIdea(-1);
    // j_2->getIdea(99);
    // *j_2 = *j_1;
    // j_1->getIdea(99);
    // j_2->getIdea(99);

    const Dog  * meta_1 = new Dog  ();
    Dog * j_1 = new Dog  ();
    Dog * j_2 = new Dog ();
    *j_1 = *meta_1;
    std::cout << j_1->getType() << " " << std::endl;
    j_1->getIdea(0);
    j_2->getIdea(0);
    j_1->setIdea(1,"Ha Ha Ha");
    j_1->getIdea(1);
    j_2->getIdea(1);
    *j_2 = *j_1;
    j_1->getIdea(1);
    j_2->getIdea(1);
    
    delete meta_1;
    delete j_1;
    delete j_2;
}