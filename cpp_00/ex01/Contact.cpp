#include "Contact.hpp"

Contact::Contact(void){}

Contact::~Contact(void){}

void Contact::set_index(std::size_t index){this->index = index;}

void Contact::set_first_name (std::string first_name){this->first_name = first_name;}

void Contact::set_last_name (std::string last_name){this->last_name = last_name;}

void Contact::set_index_local (std::size_t _index){this->_index = _index;}

void Contact::set_nickname(std::string str){this->nickname = str;}

void Contact::set_darkest_secrete(std::string str){this->darkest_secrete = str;}

void Contact::set_phonenumber(std::string str){this->phonenumber = str;}

std::string Contact::get_phonenumber(void) const{return this->phonenumber;}

std::string Contact::get_nickname(void) const{return this->nickname;}

std::size_t  Contact::get_index_local (void){return this->_index;}

std::string     Contact::get_darkest_secrete(void){return this->darkest_secrete;}

std::size_t Contact::get_index(void) const{return this->index;}

std::string Contact::get_first_name(void) const{return this->first_name ;}

std::string Contact::get_last_name(void) const{return this->last_name ;}


void    Contact::display_contact(void) const{
    std::cout << std::setw(10) << Contact::_index  <<  "|" ;
    std::cout << std::setw(10) << Contact::first_name.substr(0,10) <<  "|" ;
    std::cout << std::setw(10) << Contact::display_string(Contact::last_name) << "|";
    std::cout << std::setw(10) << Contact::display_string(Contact::phonenumber) << "|" << std::endl;
}

void Contact::display_search(void)
{
    std::cout<< "Fisrt Name   :" << Contact::get_first_name() <<std::endl;
    std::cout<< "Last  Name   :" << Contact::get_last_name() <<std::endl;
    std::cout<< "Phone number :" << Contact::get_phonenumber() <<std::endl;
    std::cout<< "Darkest secrete :" << Contact::get_darkest_secrete() <<std::endl;
}

std::string   Contact::display_string(std::string str) const
{
    if(str.length() > 9)
        return str.substr(0, 9) + ".";
    else
        return str;
}