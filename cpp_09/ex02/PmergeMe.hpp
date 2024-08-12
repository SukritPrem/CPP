#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>
template<typename Container, typename ContainPair>
class PmergeMe
{
    private:
        Container _container;
        ContainPair _containerPair;
        bool _haveOdd;
        int _aloneNum;
    public:
        PmergeMe(){
            _haveOdd = false;
        };

        void setData(Container &data){
            _container = data;
        }

        void insertContainerToContainerPair(){
            // Iterator it;
            std::pair<int, int> pairValue;
            typename Container::iterator it;
            // std::cout << _container.size() << std::endl;
            if(_container.size() % 2 == 1)
                _haveOdd = true;

            for(it = _container.begin(); it != _container.end(); it++){
                pairValue.first = *it;
                if(it++ + 1 == _container.end())
                {
                    _aloneNum = pairValue.first;
                    break;
                }        
                pairValue.second = *it;
                _containerPair.push_back(pairValue);
            }
            // _containerPair.push_back(pairValue);
        }

        void printContainerPair(){
            typename ContainPair::iterator it = _containerPair.begin();
            while(it != _containerPair.end())
            {
                std::cout << it->first << std::endl;
                std::cout << it->second << std::endl;
                it++;
            }
        }


        void sortContainerInsidePair(){
            typename ContainPair::iterator it = _containerPair.begin();
            std::pair<int, int> pairValue;
            while(it != _containerPair.end())
            {
                if(it->first > it->second)
                {
                    int tmp = it->second;
                    it->second = it->first;
                    it->first = tmp;
                }
                it++;
            }
        }


        void mergeSortContainerPair(){

            mergeSort(_containerPair, 0, _containerPair.size() - 1);
            
        }

        void merge(ContainPair &vec, int left, int mid, int right) {
            int n1 = mid - left + 1;
            int n2 = right - mid;

            ContainPair leftVec(n1);
            ContainPair rightVec(n2);

            for (int i = 0; i < n1; ++i) {
                leftVec[i] = vec[left + i];
            }
            for (int i = 0; i < n2; ++i) {
                rightVec[i] = vec[mid + 1 + i];
            }

            int i = 0, j = 0, k = left;
            while (i < n1 && j < n2) {
                if (leftVec[i].first <= rightVec[j].first) {
                    vec[k] = leftVec[i];
                    ++i;
                } else {
                    vec[k] = rightVec[j];
                    ++j;
                }
                ++k;
            }

            while (i < n1) {
                vec[k] = leftVec[i];
                ++i;
                ++k;
            }

            while (j < n2) {
                vec[k] = rightVec[j];
                ++j;
                ++k;
            }
        }

        void mergeSort(ContainPair &container, int left, int right) {
            if (left < right) {
                int mid = left + (right - left) / 2;
                mergeSort(container, left, mid);
                mergeSort(container, mid + 1, right);
                merge(container, left, mid, right);
            }
        }

        void clearContainer(){
            _container.clear();
        }

        void insertContainerPairToContainer(){
            typename ContainPair::iterator it = _containerPair.begin();
            while(it != _containerPair.end())
            {
                _container.push_back(it->first);
                it++;
            }    
        }

        void binarySearchContainer(){
            typename ContainPair::iterator it = _containerPair.begin();
            
            while(it != _containerPair.end())
            {
                typename Container::iterator position = std::lower_bound(_container.begin(), _container.end(), it->second);
                _container.insert(position, it->second);
                it++;
            }

            if(_haveOdd)
            {
                typename Container::iterator position = std::lower_bound(_container.begin(), _container.end(), _aloneNum);
                _container.insert(position, _aloneNum);
            }
        }

        void printBeforeSort(){
            std::cout << "Before:  ";
            printContainer();
        }

        void printContainer(){
            typename Container::iterator it = _container.begin();
            while(it != _container.end())
            {
                std::cout << *it << " " ;
                it++;
            }
            std::cout << std::endl;
        }

        void printAfterSort(){
            std::cout << "After:   ";
            printContainer();
        }
        void run(bool print){
            std::clock_t start = std::clock();
            insertContainerToContainerPair();
            sortContainerInsidePair();
            mergeSortContainerPair();
            clearContainer();
            insertContainerPairToContainer();
            binarySearchContainer();
            std::clock_t end = std::clock();
            if(print)
                printAfterSort();
            std::cout << "Time to process a range of "<< _container.size() <<" elements with std::[..] : ";
            std::cout << 1000.0 * (end - start) / CLOCKS_PER_SEC  << " ms"<< std::endl;

        }
        ~PmergeMe(){

        };
};
#endif