#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <iomanip>

class Contact{
    public:
        Contact(void);
        ~Contact(void);
        // void    set_index(void);
        void    set_first_name(std::string name);
        void    set_last_name(std::string name);
        void    set_index(std::size_t index);
        void    set_index_local(std::size_t _index);
        void    set_nickname(std::string str);
        void    set_darkest_secrete(std::string str);
        void    set_phonenumber(std::string str);
        std::string     get_phonenumber(void) const;
        std::size_t     get_index_local(void);
        std::string     get_first_name(void) const;
        std::size_t     get_index(void) const;
        std::string     get_last_name(void) const;
        std::string     get_nickname(void) const;
        std::string     get_darkest_secrete(void);
        void    display_contact(void) const;
        void    display_search(void);
        std::size_t     index;
        std::string     display_string(std::string str) const;
        // std::string get_last_name(void) const;
        // std::string get_nickname(void) const;
    private:
        int             _index;
        std::string     first_name;
        std::string     last_name;
        std::string     nickname;
        std::string     darkest_secrete;
        std::string     phonenumber;
};

#endif