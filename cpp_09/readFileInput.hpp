#ifndef  READFILEINPUT_H
# define READFILEINPUT_H

#include "readFile.hpp"
#include <map>
#include <vector>
#include <sstream>
#include "Storefourkey.hpp"
#include <stdlib.h>

class ReadFileInput : public ReadFile
{
    private:
        Storefourkey info;
        std::map<int, Storefourkey> output;
        std::vector<std::string> formatHeader;
        std::map<std::string, int> checkValue;
        void checkAlldigit(std::string &value,std::string string){
            for(size_t i = 0; i < value.length() ;i++)
            {
                if(!isdigit(value[i]))
                    info.setstatus(string);
            }
        };
        std::string checkFormatHeader(std::string &line){
            std::stringstream row(line);
            std::string value;
            int count = 0;
            int check = 0;
            while (getline(row, value, ' ')){

                if(value == *(formatHeader.begin() + count) && count == 0)
                    check++;
                if(value == *(formatHeader.begin() + count) && count == 1)
                    check++;
                if(value == *(formatHeader.begin() + count) && count == 2)
                    check++;
                count++;
            }
            std::cout << check << std::endl;
            if(check != 3)
                return("Bad format header");
            else
                return(info.getstatus());
        };
        void    checkFormatDate(std::string &word)
        {
            int check = 0;
            int count = 0;
            std::string value;
            std::stringstream groupDate(word);
            //word format 2011-12-09
            while(getline(groupDate, value, '-'))
            {
                 if(value.length() == 4 && count == 0)
                {
                    checkAlldigit(value,"ERROR YEAR MUST INT.");
                    info.setyear(value);
                    check++;
                }
                if(value.length() == 2 && count == 1)
                {
                    checkAlldigit(value,"ERROR MOUNTH MUST INT.");
                    check++;
                }   
                if(value.length() == 2 && count == 2)
                {
                    checkAlldigit(value,"ERROR DATE MUST INT.");
                    check++;
                }    
                count++;
            }
            if(check != 3)
                info.setstatus("ERROR DATE.");
        }
        void    countDotandNegative(std::string &word)
        {
            for (size_t i = 0; i < word.length(); ++i) 
            {
                    if (word[i] == '-') {
                        checkValue["positionNegative"] = i;
                        checkValue["CountDot"]++;
                    }
                    if (word[i] == '.') {
                        checkValue["positionDot"] = i;
                        checkValue["CountNegative"]++;
                    }
            }
        }

        void    setStatusAfterCountDotandNegative(std::string &word)
        {
            if(checkValue["CountDot"] > 1 && checkValue["CountNegative"] > 1)
                info.setstatus("ERROR VALUE DOT AND NEGATIVE.");
            else if(checkValue["CountNegative"] > 1 || checkValue["positionNegative"] >= 0)
                info.setstatus("ERROR VALUE NEGATIVE IT'S MUST POSITIVE.");
            else if(checkValue["CountDot"] > 1)
                info.setstatus("ERROR VALUE DOT.");
            else
            {
                int i = 0;
                if(checkValue["positionNegative"] == 0)
                    i++;
                for (; i < checkValue["positionDot"]; i++)
                {
                    if(!isdigit(word[i]))
                        info.setstatus("ERROR VALUE MUST INT.");
                }
                int postDot = i;
                for (; static_cast<unsigned long>(i) < word.length() - postDot; i++)
                {
                    if(!isdigit(word[i]))
                        info.setstatus("ERROR VALUE MUST INT.");
                }

                info.setstatus("OK");
            }
        }
        
        void    checkFormatValue(std::string &word)
        {
            countDotandNegative(word);
            setStatusAfterCountDotandNegative(word);
            if(info.getstatus() == "OK")
            {

            }
        }
        void    checkFormatKeyValue(std::string &line)
        {
            std::stringstream groupWord(line);
            std::string word;
            int count = 0;
            while(getline(groupWord,word,' '))
            {
                if(count == 0)
                {
                    checkFormatDate(word);
                }
                else if(count == 1 && info.getstatus() == "Unknow")
                {
                    if(word != "|")
                        info.setstatus("ERROR '|'");
                }
                else if(count == 2 && info.getstatus() == "Unknow")
                {
                    checkFormatValue(word);
                }
                count++;
            }
        }
    public:
        ReadFileInput(std::string name) : ReadFile(name){
            setfomatHeader();
            setCheckValue();
        };
        void    setCheckValue(void)
        {
            checkValue["CountNegative"] = 0;
            checkValue["CountDot"] = 0;
        }
        void    setfomatHeader(void)
        {
            formatHeader.push_back("date");
            formatHeader.push_back("|");
            formatHeader.push_back("value");
        }

        void   readFileContents(void){
            if(!ReadFile::customOpenFile())
                throw std::runtime_error("Can't Open file data");
        }


        std::map<int, Storefourkey> convertfileInputToMap(void)
        {
            std::string line;
            int loop_count = 0;
            while (getline(ReadFile::getfile(), line)) {

                //check header format (date | value)
                if(loop_count == 0)
                    info.setstatus(checkFormatHeader(line));
                else
                    checkFormatKeyValue(line);

                if(loop_count == 1)
                    break;
                loop_count++;

                output[loop_count] = info;
            }
            return output;
        }
};

#endif
