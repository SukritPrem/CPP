#include <iostream>
#include <map>
#include <ctime>


int main() {
    std::map<int, int> myMap;

    // Example timestamps
    int t1 = 0; // current time
    int t2 = 1;            // current time + 100 seconds
    int t3 = 2;            // current time + 200 seconds

    // Insert elements into the map
    myMap[t1] =10;
    myMap[t2] =20;
    myMap[t3] =30;
    // Define a time for which we want to find the lower bound

    // Find the lower bound
    std::map<int, int>::iterator  it = myMap.lower_bound(2);
    std::map<int, int>::iterator  it2 = myMap.upper_bound(2);
    std::cout << "Lower bound of 10 is " << it->first << " " << it->second << std::endl;
    std::cout << "Upper bound of 10 is " << it2->first << " " << it2->second << std::endl;
    return 0;
}
