#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

class Storefourkey
{
    private:
        std::string status;
        std::string year;
        std::string mounth;
        std::string date;
        std::string value;
    public:
        Storefourkey(void);

        void setstatus(std::string status){
            this->status = status;
        };

        std::string getstatus(void){
            return status;
        };
        void setyear(std::string year){
            this->year = year;
        };
        std::string getyear(void){
            return year;
        };
};

void adv_tokenizer(std::string s, char del)
{
    std::stringstream ss(s);
    std::string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        std::cout << word << std::endl;
    }
}


bool isNumber(const std::string& str) {
    std::istringstream iss(str);
    double num;
    return iss >> num && iss.eof();  // Check if entire string was converted and no extra characters
}

int main() {
    //Get file format from .csv
    // // Open the CSV file
    // std::ifstream file("data.csv");

    // // Check if the file is opened successfully
    // if (!file.is_open()) {
    //     std::cerr << "Failed to open file." << std::endl;
    //     return 1;
    // }
    // // Define a vector to store each row of the CSV file
    // std::vector<std::vector<std::string> > data;
    // std::string line;
    // // Read each line of the file
    // while (getline(file, line)) {
    //     std::stringstream ss(line);
    //     std::vector<std::string> row;
    //     std::string value;

    //     // Split the line into tokens based on comma delimiter
    //     while (getline(ss, value, ',')) {
    //         row.push_back(value);
    //     }

    //     // Store the row in the data vector
    //     data.push_back(row);
    // }

    // // Close the file
    // file.close();

    // // // Print the contents of the CSV file
    // // for (size_t i = 0; i < data.size(); ++i) {
    // //     const vector<string>& row = data[i];
    // //     for (size_t j = 0; j < row.size(); ++j) {
    // //         const string& cell = row[0];
    // //         cout << cell << "\t";
    // //     }
    // //     cout << endl;
    // // }


    // Open the CSV file
    std::ifstream file("input.txt");
    // check format .txt

    // Check if the file is opened successfully
    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    std::vector<std::string> formatHeader;
 
    // Insert some values into the map
    formatHeader.push_back("date");
    formatHeader.push_back("|");
    formatHeader.push_back("value");
    // Define a vector to store each row of the CSV file
    std::vector<std::vector<std::string> > data;
    std::map<int, std::map<std::string, std::string>> data_output;
    std::string line;
    int loop_count = 0;
    // Read each line of the file
    while (getline(file, line)) {
        std::stringstream row(line);
        std::string value;


        //check header format (date | value)
        if(loop_count == 0)
        {
            int count = 0;
            int check = 0;
            while (getline(row, value, ' ')) {
                if(value == "date" && count == 0)
                    check++;
                if(value == "|" && count == 1)
                    check++;
                if(value == "value" && count == 2)
                    check++;
                count++;
            }
            std::cout << check << std::endl;
            if(check != 3)
                throw std::runtime_error("Bad format header");
        }
        else
        {
            std::vector<std::string> afterSplit;
            int countRow = 0;
            int checkRow = 0;
            int count = 0;
            std::string groupWord;
            // int check_raw = 0;

            //check input format date (2011-13-01 | 3)
            //check input format date (2011-13-01 | -3)
            //check input format date (2011-13-01 | 0.3)
            while (getline(row, groupWord , ' ')) 
            {
                Storefourkey  line_output;

                //check fomat 2011-13-01
                if(countRow == 0)
                {
                    std::string key1;
                    int check = 0;
                    std::stringstream groupDate(groupWord);

                    while(getline(groupDate,key1, '-'))
                    {
                        if(key1.length() == 4 && count == 0)
                        {
                            line_output.setyear(key1);
                            check++;
                        }
                        if(key1.length() == 2 && count == 1)
                        {
                            check++;
                        }    
                        if(key1.length() == 2 && count == 2)
                            check++;
                        count++;
                    }
                    if(check != 3)
                        line_output.setstatus("ERROR DATE.");
                }

                //check format "|"
                if(!(value == "|" && countRow == 1 && line_output.getstatus() != "ERROR DATE."))
                    line_output.setstatus("ERROR '|'");

                //check format value       
                if(countRow == 2 && line_output.getstatus() != "ERROR DATE." &&
                    line_output.getstatus() != "ERROR '|'")
                {
                    std::string groupValue;
                    groupValue = groupWord;
                    std::map<std::string, int>  map;
                    //get negtive; -7.9 - 7
                    //get number; 8
                    //get float; 8.9
                    map["CountNegative"] = 0;
                    map["CountDot"] = 0;
                    for (size_t i = 0; i < groupValue.length(); ++i) 
                    {
                            if (groupValue[i] == '-') {
                                map["positionNegative"] = i;
                                map["CountDot"]++;
                            }
                            if (groupValue[i] == '.') {
                                map["positionDot"] = i;
                                map["CountNegative"]++;
                            }
                    }
                    if(map["CountDot"] > 1 && map["CountNegative"] > 1)
                        line_output.setstatus("ERROR VALUE DOT AND NEGATIVE.");
                    else if(map["CountNegative"] > 1 || map["positionNegative"] > 0)
                        line_output.setstatus("ERROR VALUE NEGATIVE IT'S MUST POSITIVE.");
                    else if(map["CountDot"] > 1)
                        line_output.setstatus("ERROR VALUE DOT.");
                    else
                    {
                        size_t i = 0;
                        for (; i < map["positionDot"]; i++)
                        {
                            if(!isdigit(groupValue[i]))
                                line_output.setstatus("ERROR VALUE MUST INT.");
                        }
                        
                        for (; i < groupValue.length() - i; i++)
                        {
                            if(!isdigit(groupValue[i]))
                                line_output.setstatus("ERROR VALUE MUST INT.");
                        }

                        line_output.setstatus("OK");
                    }    
                }

                countRow++;
            //     if(count == 2)
            //     {
            //         ss >> value;
            //         std::cout << value << std::endl;
            //         check_raw++;
            //     }
            //     count++;
            }
            // std::cout << check_raw << std::endl; 
        }  
        if(loop_count == 1)
                    break;
        //Check Header
        // if(ss >> value && count == 0)
        // {  
        //     std::cout << value << std::endl;
        //     if(value.compare("date") == 0)
        //     {
        //         ss >> value;
        //         if(value.compare("|") == 0)
        //         {
        //             ss >> value;
        //             if(value.compare("value") == 0)
        //             {

        //             }
        //         }
        //     }
        //     else
        //         throw std::runtime_error("Format does't not correct.");
        // }
        // data_output[loop_count] = 
        loop_count++;
        std::cout << std::endl;
        // Split the line into tokens based on comma delimiter


        // Store the row in the data vector
        // data.push_back(row);
    }

    // Close the file
    file.close();

    // // Print the contents of the CSV file
    // for (size_t i = 0; i < data.size(); ++i) {
    //     const vector<string>& row = data[i];
    //     for (size_t j = 0; j < row.size(); ++j) {
    //         const string& cell = row[0];
    //         cout << cell << "\t";
    //     }
    //     cout << endl;
    // }
    return 0;
}
