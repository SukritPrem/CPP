
#include "Floor.hpp"


AMateria* Floor::_floor[LENGTH] = {NULL}; // Initialize all elements to nullptr
size_t Floor::_floorSize = 0;

Floor::Floor(void)
{
    std::cout << "Floor constructor void called" <<std::endl;
}

Floor::~Floor(void)
{
    std::cout << "Hi" <<std::endl;
    for(int i = 0; i < LENGTH; i++)
    {
        if(_floor[i] != NULL)
        { 
            delete _floor[i];
            _floor[i] = NULL;
        }     
    }
    std::cout << "Floor Deconstructor void called" <<std::endl; 
}

Floor & Floor::operator=(Floor & r_obj)
{
    if(this != &r_obj)
    {
        for(size_t i = 0; i < r_obj._floorSize; i++)
            _floor[i] = r_obj._floor[i];
        _floorSize = r_obj._floorSize;
    }    
    return (*this);
}

Floor::Floor(Floor & r_obj)
{
    for(size_t i = 0; i < r_obj._floorSize; i++)
        _floor[i] = r_obj._floor[i];
    _floorSize = r_obj._floorSize;
}

void    Floor::setFloor(AMateria & m)
{
    if(_floorSize == LENGTH)
    {
        for(size_t i = 0; i < _floorSize; i++)
        {
            if(_floor[i] != NULL)
            {
                delete _floor[i];
                _floor[i] = NULL;
            }   
        }    
        _floorSize = 0;
    }
    std::cout << "index floor" << _floorSize << std::endl;
    if(_floor[_floorSize] == NULL)
        _floor[_floorSize] = &m;
    else
    {
        delete _floor[_floorSize];
        _floor[_floorSize] = &m;
    }
    _floorSize++;
}

// void     Floor::setFloorIdxNull(size_t i)
// {
//     if(i < LENGTH && i >= 0 && _floor[i] != NULL)
//         _floor[i] = NULL;
// }
AMateria * Floor::getFromFloor(AMateria *m)
{
    for(int i = 0; i < LENGTH; i++)
    {
        if(_floor[i] == m)
        {
            _floor[i] = NULL;
            return m;
        }
    }
    return NULL;
}

AMateria * Floor::getFloor(size_t i)
{
    if(i < LENGTH && i >= 0 && _floor[i] != NULL)
        return _floor[i];
    else
        return NULL;
}