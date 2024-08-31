
#include "BitcoinExchange.hpp"
int main(int argc, char **argv)
{
    (void)argv;
    (void)argc;
    if(argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    // BitcoinExchange b("test","test");
    // BitcoinExchange a(b);
    BitcoinExchange b(argv[1],"data.csv");
    BitcoinExchange a(b);
    return 0;
    // BitcoinExchange("data1.csv","data.csv"); //for testing purposes
    // BitcoinExchange("./test/data1.csv","data.csv"); //for testing purposes
}