#ifndef READFILE_H
# define READFILE_H

#include <fstream>
#include <iostream>

class ReadFile
{
    private:
        std::string name;
        std::ifstream *file;
    public:
        ReadFile(void){};
        ReadFile(std::string &name){setNamefile(name);};
        void setNamefile(std::string &name){
            this->name = name;
        }

        std::ifstream& getfile(void){
            return *file;
        }

        bool customOpenFile(void){

            file = new std::ifstream(this->name.c_str());

            // Check if the file is opened successfully
            if (!file->is_open()) {
                std::cerr << "Failed to open file." << std::endl;
                return false;
            }
            return true;
        };

        ~ReadFile() {
            if (file->is_open()) 
            {
                file->close();
            }
        }
        virtual void   readFileContents(void) = 0;
};
#endif