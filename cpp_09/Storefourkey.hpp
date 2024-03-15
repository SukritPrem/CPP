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

        void setyear(std::string year){
            this->year = year;
        };

        void setmounth(std::string mounth){
            this->mounth = mounth;
        }

        void setdate(std::string date)
        {
            this->date = date;
        }

        void setvalue(std::string value)
        {
            this->value = value;
        }

        std::string getyear(void){
            return year;
        };

        std::string getstatus(void){
            return status;
        };

        std::string getdate(void){
            return date;
        }

        std::string getValue(void){
            return value;
        }
};

#endif
