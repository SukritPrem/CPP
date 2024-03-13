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

    void    clear(void);
    Span(unsigned int N);
    int&    operator[](unsigned int n);
    int     size(void) const;
    void    addNumber(int num);
    int     shortestSpan(void);
    int     longestSpan(void);
};

#endif