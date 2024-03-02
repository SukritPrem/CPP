#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main ()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    bool result = easyfind(vec, 6);
    std::cout << "Result :" << result << std::endl;
}