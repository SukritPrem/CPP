#include "RPN.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

int main (int argc, char **argv) 
{
    std::string word;

    if(argc != 2)
    {
        return 0;
    }

    std::istringstream input(argv[1]);
    std::string expression = "";
    RPN stack;
    while(input >> word)
    {
        expression = expression + " " + word;
    }
    // std::cout << expression.c_str() << std::endl;
    answer output = stack.evaluate(expression.c_str());
    if(output.print)
        std::cout << output.number << std::endl;

}