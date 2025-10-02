#include "BitcoinExchange.hpp"

int main(){
    BitcoinExchange main("data2.csv");
    std::cout << "======================================================\n";
    main.parseFile("file.txt");

}