#ifndef SCALAR_CONVERTER_H
#define SCALAR_CONVERTER_H

#include <iostream>
#include <sstream>
#include <cmath>
#include <climits>
#include <cfloat>
class ScalarConverter
{
    private:
        std::string errorOutput[3];
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter const &src);
        ScalarConverter &operator=(ScalarConverter const &src);
        std::string toLower(const std::string& str) ;
        void convert(const std::string &input);
        std::string printChar(const std::string &input);
        std::string printInt(const std::string &input);
        std::string printFloat(const std::string &input);
        std::string printDouble(const std::string &input);
        // void printDouble();
};
#endif
