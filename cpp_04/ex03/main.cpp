// #include "IMateriaSourse.hpp"
// #include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
int main(void)
{
    AMateria *test = new Ice();
    std::cout << test->getType() <<std::endl;
    IMateriaSource *test_materia = new MateriaSource();

    test_materia->learnMateria(new Ice());
    delete test_materia;
    delete test;
    return(0);
}