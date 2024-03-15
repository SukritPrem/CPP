#ifndef  READFILEDATA_H
# define READFILEDATA_H

#include "readFile.hpp"

class ReadFiledata : public ReadFile
{
    private:
        std::map<int, Storefourkey> output;
    public:
        ReadFiledata(std::string name) : ReadFile(name){}
    
        void   readFileContents(void){
            if(!ReadFile::customOpenFile())
                throw std::runtime_error("Can't Open file input");
        }
        
        std::map<int, Storefourkey> convertfileInputToMap(void)
        {
            std::string line;
            int loop_count = 0;
            // Read each line of the file
            while (getline(ReadFile::getfile(), line))
            {
                std::stringstream groupWord(line);
                Storefourkey info;
                std::string value;
                int count = 0;
                int countOr = 0;
                // Split the line into tokens based on comma delimiter
                while (getline(groupWord, value, ',')) {
                    std::stringstream groupDate(value);
                    while(getline(groupDate, value, '-') && count == 0)
                    {
                        if(value.length() == 4 && count == 0)
                            info.setyear(value);
                        else if(value.length() == 2 && count == 1)
                            info.setmounth(value);
                        else if(value.length() == 2 && count == 2)
                            info.setdate(value);
                            // group
                        count++;
                    }
                    if(count == 1)
                        info.setvalue(value);
                    countOr++;
                }
                output[loop_count] = info;
            }
            return output;
        }
    
};

#endif
