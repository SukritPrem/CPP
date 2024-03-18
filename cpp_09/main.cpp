

#include "readFileInput.hpp"
#include "readFileData.hpp"

int main(void)
{

    // Test Read file data

    // ReadFileData test1("data.csv");
    // test1.readFileContents();
    // test1.convertfileDataToMap();


    // ReadFileData *test = new ReadFileData("data.csv");
    // test->testread();
    // (void)test;
    // (void)test1;
     ReadFileInput dataInput("input.txt", "|");
    dataInput.readFileContents();
    dataInput.convertfileInputToMap();
}