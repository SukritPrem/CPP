
#include <stack>
#include <string>
#include <iostream>
#include <stdlib.h>

struct answer
{
    bool    print;
    int number;
};

class RPN
{
    private:
        answer      output;
        std::stack<double> stack;
    public:
        RPN(){};
        ~RPN(){};
        void push(double value){
            stack.push(value);
        };
        
        double pop(){
            double value = stack.top();
            stack.pop();
            return value;
        };

        answer evaluate(std::string expression){

            for (unsigned long i = 0; i < expression.length(); i++){
                if (expression[i] == ' '){
                    continue;
                }
                else if (isdigit(expression[i])){
                    std::string number = "";
                    while (i < expression.length() && isdigit(expression[i])){
                        number += expression[i];
                        i++;
                    }
                    i--;
                    push(atoi(number.c_str()));
                }
                else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/'){
                    double a = pop();
                    double b = pop();
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
};