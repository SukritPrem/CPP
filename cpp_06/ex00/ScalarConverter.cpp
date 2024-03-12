
#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {
    errorOutput[0] = "impossible";
    errorOutput[1] = "+inf";
    errorOutput[2] = "-inf";
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
    (void)src;
}


ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src) {
    (void)src;
    return *this;
}

void ScalarConverter::convert(const std::string &input)
{
    // std::istringstream iss(input);
    std::cout << "char: "<< printChar(input) << std::endl;
    std::cout << "int:  "<<printInt(input) << std::endl;
    std::cout << "float:"<<printFloat(input) << std::endl;
    std::cout << "double:"<<printDouble(input) << std::endl;
}

std::string ScalarConverter::printChar(const std::string &input)
{
    std::istringstream iss(input);
    std::ostringstream output;
    long double d;
    iss >> d;
    
    if(toLower(input) == "nan" || toLower(input) == "-inf" 
    || toLower(input) == "+inf" || toLower(input) == "inf"
        || d > static_cast<int>(CHAR_MAX)
        || d < static_cast<int>(CHAR_MIN)
    )
        output << "impossible";
    else if(isprint(d))
        output << "'" << static_cast<char>(d) << "'";   
    else if(d == 0)
        output << "Non displayable";

    return (output.str());
}

std::string ScalarConverter::toLower(const std::string& str) {
    (void)str;
    std::string result = str;
    for (std::string::iterator it = result.begin(); it != result.end(); ++it) {
        *it = tolower(*it);
    }
    return result;
}

std::string ScalarConverter::printInt(const std::string &input)
{
    std::istringstream iss(input);
    std::ostringstream output;
    long double d;
    // std::cout<< "->" << toLower(input) <<std::endl;
    if(toLower(input) == "nan" || toLower(input) == "-inf" 
    || toLower(input) == "+inf" || toLower(input) == "inf")
        output << "impossible";
    else
    {
        if(iss >> d)
        {

            if( d > static_cast<int>(INT_MAX) || d < static_cast<int>(INT_MIN))
            {
                output << "impossible";
                return output.str();
            }
            output << static_cast<int>(d);   
            return output.str();
        }
        else
        {
           output << "impossible";
            return output.str(); 
        }
    }
    return (output.str());
}

std::string ScalarConverter::printFloat(const std::string &input)
{
    std::istringstream iss(input);
    std::ostringstream output;
    long double d;



    if(toLower(input) == "-inf" )
    {
        output << "-inff";
        return output.str();
    }
    else if(toLower(input) == "+inf" || toLower(input) == "inf" )
    {
        output << "+inff";
        return output.str();
    } 
    else if(toLower(input) == "nan")
    {
        output << "nanf";
        return output.str();
    }     
    else
    {
        if (iss >> d)
        {
            if (d > (FLT_MAX) || d < -(FLT_MAX))
            {
                output << "impossible";
                return output.str();
            }
            else
                output << static_cast<float>(d);   
        }
        else
        {
            output << "impossible";
            return output.str();
        } 

    }


    
    if(output.str().find('.') != std::string::npos)
        output << "f";
    else
        output << ".0f";

    return (output.str());
}

std::string ScalarConverter::printDouble(const std::string &input)
{
    std::istringstream iss(input);
    std::ostringstream output;
    long double d;
    
    if(toLower(input) == "-inf" )
    {
        output << "-inf";
        return output.str();
    }
    else if(toLower(input) == "+inf" || toLower(input) == "inf" )
    {
        output << "+inf";
        return output.str();
    } 
    else if(toLower(input) == "nan")
    {
        output << "nan";
        return output.str();
    }   
    else
    {
        if (iss >> d)
        {
            if (d > (DBL_MAX) || d < -(DBL_MAX))
            {
                output << "impossible";
                return output.str();
            }
            else
                output << static_cast<double>(d);   
        }
        else
        {
            output << "impossible";
            return output.str();
        } 

    }


    if(output.str().find('.') == std::string::npos)
        output << ".0";

    return (output.str());
}