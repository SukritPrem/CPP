#ifndef READFILE_H
# define READFILE_H
#include "readFile.hpp"
#include <map>
#include <vector>
#include <sstream>
#include "Storefourkey.hpp"
#include <stdlib.h>
#include <climits>
#include <fstream>
#include <iostream>

class ReadFile
{
    private:
        std::string _name;
        std::ifstream *file;
    public:
        ReadFile(void){};
        ReadFile(std::string &name){setNamefile(name);};
        void setNamefile(std::string &name){
                        // std::cout << "test" << std::endl;
            _name = name;
        }

        std::ifstream& getfile(void){
            return *file;
        }

        bool customOpenFile(void){
            // std::cout << "test" << std::endl;
            file = new std::ifstream(_name.c_str());

            // Check if the file is opened successfully
            if (!file->is_open()) {
                std::cerr << "Failed to open file." << std::endl;
                return false;
            }
            return true;
        };

        virtual ~ReadFile() {
            if(file)
            {
                if (file->is_open()) 
                {
                    file->close();
                }
            }
            delete file;
        }
        virtual void   readFileContents(void) = 0;
};
#endif