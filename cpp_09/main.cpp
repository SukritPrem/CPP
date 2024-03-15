

#include "readFileInput.hpp"

int main(void)
{
    ReadFileInput data("input.txt");
    
    data.readFileContents();
    data.convertfileInputToMap();
}