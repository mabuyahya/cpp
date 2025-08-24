#include <string>

class Contact{
    public:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string darkest_secret;
        std::string phone_number;
    public:
        Contact();
        Contact(std::string first_name, std::string last_name, std::string nick_name,std::string darkest_secret,std::string phone_number);
};