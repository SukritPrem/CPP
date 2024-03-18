#ifndef  CREATEOUTPUT_H
# define CREATEOUTPUT_H

#include "readFileData.hpp"
#include "readFileInput.hpp"

class CreateOutput
{
    private:
        ReadFileInput *fileInput;
        ReadFileData *fileData;
    public:
        void caluculateOutput(void){
            ReadFileInput dataCsv();
        };

};


#endif