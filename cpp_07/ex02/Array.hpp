

#ifndef ARRAY_H
#define ARRAY_H

template<typename T>
class Array{
    private:
        T* elements;
        unsigned int size;
    public:
        Array(void);
        ~Array(void);
        Array(size_t n) : size(n){
            elements = new T[size];
            for(size_t i = 0 ; i < size; i++)
            {
                elements[i] = T();
            }
        }

        Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] elements;
            size_ = other.size_;
            elements = new T[size_];
            for (unsigned int i = 0; i < size_; ++i) {
                elements[i] = other.elements[i];
            }
        }
        return *this;
        }

        unsigned int size() const {
        return size_;
        }


        Array(const Array& other) : size(other.size) {
            elements = new T[size];           
            for (unsigned int i = 0; i < size; ++i) {
                elements[i] = other.elements[i];
            }
        }
        
        
        ~Array() {
            delete[] elements;
        }


        T& operator[](unsigned int index) 
        {
            if (index >= size_) {
                throw std::out_of_range("Index out of bounds");
            }
            return elements[index];
        }

        ~Array() {
            delete[] elements;
        }
};
#endif