#include "Phonebook.hpp"
#include <iostream>
#include <sstream>

int main(void)
{
    Phonebook   book;
    std::string input;
    std::size_t number;

    while(true)
    {
        std::cout << "Program can use 3 command (ADD, SEARCH, EXIT): ";
		if(!std::getline(std::cin, input))
            break;
		if (input == "ADD")
			book.Add();
		else if (input == "SEARCH")
        {
            if(book.get_index())
                book.Display();
            std::cout << "number index for search :";
            if(!std::getline(std::cin, input))
                break;
            std::istringstream(input) >> number;
            number = number - 1;
            if(number >= 0 && number < 8 && number <= book.get_index_local())
			    book.Search(number);
            else
                std::cout << "ERROR SEARCH." << std::endl; 
        }    
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Invalid command." << std::endl;
    }
    std::cout << "Program TURN OFF." << std::endl;
}