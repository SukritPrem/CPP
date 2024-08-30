
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <stdlib.h>

#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <cctype>

struct answer{
    bool print;
    int value;
};

class RPN
{
    public:
        RPN();
        ~RPN();
        RPN(RPN const &rhs);
        RPN & operator=(RPN const &rhs);
        int stringToInt(const std::string& str);
        bool isNumber(const std::string& str);
        void parseInputToQueue(const std::string& input, std::queue<std::string>& tokens);
        answer evaluateRPN(std::queue<std::string>& tokens);
};