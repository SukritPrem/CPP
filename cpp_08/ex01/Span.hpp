#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#ifndef SPAN_H
#define SPAN_H
class Span {
private:
    std::vector<int> numbers;
    unsigned int maxSize;

public:
    Span(void){};
    ~Span(void){};
    Span(Span &r_obj);
    Span & operator=(Span &r_obj);

    Span(unsigned int N);
    void addNumber(int num);
    int shortestSpan(void);
    int longestSpan(void);
};

#endif