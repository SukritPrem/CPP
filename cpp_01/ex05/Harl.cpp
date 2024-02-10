
#include "Harl.hpp"

void    Harl::debug(void)
{
    std::cout <<"[DEBUG]"<<std::endl;
    std::cout <<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
    std::cout << std::endl;
}

void    Harl::info(void)
{
    std::cout <<"[INFO]"<<std::endl;
    std::cout <<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    std::cout << std::endl;
}

void    Harl::warning(void)
{
    std::cout <<"[WARNING]"<<std::endl;
    std::cout <<"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
}

void    Harl::error(void)
{
    std::cout <<"[ERROR]"<<std::endl;
    std::cout <<"This is unacceptable! I want to speak to the manager now."<<std::endl;
    std::cout << std::endl;
}

void    Harl::complain(std::string level)
{
    void (Harl::*f[])() = {&Harl::warning, &Harl::error, &Harl::debug, &Harl::info};

    for(size_t i = 0; i < level.length(); i++)
        level[i] = tolower(level[i]);

    if (level == "warning")
        (this->*f[0])();
    else if (level == "error")
        (this->*f[1])();
    else if (level == "debug")
        (this->*f[2])();
    else if (level == "info")
        (this->*f[3])();
    else
        std::cout << "Unknown :" << level << std::endl;

}