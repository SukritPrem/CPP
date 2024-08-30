#include "RPN.hpp"

RPN::RPN(){};
RPN::~RPN(){};

RPN::RPN(RPN const &rhs){
    *this = rhs;
}
RPN & RPN::operator=(RPN const &rhs){
	if (this != &rhs) {
	}
	return (*this);
}

int RPN::stringToInt(const std::string& str) {
    int num;
    std::stringstream ss(str);
    ss >> num;
    return num;
}

bool RPN::isNumber(const std::string& str) {
    for (size_t i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i]) && !(i == 0 && (str[i] == '-' || str[i] == '+'))) {  // Handle negative and positive numbers
            return false;
        }
    }
    return true;
}

void RPN::parseInputToQueue(const std::string& input, std::queue<std::string>& tokens) {
    std::stringstream ss(input);
    std::string token;

    while (ss >> token) {
        // Optional validation check
        if (!isNumber(token) && token != "+" && token != "-" && token != "*" && token != "/") {
            std::cout << "Invalid token: " << token << std::endl;
            exit(0); 
        }
        tokens.push(token);
    }
}



answer RPN::evaluateRPN(std::queue<std::string>& tokens) {
    std::stack<int> st;
    std::stack<char> operand;
    answer output;
    if(tokens.empty())
    {
        output.print = false;
        return output;
    }

    while (!tokens.empty()) {
        std::string token = tokens.front();
        tokens.pop();
        if ((token == "+" || token == "-" || token == "*" || token == "/") && st.empty())
        {
            output.value = 0;
            output.print = false;
            return output;
        }

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int operand2 = st.top(); st.pop();
            if(st.empty())
            {
                output.print = false;
                return output;
            }
            int operand1 = st.top(); st.pop();

            if (token == "+") st.push(operand1 + operand2);
            else if (token == "-") st.push(operand1 - operand2);
            else if (token == "*") st.push(operand1 * operand2);
            else if (token == "/") st.push(operand1 / operand2);
        } else {
            st.push(stringToInt(token));
        }
    }
    output.print = true;
    output.value = st.top();
    return output;
}