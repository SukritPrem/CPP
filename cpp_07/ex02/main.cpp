#include "Array.hpp"

int main(void)
{
    Array<int> intArray(5);
    intArray[0] = 10; // Assigns value 10 to the first element of the array
    intArray[1] = 20;
    for(unsigned int  i = 0; i < intArray.size(); i++)
    {
        std::cout << intArray[i] << std::endl;
    }
    try
    {
        intArray[100] = 50;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        intArray[-1] = 50;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "--------------------" << std::endl;
        std::cout << "Size array one default." <<std::endl;
        Array<int> *intArray = new Array<int>();
        (void)intArray;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "--------------------" << std::endl;
        std::cout << "Size array zero." <<std::endl;
        Array<int> *intArray = new Array<int>(0);
        (void)intArray;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
      try
    {
        std::cout << "--------------------" << std::endl;
        std::cout << "Size array one default." <<std::endl;
        Array<char> *charArray = new Array<char>();
        std::cout << (*charArray)[0] << std::endl;
        std::cout << "--------------------" << std::endl;
        (void)charArray;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}