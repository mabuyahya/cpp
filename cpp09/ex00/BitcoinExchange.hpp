#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <stdexcept>

enum Mode{
    DATABASE_MODE,
    FILEDATA_MODE,
};


enum Error{
    NOTPOS = 2,
    TOOLARG = 3,
    NONE = 0,
};

class BitcoinExchange
{
    private:
        std::string dataBase;
        std::string fileData;
        std::map<std::string , float> dataBaseMap;
        std::string fileDate;
        float   fileValue;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &);
        BitcoinExchange &operator=(const BitcoinExchange &);
        BitcoinExchange(std::string );
        void parseFile(std::string);
    private:
        void readData(std::string , int mode);
        void validateData(int mode);
        int checkHeader(std::string, std::string, std::string, std::string);
        int checkLine(std::string,int mode);
        std::string trem(std::string);
        int validDate(std::string);
        int validValue(std::string);
        int checkAllDigit(std::string , std::string , std::string);
};


#endif