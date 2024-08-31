#include "RPN.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try{

        std::string input = argv[1];
        std::queue<std::string> tokens;

        RPN test;
        test.parseInputToQueue(input, tokens);

        // Evaluate the RPN expression
        answer result = test.evaluateRPN(tokens);
        if(result.print)
            std::cout << result.value << std::endl;
}catch(std::invalid_argument e)
{
    std::cerr << e.what() << std::endl;
    return 1;
}catch(std::exception e)
{
    std::cerr << e.what() << std::endl;
    return 1;
}
    return 0;
}