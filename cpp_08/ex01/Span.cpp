#include "Span.hpp"

Span::Span(unsigned int N) : maxSize(N) {}

Span & Span::operator=(Span &r_obj)
{
    if(this != &r_obj)
    {
        maxSize = r_obj.maxSize;
        numbers.clear(); // Clear current contents
        for (std::vector<int>::const_iterator it = r_obj.numbers.begin(); it != r_obj.numbers.end(); ++it)
        {
            numbers.push_back(*it);
        }
    }
    return (*this);
}

Span::Span(Span &r_obj)
{
    *this = r_obj;
}

void    Span::clear(void)
{
    numbers.clear();
}

int& Span::operator[](unsigned int n)
{
    if (numbers.size() <= 0)
        throw std::runtime_error("Error zero index.");
    if (n >= maxSize) {
        throw std::runtime_error("Index out of bounds");
    }
    return numbers.at(n);
}

int Span::size(void) const
{
    return maxSize;
}
void Span::addNumber(int num)
{
    if (numbers.size() >= maxSize) {
        throw std::runtime_error("Span is full. Cannot add more numbers.");
    }
    numbers.push_back(num);   
}

int Span::shortestSpan(void)
{
    if (numbers.size() <= 1) {
        throw std::runtime_error("Not enough numbers to find a span.");
    }
    std::sort(numbers.begin(), numbers.end());
    int minSpan = numbers[1] - numbers[0];
    for (size_t i = 2; i < numbers.size(); ++i) 
    {
        int span = numbers[i] - numbers[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan(void) {
    
    if (numbers.size() <= 1) 
        throw std::runtime_error("Not enough numbers to find a span.");

    std::sort(numbers.begin(), numbers.end());
    return numbers[numbers.size() - 1] - numbers[0];
}