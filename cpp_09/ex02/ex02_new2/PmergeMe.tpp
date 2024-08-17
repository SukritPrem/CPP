
#include "PmergeMe.hpp"

template<typename Container>
PmergeMe<Container>::PmergeMe(){
    _haveOdd = false;
};

// template<typename Container>
// PmergeMe<Container>::~PmergeMe(){
// };

template class PmergeMe<std::vector<int> >;