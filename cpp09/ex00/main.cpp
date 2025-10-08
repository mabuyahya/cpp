#include "BitcoinExchange.hpp"

int main(int c, char **s){
    if (c != 2){
        std::cout << "Error: could not open file.\n";
        return (1);
    }
    try {
        BitcoinExchange main("data.csv");
        main.parseFile(s[1]);
    } catch (std::exception& e) {
        (void) e;
        return (1);
    }
    return (0);
}