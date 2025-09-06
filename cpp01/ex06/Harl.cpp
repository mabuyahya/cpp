#include "Harl.hpp"

void    Harl::debug( void ){
    std::cout << "[ DEBUG ]" << "\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}
void    Harl::info( void ){
    std::cout << "[ INFO ]" << "\n";
    std::cout << "cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}
void    Harl::warning( void ){
    std::cout << "[ WARNING ]" << "\n";
    std::cout << "think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n";
}
void    Harl::error( void ){
    std::cout << "[ ERROR ]" << "\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.";
}

void    Harl::complain( std::string level ){
    int intLevel = -1;

    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            intLevel = i + 1;
            break ;
        }
    }
    switch (intLevel)
    {
        case 1:
            this->debug();
            std::cout << "\n";
        case 2:
            this->info();
            std::cout << "\n";
        case 3:
            this->warning();
            std::cout << "\n";
        case 4:
            this->error();
            std::cout << "\n";
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
}
