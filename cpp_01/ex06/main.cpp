#include "Harl.hpp"

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        Harl    obj;
        obj.complain(argv[1]);
    }
    else
        std::cout << "This program have input like ./harlFilter string" << std::endl;
}