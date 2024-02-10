#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
//const Animal* meta = new Animal();
// const Dog *j =  new Dog();
const Animal *i =  new  Dog();
// // const Dog *z = new Dog();
// const WrongAnimal *wrongcat = new WrongCat();

// wrongcat->makeSound();
// std::cout << sizeof(i) <<std::endl;
// std::cout << sizeof(j) <<std::endl;
// std::cout << j->getType() << " " << std::endl;
// std::cout << i->getType() << " " << std::endl;
//i->makeSound(); //will output the cat sound!
// j->makeSound();
//meta->makeSound();
//delete meta;
// delete j;
delete i;
// delete wrongcat;
}