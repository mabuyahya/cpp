#ifndef PHONEBOOK_CPP
#define PHONEBOOK_CPP
#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    index = 0; 
}

void PhoneBook::searchContact()
{
    printColumn("index");
    std::cout << "|";
    printColumn("first name");
    std::cout << "|";
    printColumn("last name");
    std::cout << "|";
    printColumn("nick name");
    std::cout << "|";
    std::cout << "\n";
    for (int i = 0; i < index ; i++)
        printContactInfo(contacts[i], i);
    std::cout << "enter index:";
    // std::string index;
    // std::cin >> index;
    // printIndexInfo(index);

}

void PhoneBook::printIndexInfo(int i)
{
    if (i > 7)
        return ; 
    Contact contact = contacts[i];
    std::cout << "first name :"<< contact.first_name << "\n";
    std::cout << "last name :"<< contact.last_name << "\n";
    std::cout << "nick name :"<< contact.nick_name << "\n";
    std::cout << "darkest secret :"<< contact.darkest_secret << "\n";
    std::cout << "phone number :"<< contact.phone_number << "\n";

}

void PhoneBook::printContactInfo(Contact contact, int i)
{
    std::cout << std::right << std::setw(10) << i;
    std::cout << "|";
    printColumn(contact.first_name);
    std::cout << "|";
    printColumn(contact.last_name);
    std::cout << "|";
    printColumn(contact.nick_name);
    std::cout << "|" << "\n";
}

void PhoneBook::addContact(Contact newContact)
{
    this->contacts[this->index] = newContact;
    index = index + 1 % 8;
}

void PhoneBook::printColumn(const std::string& str)
{
    std::string temp;
    temp = str;
    if (str.length() > 10)
        temp = str.substr(0, 9) + ".";
    
    std::cout << std::right << std::setw(10) << temp;
}
#endif
