#ifndef STOREFOURKEY_H
# define STOREFOURKEY_H

#include <iostream>
#include <string>

class Storefourkey
{
    private:
        std::string status;
        std::string year;
        std::string mounth;
        std::string date;
        std::string value;
    public:
        Storefourkey(void) {
            setstatus("Unknow");
        };
        void setstatus(std::string status){
            this->status = status;
        };

        std::string getstatus(void){
            return status;
        };
        void setyear(std::string year){
            this->year = year;
        };
        std::string getyear(void){
            return year;
        };
};

#endif
