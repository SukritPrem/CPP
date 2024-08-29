
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

class RPN
{
    public:
        RPN();
        ~RPN();
        RPN(RPN const &rhs);
        RPN & operator=(RPN const &rhs);
        static int stringToInt(const std::string& str);
        static bool isNumber(const std::string& str);
        static void parseInputToQueue(const std::string& input, std::queue<std::string>& tokens);
        static int evaluateRPN(std::queue<std::string>& tokens);
};