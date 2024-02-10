#ifndef FILE_H
# define FILE_H
#include <iostream>
#include <fstream>
#include <string>


class   File{
    private:
        std::ifstream  *_input;
        std::ofstream   *_output;
    public:
        File(void);
        ~File(void);
        int     replace_str_file(char *argv, char *replace);
        int     setting_file(char *argv);
        void    set_input(char *argv);
        void    set_output(char *argv);
};

#endif