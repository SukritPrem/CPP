#include "iter.hpp"

int main() {
    // Example usage
    int arr[] = {1, 2, 3, 4, 5};
    iter<int, void(*)(int)>(arr, 5, printElement);
    std::string strArray[5];

    // Assign values to the elements of the array
    strArray[0] = "Hello";
    strArray[1] = "world";
    strArray[2] = "from";
    strArray[3] = "C++";
    strArray[4] = "!";
    std::cout << std::endl;
    
    iter<std::string, void(*)(std::string)>(strArray, 5, printElement);


    return 0;
}