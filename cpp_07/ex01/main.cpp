#include "iter.hpp"

int main() {
    // Example usage
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, print<const int>);
    std::string strArray[5];

    // Assign values to the elements of the array
    strArray[0] = "Hello";
    strArray[1] = "world";
    strArray[2] = "from";
    strArray[3] = "C++";
    strArray[4] = "!";
    std::cout << std::endl;
    
    iter(strArray, 5, print<std::string>);


    return 0;
}