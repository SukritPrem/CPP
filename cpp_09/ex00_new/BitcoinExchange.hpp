#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <climits>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

class BitcoinExchange {
     private:
        std::string _name;
        std::stringstream buffer;
    public:
        BitcoinExchange(void){};
        BitcoinExchange(std::string name)
        {
            std::ifstream file(name.c_str()); // Open the file

            if (!file.is_open()) {
                std::cerr << "Error opening the file!" << std::endl;
            }
            buffer << file.rdbuf();
            std::string line;
            std::getline(buffer, line);
            std::cout <<line;
        };
};


#endif