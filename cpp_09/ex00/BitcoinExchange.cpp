#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange(
){
};

BitcoinExchange::BitcoinExchange(std::string name, std::string fileExchangeRate)
{
    copyDataToExchangeRate(fileExchangeRate);
    std::ifstream file(name.c_str()); // Open the file
    if (!file.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
    }
    checkBySplitFirstLine('|', file);
    checkBySplitExchanges(file);
    file.close();
};

BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs){
    *this = rhs;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const &rhs){
    
    if(this != &rhs){
        _exchangeRate = rhs._exchangeRate;
        _name = rhs._name;
        _buffer.str(rhs._buffer.str());
    }
    return (*this);
}

time_t BitcoinExchange::stringToTimestamp(const std::string& dateString) {
    std::tm tm = {};
    strptime(dateString.c_str(), "%Y-%m-%d", &tm);
    time_t timestamp = mktime(&tm);
    return timestamp;
}

void BitcoinExchange::checkBySplitFirstLine(char c, std::ifstream &file)
{
    (void)c;
    std::string line;
    std::getline(file, line);
    std::istringstream ss(line);
    // int i = 0;
    ss >> line;
    if(line != "date")
        throw std::invalid_argument("Invalid file format");
    ss >> line;
    if(line != "|")
        throw std::invalid_argument("Invalid file format");
    ss >> line;
    if(line != "value")
        throw std::invalid_argument("Invalid file format"); 
}

#include <list>
std::list<std::string> BitcoinExchange::split(const std::string& s, char delimiter) {
    std::list<std::string> tokens;
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

bool BitcoinExchange::checkItallDateIsNumber(std::list<std::string> &parts)
{
    int i = 0;
    int j = 0;
    for (std::list<std::string>::iterator it = parts.begin(); it != parts.end(); ++it) {

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

        bool BitcoinExchange::checkMonth(std::string &month)
        {
            int i = 0;
            std::stringstream ss(month);
            ss >> i;
            ss.clear();
            if(i < 1 || i > 12)
                return false;
            return true;
        }

        bool BitcoinExchange::isLeapYear(int year) {
            if (year % 4 != 0) return false;
            if (year % 100 != 0) return true;
            if (year % 400 != 0) return false;
            return true;
        }

        // Function to get the number of days in a given month of a given year
        int BitcoinExchange::getDaysInMonth(int year, int month) {
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


        bool BitcoinExchange::checkDay(std::string &day, std::string &month, std::string &year)
        {
            int d = 0;
            int m = 0;
            std::stringstream mm(month);
            std::stringstream dd(day);
            mm >> m;
            dd >> d;
            mm.clear();
            dd.clear();
            int max_day = getDaysInMonth(atoi(year.c_str()), m);
            if(d < 1 || d > max_day)
                return false;
            return true;
        }
        
        bool BitcoinExchange::checkFormatdate(std::string &date)
        {
            std::list<std::string> parts = split(date, '-');
            if(parts.size() != 3)
                return false;
            if(checkItallDateIsNumber(parts) == false)
                return false;
                
            std::list<std::string>::iterator it = parts.begin();
            std::list<std::string>::iterator year = it++;
            std::list<std::string>::iterator month = it++;
            std::list<std::string>::iterator day = it++;

            if(checkMonth(*month) == false)
                return false;
            if(checkDay(*day, *month, *year) == false)
                return false;
            return true;
        }

        bool BitcoinExchange::checkSymbol(std::string &symbol)
        {
            if(symbol.size() != 1)
                return false;
            if(symbol != "|")
                return false;
            return true;
        }

        bool BitcoinExchange::containsAlphabet(const std::string& str) {
            for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
                if (std::isalpha(*it)) {
                    return true;
                }
            }
            return false;
        }

        void BitcoinExchange::checkBySplitExchanges(std::ifstream &file)
        {
            std::string line;
            std::string date;
            std::string exchange_rate;
            std::string symbol;
            std::list<std::string> parts;
            std::pair<int, std::string> store;
            // int countAlpha = 0;
            while (std::getline(file, line)) {
                std::istringstream ss(line);
                std::string clone = line;
                // std::cout << line << std::endl
                while(ss >> line)
                    parts.push_back(line);
                if(parts.size() != 3)
                {
                    std::cout << "Error: Bad input => " << clone << std::endl;
                    parts.clear();
                    ss.clear();
                    continue;
                }
                ss.clear();
                ss.seekg(0, std::ios::beg);

                ss >> date;
                ss >> symbol;
                ss >> exchange_rate;
                // std::cout << date << " " << symbol << " " << exchange_rate << std::endl;
                // exchange_rate = *first++;
                if(containsAlphabet(exchange_rate))
                {
                    std::cout << "Error: Bad input => " << clone << std::endl;
                    parts.clear();
                    ss.clear();
                    continue;
                }
                double f;
                std::stringstream ss1(exchange_rate);
                ss1 >> f;
                removeSpaces(date);

                if(!checkFormatdate(date))
                {
                    std::cout << "Error: Bad input => " << clone << std::endl;
                    parts.clear();
                    ss.clear();
                    continue;
                }   

                if(!checkSymbol(symbol))
                {
                    std::cout << "Error: Bad input => " << clone << std::endl;
                    parts.clear();
                    ss.clear();
                    continue;
                }
                if(f < 0)
                {
                    std::cout << "Error: not a positive number." << std::endl;
                    parts.clear();
                    ss.clear();
                    continue;
                }
                if(f > static_cast<int>(INT_MAX))
                {
                    std::cout << "Error: too large a number." << std::endl;
                    parts.clear();
                    ss.clear();
                    continue;
                }

                
                std::map<std::time_t , double>::iterator _itUp = _exchangeRate.upper_bound(stringToTimestamp(date));

                _itUp--;
                if(_itUp == _exchangeRate.end()){
                    std::cout << "Not have data in current date." << std::endl;
                    parts.clear();
                    ss.clear();
                    continue;
                }
                std::cout << date << " => " << f << " = " << f * _itUp->second << std::endl;

                parts.clear();
                ss.clear();
            }
        }

        bool BitcoinExchange::containsSpace(const std::string& str) {
            // Check if the string contains a space
            return str.find(' ') != std::string::npos;
        }
        void BitcoinExchange::removeSpaces(std::string& str) {
            str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
        }

        void BitcoinExchange::copyDataToExchangeRate(std::string fileExchangeRate)
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
                std::stringstream ss1(rate);
                ss1 >> f;
                _exchangeRate.insert(std::pair<std::time_t, double>(stringToTimestamp(date), f));
            }

        }
