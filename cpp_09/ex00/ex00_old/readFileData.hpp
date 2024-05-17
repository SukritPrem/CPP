#ifndef  READFILEDATA_H
# define READFILEDATA_H

#include "readFileInput.hpp"

class ReadFileData : public ReadFileInput
{
    private:
        std::map<int, Storefourkey> output;
    public:
        ReadFileData(std::string name) : ReadFileInput(name, ","){
            setfomatHeader();
        }
        ~ReadFileData(void){
            // std::cout << "Bye Bye" << std::endl;
        };

        void   readFileContents(void){
            if(!ReadFile::customOpenFile())
                throw std::runtime_error("Can't Open file input");
        }

        void    setfomatHeader(void)
        {
            //need becase class readFileData inheritance from readfileinput
            formatHeader.clear();
            formatHeader.push_back("date");
            formatHeader.push_back(",");
            formatHeader.push_back("exchange_rate");
        }     

        std::string addSpacesAfterComma(std::string input) {
            std::string output = input;
            size_t pos = output.find(',');
            while (pos != std::string::npos) {
                output.insert(pos, " ");
                output.insert(pos + 2, " ");
                pos = output.find(',', pos + 2);
            }
            return output;
        }


        std::map<int, Storefourkey> convertfileDataToMap(void)
        {
            std::string line;
            int loop_count = 0;

            while (getline(ReadFile::getfile(), line)) 
            {
                // std::cout << "-->" << addSpacesAfterComma(line) << std::endl;
                if(loop_count == 0)
                    ReadFileInput::info.setstatus(checkFormatHeader(addSpacesAfterComma(line)));
                else
                    checkFormatKeyValue(addSpacesAfterComma(line));
                std::cout << info.getstatus() << std::endl;
                loop_count++;
                output[loop_count] = info;
                info.setstatus("Unknow");
            }
            return output;
        }
    
};

#endif
