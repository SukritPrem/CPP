#include <iostream>
#include <fstream>
#include <string>
#include "File.hpp"
int main(int argc, char **argv)
{
	// check argument
	if (argc != 4) {
		std::cerr << "Need 4 argument ./a.out file str1 str2" << std::endl;
		return (EXIT_FAILURE);
	}
	File test;
	if(test.setting_file(argv[1]))
		return (EXIT_FAILURE);
	test.replace_str_file(argv[2],argv[3]);
	return(0);
}