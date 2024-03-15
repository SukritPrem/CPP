

#include "readFileInput.hpp"
#include "readFileData.hpp"

int main(void)
{
    ReadFileInput dataInput("input.txt");
    ReadFiledata dataCsv("data.csv");
    dataInput.readFileContents();
    dataInput.convertfileInputToMap();
}