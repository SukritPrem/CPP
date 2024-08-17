
#include <stack>
#include <string>
#include <iostream>
#include <stdlib.h>

struct answer
{
    bool print;
    int number;
};

class RPN
{
    private:
        answer      output;
        std::stack<double> stack;
    public:
        RPN();
        ~RPN();
        void push(double value);
        double pop();
        answer evaluate(std::string expression);
};