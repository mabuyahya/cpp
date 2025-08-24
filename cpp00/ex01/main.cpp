#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

void get_contact(PhoneBook& pb)
{
    Contact new_contact;
    
    std::cout << "First name :";
    std::cin >> new_contact.first_name;
    std::cout << "last name :";
    std::cin >> new_contact.last_name;
    std::cout << "nick name :";
    std::cin >> new_contact.nick_name;
    std::cout << "darkest secret :";
    std::cin >> new_contact.darkest_secret;
    std::cout << "phone number :";
    std::cin >> new_contact.phone_number;
    pb.addContact(new_contact);

}

int main()
{
    PhoneBook pb;
    std::string cmd;
    // std::string str = "1234567890";
    // std::cout << "|";
    // std::cout << str.substr(0, 9) << "\n";
    // std::cout << str.length() << "\n";
    // std::cout << "|";
    while (true)
    {
        std::cout << "enter a command:";
        std::getline(std::cin, cmd);
        if (cmd == "a")
            get_contact(pb);
        else if (cmd == "s")
            pb.searchContact();
        else if (cmd == "e")
            break;
    }
}

