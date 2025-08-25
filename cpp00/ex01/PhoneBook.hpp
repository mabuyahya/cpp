#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int index;
    public:
        PhoneBook();
        void addContact();
        void searchContact();
    private:
        Contact getContact();
        void printContactInfo(Contact contact, int i);
        void printIndexInfo(int i);
        void printColumn(const std::string& str);
        std::string getUserInput(std::string str, int i);
};
#endif