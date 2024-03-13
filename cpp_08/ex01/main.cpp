#include "Span.hpp"

int main(void)
{
    Span test(5);
    //Error not add value.
    try
    {
        for(int i = 0 ; i < test.size() ; i++)
            test[i] = test[i] * 5;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    {
        //normal case
        //-->add value and print
        for(int i = 0 ; i < test.size() ; i++)
        {
            if(i % 2 == 0)
                test.addNumber(i * 2);
            else
                test.addNumber(i + 1);
        }
        try
        {
            for(int i = 0 ; i < test.size() ; i++)
            {
                if(i % 2 == 0)
                    test[i] = test[i] * 5;
                else
                    test[i] = test[i] * 2;
            }    
            
            for(int i = 0 ; i < test.size() ; i++)
            {
                std::cout << test[i] << std::endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        //-->shortestspan
        std::cout << "Shortest Span:" << test.shortestSpan() << std::endl;

        //-->longestspan
        std::cout << "longest Span:" << test.longestSpan() << std::endl;
    }

    //Error -1 and maximun size
    {
        test[4];
        try
        {
            test[-1];
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        try
        {
            test[500];
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        
    }

    //Error add value maximun size
    {
      
        try
        {
            test.addNumber(2);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    //Error shortestspan and longest span
    {
        test.clear();
        test.addNumber(2);
        try
        {
            std::cout << "Shortest Span:" << test.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            std::cout << "longest Span:" << test.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }       
    }


}