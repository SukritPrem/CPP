#include <iostream>
#include "Phonebook.hpp"

Phonebook::Phonebook(void){
    Phonebook::set_error(0);
    Phonebook::book->set_index(0);
    Phonebook::book->set_index_local(0);
};

Phonebook::~Phonebook(void){}

void Phonebook::Add(void)
{
    // std::cout << book->get_index() <<std::endl;
    if(Phonebook::book->get_index() == Max_contact)
    {
        Phonebook::book->set_index(0);
        Phonebook::book->set_index_local(0);
    }    
    if(Phonebook::book->get_index() < Max_contact)
    {
        Phonebook::get_input();
    }
}

void Phonebook::get_input(void)
{
    if(!Phonebook::get_firstname_input())
    {
        std::cout << "Fist Name ERROR IS EMPTY." << std::endl;
        Phonebook::set_error(1);
    } 
    if(Phonebook::get_error() == 1 || !Phonebook::get_last_name_input())
    {
        if(Phonebook::get_error() == 0)
            std::cout << "Last Name ERROR IS EMPTY." << std::endl;
        Phonebook::set_error(1);
    }
    if(Phonebook::get_error() == 1 || !Phonebook::get_phone_number())
    {
        if(Phonebook::get_error() == 0)
            std::cout << "Phone Number ERROR IS EMPTY." << std::endl;
        Phonebook::set_error(1);
    }
    if(Phonebook::get_error() == 1 || !Phonebook::get_darkest_secrete())
    {
        if(Phonebook::get_error() == 0)
            std::cout << "Darkest Secrete ERROR IS EMPTY." << std::endl;
        Phonebook::set_error(1);
    }
    if(Phonebook::get_error())
    {
        std::cout << "ERROR UPDATE PHONEBOOK." << std::endl;
        Phonebook::set_error(0);
    }
    else
        Phonebook::set_contact(Phonebook::get.get_first_name()
                                ,Phonebook::get.get_last_name()
                                ,Phonebook::book->get_index()
                                ,Phonebook::get.get_phonenumber()
                                ,Phonebook::get.get_darkest_secrete());
}


int Phonebook::get_firstname_input(void)
{
    std::string input;
    std::cout << "First Name :"; 
    if(!std::getline(std::cin, input))
    {
        std::cout << std::endl;
        Phonebook::set_error(2);
        return (0);
    }    
    if(input.empty() == 1)
        return(0);
    Phonebook::get.set_first_name(input);
    return (1);
}

int Phonebook::get_last_name_input(void)
{
    std::string input;
    std::cout << "Last Name :"; 
    if(!std::getline(std::cin, input))
    {
        std::cout << std::endl;
        return (0);
    }
    if(input.empty() == 1)
        return(0);
    Phonebook::get.set_last_name(input);
    return (1);   
}

int Phonebook::get_phone_number(void)
{
    std::string input;
    std::cout << "Phone number :"; 
    if(!std::getline(std::cin, input))
    {
        std::cout << std::endl;
        return (0);
    }
    if(input.empty() == 1)
        return(0);
    Phonebook::get.set_phonenumber(input);
    return (1);   
};

int Phonebook::get_darkest_secrete(void)
{
    std::string input;
    std::cout << "darkest secrete :"; 
    if(!std::getline(std::cin, input))
    {
        std::cout << std::endl;
        return (0);
    }
    if(input.empty() == 1)
        return(0);
    Phonebook::get.set_darkest_secrete(input);
    return (1);   
};

void Phonebook::Search(size_t index)
{
    if(index < Max_contact && Phonebook::book->get_index_local())
    {
        for(size_t i = 0; i < Max_contact; i++)
        {
            if(i == index)
                Phonebook::book[i].display_search();
        }
    }
    else if(!Phonebook::book->get_index_local())
        std::cout << "EMPTY PHONEBOOK." << std::endl;
}

void Phonebook::Display(void)
{
    if(Phonebook::book->get_index_local())
    {
        Phonebook::display_table();
        for(int i = 0; i < Max_contact; i++)
        {
            if(Phonebook::book[i].get_first_name().empty() == 0)
                Phonebook::book[i].display_contact();
        }
    }    
}

void    Phonebook::display_table(void){
    std::cout << std::setw(10) << "index" <<  "|" ;
    std::cout << std::setw(10) << "First Name"<<  "|" ;
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "PhoneNum"<< "|" << std::endl;
}
void    Phonebook::set_error(size_t error){this->error = error;}

int Phonebook::get_error(void) const{return this->error;}

void Phonebook::set_contact(std::string first_name, 
                            std::string last_name, 
                            std::size_t _index, 
                            std::string phone_number, 
                            std::string darkest_secrete)
{    
    Phonebook::book[Phonebook::book->get_index()].set_first_name(first_name);
    Phonebook::book[Phonebook::book->get_index()].set_last_name(last_name);
    Phonebook::book[Phonebook::book->get_index()].set_phonenumber(phone_number);
    Phonebook::book[Phonebook::book->get_index()].set_darkest_secrete(darkest_secrete);
    Phonebook::book[Phonebook::book->get_index()].set_index_local(_index + 1);  
    Phonebook::book->set_index(_index + 1); 
}

std::size_t  Phonebook::get_index_local(void){return Phonebook::book->get_index_local();}

std::size_t  Phonebook::get_index(void){return Phonebook::book->get_index();}