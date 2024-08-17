#include "PmergeMe.hpp"
#include <string>

#include <iostream>

template<typename U>
TT<U>::TT(U u): _u(u){
    std::cout << _u << std::endl;
}

template<typename U>
TT<U>::TT(){
    std::cout << "Hello" << std::endl;
}
