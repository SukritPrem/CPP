#ifndef FLOOR_H
# define FLOOR_H
#include "AMateria.hpp"
#ifndef LENGTH 
# define LENGTH 4
#endif

class Floor
{
    private:
        static AMateria * _floor[LENGTH];
        static size_t      _floorSize;
    public:
        Floor(void);
        ~Floor(void);
        Floor & operator=(Floor & r_obj);
        Floor(Floor & r_obj);

        AMateria * getFromFloor(AMateria *m);
        // void    setFloorIdxNull(size_t i);
        void    setFloor(AMateria & m);
        AMateria * getFloor(size_t i);
};

// AMateria* Floor::_floor[LENGTH] = {NULL}; // Initialize all elements to nullptr
// size_t Floor::_floorSize = 0;
#endif