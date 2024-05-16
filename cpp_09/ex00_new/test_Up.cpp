#include <iostream>
#include <map>
#include <ctime>


int main() {
    std::map<float, float> myMap;

    // Example timestamps
    float t1 = 1; // current time
    float t2 = 2;            // current time + 100 seconds
    float t3 = 3;            // current time + 200 seconds
    float t4 = 4;
    // Insert elements float to the map
    myMap[t1] =10;
    myMap[t2] =20;
    myMap[t3] =30;
    myMap[t4] = 25;
    // Define a time for which we want to find the lower bound

    // Find the lower bound
    // std::map<float, float>::iterator  it = myMap.lower_bound(2.3);
    std::map<float, float>::iterator  it2 = myMap.upper_bound(1.5);
    // std::cout << "Lower bound of 10 is " << it->first << " " << it->second << std::endl;
    std::cout << "Upper bound of 10 is " << it2->first << " " << it2->second << std::endl;
    return 0;
}
