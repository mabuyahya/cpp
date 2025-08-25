#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string darkestSecret;
        std::string phoneNumber;
    public:
        Contact();
        Contact(std::string firstName, std::string lastName,
                std::string nickName,std::string darkestSecret,std::string phoneNumber);
    void setFirstName(const std::string& first_name);
    void setLastName(const std::string& last_name);
    void setNickName(const std::string& nick_name);
    void setDarkestSecret(const std::string& darkest_secret);
    void setPhoneNumber(const std::string& phone_number);
    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getDarkestSecret();
    std::string getPhoneNumber();
};
#endif