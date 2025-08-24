#include "Contact.hpp"

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name,std::string darkest_secret,std::string phone_number)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nick_name = nick_name;
    this->darkest_secret = darkest_secret;
    this->phone_number = phone_number;
}

Contact::Contact()
{
}