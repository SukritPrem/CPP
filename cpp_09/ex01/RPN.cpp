#include "RPN.hpp"

RPN::RPN(){};
RPN::~RPN(){};
void RPN::push(double value){
    stack.push(value);
};

double RPN::pop(){
    if(stack.size() == 0)
        throw (std::invalid_argument("when pop stack size is Zero."));	
    double value = stack.top();
    stack.pop();
    return value;
};

RPN::RPN(RPN const &rhs){
    *this = rhs;
}
RPN & RPN::operator=(RPN const &rhs){
	if (this != &rhs) {
		output = rhs.output;
        stack = rhs.stack;
	}
	return (*this);
}


answer RPN::evaluate(std::string expression){

    for (unsigned long i = 0; i < expression.length(); i++){
        if (expression[i] == ' '){
            continue;
        }
        else if (isdigit(expression[i])){
            std::string number = "";
            while (i < expression.length() && isdigit(expression[i])){
                number += expression[i];
                i++;
                break;
            }
            i--;
            // std::cout << "number: " << number.c_str() << std::endl;
            push(atoi(number.c_str()));
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/'){
            double a = pop();
            double b = pop();
            // std::cout << "a: "<< a << " " << "b: " << b << std::endl;
            if (expression[i] == '+'){
                push(b + a);
            }
            else if (expression[i] == '-'){
                push(b - a);
            }
            else if (expression[i] == '*'){
                push(b * a);
            }
            else if (expression[i] == '/'){
                push(b / a);
            }
        }
        else
        {
            std::cout << "Error" << std::endl;
            output.print = false;
            return output;
        }
    }
    output.print = true;
    output.number = pop();
    return output;
};