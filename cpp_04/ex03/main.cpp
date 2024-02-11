// #include "IMateriaSourse.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
int main(void)
{
    AMateria *test = new Ice();
    std::cout << test->getType() <<std::endl;
    IMateriaSource *src = new MateriaSource();
    IMateriaSource *src_1 = new MateriaSource();
    ICharacter *person = new Character("person1");

    AMateria *tmp;
    tmp = NULL;
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());
    src_1->learnMateria(new Ice());
    src_1->learnMateria(new Ice());
    tmp = src->createMateria("ice");
    std::cout <<"testtmp" << tmp->getType() <<std::endl;
    person->equip(tmp);
    person->equip(src->createMateria("ice"));
    person->equip(src->createMateria("ice"));
    person->equip(src->createMateria("ice"));
    person->equip(src->createMateria("ice"));
    person->equip(src->createMateria("ice"));
    person->unequip(5);
    // person->equip(src->createMateria("ice"));
    // person->equip(src->createMateria("ice"));
    // person->equip(src->createMateria("ice"));
    // person->equip(src->createMateria("ice"));
    std::cout << tmp << std::endl;
    person->equip(tmp);
    person->equip(tmp);
    person->unequip(0);
    // person->use(0,)
    // person->equip(tmp);
    // person->equip(tmp);
    // person->equip(tmp);
    // person->equip(tmp);
    ICharacter *person2 = new Character("person2");
    person2->equip(tmp);
    person2->use(0, *person);
    delete src;
    delete test;
    delete person;
    delete src_1;
    delete person2;
    return(0);
}