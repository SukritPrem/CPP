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
class BitcoinExchange {
     private:
        std::string _name;
        std::stringstream buffer;
        std::map<std::time_t, double> _exchangeRate;
        
        std::map<std::time_t, std::pair<double, std::string> > _data;
    public:
        BitcoinExchange(void){};
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
            // std::cout << line << std::endl;
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

        bool checkItallIsNumber(std::vector<std::string> &parts)
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

        bool checkFormatdate(std::string &date)
        {
            std::vector<std::string> parts = split(date, '-');
            if(parts.size() != 3)
                return false;
            if(checkItallIsNumber(parts) == false)
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

                // debug
                // char buffer[80];
                // std::tm *tm = std::localtime(&_itUp->first);
                // std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm);
                // std::cout << "Formatted Date and Time: " << buffer << std::endl;

                std::cout << date << " => " << f * _itUp->second << std::endl;

                parts.clear();
            }
            // for (std::map<std::time_t, double>::const_iterator it = _data["data"].begin(); it != _data["data"].end(); ++it) {
            //     printf("%ld %f\n", it->first, it->second * 2);
            // }
        }

        // void calculate()
        // {
        //    for(std::map<std::time_t, double>::iterator it = _exchangeRate.begin(); it != _exchangeRate.end(); ++it)
        //    {
        //        for(std::map<std::time_t, std::pair<double, std::string> >::iterator it2 = _data.begin(); it2 != _data.end(); ++it2)
        //        {
        //             std::cout << it->first << " " << it2->first << std::endl;
        //        }
        //    }
        // }

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
                // std::cout << date << " " << rate << std::eneedl;
                double f;
                sscanf(rate.c_str(), "%lf", &f);
                _exchangeRate.insert(std::pair<std::time_t, double>(stringToTimestamp(date), f));
            }
            // for (std::map<std::time_t, double>::const_iterator it = _exchangeRate.begin(); it != _exchangeRate.end(); ++it) {
            //     printf("%ld %f\n", it->first, it->second * 2);
            // }

        }
};


#endif