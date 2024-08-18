#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
#include <climits>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <cctype>
class BitcoinExchange {
     private:
        std::string _name;
        std::stringstream buffer;
        std::map<std::time_t, double> _exchangeRate;
    public:
        ~BitcoinExchange(void);
        BitcoinExchange(std::string name, std::string fileExchangeRate);

        BitcoinExchange(BitcoinExchange const &rhs);

        BitcoinExchange & operator=(BitcoinExchange const &rhs);


        time_t stringToTimestamp(const std::string& dateString);

        void checkBySplitFirstLine(char c, std::ifstream &file);

        std::vector<std::string> split(const std::string& s, char delimiter);
        bool checkItallDateIsNumber(std::vector<std::string> &parts);

        bool checkMonth(std::string &month);

        bool isLeapYear(int year);

        // Function to get the number of days in a given month of a given year
        int getDaysInMonth(int year, int month);


        bool checkDay(std::string &day, std::string &month, std::string &year);
        
        bool checkFormatdate(std::string &date);

        bool checkSymbol(std::string &symbol);

        bool containsAlphabet(const std::string& str);

        void checkBySplitExchanges(std::ifstream &file);

        bool containsSpace(const std::string& str);
        void removeSpaces(std::string& str);

        void copyDataToExchangeRate(std::string fileExchangeRate);
};


#endif