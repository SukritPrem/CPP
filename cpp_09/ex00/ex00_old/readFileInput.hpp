#ifndef  READFILEINPUT_H
# define READFILEINPUT_H

#include "readFile.hpp"
// #include <map>
// #include <vector>
// #include <sstream>
// #include "Storefourkey.hpp"
// #include <stdlib.h>
// #include <climits>

class ReadFileInput : public ReadFile
{
    protected:
        std::string separate;
        Storefourkey info;
        std::vector<std::string> formatHeader;
        std::map<std::string, int> checkValue;
        virtual std::string checkFormatHeader(std::string line){
            std::cout << *(formatHeader.begin() + 1) << std::endl;
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
                return(toUpper("Bad format header"));
            else
                return(toUpper("OK format header."));
        };

        void    checkFormatKeyValue(std::string line)
        {
            std::stringstream groupWord(line);
            std::string word;
            int count = 0;
            while(groupWord >> word)
            {
                if(count == 0)
                {
                    checkFormatDate(word);
                    if(groupWord.eof())
                        info.setstatus("Have Only Date");
                }
                else if(count == 1 && info.getstatus() == "Unknow")
                {
                    if(word != getSeparate())
                        info.setstatus("ERROR " + getSeparate());
                    if(groupWord.eof())
                        info.setstatus("Have Only Date and " + getSeparate());
                }
                else if(count == 2 && info.getstatus() == "Unknow")
                {
                    checkFormatValue(word);
                    break;
                }
                count++;
            }
            if(!groupWord.eof())
                info.setstatus(toUpper("Have Many group word in line"));
        }


    private:
        std::map<int, Storefourkey> output;
        bool isValueGreaterThanIntMax(long value) {
            // std::cout << value << std::endl;
            return static_cast<long>(value) > static_cast<long>(INT_MAX);
        }
        std::string toUpper(const std::string& str) {
            std::string result = str;
            for (size_t i = 0; i < result.length(); ++i) 
            {
                if (result[i] >= 'a' && result[i] <= 'z') {
                    result[i] -= ('a' - 'A'); // Convert to uppercase
                }
            }
            return result;
        }
        void checkAlldigit(std::string &value,std::string string){
            for(size_t i = 0; i < value.length() ;i++)
            {
                if(!isdigit(value[i]))
                    info.setstatus(string);
            }
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
                    info.setmounth(value);
                    check++;
                }   
                if(value.length() == 2 && count == 2)
                {
                    checkAlldigit(value,"ERROR DATE MUST INT.");
                    info.setdate(value);
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
                        checkValue["CountNegative"]++;
                    }
                    if (word[i] == '.') {
                        checkValue["positionDot"] = i;
                        checkValue["CountDot"]++;
                    }
            }
        }

        void    setStatusAfterCountDotandNegative(std::string &word)
        {
            if(checkValue["CountDot"] > 1 && checkValue["CountNegative"] > 1)
                info.setstatus("ERROR VALUE DOT AND NEGATIVE.");
            else if(checkValue["CountNegative"] > 0)
                info.setstatus("ERROR VALUE NEGATIVE IT'S MUST POSITIVE.");
            else if(checkValue["CountDot"] > 0 && (checkValue["positionDot"] == 0 || \
                checkValue["positionDot"] == static_cast<int>(word.length() - 1)))
                info.setstatus("ERROR VALUE DOT.");
            else
            {
                int i = 0;
                for (; i < checkValue["positionDot"]; i++)
                {
                    if(!isdigit(word[i]))
                        info.setstatus("ERROR VALUE MUST INT.");
                }
                int postDot = i++;
                for (; static_cast<unsigned long>(i) < word.length() - postDot; i++)
                {
                    if(!isdigit(word[i]))
                        info.setstatus("ERROR VALUE MUST INT.");
                }
                if(info.getstatus() == "Unknow")
                {
                    std::stringstream ss(word);
                    long long value;
                    ss >> value;
                    if(isValueGreaterThanIntMax(value))
                        info.setstatus("ERROR SIZE MAX INT");
                    else{
                        info.setvalue(word);
                        info.setstatus("OK VALUE.");
                    }    
                }  
            }
        }
        
        void    resetCheckValue(void)
        {
            checkValue["CountNegative"] = 0;
            checkValue["positionDot"] = 0;
            checkValue["CountDot"] = 0;
        }

        void    checkFormatValue(std::string &word)
        {
            resetCheckValue();
            countDotandNegative(word);
            setStatusAfterCountDotandNegative(word);
            // if(info.getstatus() == "OK")
            // {
            //     std::cout << info.getstatus() << std::endl;
            // }
        }


    public:
        ReadFileInput(void){};
        ~ReadFileInput(void){
            // std::cout << "Bye by ReadFile" << std::endl;
        };
        ReadFileInput(std::string name, std::string separate) : ReadFile(name){
            setSeparate(separate);
            setfomatHeader();
            setCheckValue();
        }

        void    setCheckValue(void)
        {
            checkValue["CountNegative"] = 0;
            checkValue["CountDot"] = 0;
        }
        void    setSeparate(std::string separate)
        {
            this->separate = separate;
        }
        std::string &getSeparate(void){return separate;};

        virtual void    setfomatHeader(void)
        {
            formatHeader.push_back("date");
            formatHeader.push_back("|");
            formatHeader.push_back("value");
        }

        void   readFileContents(void){
            if(!ReadFile::customOpenFile())
                throw std::runtime_error("Can't Open file input");
        }


        std::map<int, Storefourkey> convertfileInputToMap(void)
        {
            std::string line;
            int loop_count = 0;
            while (getline(ReadFile::getfile(), line)) {
                // std::cout << line << std::endl;
                // check header format (date | value)
                if(loop_count == 0)
                    info.setstatus(checkFormatHeader(line));
                else
                    checkFormatKeyValue(line);
                std::cout << info.getstatus() << std::endl;
                // if(loop_count == 2)
                //     break;
                loop_count++;
                output[loop_count] = info;
                info.setstatus("Unknow");
            }
            return output;
        }
};

#endif
