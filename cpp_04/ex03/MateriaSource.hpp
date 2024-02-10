#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.hpp"
#include "Ice.hpp"
#define MATERIA_LENGTH  4

class MateriaSource : virtual public IMateriaSource
{
        private:
                size_t          _skillIndex;
                AMateria     *_aMateria[MATERIA_LENGTH] ;
        public:
                MateriaSource(void);
                ~MateriaSource(void);
                void learnMateria(AMateria*);
                AMateria* createMateria(std::string const & type);
};

#endif