#include <iostream>
#include <map>
#include <ctime>

int main() {
    // Create a map with std::time_t keys and values of type std::pair<std::time_t, double>
    std::map<std::time_t, std::pair<std::time_t, double>> myMap;

    // Insert some example data into the map
    myMap[1625072045] = 
    myMap[1625072145] = 
    myMap[1625072245] = std::make_pair(1625072245, 30.5);

    // Define a key for which we want to find the lower bound
    std::time_t key = 1625072100; // Adjust this timestamp to your needs

    // Find the lower bound for the key
    auto it = myMap.lower_bound(key);
    auto it1 = myMap.upper_bound(key);
    std::cout << "it1: " << it1->second.first << std::endl;
    // Check if the iterator is valid and print the result
    if (it != myMap.end()) {
        std::time_t foundKey = it->first;
        std::time_t valueTime = it->second.first;
        double valueDouble = it->second.second;
        std::cout << "Lower bound found at key: " << foundKey << std::endl;
        std::cout << "Associated value: (" << valueTime << ", " << valueDouble << ")" << std::endl;
    } else {
        std::cout << "No lower bound found for the given key." << std::endl;
    }

    return 0;
}
