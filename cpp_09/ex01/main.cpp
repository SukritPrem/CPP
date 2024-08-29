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

    std::string input = argv[1];
    std::queue<std::string> tokens;

    RPN test;
    test.parseInputToQueue(input, tokens);

    // Evaluate the RPN expression
    int result = test.evaluateRPN(tokens);
    std::cout << result << std::endl;

    return 0;
}