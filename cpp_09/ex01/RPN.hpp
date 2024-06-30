
#include <stack>
#include <string>
#include <iostream>

class RPN
{
    private:
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

        double evaluate(std::string expression){

            for (int i = 0; i < expression.length(); i++){
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
                    push(std::stod(number));
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
                    return 0;
                }
            }

            return pop();
        };
};