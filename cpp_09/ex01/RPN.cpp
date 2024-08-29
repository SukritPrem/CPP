#include "RPN.hpp"

RPN::RPN(){};
RPN::~RPN(){};

RPN::RPN(RPN const &rhs){
    *this = rhs;
}
RPN & RPN::operator=(RPN const &rhs){
	if (this != &rhs) {
		// output = rhs.output;
        // stack = rhs.stack;
	}
	return (*this);
}

int RPN::stringToInt(const std::string& str) {
    int num;
    std::stringstream ss(str);
    ss >> num;
    return num;
}

// Function to validate if a string is a number
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
            std::cerr << "Invalid token: " << token << std::endl;
            exit(1);  // Exit if an invalid token is found
        }
        tokens.push(token);
    }
}

int RPN::evaluateRPN(std::queue<std::string>& tokens) {
    std::stack<int> st;

    while (!tokens.empty()) {
        std::string token = tokens.front();
        tokens.pop();

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int operand2 = st.top(); st.pop();
            int operand1 = st.top(); st.pop();

            if (token == "+") st.push(operand1 + operand2);
            else if (token == "-") st.push(operand1 - operand2);
            else if (token == "*") st.push(operand1 * operand2);
            else if (token == "/") st.push(operand1 / operand2);
        } else {
            st.push(stringToInt(token));
        }
    }

    return st.top();
}