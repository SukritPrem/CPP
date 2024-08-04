
#include <cstdlib>
#include <iostream>
#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <utility>
#include <string>

int main(int argc,char **argv)
{
    (void)argc;
    (void)argv;
    std::string mocArgv[100] = {"9", "8", "2", "1", "3", "5", "4", "10", "12","6"};
    std::vector<int> vec;
    std::deque<int> list;
    // int mockArgc = 100;
    int count = 0;
    while (mocArgv[count] != "") {
        count++;
    }

    // std::cout << count << std::endl;
    for (int i = 0; i < count; i++){
        // std::cout << mocArgv[i] << std::endl;
        vec.push_back(std::atoi(mocArgv[i].c_str()));
        list.push_back(std::atoi(mocArgv[i].c_str()));
    }

    // PmergeMe<std::vector<int>, std::vector<std::pair<int,int> > > test;

    PmergeMe<std::deque<int>, std::deque<std::pair<int,int> > > test;
    test.setData(list);
    test.insertContainerToContainerPair();
    test.sortContainerInsidePair();
    // test.printContainerPair();
    // std::cout << "-----------------------------" << std::endl;
    test.mergeSortContainerPair();
    // test.printContainerPair();
    // std::cout << "-----------------------------" << std::endl;
    test.clearContainer();
    test.insertContainerPairToContainer();
    test.printContainer();
    std::cout << "-----------------------------" << std::endl;
    test.binarySearchContainer();
    std::cout << "-----------------------------" << std::endl;
    test.printContainer();
    // test2.setData(list);
    // test.sortContainer();
    // test.printOutput();
}