

#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
template<typename T>
class Array{
    private:
        T* elements;
        unsigned int _size;
    public:
        Array(void) : elements(new T()), _size(1) {}
        Array(size_t n) : _size(n){
            if(n == 0)
                throw std::runtime_error("Size index not Zero.");
            elements = new T[_size];
            for(size_t i = 0 ; i < _size; i++)
            {
                elements[i] = T();
            }
        }
        Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] elements;
            _size = other._size;
            elements = new T[_size];
            for (unsigned int i = 0; i < _size; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
        }

        unsigned int size() const {
        return _size;
        }


        Array(const Array& other) : _size(other.size) {
            elements = new T[_size];           
            for (unsigned int i = 0; i < _size; ++i) {
                elements[i] = other.elements[i];
            }
        }


        T& operator[](unsigned int index) 
        {
            if (index >= _size) {
                throw std::runtime_error("Index out of bounds");
            }
            return elements[index];
        }

        ~Array() {
            delete[] elements;
        }
};
#endif