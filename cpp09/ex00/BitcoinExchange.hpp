#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <map>

enum Mode{
    DATABASE_MODE,
    FILEDATA_MODE,
};

class BitcoinExchange
{
    private:
        std::string dataBase;
        std::string fileData;
        std::map<std::string , float> dataBaseMap;
        std::map<std::string , float> fileDataMap;
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

void BitcoinExchange::parseFile(std::string fileName){
    readData(fileName, FILEDATA_MODE);
    validateData(FILEDATA_MODE);
    for (std::map<std::string, float>::iterator it = dataBaseMap.begin(); it != dataBaseMap.end(); it++)
    {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}

int BitcoinExchange::validValue(std::string value){
    int dotCount = 0;
    for (size_t i = 0; i < value.size(); i++)
    {
        if (value[i] == '.')
            dotCount++;
    }
    if (dotCount > 1 || value[value.size() - 1] == '.')
        return (0);
    for (size_t i = 0; i < value.size(); i++)
    {
        if (!std::isdigit(value[i]) && value[i] != '.')
            return (0);
    }
    return (1);
}

int BitcoinExchange::checkAllDigit(std::string year, std::string month, std::string day){
    for (size_t i = 0; i < year.size(); i++)
    {
        if (!std::isdigit(year[i]))
            return (0);
    }
    for (size_t i = 0; i < month.size(); i++)
    {
        if (!std::isdigit(month[i]))
            return (0);
    }
    for (size_t i = 0; i < day.size(); i++)
    {
        if (!std::isdigit(day[i]))
            return (0);
    }
    return (1);
}

int BitcoinExchange::validDate(std::string date){
    int count = 0;
    for (size_t i = 0; i < date.size(); i++){
        if (date[i] == '-')
            count++;
    }
    if (count != 2)
        return (0);
    int pos[2];
    pos[0] = date.find_first_of("-");
    pos[1] = date.find_last_of("-");
    std::string year = trem(date.substr(0, pos[0]));
    std::string month = trem(date.substr(pos[0] + 1, pos[1] - pos[0] - 1));
    std::string day = trem(date.substr(pos[1] + 1));
    if (year.empty() || month.empty() || day.empty())
        return (0);
    if (year.size() != 4 || month.size() != 2 || day.size() != 2)
        return (0);
    if (!checkAllDigit(year, month, day))
        return (0);
    int yearI = std::atoi(year.c_str());
    int monthI = std::atoi(month.c_str());
    int dayI = std::atoi(day.c_str());
    if (yearI < 0 || yearI > 2025 || monthI < 1 || monthI > 12 || dayI < 1 || dayI > 31)
        return (0);
    return (1);
}

std::string BitcoinExchange::trem(std::string str){
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos)
        return ("");
    int len = str.find_last_not_of(" \n \t") - first + 1;
    return(str.substr(first, len));
}

int BitcoinExchange::checkHeader(std::string str, std::string del, std::string first, std::string secand){
    size_t delIndex = str.find(del);
    if (delIndex == std::string::npos)
        return (0);
    if (first != trem(str.substr(0, delIndex)))
        return (0);
    if (secand != trem(str.substr(delIndex + 1)))
        return (0);
    return (1);
}

int BitcoinExchange::checkLine(std::string str, int mode){
    std::string del = (mode == DATABASE_MODE ? "," : ":");
    size_t delIndex = str.find(del);
    if (delIndex == std::string::npos)
        return (0);
    std::string date = trem(str.substr(0, delIndex));
    std::string value = trem(str.substr(delIndex + 1));
    if (date.empty() || value.empty())
        return (0);
    if (!validDate(date) ||  !validValue(value))
        return (0);
    if (mode == DATABASE_MODE)
        dataBaseMap[date] = std::atof(value.c_str());
    else
        fileDataMap[date] = std::atof(value.c_str());
    return (1);
}

void    BitcoinExchange::validateData(int mode){
    size_t i = 0;
    size_t end = 0;
    size_t len = 0;
    std::string line;

    std::string del = (mode == DATABASE_MODE ? "," : "|");
    std::string first = "date";
    std::string secend = (mode == DATABASE_MODE ? "exchange_rate" : "value");
    std::string data = (mode == DATABASE_MODE ? dataBase : fileData);

    std::cout << del << first << secend << std::endl;
    end = data.find("\n", i);
    if (end == std::string::npos)
        end = data.size();
    len = end - i;
    line = data.substr(i, len);
    if (!checkHeader(line, del, first, secend))
    {
        std::cout << "Error: bad header => " << line << std::endl;
        std::exit(2);
    }
    i = end + 1;
    while (i < data.size())
    {
        end = data.find("\n", i);
        if (end == std::string::npos)
            end = data.size();
        len = end - i;
        line = data.substr(i, len);
        i = end + 1;
        if (!checkLine(line, DATABASE_MODE))
        {
            std::cout << "Error: bad input " << line << std::endl;
            std::exit(3);
        }
    }
}

void    BitcoinExchange::readData(std::string fileName, int mode){
    std::ifstream    file(fileName.c_str());
    if (!file || !file.is_open()){
        std::cout << "Error: could not open file. : " << fileName << std::endl;
        std::exit(1);
    }
    std::ostringstream dataBaseStream;
    dataBaseStream << file.rdbuf();
    if (mode == DATABASE_MODE)
        dataBase = dataBaseStream.str();
    else 
        fileData = dataBaseStream.str();
}

BitcoinExchange::BitcoinExchange()
{
    readData("data.csv", DATABASE_MODE);
    validateData(DATABASE_MODE);
}

BitcoinExchange::BitcoinExchange(std::string fileName)
{
    readData(fileName, DATABASE_MODE);
    validateData(DATABASE_MODE);
    for (std::map<std::string, float>::iterator it = dataBaseMap.begin(); it != dataBaseMap.end(); it++)
    {
        std::cout << it->first << " => " << it->second << std::endl;
    }
    
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &)
{
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &)
{
    return(*this);
}

#endif 