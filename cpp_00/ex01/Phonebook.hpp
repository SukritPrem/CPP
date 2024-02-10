#ifndef PHONEBOOK_H
# define PHONEBOOK_H
#include "Contact.hpp"
#define Max_contact 8

class Phonebook{
    public:
        Phonebook(void);
        ~Phonebook(void);
        void    Add(void);
        void    Search(size_t index);
        void    Display(void);
        void    display_table(void);
        int     get_firstname_input(void);
        int     get_last_name_input(void);
        int     get_phone_number(void);
        int     get_darkest_secrete(void);
        void    set_error(size_t error);
        int     get_error(void) const;
        std::size_t     get_index_local(void);
        std::size_t     get_index(void);
        void     get_input(void);
        void     set_contact(std::string first_name, 
                            std::string last_name, 
                            std::size_t _index, 
                            std::string phone_number, 
                            std::string darkest_secrete);
    private:
        Contact get;
        Contact book[Max_contact];
        static std::size_t     needinput;
        std::size_t    error;
};

#endif