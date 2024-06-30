
#include <cstdlib>
#include <iostream>
#include "PmergeMe.hpp"
#include <vector>
#include <list>
int main(int argc,char **argv)
{

    std::vector<int> vec;
    std::list<int> list;
    for (int i = 1; i < argc; i++){
        vec.push_back(std::atoi(argv[i]));
        list.push_back(std::atoi(argv[i]));
    }

    PmergeMe<std::vector<int>,std::vector<int>::iterator> test;
    PmergeMe<std::list<int>,std::list<int>::iterator> test2;


}