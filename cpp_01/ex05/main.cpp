#include "Harl.hpp"

int main(int argc,char **argv)
{
    Harl    obj;
    if(argc == 2)
    {    
        obj.complain(argv[1]);
    }
    else
        std::cout << "This program have input like ./harl string" << std::endl;
}