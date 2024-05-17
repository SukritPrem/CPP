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
        BitcoinExchange(void){};
        ~BitcoinExchange(void){};
        BitcoinExchange(std::string name, std::string fileExchangeRate)
        {
            copyDataToExchangeRate(fileExchangeRate);
            std::ifstream file(name.c_str()); // Open the file
            if (!file.is_open()) {
                std::cerr << "Error opening the file!" << std::endl;
            }
            checkBySplitFirstLine(',', file);
            checkBySplitExchanges(file);
            // calculate();
        };

        time_t stringToTimestamp(const std::string& dateString) {
            std::tm tm = {};
            strptime(dateString.c_str(), "%Y-%m-%d", &tm);
            time_t timestamp = mktime(&tm);
            return timestamp;
        }


        void checkBySplitFirstLine(char c, std::ifstream &file)
        {
            std::string line;
            std::getline(file, line);
            std::istringstream ss(line);
            // int i = 0;
            std::getline(ss, line, c);
            if(line != "date")
                throw std::invalid_argument("Invalid file format");
            std::getline(ss, line, c);
            if(line != "exchange_rate")
                throw std::invalid_argument("Invalid file format"); 
        }

        std::vector<std::string> split(const std::string& s, char delimiter) {
            std::vector<std::string> tokens;
            size_t start = 0;
            size_t end = s.find(delimiter);

            while (end != std::string::npos) {
                tokens.push_back(s.substr(start, end - start));
                start = end + 1;
                end = s.find(delimiter, start);
            }

            tokens.push_back(s.substr(start, end - start));
            return tokens;
        }

        bool checkItallDateIsNumber(std::vector<std::string> &parts)
        {
            int i = 0;
            int j = 0;
            for (std::vector<std::string>::iterator it = parts.begin(); it != parts.end(); ++it) {

                for(std::string::iterator it2 = it->begin(); it2 != it->end(); ++it2)
                {
                    if(!isdigit(*it2))
                        return false;
                    j++;
                }
                if(i == 0)
                {
                    if(j != 4)
                        return false;
                }
                else if(i == 1)
                {
                    if(j != 2)
                        return false;
                }
                else if(i == 2)
                {
                    if(j != 2)
                        return false;
                }
                i++;
                j = 0;
            }

            return true;
        }

        bool checkMonth(std::string &month)
        {
            int i = 0;
            sscanf(month.c_str(), "%d", &i);
            if(i < 1 || i > 12)
                return false;
            return true;
        }

        bool isLeapYear(int year) {
            if (year % 4 != 0) return false;
            if (year % 100 != 0) return true;
            if (year % 400 != 0) return false;
            return true;
        }

        // Function to get the number of days in a given month of a given year
        int getDaysInMonth(int year, int month) {
            switch (month) {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    return 31;
                case 4: case 6: case 9: case 11:
                    return 30;
                case 2:
                    return isLeapYear(year) ? 29 : 28;
                default:
                    return 0; // Invalid month
            }
        }


        bool checkDay(std::string &day, std::string &month, std::string &year)
        {
            int d = 0;
            int m = 0;
            sscanf(month.c_str(), "%d", &m);
            sscanf(day.c_str(), "%d", &d);
            int max_day = getDaysInMonth(atoi(year.c_str()), m);
            if(d < 1 || d > max_day)
                return false;
            return true;
        }
        
        bool checkFormatdate(std::string &date)
        {
            std::vector<std::string> parts = split(date, '-');
            if(parts.size() != 3)
                return false;
            if(checkItallDateIsNumber(parts) == false)
                return false;
            std::vector<std::string>::iterator year = parts.begin();
            std::vector<std::string>::iterator month = parts.begin() + 1;
            std::vector<std::string>::iterator day = parts.begin() + 2;
            if(checkMonth(*month) == false)
                return false;
            if(checkDay(*day, *month, *year) == false)
                return false;
            return true;
        }

        bool checkSymbol(std::string &symbol)
        {
            if(symbol.size() != 1)
                return false;
            if(symbol != "|")
                return false;
            return true;
        }

        bool containsAlphabet(const std::string& str) {
            for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
                if (std::isalpha(*it)) {
                    return true;
                }
            }
            return false;
        }

        void checkBySplitExchanges(std::ifstream &file)
        {
            std::string line;
            std::string date;
            std::string exchange_rate;
            std::string symbol;
            std::vector<std::string> parts;
            std::pair<int, std::string> store;
            // int i = 0;
            while (std::getline(file, line)) {
                std::istringstream ss(line);
                std::string clone = line;
                while(ss >> line)
                    parts.push_back(line);
                if(parts.size() != 3)
                {
                    std::cout << "Error: Bad input => " << clone << std::endl;
                    parts.clear();
                    continue;
                }

                date = parts[0];
                symbol = parts[1];
                exchange_rate = parts[2];
                if(containsAlphabet(exchange_rate))
                {
                    std::cout << "Error: Bad input => " << clone << std::endl;
                    parts.clear();
                    continue;
                }

                double f;
                sscanf(exchange_rate.c_str(), "%lf", &f);
                removeSpaces(date);

                if(!checkFormatdate(date))
                {
                    std::cout << "Error: Bad input => " << clone << std::endl;
                    parts.clear();
                    continue;
                }   
                if(!checkSymbol(symbol))
                {
                    std::cout << "Error: Bad input => " << clone << std::endl;
                    parts.clear();
                    continue;
                }
                if(f < 0)
                {
                    std::cout << "Error: not a positive number." << std::endl;
                    parts.clear();
                    continue;
                }
                if(f > static_cast<int>(INT_MAX))
                {
                    std::cout << "Error: too large a number." << std::endl;
                    parts.clear();
                    continue;
                }
                
                std::map<std::time_t , double>::const_iterator _itUp = _exchangeRate.upper_bound(stringToTimestamp(date));
                
                _itUp--;

                std::cout << date << " => " << f * _itUp->second << std::endl;

                parts.clear();
            }
        }

        bool containsSpace(const std::string& str) {
            // Check if the string contains a space
            return str.find(' ') != std::string::npos;
        }
        void removeSpaces(std::string& str) {
            str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
        }

        void copyDataToExchangeRate(std::string fileExchangeRate)
        {
            std::ifstream file(fileExchangeRate.c_str()); // Open the file
            if (!file.is_open()) {
                std::cerr << "Error opening the file!" << std::endl;
            }
            std::string line;
            std::string date;
            std::string rate;
            std::getline(file, line);//skip first line
            while (std::getline(file, line)) {
                std::istringstream ss(line);
                std::getline(ss, date, ',');
                std::getline(ss, rate, ',');
                double f;
                sscanf(rate.c_str(), "%lf", &f);
                _exchangeRate.insert(std::pair<std::time_t, double>(stringToTimestamp(date), f));
            }

        }
};


#endif