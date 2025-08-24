#include "Contact.hpp"
class PhoneBook
{
    private:
        Contact contacts[8];
        int index;
    public:
        PhoneBook();
        void addContact(Contact newContact);
        void searchContact();
    private:
        void printContactInfo(Contact contact, int i);
        void printIndexInfo(int i);
        void printColumn(const std::string& str);
};