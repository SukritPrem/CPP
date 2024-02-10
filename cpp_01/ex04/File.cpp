#include "File.hpp"

File::File(void){
    _input = NULL;
    _output = NULL;
    std::cout << "Create constructer class File" << std::endl;
}

File::~File(void){
    std::cout << "Deconstructer class File" << std::endl;
    if(_input)
    {
        _input->close();
        delete _input;
        _input = NULL;
    }    
    if(_output)
    {
        _output->close();
        delete _output;
        _output = NULL;
    }    
}

void    File::set_input(char *argv)
{
    _input = new std::ifstream(argv);
	if (!_input->is_open()) {
		std::cerr << "Error set input" << argv << std::endl;
        _input->close();
        delete _input;
        _input = NULL;
	}
}

void File::set_output(char *argv)
{
    std::string file = argv;
    file = file + ".replace";
    _output = new std::ofstream(file, std::ios::binary);;
	if (!_output->is_open()) {
		std::cerr << "Error set output " << argv << std::endl;
        _output->close();
        delete _output;
        _output = NULL;
    }
}
int     File::setting_file(char *argv)
{
    set_input(argv);
    if(_input == NULL)
        return (1);  
    set_output(argv);
    if(_input == NULL || _output == NULL)
        return (1);
    return(0);
}

int    File::replace_str_file(char *argv, char *replace)
{
	std::string	buf;
	std::string word_re = argv;
	size_t pos;
	while(std::getline(*_input, buf)) {
        pos = buf.find(argv);
        while(pos != std::string::npos)
        {
			if(pos == std::string::npos)
				*_output << buf;
			else
			{
				std::string before = buf.substr(0, pos);
				*_output << before << replace;
				buf = buf.substr(pos + word_re.length());
				pos = buf.find(argv);
			}	
        }
		if(pos == std::string::npos)
			*_output << buf;
		*_output << std::endl;
	}
	return (0);
}